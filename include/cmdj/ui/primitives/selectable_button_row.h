#include "ui/primitives/selectable_button.h"

#include <vector>
#include <string>
#include <functional>

#include <ftxui/component/component.hpp>

namespace ui {
	// simple wrapper to hold button data, match ui::selectableButton
	struct ButtonConfig {
		std::string label{};
		std::function<bool()> isSelected{};
		std::function<void()> onClick{};
	};

	// factory function to generate a dynamic row of selectable buttons
	ftxui::Component selectableButtonRow(const std::vector<ButtonConfig>& buttonConfigs);
}
