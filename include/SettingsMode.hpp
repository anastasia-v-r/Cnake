#pragma once
#include "Mode.hpp"
#include <SFML/Graphics.hpp>

class SettingsMode : public Mode
{
public:
	SettingsMode(std::mutex* mutex);
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:

private:

};