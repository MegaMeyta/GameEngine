#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>
#include <windows.h>
#include <list>
#include <fstream>
#include <TGUI/TGUI.hpp>
#include "Game.h"
#include "UI.h"
#include "global.h"

using namespace std;

int main()
{
    // Display the list of all the video modes available for fullscreen
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();

    // Display each mode
    for (std::size_t i = 0; i < modes.size(); ++i)
    {
        sf::VideoMode mode = modes[i];
        std::cout << "Mode #" << i << "\t"
            << mode.width << "x" << mode.height << " \t "
            << mode.bitsPerPixel << " bpp" << std::endl;
    }

    // Get and display desktop mode
    sf::VideoMode mode = sf::VideoMode::getDesktopMode();
    std::cout << "Desktop" << "\t"
        << mode.width << "x" << mode.height << " \t "
        << mode.bitsPerPixel << " bpp" << std::endl;


    tgui::GuiSFML gui(window);
    tgui::Theme theme{ "Black.txt" };
    tgui::Button::Ptr testing = tgui::Button::create();
    testing->setPosition(500, 500);
    testing->setSize(100, 100);
    gui.add(testing);

    auto listBox = tgui::ListBox::create();
    listBox->setSize(250, 120);
    listBox->setItemHeight(24);
    listBox->setPosition(500, 340);
    listBox->addItem("Item 1");
    listBox->addItem("Item 2");
    listBox->addItem("Item 3");
    listBox->addItem("Item 1");
    listBox->addItem("Item 2");
    listBox->addItem("Item 3");
    gui.add(listBox);



    //Creates Rectangles for Menu
    sf::RectangleShape background(sf::Vector2f(resolutionX, desktopHeight));
    sf::RectangleShape Title(sf::Vector2f(resolutionX / 3, desktopHeight / 8));
    sf::RectangleShape button(sf::Vector2f(resolutionX / 5, desktopHeight / 12));
    sf::RectangleShape button2(sf::Vector2f(resolutionX / 5, desktopHeight / 12));
    sf::RectangleShape button3(sf::Vector2f(resolutionX / 5, desktopHeight / 12));
    sf::RectangleShape button4(sf::Vector2f(resolutionX / 5, desktopHeight / 12));

    //Sets Color and position for menu rectangles
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
            gui.handleEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Functions for each button in menu
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            int x = sf::Mouse::getPosition(window).x;
            int y = sf::Mouse::getPosition(window).y;
            if (x < resolutionX/5) {
                //First button starts the game
                if (y > button.getPosition().y && y < button.getPosition().y + button.getSize().y) {
                    cout << "Start Game\n";
                    game();
                }
                else if (y > button2.getPosition().y && y < button2.getPosition().y + button2.getSize().y) {
                    cout << "button 2";
                    readSettings();
                }
                else if (y > button3.getPosition().y && y < button3.getPosition().y + button3.getSize().y) {
                    cout << "button 3";
                }
                else if (y > button4.getPosition().y && y < button4.getPosition().y + button4.getSize().y) {
                    cout << "button 4";
                }
            }
            Sleep(100);
        }

        window.clear();
        
        window.draw(background);
        window.draw(Title);
        window.draw(button);
        window.draw(button2);
        gui.draw();
        window.draw(button3);
        window.draw(button4);
       
        window.display();
    }

    return 0;
}


