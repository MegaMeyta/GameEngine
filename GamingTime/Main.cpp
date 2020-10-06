#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>
#include <windows.h>
#include <list>
#include <fstream>
#include "Game.h"
#include "global.h"

using namespace std;


int main()
{
    
    sf::RectangleShape background(sf::Vector2f(desktopWidth, desktopHeight));
    sf::RectangleShape Title(sf::Vector2f(desktopWidth / 3, desktopHeight / 8));
    sf::RectangleShape button(sf::Vector2f(desktopWidth / 5, desktopHeight / 12));
    sf::RectangleShape button2(sf::Vector2f(desktopWidth / 5, desktopHeight / 12));
    sf::RectangleShape button3(sf::Vector2f(desktopWidth / 5, desktopHeight / 12));
    sf::RectangleShape button4(sf::Vector2f(desktopWidth / 5, desktopHeight / 12));
    Title.setPosition(0,40);
    background.setFillColor(sf::Color::Black);
    Title.setFillColor(sf::Color::Red);
    button.setPosition(0, Title.getSize().y + 90);
    button2.setPosition((0), button.getPosition().y + button.getSize().y + 30);
    button3.setPosition(0, button2.getPosition().y + button2.getSize().y + 30);
    button4.setPosition(0, button3.getPosition().y + button3.getSize().y + 30);

    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        
        window.draw(background);
        window.draw(Title);
        window.draw(button);
        window.draw(button2);
        window.draw(button3);
        window.draw(button4);
       
        window.display();
    }

    return 0;
}

