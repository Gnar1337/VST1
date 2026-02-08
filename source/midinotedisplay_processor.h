#pragma once

#include "public.sdk/source/vst/vstaudioeffect.h"

namespace Steinberg {
namespace Vst {
namespace MidiNoteDisplay {

class MidiNoteDisplayProcessor : public AudioEffect
{
public:
    MidiNoteDisplayProcessor();
    ~MidiNoteDisplayProcessor() SMTG_OVERRIDE;

    static FUnknown* createInstance(void* /*context*/)
    {
        return (IAudioProcessor*)new MidiNoteDisplayProcessor;
    }

    tresult PLUGIN_API initialize(FUnknown* context) SMTG_OVERRIDE;
    tresult PLUGIN_API terminate() SMTG_OVERRIDE;
    tresult PLUGIN_API setActive(TBool state) SMTG_OVERRIDE;
    tresult PLUGIN_API process(ProcessData& data) SMTG_OVERRIDE;
    tresult PLUGIN_API setState(IBStream* state) SMTG_OVERRIDE;
    tresult PLUGIN_API getState(IBStream* state) SMTG_OVERRIDE;

protected:
    void processMidiEvent(const Event& event);
};

} // namespace MidiNoteDisplay
} // namespace Vst
} // namespace Steinberg
