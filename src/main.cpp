// Preprocessor
#include <SFML/Graphics.hpp> 
#include <iostream> 
#include <string>
#include <vector>
#include <stack>
#include <math.h>
#include "fs.hpp" 
#include "player.hpp"
#include "Mode.hpp"
#include "IntroMode.hpp"
#include "MenuMode.hpp"
#include "GameMode.hpp"
// Func
void RenderScreen(sf::RenderWindow* window) {
	window->setActive(true);
	window->setFramerateLimit(120);
	sf::Clock RenderClock;
	sf::Time TotalTime;
	sf::Time ElapsedTime;
	unsigned int frames = 0;
	unsigned int FPS = 0;
	sf::Font font;
	font.loadFromFile("../../../fonts/bauh.ttf");
	std::vector<sf::Text> Stats = { 
		sf::Text("FPSCounter", font, 30),
		sf::Text("TotalFPS", font, 15),
		sf::Text("FrameInterval", font, 15),
		sf::Text("CurrentRunTime", font, 15)		
	};
	auto size = Stats[0].getScale().y;
	for (int i = 1; i < Stats.size(); i++) {
		Stats[i].setPosition(0, 30.0f * i);
	}
	while (true) {
		window->clear();
		for (const auto& text : Stats) {
			window->draw(text);
		}
		window->display();
		frames++;
		ElapsedTime = RenderClock.restart();
		TotalTime += ElapsedTime;
		FPS = frames / TotalTime.asSeconds();
		Stats[0].setString(std::to_string(FPS) + " FPS");
		Stats[1].setString(std::to_string(frames) + " Frames");
		Stats[2].setString(std::to_string(ElapsedTime.asMicroseconds())+ "µs FrameTime");
		Stats[3].setString(std::to_string( (std::round( TotalTime.asSeconds() * 10) / 10) ) + "s TotalTime" );
		// TODO: Properly round seconds to the hundreth decimal place
	}
}
// Entry Point
int main() {
	// Path Check
	#ifdef FS_SUPPORT
		std::cout << fs::current_path().string() << std::endl;
	#endif
	auto desktop = sf::VideoMode::getDesktopMode();
	desktop.width += 1;
	sf::RenderWindow window(desktop, "Cnake", sf::Style::None);
	window.setActive(false);

	std::vector<sf::RectangleShape> Elements{sf::RectangleShape(sf::Vector2f(10, 10))};
	std::stack<Mode*> ModeStack;
	ModeStack.push(new IntroMode);

	sf::Thread RenderThread(&RenderScreen, &window);
	RenderThread.launch();

	sf::Clock GameClock;
	while (window.isOpen()) {
		sf::Time timePassed = GameClock.restart();
		auto result = ModeStack.top()->Run(timePassed, window);
		switch (result.first)
		{
		case ModeAction::None:
			break;
		case ModeAction::Add:
			switch (result.second)
			{
			case ModeOption::Intro:
				ModeStack.push(new IntroMode);
				break;
			case ModeOption::Menu:
				ModeStack.push(new MenuMode);
				break;
			case ModeOption::Game:
				ModeStack.push(new GameMode);
				break;
			case ModeOption::Paused:
				// TODO: Decide how to pause the game
				break;
			}
			break;
		case ModeAction::Remove:
			ModeStack.pop();
			break;
		}
	}


}
