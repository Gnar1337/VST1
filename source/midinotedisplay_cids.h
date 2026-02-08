#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace Steinberg {
namespace Vst {
namespace MidiNoteDisplay {

// Plugin UIDs - these must be unique
// Note: These are example UIDs. For production use, generate proper GUIDs using:
// - Windows: guidgen.exe or [System.Guid]::NewGuid() in PowerShell
// - macOS/Linux: uuidgen command
// - Online: https://www.guidgenerator.com/
static const FUID kProcessorUID(0xA9B2C3D4, 0xE5F60718, 0x293A4B5C, 0x6D7E8F90);
static const FUID kControllerUID(0x1A2B3C4D, 0x5E6F7081, 0x92A3B4C5, 0xD6E7F890);

#define MidiNoteDisplayVST3Category "Fx"

} // namespace MidiNoteDisplay
} // namespace Vst
} // namespace Steinberg
