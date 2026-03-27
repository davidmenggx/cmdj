#include "ui/panels/volume_selector.h"
#include "ui/primitives/selectable_button_row.h"
#include "core/button_types.h"
#include "core/app_state.h"

#include <vector>

using namespace ftxui;

ui::VolumeSelector::VolumeSelector(core::AppState& appState)
    : m_appState{ appState }
{
    std::vector<ui::ButtonConfig> buttonConfigs{ {
        {"Smooth crossfade",
         [&]() { return m_appState.m_volumeState == VolumeType::kSmoothCrossfade; },
         // temporary, change the onClick to actually do something in the app state:
         [&]() { m_appState.m_volumeState = VolumeType::kSmoothCrossfade; }},
        {"Overlap",
         [&]() { return m_appState.m_volumeState == VolumeType::kOverlap; },
         [&]() { m_appState.m_volumeState = VolumeType::kOverlap; }},
        {"Fade in fade out",
         [&]() { return m_appState.m_volumeState == VolumeType::kFadeInFadeOut; },
         [&]() { m_appState.m_volumeState = VolumeType::kFadeInFadeOut; }},
        {"Cut in fade out",
         [&]() { return m_appState.m_volumeState == VolumeType::kCutInFadeOut; },
         [&]() { m_appState.m_volumeState = VolumeType::kCutInFadeOut; }},
        {"Fade in cut out",
         [&]() { return m_appState.m_volumeState == VolumeType::kFadeInCutOut; },
         [&]() { m_appState.m_volumeState = VolumeType::kFadeInCutOut; }},
        {"Center cut",
         [&]() { return m_appState.m_volumeState == VolumeType::kCenterCut; },
         [&]() { m_appState.m_volumeState = VolumeType::kCenterCut; }},
        {"Crossfade",
         [&]() { return m_appState.m_volumeState == VolumeType::kCrossfade; },
         [&]() { m_appState.m_volumeState = VolumeType::kCrossfade; }},
        {"Fade in fast out",
         [&]() { return m_appState.m_volumeState == VolumeType::kFadeInFastOut; },
         [&]() { m_appState.m_volumeState = VolumeType::kFadeInFastOut; }},
    } };

    m_buttons = ui::selectableButtonRow(buttonConfigs);

    // ftxui, add the row to component hierarchy/tree
    Add(m_buttons);
}

Element ui::VolumeSelector::OnRender() {
    // xframe preserves the shapes of the buttons and makes them extend offscreen as needed
    return m_buttons->Render() | xframe;
}

// factory function for transition selector
Component ui::volumeSelector(core::AppState& appState) {
    return Make<VolumeSelector>(appState);
}
