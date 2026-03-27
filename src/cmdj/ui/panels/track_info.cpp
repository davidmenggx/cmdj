#include "ui/colors.h"
#include "ui/panels/track_info.h"
#include "ui/primitives/truncated_text.h"

#include <string>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/color.hpp>

using namespace ftxui;

Element ui::trackInfo(
    const std::string& title,
    const std::string& artists,
    const std::string& bpm,
    const std::string& duration
) {
    // target layout:
    // My song title            135 BPM
    // The artist names            4:52
    // ^^leftColumn       rightColumn^^

    auto leftColumn = vbox({
        truncatedText(title),
        truncatedText(artists) | color(ui::theme::kTextMedium)
        });

    auto rightColumn = vbox({
        hbox({filler(), text(bpm)}),
        hbox({filler(), text(duration) | color(ui::theme::kTextMedium)})
        });

    return hbox({
        leftColumn | flex,
        separatorEmpty(),
        separatorEmpty(),
        rightColumn
        });
}
