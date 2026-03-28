#include "ui/panels/effect_selector.h"
#include "ui/primitives/selectable_button_row.h"
#include "core/button_types.h"
#include "core/app_state.h"

#include <vector>

using namespace ftxui;

ui::EffectSelectorBase::EffectSelectorBase(core::AppState& app_state)
    : m_app_state{ app_state }
{
    std::vector<ui::ButtonConfig> button_configs{ {
        {"Low pass filter out",
         [&]() { return m_app_state.m_effect_state == EffectType::kLowPassFilterOut; },
         // temporary, change the onClick to actually do something in the app state:
         [&]() { m_app_state.m_effect_state = EffectType::kLowPassFilterOut; }},
        {"Low pass filter in",
         [&]() { return m_app_state.m_effect_state == EffectType::kLowPassFilterIn; },
         [&]() { m_app_state.m_effect_state = EffectType::kLowPassFilterIn; }},
        {"Low pass filter in low pass filter out",
         [&]() { return m_app_state.m_effect_state == EffectType::kLowPassFilterInLowPassFilterOut; },
         [&]() { m_app_state.m_effect_state = EffectType::kLowPassFilterInLowPassFilterOut; }},
        {"Low pass filter in high pass filter out",
         [&]() { return m_app_state.m_effect_state == EffectType::kLowPassFilterInHighPassFilterOut; },
         [&]() { m_app_state.m_effect_state = EffectType::kLowPassFilterInHighPassFilterOut; }},
        {"High pass filter out",
         [&]() { return m_app_state.m_effect_state == EffectType::kHighPassFilterOut; },
         [&]() { m_app_state.m_effect_state = EffectType::kHighPassFilterOut; }},
        {"High pass filter in",
         [&]() { return m_app_state.m_effect_state == EffectType::kHighPassFilterIn; },
         [&]() { m_app_state.m_effect_state = EffectType::kHighPassFilterIn; }},
        {"High pass filter in low pass filter out",
         [&]() { return m_app_state.m_effect_state == EffectType::kHighPassFilterInLowPassFilterOut; },
         [&]() { m_app_state.m_effect_state = EffectType::kHighPassFilterInLowPassFilterOut; }},
        {"High pass filter in high pass filter out",
         [&]() { return m_app_state.m_effect_state == EffectType::kHighPassFilterInHighPassFilterOut; },
         [&]() { m_app_state.m_effect_state = EffectType::kHighPassFilterInHighPassFilterOut; }},
        {"None",
         [&]() { return m_app_state.m_effect_state == EffectType::kNone; },
         [&]() { m_app_state.m_effect_state = EffectType::kNone; }},
    } };

    m_buttons = ui::SelectableButtonRow(button_configs);

    // ftxui, add the row to component hierarchy/tree
    Add(m_buttons);
}

Element ui::EffectSelectorBase::OnRender() {
    // xframe preserves the shapes of the buttons and makes them extend offscreen as needed
    return m_buttons->Render() | xframe;
}

// factory function for transition selector
Component ui::EffectSelector(core::AppState& app_state) {
    return Make<EffectSelectorBase>(app_state);
}
