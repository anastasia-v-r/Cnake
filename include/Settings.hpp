#pragma once
#include <SFML/Graphics.hpp>

class Settings
{
public:
	Settings(sf::RenderWindow*);
	~Settings() = default;
	bool getFpsLock() { return fpsLock; };
	float getGameSpeed() { return gameSpeed; };
	void setFpsLock(bool);
	void setGameSpeed(float temp) { gameSpeed = temp; };
	void saveToFile();
private:
	bool fpsLock;
	float gameSpeed;
	sf::RenderWindow* window;
};