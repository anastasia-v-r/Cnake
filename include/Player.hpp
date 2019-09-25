#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

enum Direction {
	Up,
	Right,
	Down,
	Left
};

class Player : public sf::Drawable
{
public:
	// Constructor
	Player(const std::map<std::string, sf::Texture>&);
	// Destructor
	~Player();
	// Setters
	void processKeys(sf::Keyboard::Key);
	// Getters
	// Processors
	void movePlayer();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	std::vector<sf::RectangleShape> snakeBody;
	Direction dir;
};
