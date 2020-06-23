#pragma once
#include "EqProcessor.h"
#include "Components/BandEditor.h"
#include "Components/SpectrumAnalyzer.h"
#include "Components/XYPad.h"
#include "Components/FrequencyCurve.h"
#include "LookAndFeel/LookAndFeel.h"
#include <BinaryData.h>

namespace witte
{

class EqAudioProcessorEditor : public AudioProcessorEditor
{
    public:
        EqAudioProcessorEditor (EqAudioProcessor&, AudioProcessorValueTreeState&);
        ~EqAudioProcessorEditor() override;

        void paint (Graphics&) override;
        void resized() override;


    private:
        EqAudioProcessor& processor;
        AudioProcessorValueTreeState& tree;
        witte::LookAndFeel lookAndFeel;

        Image background {ImageCache::getFromMemory (BinaryData::texture_png, BinaryData::texture_pngSize)};

        witte::SpectrumAnalyzer analyzer;
        witte::FrequencyCurve frequencyCurve;
        witte::XYPad xyPad;

        witte::BandEditor band1;
        witte::BandEditor band2;
        witte::BandEditor band3;
        witte::BandEditor band4;
        witte::BandEditor band5;

        Slider outputGain;
        AudioProcessorValueTreeState::SliderAttachment attOutputGain;


        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EqAudioProcessorEditor)
};

}
