#include "ui/panels/eq_selector.h"
#include "ui/primitives/selectable_button_row.h"
#include "core/button_types.h"
#include "core/app_state.h"

#include <vector>

using namespace ftxui;

ui::EqSelectorBase::EqSelectorBase(core::AppState& app_state)
    : m_app_state{ app_state }
{
    std::vector<ui::ButtonConfig> button_configs{ {
        {"Center bass swap",
         [&]() { return m_app_state.m_eq_state == EqualizerType::kCenterBassSwap; },
         // temporary, change the onClick to actually do something in the app state:
         [&]() { m_app_state.m_eq_state = EqualizerType::kCenterBassSwap; }},
        {"End bass swap",
         [&]() { return m_app_state.m_eq_state == EqualizerType::kEndBassSwap; },
         [&]() { m_app_state.m_eq_state = EqualizerType::kEndBassSwap; }},
        {"Start bass swap",
         [&]() { return m_app_state.m_eq_state == EqualizerType::kStartBassSwap; },
         [&]() { m_app_state.m_eq_state = EqualizerType::kStartBassSwap; }},
        {"Three band fade",
         [&]() { return m_app_state.m_eq_state == EqualizerType::kThreeBandFade; },
         [&]() { m_app_state.m_eq_state = EqualizerType::kThreeBandFade; }},
        {"Quick bass cut",
         [&]() { return m_app_state.m_eq_state == EqualizerType::kQuickBassCut; },
         [&]() { m_app_state.m_eq_state = EqualizerType::kQuickBassCut; }},
        {"Long bass cut",
         [&]() { return m_app_state.m_eq_state == EqualizerType::kLongBassCut; },
         [&]() { m_app_state.m_eq_state = EqualizerType::kLongBassCut; }},
        {"None",
         [&]() { return m_app_state.m_eq_state == EqualizerType::kNone; },
         [&]() { m_app_state.m_eq_state = EqualizerType::kNone; }},
    } };

    m_buttons = ui::SelectableButtonRow(button_configs);

    // ftxui, add the row to component hierarchy/tree
    Add(m_buttons);
}

Element ui::EqSelectorBase::OnRender() {
    // xframe preserves the shapes of the buttons and makes them extend offscreen as needed
    return m_buttons->Render() | xframe;
}

// factory function for transition selector
Component ui::EqSelector(core::AppState& app_state) {
    return Make<EqSelectorBase>(app_state);
}
