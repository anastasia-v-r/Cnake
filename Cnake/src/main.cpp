// Proprocessor
#include <SFML/Graphics.hpp> // SFML Graphics
#include <conio.h>
#include <iostream>
#include <chrono>
#include <thread>
// Entry Point
int main() {

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Cnake", sf::Style::Close | sf::Style::Titlebar); // Create Window

	while (window.isOpen()) { // Game Loop

		sf::Event evnt;
		while (window.pollEvent(evnt)) { // Check all events since last iteration
			if (evnt.type == sf::Event::Closed) { // "Close Event" occurs, close window
				window.close();
			}
		}
	}
}

