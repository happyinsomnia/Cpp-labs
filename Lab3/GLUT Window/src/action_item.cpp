#include "action_item.hpp"

ActionItem::ActionItem() = default;

ActionItem::ActionItem(std::string label) : m_label(label)
{
	m_action = {};
}

ActionItem::ActionItem(std::string label, std::function<void()> action) : ActionItem(label)
{
	m_action = action;
}

const std::string& ActionItem::GetItemName() const noexcept { return m_label; }

void ActionItem::Show() const
{}