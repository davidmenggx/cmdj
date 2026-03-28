#include "ui/primitives/selectable_button.h"

#include <vector>
#include <string>
#include <functional>

#include <ftxui/component/component.hpp>

namespace ui {
	// simple wrapper to hold button data, match ui::selectableButton
	struct ButtonConfig {
		std::string label{};
		std::function<bool()> is_selected_callback{};
		std::function<void()> on_click{};
	};

	// factory function to generate a dynamic row of selectable buttons
	ftxui::Component SelectableButtonRow(const std::vector<ButtonConfig>& button_configs);
}
