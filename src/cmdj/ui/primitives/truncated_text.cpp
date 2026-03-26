#include "ui/primitives/truncated_text.h"

#include <algorithm>
#include <memory>

#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>

using namespace ftxui;

namespace ui {
	TruncatedText::TruncatedText(std::string text)
		: m_text{ std::move(text) }
	{
		m_glyphs = Utf8ToGlyphs(m_text);
	}

	void TruncatedText::ComputeRequirement() {
		// at least 3 characters are needed for the "..."
		requirement_.min_x = std::min(static_cast<int>(std::ssize(m_glyphs)), 3);
		requirement_.min_y = 1;
		requirement_.flex_shrink_x = 1;
		requirement_.flex_grow_x = 0;
	}

	void TruncatedText::Render(Screen& screen) {
		int availableTextWidth{ box_.x_max - box_.x_min + 1 };
		// do not even try to render the text if no room given
		if (availableTextWidth <= 0)
			return;

		Element child{};
		if (static_cast<int>(std::ssize(m_glyphs)) <= availableTextWidth) {
			// enough room for all of the text
			child = text(m_text);
		} 
		// only enough room to draw the ellipses
		else if (availableTextWidth <= 3) {
			child = text(std::string(availableTextWidth, '.'));
		} 
		// we can only fit part of the text in, have to truncate rest
		else {
			// leave 3 characters room for "..."
			int targetTextWidth{ availableTextWidth - 3 };
			std::string truncatedText{};

			for (int i{ 0 }; i < targetTextWidth; ++i) {
				if (m_glyphs[i].empty())
					continue;
				// edge case when we have just one character left before truncating
				// and said character is too wide. fill with placeholder space character
				if (i == targetTextWidth - 1 
					&& i + 1 < static_cast<int>(std::ssize(m_glyphs))
					&& m_glyphs[i + 1].empty())
					truncatedText += " ";
				else
					truncatedText += m_glyphs[i];
			}
			truncatedText += "...";
			child = text(truncatedText);
		}
		child->ComputeRequirement();
		child->SetBox(box_);
		child->Render(screen);
	}

	// almost identical implementation to ftxui::text(std::string_view text)
	Element truncatedText(std::string text) {
		return std::make_shared<TruncatedText>(std::move(text));
	}
}
