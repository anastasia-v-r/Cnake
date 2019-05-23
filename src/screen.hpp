#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Screen : public sf::Drawable
{
private:
	std::vector<sf::Drawable*> screenElements;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
protected:
	Screen() {};
	Screen(std::vector<sf::Drawable*> list)
		: screenElements(list)
	{
	}
};