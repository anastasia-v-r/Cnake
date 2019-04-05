#pragma once
#include "input.h"
#include "instance.h"
#include <vector>

direction userInput(std::vector<std::vector<char>>& instance, char ch) {
	if (ch == 119) {
		return 1;
	} else if (ch == 97) {
		return 2;
	} else if (ch == 115) {
		return 3;
	} else if (ch == 100) {
		return 4;
	}
}