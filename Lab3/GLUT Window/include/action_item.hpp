#pragma once
#include <string>
#include <functional>

class ActionItem
{
private:
	std::string m_label;
	std::function<void(const std::string&)> m_action;

public:
	ActionItem();
	ActionItem(std::string label, std::function<void(const std::string&)> action = {});

	const std::string& GetItemName() const noexcept;
	void Show() const;
};