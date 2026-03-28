#include "ui/colors.h"
#include "ui/primitives/selectable_button.h"

#include <string>
#include <functional>

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>

using namespace ftxui;

// factory function to generate a selectable button for each selectable type
Component ui::SelectableButton(
    const std::string& label,
    std::function<bool()> is_selected_callback, // returns true if the button is selected
    std::function<void()> on_click
) {
     ButtonOption option;

     option.transform = [=](const EntryState& state) {
         auto element = text("  " + label + "  ") | center;

         // apply styling based on selected State
         if (is_selected_callback()) {
             element = element | bgcolor(ui::theme::kButtonSelected) | color(ui::theme::kTextDark);
         }
         else if (state.focused) {
             element = element | bgcolor(ui::theme::kButtonFocused) | focus;
         }
         else {
             element = element | color(ui::theme::kTextLight);
         }

         return element | size(HEIGHT, EQUAL, 3) | borderEmpty;
     };

     return Button(label, on_click, option);
}
