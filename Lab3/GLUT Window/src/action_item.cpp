#include "action_item.hpp"
#include <imgui.h>
ActionItem::ActionItem() = default;

ActionItem::ActionItem(std::string label, std::function<void(const std::string&)> action)
	: m_label(label), m_action(std::move(action)) {}

const std::string& ActionItem::GetItemName() const noexcept { return m_label; }

bool ActionItem::HasChildren() const
{
	return !m_children.empty();
}

void ActionItem::AddChild(const ActionItem& field)
{
	m_children.push_back(field);
}

void ActionItem::AddChild(const std::string& label)
{
	m_children.push_back(ActionItem(label));
}

void ActionItem::Show() const
{
	if (m_children.empty())
	{
		if (ImGui::MenuItem(m_label.c_str()))
		{
			if (m_action)
				m_action(m_label);
		}
	}

	else
	{
		if (ImGui::BeginMenu(m_label.c_str()))
		{
			for (const auto& child : m_children)
				child.Show();

			ImGui::EndMenu();
		}
	}
}