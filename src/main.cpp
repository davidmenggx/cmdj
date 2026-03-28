#include "ui/primitives/truncated_text.h"
#include "ui/primitives/selectable_button_row.h"

#include "core/app_state.h"

#include "ui/panels/transition_preset_selector.h"
#include "ui/panels/eq_selector.h"
#include "ui/panels/volume_selector.h"
#include "ui/panels/effect_selector.h"
#include "ui/panels/track_info.h"
#include "ui/panels/waveform_viewer.h"

#include <string>
#include <memory>

#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;

int main() {
    core::AppState app_state{};

    Element first_song = ui::TrackInfo(
        R"(I am a very very very long line of text/song title that will take up 
many many many lines so I will not fit onto the page at all!)",
        "David",
        "175 BPM",
        "3:48"
        );

    Element second_song = ui::TrackInfo(
        "Sandra's Rose",
        "Drake",
        "130 BPM",
        "4:23"
        );

    auto preset_panel = ui::TransitionPresetSelector(app_state);
    auto wv = std::make_shared<ui::WaveformViewer>(app_state);

    auto all_panels = Container::Vertical({
        wv,
        preset_panel
        });

    auto layout = Renderer(all_panels, [&] {
        return vbox({
            first_song,
            separatorEmpty(),
            wv->OnRender(),
            separatorEmpty(),
            second_song,
            separatorEmpty(),
            preset_panel->Render() | center,    
            }) | center;
        });

    auto screen = ScreenInteractive::Fullscreen();
    screen.Loop(layout);

    return 0;
}
