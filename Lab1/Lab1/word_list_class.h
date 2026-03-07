#pragma once
#include<vector>
#include<string>
#include<iostream>
#include "center_text.h"

class WordList
{
public:

	WordList();
	WordList(const std::vector<std::string>& data);
	WordList(const std::initializer_list<std::string>& init);

	void output_center(const int width);
	std::string get(const int index);
	void add(const std::string& str);

	std::string& operator[](const int index);

	std::vector<std::string>::iterator begin();
	std::vector<std::string>::iterator end();

	~WordList();
private:
	std::vector<std::string> data;
};
