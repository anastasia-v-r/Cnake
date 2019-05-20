#include "screen.h"
#include <SFML/Graphics.hpp>

void Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (auto& element : screenElements) {
		target.draw(element, states);
	}
}