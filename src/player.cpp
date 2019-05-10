#include "player.h"

void Player::setColor(sf::Color colorH, sf::Color colorB) {
	snake[0].setFillColor(colorH);
	for (int i = 1; i < snake.size(); i++) {
		snake[i].setFillColor(colorB);
	}
}

void Player::setOrigin() {
	for (int i = 0; i > -(snake.size()); i--) {
		snake[i].setOrigin(sf::Vector2f(0, i));
	}
}

void Player::move() {

}

void Player::access(sf::RectangleShape **a) {
	*a = (sf::RectangleShape*)&snake;
}