#pragma once
#include "input.h"
#include "instance.h"
#include <vector>

direction userInput(std::vector<std::vector<char>>& instance, char ch) {
	if (ch == 119) {
		return UP;
	} else if (ch == 97) {
		return LEFT;
	} else if (ch == 115) {
		return DOWN;
	} else if (ch == 100) {
		return RIGHT;
	}
}