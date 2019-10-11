#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <mutex>

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
	Player(const std::map<std::string, sf::Texture>&, std::mutex*);
	// Destructor
	~Player();
	// Setters
	void processKeys(sf::Keyboard::Key);
	// Getters
	sf::Vector2f getHeadPos();
	// Processors
	void movePlayer();
	void addPart();
	bool safeCheck(sf::RectangleShape&, sf::Text&, sf::Sound&, sf::Sound&);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	std::vector<sf::RectangleShape> snakeBody;
	Direction m_dir;
	Direction m_lastDir;
	std::mutex* mu;
	int playerScore;
};
