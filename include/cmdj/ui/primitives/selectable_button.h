#pragma once

#include <string>
#include <functional>

#include <ftxui/component/component.hpp>

namespace ui {
    // factory function to generate a selectable button for each selectable type
    ftxui::Component selectableButton(
        const std::string& label,
        std::function<bool()> isSelectedCallback, // returns true if the button is selected
        std::function<void()> onClick
    );
}
