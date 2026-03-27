#include "ui/colors.h"
#include "ui/primitives/selectable_button.h"

#include <string>
#include <functional>

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>

using namespace ftxui;

// factory function to generate a selectable button for each selectable type
Component ui::selectableButton(
    const std::string& label,
    std::function<bool()> isSelectedCallback, // returns true if the button is selected
    std::function<void()> onClick
) {
     ButtonOption option;

     option.transform = [=](const EntryState& state) {
         auto element = text("  " + label + "  ") | center;

         // apply styling based on selected State
         if (isSelectedCallback()) {
             element = element | bgcolor(ui::theme::kButtonSelected) | color(ui::theme::kButtonSelectedText);
         }
         else if (state.focused) {
             element = element | bgcolor(ui::theme::kButtonFocused) | focus;
         }
         else {
             element = element | color(Color::GrayLight);
         }

         return element | size(HEIGHT, EQUAL, 3) | borderEmpty;
     };

     return Button(label, onClick, option);
}
