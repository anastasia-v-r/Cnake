#include "screen.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

void Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (const auto& element : screenElements) {
		target.draw(*element, states);
	}
}
