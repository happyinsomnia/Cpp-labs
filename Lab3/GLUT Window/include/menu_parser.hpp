#pragma once
#include<string>
#include<vector>
#include <menu.hpp>

class MenuParser
{
private:

	struct Node
	{
		std::string label;
		std::vector<Node> children;
	};
	static std::vector<Node> ParseTree(const std::vector<std::string>& data);
	static ActionItem Convert(const Node& node);

public:

	static Menu Parse(const std::vector<std::string>& data);
};