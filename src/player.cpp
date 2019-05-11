#include "player.h"
#include <iostream>

void Player::setColor(sf::Color colorH, sf::Color colorB) {
	snake[0].setFillColor(colorH);
	for (int i = 1; i < snake.size(); i++) {
		snake[i].setFillColor(colorB);
	}
}

void Player::setPosition() {
	sf::Vector2f temp = snake[0].getSize();
	for (int i = 0; i < snake.size(); ++i) {
		snake[i].setPosition(100.0f, (100.0f + (i * temp.x)));
	}
}

void Player::drawSnake(sf::RenderWindow window) {
	for (int i = 0; i < snake.size(); i++) {
		window.draw(snake[i]);
	}
}

void Player::move(sf::Keyboard::Key dasKey) {
	float x = 0; float y = 0; float increment = 5.0f;
	switch (dasKey)
	{
	case(sf::Keyboard::W):
		y = -(increment);
		break;
	case(sf::Keyboard::A):
		x = -(increment);
		break;
	case(sf::Keyboard::S):
		y = increment;
		break;
	case(sf::Keyboard::D):
		x = increment;
		break;
	default:
		break;
	}
	std::cout << "X[" << x << "] Y[" << y << "]" << std::endl;
	for (int i = 0; i < snake.size(); ++i) {
		snake[i].move(x, y);
	}
}

sf::RectangleShape* Player::access() {
	return &snake[0];
}