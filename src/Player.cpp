#include "Player.hpp"
#include <iostream>

Player::Player(const std::map<std::string, sf::Texture>& textures)
	: snakeBody(3, sf::RectangleShape(sf::Vector2f(100.0f, 100.0f)))
	, dir{ Direction::Left }
{
	for (int i = 0; i < snakeBody.size(); i++) {
		snakeBody[i].setPosition((float)(800 + (i * 100)), 500.0f);
		snakeBody[i].setTexture(&(textures.at("snakebody")));
	}
	snakeBody[0].setTexture(&(textures.at("snakehead")));
}

Player::~Player() {

}

void Player::processKeys(sf::Keyboard::Key key) {
	switch (key)
	{
	case sf::Keyboard::W:
	case sf::Keyboard::Up:
		if (dir != Direction::Down) {
			dir = Direction::Up;
		}
		break;
	case sf::Keyboard::D:
	case sf::Keyboard::Right:
		if (dir != Direction::Left) {
			dir = Direction::Right;
		}
		break;
	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		if (dir != Direction::Up) {
			dir = Direction::Down;
		}
		break;
	case sf::Keyboard::A:
	case sf::Keyboard::Left:
		if (dir != Direction::Right) {
			dir = Direction::Left;
		}
		break;
	}
}

void Player::movePlayer() {
	sf::Vector2f vel;
	auto scale = snakeBody[0].getSize().x;
	std::cout << scale;
	switch (dir)
	{
	case Up:
		vel = sf::Vector2f(0, -scale);
		break;
	case Right:
		vel = sf::Vector2f(scale, 0);
		break;
	case Down:
		vel = sf::Vector2f(0, scale);
		break;
	case Left:
		vel = sf::Vector2f(-scale, 0);
		break;
	default:
		break;
	}
	auto tempPos = snakeBody[0].getPosition();
	auto tempPos2 = tempPos;
	snakeBody[0].move(vel);
	for (int i = 1; i < snakeBody.size(); i++) {
		tempPos2 = snakeBody[i].getPosition();
		snakeBody[i].setPosition(tempPos);
		tempPos = tempPos2;
	}
}
 
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (auto& snakePart : snakeBody) {
		target.draw(snakePart, states);
	}
}
