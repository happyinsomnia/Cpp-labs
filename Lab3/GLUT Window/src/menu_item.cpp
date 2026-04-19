#include "menu_item.hpp"

MenuItem::MenuItem(const std::string& label) : m_label(label) {}

MenuItem::MenuItem(const std::string label, const Dialog& dialog) : MenuItem(label)
{
	m_dialog = dialog;
}

void MenuItem::Show()
{}