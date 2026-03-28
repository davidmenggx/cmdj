#include "ui/panels/waveform_viewer.h"
#include "ui/colors.h"
#include "core/app_state.h"

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/canvas.hpp>
#include "ftxui/screen/terminal.hpp"

using namespace ftxui;

ui::WaveformViewer::WaveformViewer(core::AppState& app_state)
    : m_app_state{ app_state }
{
}

Element ui::WaveformViewer::DrawWaveforms(int term_width, int term_height) {
    // TODO: too many magic numbers here!!!!!!!!
    int canvas_width{ term_width * 2 };
    int canvas_height{ term_height * 4 };
    Canvas canvas_ = Canvas(canvas_width, canvas_height);

    // first track starts 1/4 the way up the canvas
    int first_track_center_y{ static_cast<int>(canvas_height / 4) };
    // second track starts 3/4 the way up the canvas
    int second_track_center_y{ static_cast<int>((canvas_height / 4) * 3) };
    int max_wave_height{ static_cast<int>((canvas_height / 4) * 0.9) };

    for (long long x{ 0ll }; x < canvas_width; ++x) {
        long long idx1{ static_cast<long long>(m_app_state.m_first_track_offset + x) };
        if (idx1 >= 0 && idx1 < m_app_state.m_first_track_waveform.size()) {
            float first_track_amp{ m_app_state.m_first_track_waveform[idx1] };
            int first_track_height = static_cast<int>(first_track_amp * max_wave_height);
            // TODO: make sure the x doesn't overflow the integer limit if the song is very long!!!
            canvas_.DrawPointLine(x, first_track_center_y - first_track_height, x, first_track_center_y + first_track_height, Color::Cyan);
        }

        long long idx2{ static_cast<long long>(m_app_state.m_second_track_offset + x) };
        if (idx2 >= 0 && idx2 < m_app_state.m_second_track_waveform.size()) {
            float second_track_amp{ m_app_state.m_second_track_waveform[idx2] };
            int second_track_height = static_cast<int>(second_track_amp * max_wave_height);
            canvas_.DrawPointLine(x, second_track_center_y - second_track_height, x, second_track_center_y + second_track_height);
        }
    }
    return canvas(std::move(canvas_));
}

Element ui::WaveformViewer::OnRender() {
    // TODO: too many magic numbers here!!!!
    auto terminal_size = Terminal::Size();
    const int term_width{ terminal_size.dimx - 4 };
    const int term_height{ static_cast<int>(terminal_size.dimy * 0.6) };

    auto foreground = DrawWaveforms(term_width, term_height);

    auto transparent_overlay = emptyElement()
        | bgcolor(ui::theme::kWaveformBackground)
        | size(WIDTH, EQUAL, static_cast<int>(term_width * 0.5))
        | size(HEIGHT, EQUAL, static_cast<int>(term_height * 1.2) );

    return dbox({
        foreground | center,
        transparent_overlay | center
        }) | flex;
}
