#pragma once

#include <string>
#include <vector>

#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>

namespace ui {
	class TruncatedTextBase : public ftxui::Node {
		std::string m_text{};
		std::vector<std::string> m_glyphs{};

	public:
		TruncatedTextBase(std::string text);

		void ComputeRequirement() override;

		void Render(ftxui::Screen& screen) override;
	};

	ftxui::Element TruncatedText(std::string text);
}
