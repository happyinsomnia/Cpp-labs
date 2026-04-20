#pragma once
#include <string>
#include <functional>
#include <vector>
class ActionItem
{
private:
	std::string m_label;
	std::function<void(const std::string&)> m_action;

	std::vector<ActionItem> m_children;

public:
	ActionItem();
	ActionItem(std::string label, std::function<void(const std::string&)> action = {});

	const std::string& GetItemName() const noexcept;
	bool HasChildren() const;
	void AddChild(const ActionItem& field);
	void AddChild(const std::string& label);
	void Show() const;
};