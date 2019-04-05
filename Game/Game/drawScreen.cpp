#pragma once
#include <iostream>
using std::cout;
#include <vector>
#include "drawScreen.h"

void drawScreen(std::vector<std::vector<char>>& instance) {
	system("cls"); //system("clear");
	for (int i = 0; i < instance.size(); ++i) {
		for (int j = 0; j < instance[i].size(); ++j) {
			cout << instance[i][j];
		}
		cout << "\n";
	}
}