#include "Player.hpp"
#include <iostream>
#include <time.h>

Player::Player(const std::map<std::string, sf::Texture>& textures, std::mutex* mut)
	: snakeBody(4, sf::RectangleShape(sf::Vector2f(50.0f, 50.0f)))
	, m_dir{ Direction::Left }
	, m_lastDir{ Direction::Left }
	, mu{ mut }
{
	for (int i = 0; i < snakeBody.size(); i++) {
		snakeBody[i].setPosition((float)(960 + (i * 50)), 540.0f);
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
	std::cout << scale;
	switch (m_dir)
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
	m_lastDir = m_dir;
}

void Player::addPart() {
	mu->lock();
	snakeBody.push_back(snakeBody[1]);
	mu->unlock();
}
 
bool Player::safeCheck(sf::RectangleShape& fruit) {
	auto head = snakeBody[0];
	sf::Vector2f headPos(head.getPosition().x + (head.getSize().x / 2), head.getPosition().y + (head.getSize().y / 2));
	sf::Vector2f fruitPos(fruit.getPosition().x + (fruit.getSize().x / 2), fruit.getPosition().y + (fruit.getSize().y / 2));
	for (int i = 1; i < snakeBody.size(); i++) { // Check if snake has eaten itself
		if (snakeBody[i].getGlobalBounds().contains(headPos)) {
			return true;
		}
	}
	if (head.getGlobalBounds().contains(fruitPos)) { // Check if snake ate fruit and is so replace it
		std::srand((unsigned int)std::time(NULL));
		Player::addPart();
		float x = (float)((rand() % (1920 / 50)) * 50);
		float y = (float)((rand() % (1080 / 50)) * 50);
		bool done = true;
		fruit.setPosition(x, y);
		fruitPos = sf::Vector2f(fruit.getPosition().x + (fruit.getSize().x / 2), fruit.getPosition().y + (fruit.getSize().y / 2));
		do {
			for (int i = 1; i < snakeBody.size(); i++) {
				if (snakeBody[i].getGlobalBounds().contains(fruitPos)) {
					x = (float)((rand() % (1920 / 50)) * 50);
					y = (float)((rand() % (1080 / 50)) * 50);
					fruit.setPosition(x, y);
					fruitPos = sf::Vector2f(fruit.getPosition().x + (fruit.getSize().x / 2), fruit.getPosition().y + (fruit.getSize().y / 2));
					done = false;
					break;
				}
				done = true;
			}
		} while (!done);
	} else if (headPos.x < 310 || headPos.x > 1610 || headPos.y < 40 || headPos.y > 1040) {
		return true;
	}
	return false;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (auto& snakePart : snakeBody) {
		target.draw(snakePart, states);
	}
	target.draw(snakeBody[0], states); 
}
