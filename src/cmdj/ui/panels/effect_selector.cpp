#include "ui/panels/effect_selector.h"
#include "ui/primitives/selectable_button_row.h"
#include "core/button_types.h"
#include "core/app_state.h"

#include <vector>

using namespace ftxui;

ui::EffectSelector::EffectSelector(core::AppState& appState)
    : m_appState{ appState }
{
    std::vector<ui::ButtonConfig> buttonConfigs{ {
        {"Low pass filter out",
         [&]() { return m_appState.m_effectState == EffectType::kLowPassFilterOut; },
         // temporary, change the onClick to actually do something in the app state:
         [&]() { m_appState.m_effectState = EffectType::kLowPassFilterOut; }},
        {"Low pass filter in",
         [&]() { return m_appState.m_effectState == EffectType::kLowPassFilterIn; },
         [&]() { m_appState.m_effectState = EffectType::kLowPassFilterIn; }},
        {"Low pass filter in low pass filter out",
         [&]() { return m_appState.m_effectState == EffectType::kLowPassFilterInLowPassFilterOut; },
         [&]() { m_appState.m_effectState = EffectType::kLowPassFilterInLowPassFilterOut; }},
        {"Low pass filter in high pass filter out",
         [&]() { return m_appState.m_effectState == EffectType::kLowPassFilterInHighPassFilterOut; },
         [&]() { m_appState.m_effectState = EffectType::kLowPassFilterInHighPassFilterOut; }},
        {"High pass filter out",
         [&]() { return m_appState.m_effectState == EffectType::kHighPassFilterOut; },
         [&]() { m_appState.m_effectState = EffectType::kHighPassFilterOut; }},
        {"High pass filter in",
         [&]() { return m_appState.m_effectState == EffectType::kHighPassFilterIn; },
         [&]() { m_appState.m_effectState = EffectType::kHighPassFilterIn; }},
        {"High pass filter in low pass filter out",
         [&]() { return m_appState.m_effectState == EffectType::kHighPassFilterInLowPassFilterOut; },
         [&]() { m_appState.m_effectState = EffectType::kHighPassFilterInLowPassFilterOut; }},
        {"High pass filter in high pass filter out",
         [&]() { return m_appState.m_effectState == EffectType::kHighPassFilterInHighPassFilterOut; },
         [&]() { m_appState.m_effectState = EffectType::kHighPassFilterInHighPassFilterOut; }},
        {"None",
         [&]() { return m_appState.m_effectState == EffectType::kNone; },
         [&]() { m_appState.m_effectState = EffectType::kNone; }},
    } };

    m_buttons = ui::selectableButtonRow(buttonConfigs);

    // ftxui, add the row to component hierarchy/tree
    Add(m_buttons);
}

Element ui::EffectSelector::OnRender() {
    // xframe preserves the shapes of the buttons and makes them extend offscreen as needed
    return m_buttons->Render() | xframe;
}

// factory function for transition selector
Component ui::effectSelector(core::AppState& appState) {
    return Make<EffectSelector>(appState);
}
