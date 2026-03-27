#include "ui/panels/waveform_viewer.h"
#include "ui/colors.h"
#include "core/app_state.h"

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>

using namespace ftxui;

ui::WaveformViewer::WaveformViewer(core::AppState& appState)
    : m_appState{ appState }
{
}

Element ui::WaveformViewer::OnRender() {
    auto background = emptyElement()
        | bgcolor(ui::theme::kWaveformBackground)
        | size(WIDTH, EQUAL, 60)
        | size(HEIGHT, EQUAL, 40);

    auto foreground = vbox({
        text("Imagine I am a very very very long waveform. Imagine I am a very very very long waveform. Imagine I am a very very very long waveform.") | bold | center,
        });

    return dbox({
        background | center,
        foreground | center
        }) | flex;
}
