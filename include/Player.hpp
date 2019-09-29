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
	void addPart();
	bool safeCheck(sf::RectangleShape&);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	std::vector<sf::RectangleShape> snakeBody;
	Direction m_dir;
	Direction m_lastDir;
};
