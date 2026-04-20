#include "action_item.hpp"
#include <imgui.h>
ActionItem::ActionItem() = default;

ActionItem::ActionItem(std::string label, std::function<void(const std::string&)> action)
	: m_label(label), m_action(std::move(action)) {
}

const std::string& ActionItem::GetItemName() const noexcept { return m_label; }

void ActionItem::Show() const
{
	if (!m_action)
	{
		if (!m_label.empty())
			ImGui::MenuItem(m_label.c_str());

		return;
	}

	m_action(m_label);
}