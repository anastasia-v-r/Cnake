#pragma once

class Settings
{
public:
	Settings();
	~Settings() = default;
	bool getFpsLock() { return fpsLock; };
	float getGameSpeed() { return gameSpeed; };
	void setFpsLock(bool temp) { fpsLock = temp; };
	void setGameSpeed(float temp) { gameSpeed = temp; };
	void saveToFile();
private:
	bool fpsLock;
	float gameSpeed;
};