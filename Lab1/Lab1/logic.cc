#include "logic.h"

void separation_words(std::ifstream& file, WordList& words)
{
	std::string pars;

	while (getline(file, pars))
	{
		std::istringstream iss(pars);

		std::istream_iterator<std::string> begin(iss);
		std::istream_iterator<std::string> EOF_string_Read;

		for (auto i = begin; i != EOF_string_Read; i++)
		{
			words.add(*i);
		}
	}
}