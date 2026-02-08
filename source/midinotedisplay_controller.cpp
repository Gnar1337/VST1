#include "midinotedisplay_controller.h"
#include "midinotedisplay_cids.h"

#include "base/source/fstreamer.h"

namespace Steinberg {
namespace Vst {
namespace MidiNoteDisplay {

MidiNoteDisplayController::MidiNoteDisplayController()
{
}

MidiNoteDisplayController::~MidiNoteDisplayController()
{
}

tresult PLUGIN_API MidiNoteDisplayController::initialize(FUnknown* context)
{
    tresult result = EditController::initialize(context);
    if (result != kResultOk)
    {
        return result;
    }

    return kResultOk;
}

tresult PLUGIN_API MidiNoteDisplayController::terminate()
{
    return EditController::terminate();
}

tresult PLUGIN_API MidiNoteDisplayController::setComponentState(IBStream* state)
{
    if (!state)
        return kResultFalse;

    return kResultOk;
}

} // namespace MidiNoteDisplay
} // namespace Vst
} // namespace Steinberg
