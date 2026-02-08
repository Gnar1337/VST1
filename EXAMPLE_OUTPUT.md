# MIDI Note Display VST3 - Example Output

## Expected Output

When you load this plugin in your DAW and play MIDI notes through it, you should see output in the console like this:

```
MIDI Note ON  - Note: 60, Velocity: 0.79, Channel: 0
MIDI Note OFF - Note: 60, Velocity: 0.64, Channel: 0
MIDI Note ON  - Note: 64, Velocity: 0.85, Channel: 0
MIDI Note OFF - Note: 64, Velocity: 0.50, Channel: 0
MIDI Note ON  - Note: 67, Velocity: 0.72, Channel: 0
MIDI Note OFF - Note: 67, Velocity: 0.45, Channel: 0
```

## Understanding the Output

- **Note**: The MIDI note number (0-127)
  - Middle C (C4) = 60
  - Each semitone up = +1
  - Each semitone down = -1
  
- **Velocity**: The velocity of the note (0.0 - 1.0)
  - 0.0 = softest
  - 1.0 = loudest
  - For Note OFF events, this is the release velocity

- **Channel**: The MIDI channel (0-15)
  - 0 = MIDI Channel 1
  - 1 = MIDI Channel 2
  - etc.

## Testing the Plugin

### With Reaper
1. Launch Reaper from the command line: `reaper` (to see console output)
2. Create a new MIDI track
3. Insert the MidiNoteDisplay plugin as an FX
4. Create or play MIDI notes
5. Watch the console output

### With Ardour
1. Launch Ardour from the command line: `ardour6` (to see console output)
2. Create a new MIDI track
3. Add the MidiNoteDisplay plugin to the track
4. Record or play back MIDI
5. Watch the console output

### With JUCE AudioPluginHost
1. Download and build the AudioPluginHost from JUCE
2. Launch it from command line
3. Add the plugin
4. Connect a MIDI input
5. Play notes and watch console output

## Common MIDI Note Numbers

| Note | MIDI Number |
|------|-------------|
| C3   | 48          |
| C4 (Middle C) | 60 |
| C5   | 72          |
| A4 (440Hz) | 69 |
| C6   | 84          |

## Troubleshooting

If you don't see any output:
1. Make sure you launched the DAW from a terminal/command line
2. Verify the plugin is actually processing MIDI (check DAW's plugin chain)
3. Ensure MIDI is being sent to the track with the plugin
4. Check that the plugin is properly inserted on the track (not just previewed)
