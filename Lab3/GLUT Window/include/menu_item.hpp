#pragma once

#include <string>
#include "dialog.hpp"

class MenuItem
{
private:
	Dialog m_dialog;
	std::string m_label;
public:
	MenuItem(const std::string& label);
	MenuItem(const std::string label, const Dialog& dialog);

	
	void Show() const;
};