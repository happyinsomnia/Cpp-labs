#pragma once

#include <vector>
#include "action_item.hpp"

class Dialog
{
private:

	std::vector<ActionItem> m_fields;

public:
	Dialog();
	Dialog(const ActionItem& field);

	void AddField(const ActionItem& field);
	void Show() const;
};