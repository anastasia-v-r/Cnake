#pragma once
#include "Mode.hpp"
#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameMode : public Mode
{
public:
	GameMode(std::mutex*, float);
	virtual std::pair<ModeAction, ModeOption> Run(sf::Time, sf::RenderWindow&) override;
private:
	void processKeys(sf::Keyboard::Key, bool);
private:
	Player mPlayer;
	sf::Text score;
	sf::Font font;
	sf::Sound eat;
	sf::SoundBuffer eatSound;
	sf::Sound die;
	sf::SoundBuffer dieSound;
	float gameSpeed;
};