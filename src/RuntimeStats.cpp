#include "RuntimeStats.hpp"

RuntimeStats::RuntimeStats()
	: RenderClock()
	, totalFrames{ 0 }
	, totalTime(sf::Time::Zero)
	, elapsedTime(sf::Time::Zero)
	, font()
	, FPSCounter("", font, 30)
	, FrameInterval("", font, 15)
{
	// Load Font
	font;
	font.loadFromFile("assets/fonts/bauh.ttf");
	// Prevent Overlap
	FrameInterval.move(0, 30);
}

void RuntimeStats::update() {
	elapsedTime = RenderClock.restart();
	totalTime += elapsedTime;
	totalFrames += 1;
	FPSCounter.setString(std::to_string(static_cast<unsigned int>(totalFrames / totalTime.asSeconds())) + " FPS");
	FrameInterval.setString(std::to_string(totalTime.asMicroseconds() / totalFrames) + "µs FrameTime");
}

void RuntimeStats::draw(sf::RenderWindow& window) {
	window.draw(FPSCounter);
	window.draw(FrameInterval);
}