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
		snake[i].setPosition(200.0f, (200.0f + (i * temp.x)));
	}
}

void Player::drawSnake(sf::RenderWindow& window) {
	for (auto& i : snake) {
		window.draw(i);
	}
}

void Player::setDir(sf::Keyboard::Key kKey) {
	switch (kKey)
	{
	case sf::Keyboard::Key::W:
		dir = UP;
		break;
	case sf::Keyboard::Key::A:
		dir = LEFT;
		break;
	case sf::Keyboard::Key::S:
		dir = DOWN;
		break;
	case sf::Keyboard::Key::D:
		dir = RIGHT;
		break;
	}
}

void Player::move() {
	sf::Vector2f temPos = snake[0].getPosition();
	sf::Vector2f temPos2;
	sf::Vector2f dist = snake[0].getSize();
	sf::Vector2f nexPos;
	switch (dir)
	{
	case UP:
		snake[0].setPosition(temPos.x, (temPos.y - dist.x));
		break;
	case DOWN:
		snake[0].setPosition(temPos.x, (temPos.y + dist.x));
		break;
	case LEFT:
		snake[0].setPosition((temPos.x - dist.x) , temPos.y);
		break;
	case RIGHT:
		snake[0].setPosition((temPos.x + dist.x) , temPos.y);
		break;
	}
	for (int i = 1; i < snake.size(); ++i) {
		temPos2 = snake[i].getPosition();
		snake[i].setPosition(temPos);
		temPos = temPos2;
	}
}

direction Player::getDir() {
	return dir;
}