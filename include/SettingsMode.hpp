#pragma once
#include "Mode.hpp"
#include "Settings.hpp"
#include <SFML/Graphics.hpp>

class SettingsMode : public Mode
{
public:
	SettingsMode(std::mutex*, Settings*);
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:

private:
	Settings* settings;
	bool fps;
	float speed;
};