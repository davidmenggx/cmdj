#include "ui/primitives/truncated_text.h"

#include <string>

#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>

using namespace ftxui;

int main() {
    std::string my_text{ "I am a very long text 😂😂 that may overflow!!!" };

    auto document = vbox({
        text("50 char container:"),
        ui::truncatedText(my_text) | border | size(WIDTH, EQUAL, 50),

        text("27 char container:"),
        ui::truncatedText(my_text) | border | size(WIDTH, EQUAL, 27),

        text("40 char container:"),
        ui::truncatedText(my_text) | border | size(WIDTH, EQUAL, 40),

        text("4 char container:"),
        ui::truncatedText(my_text) | border | size(WIDTH, EQUAL, 4),

        text("3 char container:"),
        ui::truncatedText(my_text) | border | size(WIDTH, EQUAL, 3),
        });

    auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
    Render(screen, document);
    screen.Print();

    return 0;
}
