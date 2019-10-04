#include "Settings.hpp"
#include <fstream>
#include <iostream>
#include <string>

Settings::Settings() {
	std::fstream file;
	file.open("assets/settings.txt", std::ios::in);
	std::string line;
	if (!file.fail()) {
		std::getline(file, line, '\n');
		std::cout << line << std::endl;
		std::getline(file, line, '\n');
		std::cout << line << std::endl;
		if (line == "true") {
			fpsLock = true;
		} else {
			fpsLock = false;
		}
		std::getline(file, line, '\n');
		std::cout << line << std::endl;
		std::getline(file, line, '\n');
		std::cout << line << std::endl;
		gameSpeed = std::stof(line);
	} else {
		file.open("assets/settings.txt", std::ios::out);
		file << "# fpslock\n" << "false\n" << "# gamespeed\n" << ".10f\n";
		fpsLock = false;
		gameSpeed = .10f; //
	}
	file.close();
}

void Settings::saveToFile() {
	std::fstream file;
	file.open("assets/settings.txt", std::ios::out);
	file << "# fpslock\n";
	if (fpsLock) {
		file << "true\n";
	} else {
		file << "false\n";
	}
	file << "# gamespeed\n";
	file << std::to_string(gameSpeed);
	file.close();
}