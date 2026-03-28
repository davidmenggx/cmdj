#include "ui/panels/transition_preset_selector.h"
#include "ui/primitives/selectable_button_row.h"
#include "core/button_types.h"
#include "core/app_state.h"

#include <vector>

using namespace ftxui;

ui::TransitionPresetSelectorBase::TransitionPresetSelectorBase(core::AppState& app_state)
    : m_app_state{ app_state }
{
    std::vector<ui::ButtonConfig> button_configs{ {
        {"Custom",
         [&]() { return m_app_state.m_transition_state == TransitionType::kCustom; },
         // temporary, change the onClick to actually do something in the app state:
         [&]() { m_app_state.m_transition_state = TransitionType::kCustom; }},
        {"Fade",
         [&]() { return m_app_state.m_transition_state == TransitionType::kFade; },
         [&]() { m_app_state.m_transition_state = TransitionType::kFade; }},
        {"Rise",
         [&]() { return m_app_state.m_transition_state == TransitionType::kRise; },
         [&]() { m_app_state.m_transition_state = TransitionType::kRise; }},
        {"Blend",
         [&]() { return m_app_state.m_transition_state == TransitionType::kBlend; },
         [&]() { m_app_state.m_transition_state = TransitionType::kBlend; }},
        {"Wave",
         [&]() { return m_app_state.m_transition_state == TransitionType::kWave; },
         [&]() { m_app_state.m_transition_state = TransitionType::kWave; }},
        {"Melt",
         [&]() { return m_app_state.m_transition_state == TransitionType::kMelt; },
         [&]() { m_app_state.m_transition_state = TransitionType::kMelt; }},
        {"Slam",
         [&]() { return m_app_state.m_transition_state == TransitionType::kSlam; },
         [&]() { m_app_state.m_transition_state = TransitionType::kSlam; }},
        {"None",
         [&]() { return m_app_state.m_transition_state == TransitionType::kNone; },
         [&]() { m_app_state.m_transition_state = TransitionType::kNone; }},
    } };

    m_buttons = ui::SelectableButtonRow(button_configs);

    // ftxui, add the row to component hierarchy/tree
    Add(m_buttons);
}

Element ui::TransitionPresetSelectorBase::OnRender() {
    // xframe preserves the shapes of the buttons and makes them extend offscreen as needed
    return m_buttons->Render() | xframe;
}

// factory function for transition selector
Component ui::TransitionPresetSelector(core::AppState& app_state) {
    return Make<TransitionPresetSelectorBase>(app_state);
}
