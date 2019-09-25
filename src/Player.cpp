#include "Player.hpp"
#include <iostream>

Player::Player(const std::map<std::string, sf::Texture>& textures)
	: snakeBody(3, sf::RectangleShape(sf::Vector2f(100.0f, 100.0f)))
{
	for (int i = 0; i < snakeBody.size(); i++) {
		snakeBody[i].setPosition((float)(800 + (i * 100)), 500.0f);
		snakeBody[i].setTexture(&(textures.at("snakebody")));
	}
	snakeBody[0].setTexture(&(textures.at("snakehead")));
}

Player::~Player() {

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (auto& snakePart : snakeBody) {
		target.draw(snakePart, states);
	}
}
