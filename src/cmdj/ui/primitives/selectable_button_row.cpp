#include "ui/primitives/selectable_button_row.h"

#include <vector>
#include <string>
#include <functional>

#include <ftxui/component/component.hpp>

using namespace ftxui;

// factory function to generate a dynamic row of selectable buttons
Component ui::SelectableButtonRow(const std::vector<ButtonConfig>& button_configs) {
    Components button_components{};
    button_components.reserve(std::ssize(button_configs));

    for (const auto& config : button_configs) {
        // call the factory function to generate a button with the appropriate callbacks and label
        button_components.emplace_back(ui::SelectableButton(config.label, config.is_selected_callback, config.on_click));
    }

    return Container::Horizontal(std::move(button_components));
}
