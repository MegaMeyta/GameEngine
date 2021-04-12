#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;


float desktopWidth = sf::VideoMode::getDesktopMode().width / 1.5;
float desktopHeight = sf::VideoMode::getDesktopMode().height / 1.5;
float resolutionX = 1200;
float resolutionY = 800;
double height = 24;
double block = resolutionY / height;
double width = round(resolutionX/block);
double gameWidth = resolutionX;
double gameHeight = resolutionY;
double playerVelocity = 10;
bool interact;
sf::RenderWindow window(sf::VideoMode(resolutionX, resolutionY), "Re:Vale", sf::Style::Close);
void readSettings(){
	ifstream settings;
	string read;
	int fullscreen;
	settings.open("settings.txt");
	if (settings.is_open()) {
		getline(settings, read);
		resolutionX = stod(read.substr(13, read.size() + 1));
		getline(settings, read);
		resolutionY = stod(read.substr(13, read.size() + 1));
		getline(settings, read);
		fullscreen = stoi(read.substr(11, read.size()));
		cout << "\n" << resolutionX << " " << resolutionY;
		settings.close();
		block = resolutionY / height;
		width = round(resolutionX / block);
		if (fullscreen == 0)
		window.create(sf::VideoMode(resolutionX, resolutionY), "Re:Vale", sf::Style::Close);
		if (fullscreen == 1)
			window.create(sf::VideoMode(resolutionX, resolutionY), "Re:Vale", sf::Style::Fullscreen);
	}
	else {
		cout << "settings file doesn't exist";
	}
}

 






