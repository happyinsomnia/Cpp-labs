#include "file_reader.hpp"
#include <fstream>
#include <stdexcept>
#include <format>

FileReader::FileReader() = default;

std::vector<std::string> FileReader::Read(const std::string& path) const
{
	std::vector<std::string> data;

	data.reserve(50);

	std::fstream file(m_path, std::ios::in);

	if (!file.is_open())
		throw std::invalid_argument(std::format("can't open file {}", m_path));

	std::string line;

	while (std::getline(file, line))
	{
		data.push_back(line);
	}

	return data;
}