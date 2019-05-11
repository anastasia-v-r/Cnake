#include "player.h"

void Player::setColor(sf::Color colorH, sf::Color colorB) {
	snake[0].setFillColor(colorH);
	for (int i = 1; i < snake.size(); i++) {
		snake[i].setFillColor(colorB);
	}
}

void Player::setPosition() {
	for (int i = 0; i < snake.size(); ++i) {
		
	}
}

void Player::drawSnake(sf::RenderWindow window) {
	for (int i = 0; i < snake.size(); i++) {
		window.draw(snake[i]);
	}
}

void Player::move(sf::Keyboard::Key dasKey) {
	float x = 0; float y = 0;
	switch (dasKey)
	{
	case(sf::Keyboard::W):
		y = -0.1f;
	case(sf::Keyboard::A):
		x = -0.1f;
	case(sf::Keyboard::S):
		y = 0.1f;
	case(sf::Keyboard::D):
		x = 0.1f;
	default:
		break;
	}
	for (int i = 0; i < snake.size(); ++i) {
		snake[i].move(x, y);
	}
}

sf::RectangleShape* Player::access() {
	return &snake[0];
}