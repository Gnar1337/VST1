#include "midinotedisplay_processor.h"
#include "midinotedisplay_controller.h"
#include "midinotedisplay_cids.h"
#include "midinotedisplay_version.h"

#include "public.sdk/source/main/pluginfactory.h"

#define stringPluginName "MIDI Note Display"

using namespace Steinberg::Vst;
using namespace Steinberg::Vst::MidiNoteDisplay;

BEGIN_FACTORY_DEF("Steinberg Media Technologies",
                  "https://www.steinberg.net",
                  "mailto:info@steinberg.de")

    DEF_CLASS2(INLINE_UID_FROM_FUID(kProcessorUID),
               PClassInfo::kManyInstances,
               kVstAudioEffectClass,
               stringPluginName,
               Vst::kDistributable,
               MidiNoteDisplayVST3Category,
               FULL_VERSION_STR,
               kVstVersionString,
               MidiNoteDisplayProcessor::createInstance)

    DEF_CLASS2(INLINE_UID_FROM_FUID(kControllerUID),
               PClassInfo::kManyInstances,
               kVstComponentControllerClass,
               stringPluginName "Controller",
               0,
               "",
               FULL_VERSION_STR,
               kVstVersionString,
               MidiNoteDisplayController::createInstance)

END_FACTORY
