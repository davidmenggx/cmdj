#include "ui/panels/eq_selector.h"
#include "ui/primitives/selectable_button_row.h"
#include "core/button_types.h"
#include "core/app_state.h"

#include <vector>

using namespace ftxui;

ui::EqSelector::EqSelector(core::AppState& appState)
    : m_appState{ appState }
{
    std::vector<ui::ButtonConfig> buttonConfigs{ {
        {"Center bass swap",
         [&]() { return m_appState.m_eqState == EqualizerType::kCenterBassSwap; },
         // temporary, change the onClick to actually do something in the app state:
         [&]() { m_appState.m_eqState = EqualizerType::kCenterBassSwap; }},
        {"End bass swap",
         [&]() { return m_appState.m_eqState == EqualizerType::kEndBassSwap; },
         [&]() { m_appState.m_eqState = EqualizerType::kEndBassSwap; }},
        {"Start bass swap",
         [&]() { return m_appState.m_eqState == EqualizerType::kStartBassSwap; },
         [&]() { m_appState.m_eqState = EqualizerType::kStartBassSwap; }},
        {"Three band fade",
         [&]() { return m_appState.m_eqState == EqualizerType::kThreeBandFade; },
         [&]() { m_appState.m_eqState = EqualizerType::kThreeBandFade; }},
        {"Quick bass cut",
         [&]() { return m_appState.m_eqState == EqualizerType::kQuickBassCut; },
         [&]() { m_appState.m_eqState = EqualizerType::kQuickBassCut; }},
        {"Long bass cut",
         [&]() { return m_appState.m_eqState == EqualizerType::kLongBassCut; },
         [&]() { m_appState.m_eqState = EqualizerType::kLongBassCut; }},
        {"None",
         [&]() { return m_appState.m_eqState == EqualizerType::kNone; },
         [&]() { m_appState.m_eqState = EqualizerType::kNone; }},
    } };

    m_buttons = ui::selectableButtonRow(buttonConfigs);

    // ftxui, add the row to component hierarchy/tree
    Add(m_buttons);
}

Element ui::EqSelector::OnRender() {
    // xframe preserves the shapes of the buttons and makes them extend offscreen as needed
    return m_buttons->Render() | xframe;
}

// factory function for transition selector
Component ui::eqSelector(core::AppState& appState) {
    return Make<EqSelector>(appState);
}
