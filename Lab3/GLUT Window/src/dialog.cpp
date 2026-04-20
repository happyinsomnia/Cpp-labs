#include "dialog.hpp"

Dialog::Dialog() : m_fields() {}

Dialog::Dialog(const ActionItem& field)
{
	m_fields.push_back(field);
}

void Dialog::AddField(const ActionItem& field) { m_fields.push_back(field); }

bool Dialog::IsEmpty() const
{
	return m_fields.empty();
}

void Dialog::Show() const
{
	for (const auto& field : m_fields)
		field.Show();
}