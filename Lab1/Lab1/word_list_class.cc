#include "word_list_class.h"

WordList::WordList()
{
	data = std::vector<std::string>();
}

WordList::WordList(const std::vector<std::string>& data)
{
	this->data = data;
}

WordList::WordList(const std::initializer_list<std::string>& init) : data(init) {}

void WordList::output_center(const int width)
{
	std::string sentence;
	for (const auto& elem : data)
	{
		if ((sentence + " " + elem).size() > width)
		{
			cout_centered(sentence);
			sentence = elem;
			continue;
		}
		sentence = sentence + " " + elem;
	}
}

std::string WordList::get(const int index)
{
	return data[index];
}

void WordList::add(const std::string& str)
{
	data.push_back(str);
}

std::string& WordList::operator[](const int index)
{
	return data[index];
}

std::vector<std::string>::iterator WordList::begin()
{
	return data.begin();
}

std::vector<std::string>::iterator WordList::end()
{
	return data.end();
}

WordList::~WordList() = default;
