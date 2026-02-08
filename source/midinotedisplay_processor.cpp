#include "midinotedisplay_processor.h"
#include "midinotedisplay_cids.h"

#include "base/source/fstreamer.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"
#include "pluginterfaces/vst/ivstevents.h"

#include <stdio.h>

namespace Steinberg {
namespace Vst {
namespace MidiNoteDisplay {

MidiNoteDisplayProcessor::MidiNoteDisplayProcessor()
{
    setControllerClass(kControllerUID);
}

MidiNoteDisplayProcessor::~MidiNoteDisplayProcessor()
{
}

tresult PLUGIN_API MidiNoteDisplayProcessor::initialize(FUnknown* context)
{
    tresult result = AudioEffect::initialize(context);
    if (result != kResultOk)
    {
        return result;
    }

    // Add MIDI input
    addEventInput(STR16("Event In"), 1);

    return kResultOk;
}

tresult PLUGIN_API MidiNoteDisplayProcessor::terminate()
{
    return AudioEffect::terminate();
}

tresult PLUGIN_API MidiNoteDisplayProcessor::setActive(TBool state)
{
    return AudioEffect::setActive(state);
}

void MidiNoteDisplayProcessor::processMidiEvent(const Vst::Event& event)
{
    if (event.type == Vst::Event::kNoteOnEvent)
    {
        printf("MIDI Note ON  - Note: %d, Velocity: %.2f, Channel: %d\n",
               event.noteOn.pitch,
               event.noteOn.velocity,
               event.noteOn.channel);
    }
    else if (event.type == Vst::Event::kNoteOffEvent)
    {
        printf("MIDI Note OFF - Note: %d, Velocity: %.2f, Channel: %d\n",
               event.noteOff.pitch,
               event.noteOff.velocity,
               event.noteOff.channel);
    }
}

tresult PLUGIN_API MidiNoteDisplayProcessor::process(ProcessData& data)
{
    // Process input events (MIDI)
    if (data.inputEvents)
    {
        int32 numEvents = data.inputEvents->getEventCount();
        for (int32 i = 0; i < numEvents; i++)
        {
            Vst::Event event;
            if (data.inputEvents->getEvent(i, event) == kResultOk)
            {
                processMidiEvent(event);
            }
        }
    }

    return kResultOk;
}

tresult PLUGIN_API MidiNoteDisplayProcessor::setState(IBStream* state)
{
    if (!state)
        return kResultFalse;

    return kResultOk;
}

tresult PLUGIN_API MidiNoteDisplayProcessor::getState(IBStream* state)
{
    if (!state)
        return kResultFalse;

    return kResultOk;
}

} // namespace MidiNoteDisplay
} // namespace Vst
} // namespace Steinberg
