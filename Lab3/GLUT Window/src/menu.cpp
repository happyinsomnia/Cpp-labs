#include "menu.hpp"
#include <imgui.h>

Menu::Menu() = default;

Menu::Menu(const std::string& label) : m_label(label) {}

Menu::Menu(const std::string& label, const MenuItem& item) : Menu(label) { m_fields.push_back(item); }

Menu::Menu(const std::string& label, const std::vector<MenuItem> items) : Menu(label) { m_fields = items; }

void Menu::AddItem(const MenuItem& item) { m_fields.push_back(item); }

void Menu::AddItems(const std::vector<MenuItem> items)
{
	for (const auto& item : items)
		m_fields.push_back(item);
}

void Menu::Show()
{
	ImGui::Begin(m_label.c_str(), nullptr, ImGuiWindowFlags_MenuBar);
	if (ImGui::BeginMenuBar())
	{
		for (const auto& field : m_fields)
			field.Show();

		ImGui::EndMenuBar();
	}
	ImGui::End();
}