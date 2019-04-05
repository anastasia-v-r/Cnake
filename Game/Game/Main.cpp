// Includes and Usings
#include <iostream> // I/O
using std::cout; using std::cin;
#include <conio.h>
#include "instance.h"
#include "drawScreen.h"
#include <chrono>
#include <thread>
// Entry Point
int main() {
	// Variables
	int time = 0, wait = 100;
	char ch;
	bool playing = true;
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
		}
	}
}


