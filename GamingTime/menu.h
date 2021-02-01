#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>
#include <fstream>
#include "global.h"

class button {
	sf::Vector2f position;
	sf::Vector2f size;
	int shape;

	void create(int x, int y, int height, int width, int shape) {
		position.x = x;
		position.y = y;
		size.x = width;
		size.y = height;
		this->shape = shape;
	}

	void print() {
		if (shape == 1) {
			sf::RectangleShape finalbutton(size);
			finalbutton.setPosition(position);
			window.draw(button);
		}
		else if (shape == 2) {
			sf::CircleShape button(size.x);
			button.setPosition(position);
			window.draw(button);
		}
	}

	bool pressCheck() {

	}
};
