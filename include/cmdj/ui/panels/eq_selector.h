#pragma once

#include "core/app_state.h"

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>

namespace ui {
    class EqSelectorBase : public ftxui::ComponentBase {
        core::AppState& m_app_state;
        ftxui::Component m_buttons;

    public:
        EqSelectorBase(core::AppState& app_state);
        ftxui::Element OnRender() override;
    };

    // factory function for transition selector
    ftxui::Component EqSelector(core::AppState& app_state);
}
