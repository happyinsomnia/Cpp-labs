#pragma once
#include<string>
#include<vector>
#include <menu.hpp>

class MenuParser
{
public:

	static Menu Parse(const std::vector<std::string>& data);
};