#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace Steinberg {
namespace Vst {
namespace MidiNoteDisplay {

// Plugin UIDs - these must be unique
static const FUID kProcessorUID(0x12345678, 0x12345678, 0x12345678, 0x12345678);
static const FUID kControllerUID(0x87654321, 0x87654321, 0x87654321, 0x87654321);

#define MidiNoteDisplayVST3Category "Fx"

} // namespace MidiNoteDisplay
} // namespace Vst
} // namespace Steinberg
