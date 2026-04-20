#include "dialog.hpp"

Dialog::Dialog() : m_fields() {}

Dialog::Dialog(const ActionItem& field)
{
	m_fields.push_back(field);
}

void Dialog::AddField(const ActionItem& field) { m_fields.push_back(field); }

void Dialog::Show() const
{
	for (const auto& field : m_fields)
		field.Show();
}