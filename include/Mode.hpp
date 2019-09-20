#pragma once
#include <SFML/Graphics.hpp>
#include <mutex>

enum struct ModeOption
{
	None,
	Intro,
	Menu,
	Game,
	Settings,
	Paused
};

enum struct ModeAction
{
	None,
	Add,
	DropTo
};


class Mode
{
public:
	Mode(std::string, std::mutex*, ModeOption);
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) = 0;
	ModeOption type() { return ModeType; };
protected:
	void pushObject(std::string, sf::RectangleShape, std::string);
	void popObject(std::string);
public:
	std::vector<std::shared_ptr<sf::RectangleShape>> screenObjects;
	std::map<std::string, sf::RectangleShape> screenObjectsMap;
	std::map<std::string, sf::Texture> objectTextures;
protected:
	std::mutex* mut;
	ModeOption ModeType;
	sf::Time timeBank;
};