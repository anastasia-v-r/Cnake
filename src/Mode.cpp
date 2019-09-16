#include "Mode.hpp"
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

Mode::Mode(std::string fileName, std::mutex* mutex) : mut{ mutex } {
	nlohmann::json jsonData;
	std::ifstream file("assets/modes/" + fileName);
	file >> jsonData;
	auto textures = jsonData["textures"];
	for (const auto& textureItem : textures) {
		sf::Texture texture;
		texture.loadFromFile("assets/textures/" + textureItem["textureLoc"].get<std::string>());
		std::cout << "Texture Loaded!" << std::endl;
		objectTextures.emplace(textureItem["textureName"].get<std::string>(), texture);
		std::cout << "Texture emplaced!" << std::endl;
	}
	auto objects = jsonData["objects"];
	for (const auto& object : objects) {
		auto size = object["size"];
		sf::RectangleShape rect(sf::Vector2f((float)size[0], (float)size[1]));
		if (object.contains("position")) {
			std::cout << "position exists!" << std::endl;
			auto pos = object["position"];
			rect.setPosition((float)pos[0], (float)pos[1]);
		} else {
			std::cout << "no position exists!" << std::endl;
		}
		pushObject(object["name"].get<std::string>(), rect, object["textureName"].get<std::string>());
	}
}

Mode::~Mode() {
	mut->lock();
	mut->unlock();
}
/// (RectangleName, The Rectagle, the texture name)
void Mode::pushObject(std::string rectName, sf::RectangleShape newRect, std::string textureName) {
	mut->lock();
	newRect.setTexture(&objectTextures[textureName]);
	screenObjects.push_back(newRect);
	screenObjectsMap.emplace(rectName, &screenObjects.back());
	mut->unlock();
}

void Mode::popObject(std::string name) {
	mut->lock();
	sf::RectangleShape* ptr{ nullptr };
	for (auto it = screenObjectsMap.begin(); it != screenObjectsMap.end();) {
		if (it->first == name) {
			ptr = it->second;
			for (int i = 0; i < screenObjects.size(); i++) {
				if (&screenObjects[i] == ptr) {
					screenObjects.erase(screenObjects.begin() + i);
				}
			}
			it = screenObjectsMap.erase(it);
			break;
		}
	}
	mut->unlock();
}
