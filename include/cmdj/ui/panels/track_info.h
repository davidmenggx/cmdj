#include <string>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/color.hpp>

namespace ui {
    ftxui::Element TrackInfo(
        const std::string& title,
        const std::string& artists,
        const std::string& bpm,
        const std::string& duration
    );
}
