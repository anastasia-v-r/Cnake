#pragma once
#include "Mode.hpp"
#include <SFML/Graphics.hpp>

class SettingsMode : public Mode
{
public:
	SettingsMode();
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:

private:

};