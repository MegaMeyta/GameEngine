#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>
#include "UI.h"
#include "global.h"

using namespace std;

int main()
{

    sf::Texture paper;
    if (!paper.loadFromFile("paper.jpg")) {
        cout << "error";
    }
    sf::Texture gear;
    if (!gear.loadFromFile("gear.png")) {
        cout << "error";
    }
    sf::RectangleShape settings(sf::Vector2f(desktopWidth/12, desktopWidth/12));
    sf::RectangleShape mainBackground(sf::Vector2f(desktopWidth, desktopHeight));
    mainBackground.setTexture(&paper);
    settings.setTexture(&gear);
    sf::CircleShape shape(100.f);
    sf::Font font;
    if (!font.loadFromFile("University.ttf")) {
        cout << "font did not load";
    }
    sf::Text text;
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Black);
    text.setFont(font);
    text.setString("No Button");
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    text.setPosition(desktopWidth / 2, desktopHeight / 2);
    shape.setFillColor(sf::Color::Green);

    UI mainUI;
    mainUI.createUI();

    gameWidth = desktopWidth;
    gameHeight = desktopHeight;

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

            mainUI.printUI();

            window.draw(text);

            window.display();
       }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            text.setString(buttonPressed(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, gameWidth, gameHeight));
            textRect = text.getLocalBounds();
            text.setOrigin(textRect.left + textRect.width / 2.0f,
                textRect.top + textRect.height / 2.0f);
            text.setPosition(desktopWidth / 2, desktopHeight / 2);
        }

        window.clear();

        
        window.draw(mainBackground);
        mainUI.printUI();
        window.draw(text);
        window.draw(settings);

        window.display();
    }

    return 0;
}