#include "player.hpp"
#include <iostream>

void Player::setColor(sf::Color colorH, sf::Color colorB) {
	snakeBody[0].setFillColor(colorH);
	for (int i = 1; i < snakeBody.size(); i++) {
		snakeBody[i].setFillColor(colorB);
	}
}

void Player::setPosition(int sWidth, int sHeight) {
	sf::Vector2f temp = snakeBody[0].getSize();
	for (int i = 0; i < snakeBody.size(); ++i) {
		snakeBody[i].setPosition((sWidth / 2), ((sHeight / 2) + (i * temp.x)));
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
	sf::Vector2f temPos = snakeBody[0].getPosition();
	sf::Vector2f temPos2;
	sf::Vector2f dist = snakeBody[0].getSize();
	sf::Vector2f nexPos;
	switch (dir)
	{
	case UP:
		snakeBody[0].setPosition(temPos.x, (temPos.y - dist.x));
		break;
	case DOWN:
		snakeBody[0].setPosition(temPos.x, (temPos.y + dist.x));
		break;
	case LEFT:
		snakeBody[0].setPosition((temPos.x - dist.x) , temPos.y);
		break;
	case RIGHT:
		snakeBody[0].setPosition((temPos.x + dist.x) , temPos.y);
		break;
	}
	for (int i = 1; i < snakeBody.size(); ++i) {
		temPos2 = snakeBody[i].getPosition();
		snakeBody[i].setPosition(temPos);
		temPos = temPos2;
	}
}

direction Player::getDir() {
	return dir;
}

sf::Vector2f Player::getSize() {
	return snakeBody[0].getSize();
}

int Player::getScore() {
  return score;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (auto& snakePart : snakeBody) {
		target.draw(snakePart, states);
	}
}
