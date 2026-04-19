#pragma once
#include<string>
#include <vector>

class FileReader
{
private:
	std::string m_path;

public:

	FileReader();

	std::vector<std::string> Read(const std::string& path) const;
};