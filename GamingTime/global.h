#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>


 float desktopWidth = sf::VideoMode::getDesktopMode().width / 1.5;
 float desktopHeight = sf::VideoMode::getDesktopMode().height / 1.5;
 double height = 24;
 double block = desktopHeight / height;
 double width = desktopWidth / block;
 double gameWidth = desktopWidth;
 double gameHeight = desktopHeight;
 bool interact;
 sf::RenderWindow window(sf::VideoMode(desktopWidth, desktopHeight), "SFML works!", sf::Style::Close);;






