#pragma once
#include <SFML/Graphics.hpp>
#include <mutex>

enum struct ModeOption
{
	None,
	Intro,
	Menu,
	Game,
	Paused
};

enum struct ModeAction
{
	None,
	Add,
	Remove,
	RemoveAll
};


class Mode
{
public:
	Mode(std::string);
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) = 0;
protected:
	void pushObject(std::string, sf::RectangleShape, std::string);
	void popObject(std::string);
public:
	std::vector<sf::RectangleShape> screenObjects;
	std::map<std::string, sf::RectangleShape*> screenObjectsMap;
	std::map<std::string, sf::Texture> objectTextures;
protected:
	std::mutex mut;

};