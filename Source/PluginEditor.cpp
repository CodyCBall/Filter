/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================

FilterAudioProcessorEditor::FilterAudioProcessorEditor (FilterAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (400, 200);
    addAndMakeVisible(knob1 = new Slider("Knob 1"));
  
    //Cutoff
    knob1->setRange(20.0,8000.0);
    knob1->setTextValueSuffix(" Hz");
    knob1->setTextBoxStyle(Slider::TextBoxBelow,true,100,20);
    knob1->setSliderStyle(Slider::Rotary);
    knob1->setColour(Slider::rotarySliderFillColourId, Colours::black);
    knob1->setColour(Slider::rotarySliderOutlineColourId, Colours::black);
    knob1->setColour(0x1001310, Colours::black);
    knob1->addListener(this);
    knob1->setBounds(150,55,100,100);
    
    startTimer(50);

}

FilterAudioProcessorEditor::~FilterAudioProcessorEditor()
{
}

//==============================================================================
void FilterAudioProcessorEditor::paint (Graphics& g)
{   Path rec;
    Path secRec;
    
    g.fillAll (Colours::black);
    rec.addRectangle(20, 20, 360, 160);
    g.setColour(Colours::blue);
    g.fillPath(rec);
    g.setColour (Colours::black);
    g.setFont (Font("Arial", 20, Font::bold + Font::italic));
    g.drawSingleLineText("Cutoff", 80, 105); // knob 1

}

void FilterAudioProcessorEditor::timerCallback(){
    knob1->setValue(processor.getParameter(FilterAudioProcessor::knob1Param), NotificationType::dontSendNotification);


}


void FilterAudioProcessorEditor::sliderValueChanged(Slider* sliderThatWasChanged)
{
    if (sliderThatWasChanged == knob1){
        processor.setParameterNotifyingHost(FilterAudioProcessor::knob1Param,(float)knob1->getValue());
    }
    
}

    void FilterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
