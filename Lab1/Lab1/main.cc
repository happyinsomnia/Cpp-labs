#include "word_list_class.h"
#include "logic.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	string fileName;
	int width; // Width of string to align to the center

	cout << "FILE: ";
	getline(cin, fileName);

	cout << "Width: ";
	cin >> width;

	ifstream file(fileName);
	if (!file.is_open())
	{
		cerr << "Ошибка открытия файла " << endl;
		return -1;
	}
	WordList words;

	separation_words(file, words);

	words.output_center(width);

	file.close();

	return 0;
}