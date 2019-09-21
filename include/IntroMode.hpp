#pragma once
#include "Mode.hpp"
#include <SFML/Graphics.hpp>

class IntroMode : public Mode
{
public:
	IntroMode();
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:

private:
	enum fadeStage {
		In,
		Out,
		Over
	};
	fadeStage fading;
};