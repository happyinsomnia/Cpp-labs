#include "dialog.hpp"

Dialog::Dialog() = default;

Dialog::Dialog(const ActionItem& field)
{
	m_fields.push_back(field);
	m_isOpen = false;
}

void Dialog::AddField(const ActionItem& field) noexcept { m_fields.push_back(field); }

void Dialog::Show() const
{
}