#pragma once

#include <vector>
#include "action_item.hpp"

class Dialog
{
private:

	std::vector<ActionItem> m_fields;
	bool m_isOpen;

public:
	Dialog();
	Dialog(const ActionItem& field);

	void AddField(const ActionItem& field) noexcept;
	void Show() const;
};