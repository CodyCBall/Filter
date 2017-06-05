/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"



 //==============================================================================


FilterAudioProcessor::FilterAudioProcessor() : _knob1(0)

{
    cutoff = _knob1;
    Q = .707;
    
    filterL.setCoefficients(nf.makeNotchFilter(_sampleRate, cutoff, Q));
    filterR.setCoefficients(nf.makeNotchFilter(_sampleRate, cutoff, Q));
}

FilterAudioProcessor::~FilterAudioProcessor()
{
    
}

float FilterAudioProcessor::getParameter(int index){
    switch (index) {
        case knob1Param: return _knob1;
        default: return 0.0;
    }
}

void FilterAudioProcessor::setParameter(int index, float newValue){
    switch(index){
        case knob1Param:_knob1 = newValue;
            cutoff = _knob1;
            filterL.setCoefficients(nf.makeNotchFilter(_sampleRate, cutoff, Q));
            filterR.setCoefficients(nf.makeNotchFilter(_sampleRate, cutoff, Q));
            break;
  
        default: break;
    }
    
}
const String FilterAudioProcessor::getParameterName (int index){
    switch (index){
        case knob1Param: return "Cutoff frequency";
        default: return String::empty;
    }
}

//============================================================================
const String FilterAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FilterAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool FilterAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double FilterAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FilterAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int FilterAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FilterAudioProcessor::setCurrentProgram (int index)
{
}

const String FilterAudioProcessor::getProgramName (int index)
{
    return String();
}

void FilterAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void FilterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    _sampleRate = sampleRate;
    cutoff = _knob1;
    
    filterL.setCoefficients(nf.makeNotchFilter(_sampleRate, cutoff, Q));    //set coefficients
    filterR.setCoefficients(nf.makeNotchFilter(_sampleRate, cutoff, Q));
}

void FilterAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FilterAudioProcessor::setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet)
{
    // Reject any bus arrangements that are not compatible with your plugin

    const int numChannels = preferredSet.size();

   #if JucePlugin_IsMidiEffect
    if (numChannels != 0)
        return false;
   #elif JucePlugin_IsSynth
    if (isInput || (numChannels != 1 && numChannels != 2))
        return false;
   #else
    if (numChannels != 1 && numChannels != 2)
        return false;

    if (! setPreferredBusArrangement (! isInput, bus, preferredSet))
        return false;
   #endif

    return setPreferredBusArrangement (isInput, bus, preferredSet);
}
#endif

void FilterAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
  
    float numSamples = buffer.getNumSamples();              // Get number of samples

    float *dataLeft = buffer.getWritePointer(0);               // Left channel
    float *dataRight = buffer.getWritePointer(1);               // Right channel

    filterL.processSamples(dataLeft, numSamples);               // Filter left channel
    filterR.processSamples(dataRight, numSamples);              // Filter right channel
    
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());                    // Clear buffer
    
}

//==============================================================================
bool FilterAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* FilterAudioProcessor::createEditor()
{
    return new FilterAudioProcessorEditor (*this);
}

//==============================================================================
void FilterAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void FilterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FilterAudioProcessor();
}
