#pragma once

#include "core/app_state.h"

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>

namespace ui {
    class EffectSelector : public ftxui::ComponentBase {
        core::AppState& m_appState;
        ftxui::Component m_buttons;

    public:
        EffectSelector(core::AppState& appState);
        ftxui::Element OnRender() override;
    };

    // factory function for transition selector
    ftxui::Component effectSelector(core::AppState& state);
}
