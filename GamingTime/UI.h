#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>
#include "global.h"

using namespace std;

string buttonPressed(int x, int y, int width, int height, sf::RenderWindow& window) {
	if (x < width / 5 && y >(height / 8) * 7) {
        return string("button 1");
	}
    else if (x < (width / 5) * 2 && y >(height / 8) * 7) {
        return string("button 2");
    }
    else if (x < (width / 5) * 3 && y >(height / 8) * 7) {
        return string("button 3");
    }
    else if (x < (width / 5) * 4 && y >(height / 8) * 7) {
        return string("button 4");
    }
    else if (x < (width / 5) * 5 && y >(height / 8) * 7) {
        return string("button 5");
    }
    else {
        return "No button";
    }
}

class UI {

public:
    sf::RectangleShape button;
    sf::RectangleShape button2;
    sf::RectangleShape button3;
    sf::RectangleShape button4;
    sf::RectangleShape button5;

    void createUI() {
        button.setSize(sf::Vector2f(desktopWidth / 5, desktopHeight / 8));
        button2.setSize(sf::Vector2f(desktopWidth / 5, desktopHeight / 8));
        button3.setSize(sf::Vector2f(desktopWidth / 5, desktopHeight / 8));
        button4.setSize(sf::Vector2f(desktopWidth / 5, desktopHeight / 8));
        button5.setSize(sf::Vector2f(desktopWidth / 5, desktopHeight / 8));
        button.setPosition(0, (desktopHeight / 8) * 7);
        button2.setPosition(1 * (desktopWidth / 5), (desktopHeight / 8) * 7);
        button3.setPosition(2 * (desktopWidth / 5), (desktopHeight / 8) * 7);
        button4.setPosition(3 * (desktopWidth / 5), (desktopHeight / 8) * 7);
        button5.setPosition(4 * (desktopWidth / 5), (desktopHeight / 8) * 7);
        button.setFillColor(sf::Color::Red);
        button2.setFillColor(sf::Color::Yellow);
        button3.setFillColor(sf::Color::Green);
        button4.setFillColor(sf::Color::Blue);
        button5.setFillColor(sf::Color::Magenta);
        button.setOutlineThickness(button.getSize().x / 50);
        button2.setOutlineThickness(button.getSize().x / 50);
        button3.setOutlineThickness(button.getSize().x / 50);
        button4.setOutlineThickness(button.getSize().x / 50);
        button5.setOutlineThickness(button.getSize().x / 50);
        button.setOutlineColor(sf::Color::Black);
        button2.setOutlineColor(sf::Color::Black);
        button3.setOutlineColor(sf::Color::Black);
        button4.setOutlineColor(sf::Color::Black);
        button5.setOutlineColor(sf::Color::Black);

    }

    void printUI(sf::RenderWindow& window) {
        window.draw(button);
        window.draw(button2);
        window.draw(button3);
        window.draw(button4);
        window.draw(button5);
    }

    void resizeUI(float x, float y) {
        
        button.setScale(x,y);
        button2.setScale(x, y);
        button3.setScale(x, y);
        button4.setScale(x, y);
        button5.setScale(x, y);
        button.setPosition(0, (desktopHeight / 8) * 7 * y);
        button2.setPosition(1 * (desktopWidth / 5) * x, (desktopHeight / 8) * 7 * y);
        button3.setPosition(2 * (desktopWidth / 5) * x, (desktopHeight / 8) * 7 * y);
        button4.setPosition(3 * (desktopWidth / 5) * x, (desktopHeight / 8) * 7 * y);
        button5.setPosition(4 * (desktopWidth / 5) * x, (desktopHeight / 8) * 7 * y);
        button.setOutlineThickness(button.getSize().x / 50);
        button2.setOutlineThickness(button.getSize().x / 50);
        button3.setOutlineThickness(button.getSize().x / 50);
        button4.setOutlineThickness(button.getSize().x / 50);
        button5.setOutlineThickness(button.getSize().x / 50);
        cout << int(button.getSize().x) << "\n";
        cout << int(button.getSize().y) << "\n";
    }
};

