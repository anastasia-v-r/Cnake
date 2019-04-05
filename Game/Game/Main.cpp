// Includes and Usings
#include <iostream> // I/O
using std::cout; using std::cin;
#include <conio.h>
#include "instance.h"
#include "input.h"
#include "drawScreen.h"
#include "logic.h"
#include <chrono>
#include <thread>
// Entry Point
int main() {
	// Variables
	int time = 0, wait = 32;
	char ch;
	bool playing = true;
	direction dir;
	std::vector<bodyPiece> snake(1);
	// Game Loop
	while (playing) {
		std::this_thread::sleep_for(std::chrono::milliseconds(wait));
		//time += wait;
		//cout << "Waited : " << time << "ms \n";

		drawScreen(instance);
		if (_kbhit()) {
			ch = _getch();
			if (ch == 27) {
				playing = false;
			}
			else if (ch == 119 || ch == 97 || ch == 115 || ch == 100)
			{
				dir = userInput(instance, ch);
				playing = gameLogic(snake, dir);
			}
		}
	}
}