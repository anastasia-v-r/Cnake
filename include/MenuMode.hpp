#pragma once
#include "Mode.hpp"

class MenuMode : public Mode
{
public:
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:

private:

};