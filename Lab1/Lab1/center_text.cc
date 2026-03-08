#include "center_text.h"

/// <summary>
/// This function will only center the text if it is less than the length of the console!
/// Otherwise it will just display it on the console without centering it.
/// </summary>
/// <param name="text">Prints the text centered</param>
void cout_centered(std::string text)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get the console handle.

	// Create a pointer to the Screen Info pointing to a temporal screen info.
	PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO();

	// Saves the console screen info into the lpScreenInfo pointer.
	GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);

	COORD NewSBSize = lpScreenInfo->dwSize; // Gets the size of the screen

	if (NewSBSize.X > text.size())
	{
		int newpos = ((NewSBSize.X - text.size()) / 2);

		for (int i = 0; i < newpos; i++)
			std::cout << " ";
	}

	std::cout << text << std::endl; // Prints the text centered :]

	delete lpScreenInfo;
}