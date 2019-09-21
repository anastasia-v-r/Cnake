#include "Mode.hpp"
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

Mode::Mode(std::string fileName, std::mutex* mutex, ModeOption modeType) : mut{ mutex }, ModeType{ modeType } {
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
	file.close();
}

/// (RectangleName, The Rectagle, the texture name)
void Mode::pushObject(std::string rectName, sf::RectangleShape newRect, std::string textureName) {
	mut->lock();
	if (objectTextures.count(textureName)) {
		newRect.setTexture(&objectTextures[textureName]);
		std::cout << "Rectangle \"" << rectName << "\" has found texture \"" << textureName << "\"\n";
	} else if (textureName == "empty") {
		std::cout << "Rectangle \"" << rectName << "\" has chosen no texture \n";
		newRect.setFillColor(sf::Color(255, 255, 255, 0));
	} else {
		std::cout << "Rectangle \"" << rectName << "\" is missing the their texture \"" << textureName << "\"\n";
		newRect.setFillColor(sf::Color::Green);
	}
	screenObjectsMap.emplace(rectName, newRect);
	screenObjects.emplace_back(&newRect);
	mut->unlock();
}

void Mode::popObject(std::string name) {
	mut->lock();
	for (auto it = screenObjectsMap.begin(); it != screenObjectsMap.end();) {
		if (it->first == name) {
			for (int i = 0; i < screenObjects.size(); i++) {
				if (screenObjects[i] == &(it->second)) {
					screenObjects.erase(screenObjects.begin()+i);
					screenObjects.shrink_to_fit();
					break;
				}
			}
			break;
		}
	}
	mut->unlock();
}
