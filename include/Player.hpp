#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Player : public sf::Drawable
{
public:
	Player();
	~Player();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	std::vector<sf::RectangleShape>

};
