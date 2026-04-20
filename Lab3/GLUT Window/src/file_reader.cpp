#include "file_reader.hpp"
#include <fstream>
#include <stdexcept>
#include <format>

std::vector<std::string> FileReader::Read(const std::string& path)
{
	std::vector<std::string> data;

	data.reserve(50);

	std::fstream file(path, std::ios::in);

	if (!file.is_open())
		throw std::runtime_error(std::format("can't open file {}", path));

	std::string line;

	while (std::getline(file, line))
	{
		data.push_back(line);
	}

	return data;
}