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
        {"Center bass",
         [&]() { return m_appState.m_eqState == EqualizerType::kCenterBass; },
         // temporary, change the onClick to actually do something in the app state:
         [&]() { m_appState.m_eqState = EqualizerType::kCenterBass; }},
        {"End bass",
         [&]() { return m_appState.m_eqState == EqualizerType::kEndBass; },
         [&]() { m_appState.m_eqState = EqualizerType::kEndBass; }},
        {"Start bass",
         [&]() { return m_appState.m_eqState == EqualizerType::kStartBass; },
         [&]() { m_appState.m_eqState = EqualizerType::kStartBass; }},
        {"Three band",
         [&]() { return m_appState.m_eqState == EqualizerType::kThreeBand; },
         [&]() { m_appState.m_eqState = EqualizerType::kThreeBand; }},
        {"Quick bass",
         [&]() { return m_appState.m_eqState == EqualizerType::kQuickBass; },
         [&]() { m_appState.m_eqState = EqualizerType::kQuickBass; }},
        {"Long bass",
         [&]() { return m_appState.m_eqState == EqualizerType::kLongBass; },
         [&]() { m_appState.m_eqState = EqualizerType::kLongBass; }},
        {"None",
         [&]() { return m_appState.m_eqState == EqualizerType::kNone; },
         [&]() { m_appState.m_eqState = EqualizerType::kNone; }},
    } };

    m_buttons = ui::selectableButtonRow(buttonConfigs);

    // ftxui, add the row to component hierarchy/tree
    Add(m_buttons);
}

Element ui::EqSelector::OnRender() {
    return m_buttons->Render();
}

// factory function for transition selector
Component ui::eqSelector(core::AppState& appState) {
    return Make<EqSelector>(appState);
}
