#pragma once
#include <SFML/Graphics.hpp>

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
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) = 0;
private:

};