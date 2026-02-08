# MIDI Note Display VST3

A simple VST3 plugin that displays incoming MIDI notes to the console. This is a "Hello World" style plugin built with the Steinberg VST3 SDK.

## Features

- Displays MIDI Note ON events with note number, velocity, and channel
- Displays MIDI Note OFF events with note number, velocity, and channel
- Simple console output for debugging and learning

## Building

### Prerequisites

- CMake 3.14 or higher
- C++ compiler with C++14 support (Visual Studio 2017+, GCC 7+, Clang 5+)
- Git (for cloning submodules)

### Build Instructions

1. Clone the repository with submodules:
```bash
git clone --recursive https://github.com/Gnar1337/VST1.git
cd VST1
```

If you already cloned without `--recursive`, initialize the submodules:
```bash
git submodule update --init --recursive
```

2. Create a build directory and run CMake:
```bash
mkdir build
cd build
cmake ..
```

3. Build the plugin:
```bash
cmake --build . --config Release
```

### Platform-Specific Notes

#### Windows
- Use Visual Studio 2017 or later
- The plugin will be built to `build/VST3/Release/MidiNoteDisplay.vst3`

#### macOS
- Use Xcode or command-line tools
- The plugin will be built to `build/VST3/Release/MidiNoteDisplay.vst3`

#### Linux
- Use GCC or Clang
- The plugin will be built to `build/VST3/Release/MidiNoteDisplay.vst3`

## Installation

Copy the built `MidiNoteDisplay.vst3` folder to your VST3 plugin directory:

- **Windows**: `C:\Program Files\Common Files\VST3\`
- **macOS**: `~/Library/Audio/Plug-Ins/VST3/` or `/Library/Audio/Plug-Ins/VST3/`
- **Linux**: `~/.vst3/` or `/usr/lib/vst3/`

## Usage

1. Load the plugin in your DAW
2. Create a MIDI track and route it through the plugin
3. Play some MIDI notes
4. Watch the console output (where you launched the DAW or VST host) to see the MIDI note information

Example output:
```
MIDI Note ON  - Note: 60, Velocity: 0.79, Channel: 0
MIDI Note OFF - Note: 60, Velocity: 0.64, Channel: 0
MIDI Note ON  - Note: 64, Velocity: 0.85, Channel: 0
MIDI Note OFF - Note: 64, Velocity: 0.50, Channel: 0
```

## License

This project uses the Steinberg VST3 SDK, which is licensed under the Steinberg VST3 License.

## References

- [VST3 SDK](https://github.com/steinbergmedia/vst3sdk)
- [VST3 Documentation](https://steinbergmedia.github.io/vst3_doc/)