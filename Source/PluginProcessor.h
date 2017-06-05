/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "../../../Downloads/JUCE/modules/juce_audio_basics/effects/juce_IIRFilter.h"


//==============================================================================
/**
*/
class FilterAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    FilterAudioProcessor();
    ~FilterAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet) ;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    


    //==============================================================================
    const String getName() const override;
    //==============================================================================
    float getParameter (int index) override;
    void setParameter (int index, float newValue) override;
    
    const String getParameterName (int index) override;

    //==============================================================================
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    //==============================================================================
    enum Parameters{
        knob1Param,
        knob2Param
      
    };
    
    
private:
    //==============================================================================

    //Default values for filter
    const float defaultSampleRate = 44100.00;
    const float defaultMinFilterFrequency = 20.00;
    const float defaultMaxFilterFrequency = 20000.00;
    
    // Rotary
    double _knob1;
//    float m_knob2;
 
    
    float _sampleRate;
    //cooked variables
    float cutoff;
   float Q;
//    float gain;
    
    IIRCoefficients nf;
    IIRFilter filterL;
    IIRFilter filterR;

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
