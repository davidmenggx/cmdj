#pragma once

#include "ftxui/screen/color.hpp"

namespace ui::theme {
	// Application text themes
	inline const ftxui::Color kTextLight{ ftxui::Color{ 250, 250, 250 } };
	inline const ftxui::Color kTextMedium{ ftxui::Color{ 125, 125, 125 } };
	inline const ftxui::Color kTextDark{ ftxui::Color{ 30, 30, 30 } };

	// Transition/Volume/EQ/Effect selector themes
	inline const ftxui::Color kButtonSelected{ ftxui::Color{ 250, 250, 250 } };
	inline const ftxui::Color kButtonFocused{ ftxui::Color{ 30, 30, 30 } };
}
