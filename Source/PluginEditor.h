/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class FilterAudioProcessorEditor  : public AudioProcessorEditor, Slider::Listener, Timer
{
public:
    FilterAudioProcessorEditor (FilterAudioProcessor&);
    ~FilterAudioProcessorEditor();

    
    //==============================================================================
    void paint (Graphics&) override;
    
    
    void timerCallback() override;
    void sliderValueChanged (Slider* sliderThatWasChanged) override;
    
    
    void resized() override;


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FilterAudioProcessor& processor;

    ScopedPointer<Slider> knob1; //cutoff
    ScopedPointer<Slider> knob2; //Q
  

    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
