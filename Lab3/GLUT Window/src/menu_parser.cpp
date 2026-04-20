#include <menu_parser.hpp>
#include <menu_item.hpp>
#include <dialog.hpp>
#include <string>

Menu MenuParser::Parse(const std::vector<std::string>& data)
{
	if (data.empty())
		return {};

	Menu menu(data[0]);

	std::string currentLabel;
	Dialog currentDialog;
	bool hasActiveDialog = false;

	for (size_t i = 1; i < data.size(); i++)
	{
		const std::string& line = data[i];

		if (line == "--")
		{
			if (hasActiveDialog)
			{
				menu.AddItem(MenuItem(currentLabel, currentDialog));
				currentDialog = Dialog{};
				hasActiveDialog = false;
			}

			continue;
		}

		if (!hasActiveDialog)
		{
			currentLabel = line;
			hasActiveDialog = true;
		}

		else
		{
			currentDialog.AddField(ActionItem(line));
		}
	}

	if (hasActiveDialog)
		menu.AddItem(MenuItem(currentLabel, currentDialog));

	return menu;
}