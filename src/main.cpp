#include "ui/primitives/truncated_text.h"
#include "ui/primitives/selectable_button_row.h"
#include "core/app_state.h"

#include "ui/panels/transition_selector.h"
#include "ui/panels/eq_selector.h"
#include "ui/panels/volume_selector.h"
#include "ui/panels/effect_selector.h"

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

    // generate toy panels for testing
    auto transitionPanel = ui::transitionSelector(appState);
    auto eqPanel = ui::eqSelector(appState);
    auto volumePanel = ui::volumeSelector(appState);
    auto effectPanel = ui::effectSelector(appState);

    // needed so that you can navigate vertically
    auto allPanels = Container::Vertical({
        transitionPanel,
        eqPanel,
        volumePanel,
        effectPanel
        });

    auto layout = Renderer(allPanels, [&] {
        return vbox({
            transitionPanel->Render(),
            separatorEmpty(),
            eqPanel->Render(),
            separatorEmpty(),
            volumePanel->Render(),
            separatorEmpty(),
            effectPanel->Render(),
            }) | center;
        });

    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(layout);

    return 0;
}
