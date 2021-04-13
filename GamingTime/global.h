/*This header file contains all variables and objects that need to be accessed by every file. Also contains the functions responsible for chaning settings*/
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

//All the global variables and objects
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

/// <summary>
/// Functions for settings and file manipulation
/// </summary>
namespace settings {

	/// <summary>
	/// Generates a backup of a text file. Backup will be overwritten if the function is called again with the same file name
	/// </summary>
	/// <param name="filename">the file to be backed up</param>
	void backupFile(string filename) {
		ifstream original;
		ofstream copy;
		string temp;
		original.open(filename);
		copy.open(filename + ".bkup");
		if (original.is_open() && copy.is_open()) {
			bool loop = true;
			while(getline(original,temp)){
				copy << temp + "\n";
			}
			original.close();
			copy.close();
		}
		else if (original.is_open()) {
			original.close();
			cout <<"backup.txt failed to open or doesn't exist\n";
		}
		else if (copy.is_open()) {
			copy.close();
			cout << filename + " failed to open or doesn't exist\n";
		}
		else {
			cout << "no file opened\n";
		}
	}

	/// <summary>
	/// Reads settings.txt and changes the game settings according the values in the file
	/// </summary>
	void readSettings() {
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

	/// <summary>
	/// Changes the resolution and records it in settings.txt 
	/// </summary>
	/// <param name="x">new resolution width in pixels</param>
	/// <param name="y">new resolution height in pixels</param>
	void changeResolution(int x, int y){
		ofstream settings;
		string write;
		backupFile("settings.txt");
		ifstream backup;
		backup.open("settings.txt.bkup");
		settings.open("settings.txt");
		if (settings.is_open()) {
			write = "resolution_X:" + to_string(x) + "\n";
			settings << write;
			write = "resolution_Y:" + to_string(y) + "\n";
			settings << write;
			int line = 1;
			while (getline(backup, write)) {
				if (line > 2) {
					settings << write + "\n";
				}
				line++;
			}
			settings.close();
		}
		else {
			cout << "settings file doesn't exist or didn't open";
		}
		readSettings();
	}
}

 






