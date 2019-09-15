#pragma once
#include <SFML/Graphics.hpp>

class RuntimeStats
{
public:
	RuntimeStats();
	void update();
	void draw(sf::RenderWindow&);
private:

private:
	sf::Clock RenderClock;
	unsigned int totalFrames;
	sf::Time totalTime;
	sf::Time elapsedTime;
	sf::Font font;
	sf::Text FPSCounter;
	sf::Text FrameInterval;
};
