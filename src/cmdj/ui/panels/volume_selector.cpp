#include "ui/panels/volume_selector.h"
#include "ui/primitives/selectable_button_row.h"
#include "core/button_types.h"
#include "core/app_state.h"

#include <vector>

using namespace ftxui;

ui::VolumeSelectorBase::VolumeSelectorBase(core::AppState& app_state)
    : m_app_state{ app_state }
{
    std::vector<ui::ButtonConfig> button_configs{ {
        {"Smooth crossfade",
         [&]() { return m_app_state.m_volume_state == VolumeType::kSmoothCrossfade; },
         // temporary, change the onClick to actually do something in the app state:
         [&]() { m_app_state.m_volume_state = VolumeType::kSmoothCrossfade; }},
        {"Overlap",
         [&]() { return m_app_state.m_volume_state == VolumeType::kOverlap; },
         [&]() { m_app_state.m_volume_state = VolumeType::kOverlap; }},
        {"Fade in fade out",
         [&]() { return m_app_state.m_volume_state == VolumeType::kFadeInFadeOut; },
         [&]() { m_app_state.m_volume_state = VolumeType::kFadeInFadeOut; }},
        {"Cut in fade out",
         [&]() { return m_app_state.m_volume_state == VolumeType::kCutInFadeOut; },
         [&]() { m_app_state.m_volume_state = VolumeType::kCutInFadeOut; }},
        {"Fade in cut out",
         [&]() { return m_app_state.m_volume_state == VolumeType::kFadeInCutOut; },
         [&]() { m_app_state.m_volume_state = VolumeType::kFadeInCutOut; }},
        {"Center cut",
         [&]() { return m_app_state.m_volume_state == VolumeType::kCenterCut; },
         [&]() { m_app_state.m_volume_state = VolumeType::kCenterCut; }},
        {"Crossfade",
         [&]() { return m_app_state.m_volume_state == VolumeType::kCrossfade; },
         [&]() { m_app_state.m_volume_state = VolumeType::kCrossfade; }},
        {"Fade in fast out",
         [&]() { return m_app_state.m_volume_state == VolumeType::kFadeInFastOut; },
         [&]() { m_app_state.m_volume_state = VolumeType::kFadeInFastOut; }},
    } };

    m_buttons = ui::SelectableButtonRow(button_configs);

    // ftxui, add the row to component hierarchy/tree
    Add(m_buttons);
}

Element ui::VolumeSelectorBase::OnRender() {
    // xframe preserves the shapes of the buttons and makes them extend offscreen as needed
    return m_buttons->Render() | xframe;
}

// factory function for transition selector
Component ui::VolumeSelector(core::AppState& app_state) {
    return Make<VolumeSelectorBase>(app_state);
}
