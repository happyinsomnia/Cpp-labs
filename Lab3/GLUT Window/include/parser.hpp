#pragma once
#include<string>
#include<vector>

class Parser
{
private:
	std::vector<std::string> m_data;
public:

	Parser(const std::vector<std::string> data);

	void Parse();
};