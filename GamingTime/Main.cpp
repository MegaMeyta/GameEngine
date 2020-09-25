#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>
#include <string.h>
#include <iostream>
#include "UI.h"

using namespace std;

int main()
{
    float desktopWidth= sf::VideoMode::getDesktopMode().width - 100;
    float desktopHeight = sf::VideoMode::getDesktopMode().height - 100;

    sf::RenderWindow window(sf::VideoMode(desktopWidth, desktopHeight), "SFML works!");
    sf::CircleShape shape(100.f);
    sf::Font font;
    if (!font.loadFromFile("University.ttf")) {
        cout << "font did not load";
    }
    sf::Text text;
    text.setPosition(desktopWidth/2, desktopHeight/2);
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setString("No Button");
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    shape.setFillColor(sf::Color::Green);

    UI mainUI;
    mainUI.createUI();

    float gameWidth = desktopWidth;
    float gameHeight = desktopHeight;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (event.type == sf::Event::Resized) {
            
            gameWidth = event.size.width;
            gameHeight = event.size.height;

            mainUI.resizeUI(gameWidth / desktopWidth, gameHeight / desktopHeight);

            text.scale(gameWidth / desktopWidth, gameHeight / desktopHeight);

            window.clear();

            mainUI.printUI(window);

            window.draw(text);

            window.display();
       }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            text.setString(buttonPressed(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y, gameWidth, gameHeight, window));
        }

        window.clear();
        
        mainUI.printUI(window);
        window.draw(text);

        window.display();
    }

    return 0;
}