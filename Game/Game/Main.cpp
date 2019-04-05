// Includes and Usings
#include <iostream>
using std::cout; using std::cin;
#include <conio.h>
#include <chrono>
#include <thread>
// Entry Point
int main() {
	int time = 0;
	char ch;
	bool playing = true;
	while (playing) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		time += 100;
		cout << "Waited : " << time << "ms \n";
		if (_kbhit()) {
			ch = _getch();
			if (ch == 27) {
				playing = false;
			}
		}
	}
}


void drawScreen() {

}