#include "Mode.hpp"
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

Mode::Mode(std::string fileName) {
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
/// (RectangleName, The Rectagle, the texture name)
void Mode::pushObject(std::string rectName, sf::RectangleShape newRect, std::string textureName) {
	while (true) {
		if (mut.try_lock()) {
			newRect.setTexture(&objectTextures[textureName]);
			screenObjects.push_back(newRect);
			screenObjectsMap.emplace(rectName, &screenObjects.back());
			mut.unlock();
			break;
		} else {
			// std::cout << "Mutex Locked!" << std::endl;
		}
	}
}

void Mode::popObject(std::string name) {
	while (true) {
		if (true/*mut.try_lock()*/) {
			int count = 0;
			for (auto it = screenObjectsMap.begin(); it != screenObjectsMap.end();) {
				if (it->first == name) {
					screenObjects.erase(screenObjects.begin() + count);
					it = screenObjectsMap.erase(it);
					break;
				}
				count++;
			}
			//mut.unlock();
			break;
		} else {
			// std::cout << "Mutex Locked!" << std::endl;
		}
	}
}

/*
std::vector<sf::RectangleShape> screenObjects;
std::map<std::string, sf::RectangleShape*> screenObjectsMap;
std::map<std::string, sf::Texture> objectTextures;
*/