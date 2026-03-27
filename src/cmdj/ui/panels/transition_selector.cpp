#include "ui/panels/transition_selector.h"
#include "ui/primitives/selectable_button_row.h"
#include "core/button_types.h"
#include "core/app_state.h"

#include <vector>

using namespace ftxui;

ui::TransitionSelector::TransitionSelector(core::AppState& appState)
    : m_appState{ appState }
{
    std::vector<ui::ButtonConfig> buttonConfigs{ {
        {"Custom",
         [&]() { return m_appState.m_transitionState == TransitionType::kCustom; },
         // temporary, change the onClick to actually do something in the app state:
         [&]() { m_appState.m_transitionState = TransitionType::kCustom; }},
        {"Fade",
         [&]() { return m_appState.m_transitionState == TransitionType::kFade; },
         [&]() { m_appState.m_transitionState = TransitionType::kFade; }},
        {"Rise",
         [&]() { return m_appState.m_transitionState == TransitionType::kRise; },
         [&]() { m_appState.m_transitionState = TransitionType::kRise; }},
        {"Blend",
         [&]() { return m_appState.m_transitionState == TransitionType::kBlend; },
         [&]() { m_appState.m_transitionState = TransitionType::kBlend; }},
        {"Wave",
         [&]() { return m_appState.m_transitionState == TransitionType::kWave; },
         [&]() { m_appState.m_transitionState = TransitionType::kWave; }},
        {"Melt",
         [&]() { return m_appState.m_transitionState == TransitionType::kMelt; },
         [&]() { m_appState.m_transitionState = TransitionType::kMelt; }},
        {"Slam",
         [&]() { return m_appState.m_transitionState == TransitionType::kSlam; },
         [&]() { m_appState.m_transitionState = TransitionType::kSlam; }},
        {"None",
         [&]() { return m_appState.m_transitionState == TransitionType::kNone; },
         [&]() { m_appState.m_transitionState = TransitionType::kNone; }},
    } };

    m_buttons = ui::selectableButtonRow(buttonConfigs);

    // ftxui, add the row to component hierarchy/tree
    Add(m_buttons);
}

Element ui::TransitionSelector::OnRender() {
    // xframe preserves the shapes of the buttons and makes them extend offscreen as needed
    return m_buttons->Render() | xframe;
}

// factory function for transition selector
Component ui::transitionSelector(core::AppState& appState) {
    return Make<TransitionSelector>(appState);
}
