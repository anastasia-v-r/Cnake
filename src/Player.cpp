#include "Player.hpp"
#include <iostream>
#include <time.h>
#include <string>

Player::Player(const std::map<std::string, sf::Texture>& textures, std::mutex* mut)
	: snakeBody(4, sf::RectangleShape(sf::Vector2f(50.0f, 50.0f)))
	, m_dir{ Direction::Left }
	, m_lastDir{ Direction::Left }
	, mu{ mut }
	, playerScore{ 0 }
{
	for (int i = 0; i < snakeBody.size(); i++) {
		snakeBody[i].setPosition((float)(985 + (i * 50)), 565.0f);
		snakeBody[i].setTexture(&(textures.at("snakebody")));
		snakeBody[i].setOrigin(snakeBody[i].getSize().x / 2, snakeBody[i].getSize().y / 2);
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
		if (m_lastDir != Direction::Down) {
			m_dir = Direction::Up;
		}
		break;
	case sf::Keyboard::D:
	case sf::Keyboard::Right:
		if (m_lastDir != Direction::Left) {
			m_dir = Direction::Right;
		}
		break;
	case sf::Keyboard::S:
	case sf::Keyboard::Down:
		if (m_lastDir != Direction::Up) {
			m_dir = Direction::Down;
		}
		break;
	case sf::Keyboard::A:
	case sf::Keyboard::Left:
		if (m_lastDir != Direction::Right) {
			m_dir = Direction::Left;
		}
		break;
	}
}

void Player::movePlayer() {
	sf::Vector2f vel;
	auto scale = snakeBody[0].getSize().x;
	auto* head = &snakeBody[0];
	std::cout << scale;
	switch (m_dir)
	{
	case Up:
		vel = sf::Vector2f(0, -scale);
		head->setRotation(90);
		break;
	case Right:
		vel = sf::Vector2f(scale, 0);
		head->setRotation(180);
		break;
	case Down:
		vel = sf::Vector2f(0, scale);
		head->setRotation(270);
		break;
	case Left:
		vel = sf::Vector2f(-scale, 0);
		head->setRotation(0);
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
	m_lastDir = m_dir;
}

void Player::addPart() {
	mu->lock();
	snakeBody.push_back(snakeBody[1]);
	mu->unlock();
}
 
bool Player::safeCheck(sf::RectangleShape& fruit, sf::Text& text, sf::Sound& eat, sf::Sound& die) {
	auto head = snakeBody[0];
	sf::Vector2f headPos(head.getPosition().x, head.getPosition().y);
	sf::Vector2f fruitPos(fruit.getPosition().x + (fruit.getSize().x / 2), fruit.getPosition().y + (fruit.getSize().y / 2));
	for (int i = 1; i < snakeBody.size(); i++) { // Check if snake has eaten itself
		if (snakeBody[i].getGlobalBounds().intersects(snakeBody[0].getGlobalBounds())) {
			die.play();
			return true;
		}
	}
	if (head.getGlobalBounds().contains(fruitPos)) { // Check if snake ate fruit and is so replace it
		Player::addPart();
		eat.play();
		text.setString("Score : " + std::to_string(++playerScore));
		float x = (float)((rand() % (1920 / 50)) * 50) + 10.0f;
		float y = (float)((rand() % (1080 / 50)) * 50) - 10.0f;
		while (x < 310 || x >= 1610 || y < 40 || y >= 1040) {
			x = (float)((rand() % (1920 / 50)) * 50) + 10.0f;
			y = (float)((rand() % (1080 / 50)) * 50) - 10.0f;
		}
		bool done = true;
		fruit.setPosition(x, y);
		fruitPos = sf::Vector2f(fruit.getPosition().x + (fruit.getSize().x / 2), fruit.getPosition().y + (fruit.getSize().y / 2));
		do {
			for (int i = 1; i < snakeBody.size(); i++) {
				if (snakeBody[i].getGlobalBounds().contains(fruitPos)) {
					x = (float)((rand() % (1920 / 50)) * 50) + 10.0f;
					y = (float)((rand() % (1080 / 50)) * 50) - 10.0f;
					while (x < 310 || x >= 1610 || y < 40 || y >= 1040) {
						x = (float)((rand() % (1920 / 50)) * 50) + 10.0f;
						y = (float)((rand() % (1080 / 50)) * 50) - 10.0f;
					}
					fruit.setPosition(x, y);
					fruitPos = sf::Vector2f(fruit.getPosition().x + (fruit.getSize().x / 2), fruit.getPosition().y + (fruit.getSize().y / 2));
					done = false;
					break;
				}
				done = true;
			}
		} while (!done);
	} else if (headPos.x < 310 || headPos.x > 1610 || headPos.y < 40 || headPos.y > 1040) {
		die.play();
		return true;
	}
	return false;
}


sf::Vector2f Player::getHeadPos() {
	return snakeBody[0].getPosition();
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (auto& snakePart : snakeBody) {
		target.draw(snakePart, states);
	}
	target.draw(snakeBody[0], states); 
}
