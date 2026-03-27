#include "ui/primitives/selectable_button_row.h"

#include <vector>
#include <string>
#include <functional>

#include <ftxui/component/component.hpp>

using namespace ftxui;

// factory function to generate a dynamic row of selectable buttons
Component ui::selectableButtonRow(const std::vector<ButtonConfig>& buttonConfigs) {
    Components buttonComponents{};
    buttonComponents.reserve(std::ssize(buttonConfigs));

    for (const auto& config : buttonConfigs) {
        // call the factory function to generate a button with the appropriate callbacks and label
        buttonComponents.emplace_back(ui::selectableButton(config.label, config.isSelected, config.onClick));
    }

    return Container::Horizontal(std::move(buttonComponents));
}
