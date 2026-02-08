cmake_minimum_required(VERSION 3.14.0)

project(MidiNoteDisplay VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)

# Disable VSTGUI and examples since we don't need them for this simple plugin
set(SMTG_ENABLE_VSTGUI_SUPPORT OFF CACHE BOOL "Disable VSTGUI Support" FORCE)
set(SMTG_ENABLE_VST3_PLUGIN_EXAMPLES OFF CACHE BOOL "Disable VST3 Plugin Examples" FORCE)
set(SMTG_ENABLE_VST3_HOSTING_EXAMPLES OFF CACHE BOOL "Disable VST3 Hosting Examples" FORCE)

# Add the VST3 SDK
add_subdirectory(vst3sdk)
smtg_enable_vst3_sdk()

# Define the target
set(target MidiNoteDisplay)

# Create the VST3 plugin
smtg_add_vst3plugin(${target}
    source/midinotedisplay_processor.h
    source/midinotedisplay_processor.cpp
    source/midinotedisplay_controller.h
    source/midinotedisplay_controller.cpp
    source/midinotedisplay_cids.h
    source/midinotedisplay_version.h
    source/midinotedisplay_entry.cpp
)

# Set the plugin properties
smtg_target_set_bundle(${target}
    BUNDLE_IDENTIFIER com.steinberg.vst3.midinotedisplay
    COMPANY_NAME "Steinberg"
)

# Add include directories
target_include_directories(${target} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link against SDK libraries
target_link_libraries(${target}
    PRIVATE
        sdk
)

if(SMTG_MAC)
    smtg_target_codesign(${target}
        IDENTITY "-"
    )
endif(SMTG_MAC)
