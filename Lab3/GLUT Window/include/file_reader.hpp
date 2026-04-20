#pragma once
#include<string>
#include <vector>

class FileReader
{
public:

	static std::vector<std::string> Read(const std::string& path);
};