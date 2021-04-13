/*This is the main file for the game that contains the main function, the menu ui, and the settings configuration menu*/

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

void settingsMenu();

void resolutionOption(tgui::String resolution);

void resetList(tgui::GuiBase& gui, tgui::ListBox::Ptr& listBox);

int settingsExit = 0;

/// <summary>
/// The Class that contains the menu AI.
/// It is a class so it can be adjusted outside of the main function
/// </summary>
class menu {
public:
    
    sf::RectangleShape background;
    sf::RectangleShape Title;
    sf::RectangleShape button;
    sf::RectangleShape button2;
    sf::RectangleShape button3;
    sf::RectangleShape button4;

    /// <summary>
    /// Creates the main menu UI
    /// </summary>
    menu(){
        background.setSize(sf::Vector2f(resolutionX, resolutionY));
        Title.setSize(sf::Vector2f(resolutionX / 3, resolutionY / 8));
        button.setSize(sf::Vector2f(resolutionX / 5, resolutionY / 12));
        button2.setSize(sf::Vector2f(resolutionX / 5, resolutionY / 12));
        button3.setSize(sf::Vector2f(resolutionX / 5, resolutionY / 12));
        button4.setSize(sf::Vector2f(resolutionX / 5, resolutionY / 12));
        Title.setPosition(0, 40);
        background.setFillColor(sf::Color::Black);
        Title.setFillColor(sf::Color::Red);
        button.setPosition(0, Title.getSize().y + 90);
        button2.setPosition((0), button.getPosition().y + button.getSize().y + 30);
        button3.setPosition(0, button2.getPosition().y + button2.getSize().y + 30);
        button4.setPosition(0, button3.getPosition().y + button3.getSize().y + 30);
    }

    /// <summary>
    /// Draws the main menu UI onto window that can be found in global.h
    /// </summary>
    void print() {
        window.draw(background);
        window.draw(Title);
        window.draw(button);
        window.draw(button2);
        window.draw(button3);
        window.draw(button4);
    }

    /// <summary>
    /// Resizes the menu UI
    /// </summary>
    void resize() {
        background.setSize(sf::Vector2f(resolutionX, resolutionY));
        Title.setSize(sf::Vector2f(resolutionX / 3, resolutionY / 8));
        button.setSize(sf::Vector2f(resolutionX / 5, resolutionY / 12));
        button2.setSize(sf::Vector2f(resolutionX / 5, resolutionY / 12));
        button3.setSize(sf::Vector2f(resolutionX / 5, resolutionY / 12));
        button4.setSize(sf::Vector2f(resolutionX / 5, resolutionY / 12));
        Title.setPosition(0, 40);
        background.setFillColor(sf::Color::Black);
        Title.setFillColor(sf::Color::Red);
        button.setPosition(0, Title.getSize().y + 90);
        button2.setPosition((0), button.getPosition().y + button.getSize().y + 30);
        button3.setPosition(0, button2.getPosition().y + button2.getSize().y + 30);
        button4.setPosition(0, button3.getPosition().y + button3.getSize().y + 30);
    }

    
};

menu mainmenu;

int main()
{

    settings::readSettings();

    mainmenu.resize();

    while (window.isOpen())
    {
        //handles events
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Functions for each button in menu
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            int x = sf::Mouse::getPosition(window).x;
            int y = sf::Mouse::getPosition(window).y;
            if (x < resolutionX/5) {
                //First button starts the game
                if (y > mainmenu.button.getPosition().y && y < mainmenu.button.getPosition().y + mainmenu.button.getSize().y) {
                    cout << "Start Game\n";
                    game();
                }
                //Second button leads to the settings menu
                else if (y > mainmenu.button2.getPosition().y && y < mainmenu.button2.getPosition().y + mainmenu.button2.getSize().y) {
                    cout << "button 2";
                    settingsMenu();
                    settingsExit = 0;
                }
                else if (y > mainmenu.button3.getPosition().y && y < mainmenu.button3.getPosition().y + mainmenu.button3.getSize().y) {
                    cout << "button 3";
                }
                else if (y > mainmenu.button4.getPosition().y && y < mainmenu.button4.getPosition().y + mainmenu.button4.getSize().y) {
                    cout << "button 4";
                }
            }
            //Delay to prevent errors from input spamming 
            Sleep(100);
        }

        //Refreshes the window
        window.clear();
        mainmenu.print();
        window.display();
    }

    return 0;
}


/// <summary>
/// Creates the settings menu and prints on the window while the function is running
/// Will return to the main function once a resolution is selected
/// </summary>
void settingsMenu() {

    tgui::GuiSFML gui(window);

    //Generates the list box from available display modes (resolutions)
    auto listBox = tgui::ListBox::create();
    listBox->setSize({"40%","40%"});
    listBox->setItemHeight(20);
    listBox->setPosition({"20%","20%"});
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    for (std::size_t i = 0; i < modes.size(); ++i)
    {
        sf::VideoMode mode = modes[i];
        std::cout << "Mode #" << i << "\t"
            << mode.width << "x" << mode.height << " \t "
            << mode.bitsPerPixel << " bpp" << std::endl;
        listBox->addItem(to_string(mode.width) + "x" + to_string(mode.height));
    }
    listBox->onDoubleClick(resolutionOption);
    gui.add(listBox);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            gui.handleEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        //goes back to main menu
        if (settingsExit == 1) {
            break;
        }

        window.clear();
        gui.draw();
        window.display();
    }
}

/// <summary>
/// Changes the resolution based on the item selected from the list
/// Resizes the menu UI due to resolution change
/// Signals the exit to the main menu
/// </summary>
/// <param name="resolution">The string assigned to the item selected on the list</param>
void resolutionOption(tgui::String resolution) {
    int xPosition = resolution.find_first_of("x");
    int x;
    int y;
    resolution.substr(0, xPosition).attemptToInt(x);
    resolution.substr(xPosition + 1, resolution.size()).attemptToInt(y);
    settings::changeResolution(x, y);
    settingsExit = 1;
    mainmenu.resize();
}


