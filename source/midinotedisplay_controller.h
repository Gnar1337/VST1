#pragma once

#include "public.sdk/source/vst/vsteditcontroller.h"

namespace Steinberg {
namespace Vst {
namespace MidiNoteDisplay {

class MidiNoteDisplayController : public EditController
{
public:
    MidiNoteDisplayController();
    ~MidiNoteDisplayController() SMTG_OVERRIDE;

    static FUnknown* createInstance(void* /*context*/)
    {
        return (IEditController*)new MidiNoteDisplayController;
    }

    tresult PLUGIN_API initialize(FUnknown* context) SMTG_OVERRIDE;
    tresult PLUGIN_API terminate() SMTG_OVERRIDE;
    tresult PLUGIN_API setComponentState(IBStream* state) SMTG_OVERRIDE;
};

} // namespace MidiNoteDisplay
} // namespace Vst
} // namespace Steinberg
