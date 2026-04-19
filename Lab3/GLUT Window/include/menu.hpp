#pragma once
#include "menu_item.hpp"
#include <vector>
#include <string>

class Menu
{
private:
	std::vector<MenuItem> m_fields;
	std::string m_label;
public:

	Menu(const std::string& label);
	Menu(const std::string& label, const MenuItem& item);
	Menu(const std::string& label, const std::vector<MenuItem> items);

	void AddItem(const MenuItem& item);
	void AddItems(const std::vector<MenuItem> items);
	void Show();
};