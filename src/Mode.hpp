#pragma once

class Mode
{
public:
	Mode() {};
	virtual void Run(sf::Time, sf::RenderWindow&) = 0;
private:

};