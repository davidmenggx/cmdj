#include "ui/primitives/truncated_text.h"
#include "ui/primitives/selectable_button_row.h"
#include "core/app_state.h"
#include "ui/panels/transition_selector.h"

#include <string>

#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;

int main() {
    core::AppState appState{};
    // generate toy transition panel for testing
    auto transitionPanel = ui::transitionSelector(appState);

    auto layout = Renderer(transitionPanel, [&] {
        return vbox({
            transitionPanel->Render(),
            }) | center;
        });

    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(layout);

    return 0;
}
