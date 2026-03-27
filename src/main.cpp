#include "ui/primitives/truncated_text.h"
#include "ui/primitives/selectable_button_row.h"

#include "core/app_state.h"

#include "ui/panels/transition_selector.h"
#include "ui/panels/eq_selector.h"
#include "ui/panels/volume_selector.h"
#include "ui/panels/effect_selector.h"
#include "ui/panels/track_info.h"

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

    Element firstSong = ui::trackInfo(
        R"(I am a very very very long line of text/song title that will take up 
many many many lines so I will not fit onto the page at all!)",
        "David",
        "175 BPM",
        "3:48"
        );

    Element secondSong = ui::trackInfo(
        "Sandra's Rose",
        "Drake",
        "130 BPM",
        "4:23"
        );

    auto layout = Renderer(allPanels, [&] {
        return vbox({
            firstSong,
            separatorEmpty(),
            transitionPanel->Render(),
            separatorEmpty(),
            eqPanel->Render(),
            separatorEmpty(),
            volumePanel->Render(),
            separatorEmpty(),
            effectPanel->Render(),
            separatorEmpty(),
            secondSong,
            }) | center;
        });

    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(layout);

    return 0;
}
