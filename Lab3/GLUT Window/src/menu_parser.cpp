#include <menu_parser.hpp>
#include <menu_item.hpp>
#include <dialog.hpp>
#include <vector>
#include <string>

std::vector<MenuParser::Node> MenuParser::ParseTree(const std::vector<std::string>& data)
{
	std::vector<Node> roots;
	std::vector<Node*> stack;

	for (const auto& lineRaw : data)
	{
		size_t indent = 0;
		while (indent < lineRaw.size() && lineRaw[indent] == ' ')
			++indent;

		size_t level = indent / 2;
		std::string label = lineRaw.substr(indent);

		Node node(label);

		if (level == 0)
		{
			roots.push_back(node);
			stack.clear();
			stack.push_back(&roots.back());
		}
		else
		{
			stack.resize(level);

			Node* parent = stack.back();
			parent->children.push_back(node);

			stack.push_back(&parent->children.back());
		}
	}

	return roots;
}

ActionItem MenuParser::Convert(const Node& node)
{
	ActionItem item(node.label);

	for (const auto& child : node.children)
	{
		item.AddChild(Convert(child));
	}

	return item;
}

Menu MenuParser::Parse(const std::vector<std::string>& data)
{
	if (data.empty())
		return {};

	Menu menu(data[0]);

	auto tree = ParseTree({ data.begin() + 1, data.end() });

	for (const auto& node : tree)
	{
		Dialog dialog;

		for (const auto& child : node.children)
		{
			dialog.AddField(Convert(child));
		}

		menu.AddItem(MenuItem(node.label, dialog));
	}

	return menu;
}