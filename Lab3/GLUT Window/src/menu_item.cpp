#include "menu_item.hpp"
#include <imgui.h>
MenuItem::MenuItem(const std::string& label) : m_label(label) {}

MenuItem::MenuItem(const std::string label, const Dialog& dialog) : MenuItem(label)
{
	m_dialog = dialog;
}

void MenuItem::Show() const
{
	if (m_dialog.IsEmpty())
	{
		ImGui::MenuItem(m_label.c_str());
		return;
	}

	if (ImGui::BeginMenu(m_label.c_str()))
	{
		m_dialog.Show();
		ImGui::EndMenu();
	}
}