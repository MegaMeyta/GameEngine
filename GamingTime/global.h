#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>


 float desktopWidth = sf::VideoMode::getDesktopMode().width / 1.5;
 float desktopHeight = sf::VideoMode::getDesktopMode().height / 1.5;
 float height = 24;
 float block = desktopHeight / height;
 float width = desktopWidth / block;
 float gameWidth = desktopWidth;
 float gameHeight = desktopHeight;
 bool interact;
 sf::RenderWindow window(sf::VideoMode(desktopWidth, desktopHeight), "SFML works!", sf::Style::Close);;






