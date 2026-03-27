#pragma once

#include "core/app_state.h"

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>

namespace ui {
	class WaveformViewer : public ftxui::ComponentBase {
		core::AppState& m_appState;
		
	public:
		WaveformViewer(core::AppState& appState);
		ftxui::Element OnRender() override;
		// do i want an OnEvent here?
	};
}
