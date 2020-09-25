#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>

float desktopWidth = sf::VideoMode::getDesktopMode().width / 2;
float desktopHeight = sf::VideoMode::getDesktopMode().height / 2;
float gameWidth = desktopWidth;
float gameHeight = desktopHeight;
sf::RenderWindow window(sf::VideoMode(desktopWidth, desktopHeight), "SFML works!", sf::Style::Titlebar || sf::Style::Close);