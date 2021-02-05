#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>
#include <windows.h>
#include <list>
#include <fstream>
#include "UI.h"
#include "global.h"

using namespace std;

bool mleft = false;
bool mright = false;
bool mup = false;
bool mdown = false;
bool exitgame = false;
double screenX;
double screenY;
double boundaryX = 100;
double boundaryY = 100;

void buttonPressed(double x, double y, double width, double height, int& paused);

void keyPressed(player& man, boundry& tester, npc& josh);

void movePlayer(player& man, boundry& tester, npc& josh);

void spawn(double spawnX, double spawnY);

void game()
{
    int paused = 0;

    boundry tester("walls.txt");

    interact = false;

    //BACKGROUND
    sf::Texture paper;
    sf::RectangleShape mainBackground(sf::Vector2f(desktopWidth, desktopHeight));
    if (!paper.loadFromFile("paper.jpg")) {
        cout << "background texture error";
    }
    mainBackground.setTexture(&paper);

    //SETTINGS
    sf::Sprite settings;
    sf::Texture gear;
    if (!gear.loadFromFile("gear.png")) {
        cout << "error";
    }

    settings.setTexture(gear);
    double settingsScale = settings.getLocalBounds().width / (desktopWidth / 12);
    cout << settingsScale;
    settings.setScale(1 / settingsScale, 1 / settingsScale);
    
    npc josh("joshua");

    player man(24, 24, 1,2);

    menuUI pause;

    spawn(24, 24);

    pause.createUI();

    int face;

    while (window.isOpen())
    {
        face = 0;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Checks if left mouse button was clicked and calls apropriate function
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            buttonPressed(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, gameWidth, gameHeight, paused);
            Sleep(100);
        }

        //Allows for key presses to be registered.
        if (paused == 0) {
            keyPressed(man, tester, josh);
            movePlayer(man, tester, josh);
        }

        if (exitgame == true) {
            exitgame = false;
            return;
        }

        window.clear();

        //Draw functions for all elements
        window.draw(mainBackground);
        tester.print(screenX, screenY);
        man.print(window, screenX, screenY);
        josh.print();

        //Draws pause menu
        if (paused == 1) {
            pause.printUI();
        }

        window.draw(settings);
        window.display();
    }

    
}

//This function dictates the function called when the mouse left click is registered 
void buttonPressed(double x, double y, double width, double height, int& paused) {

    //Pauses game if mouse is clicked in the right place
    if (paused == 0) {
        if (x > 0 && y > 0 && x < desktopWidth / 12 && y < desktopWidth / 12) {
            paused = 1;
            cout << "pause";
        }
    }

    //Calls apropriate functions for each button in the pause menu
    else if (paused == 1) {
        if (x < width / 5 && y >(height / 8) * 7) {
            cout << "button 1";
        }
        else if (x < (width / 5) * 2 && y >(height / 8) * 7) {
            cout << "button 2";
        }
        else if (x < (width / 5) * 3 && y >(height / 8) * 7) {
            cout << "button 3";
        }
        else if (x < (width / 5) * 4 && y >(height / 8) * 7) {
            cout << "button 4";
        }
        else if (x < (width / 5) * 5 && y >(height / 8) * 7) {
            cout << "End Game";
            exitgame = true;
        }
        else if (x < desktopWidth / 12 && y < desktopWidth / 12) {
            paused = 0;
            cout << "unpause";
        }
        else {
            cout << "nothing pressed";
        }
    }
}

//This function enables different functions depending on what keys were registered at one time
void keyPressed(player& man, boundry& tester, npc& josh) {
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        mleft = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        mright = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        mup = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        mdown = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        interact = true;
    }
}

//This function moves the player depending on which functions were enabled by keyPressed
void movePlayer(player& man, boundry& tester, npc& josh) {
    tester.colision(man.playerX, man.playerY, man.playerW, man.playerH);
    //josh.colision(location.x, location.y, size.x, size.y);
    if (mleft) {
        if (test[0] == 0) {
            if (man.playerX > 0) {
                man.move(-0.2, 0);
            }
            if (man.playerX <= boundaryX - (width / 2) && man.playerX >= width / 2) {
                screenX = screenX - 0.2;
            }
        }
    }

    if (mright) {
        if (test[1] == 0) {
            if (man.playerX < boundaryX) {
                man.move(0.2, 0);
            }
            if (man.playerX <= boundaryX - (width / 2) && man.playerX >= width / 2) {
                screenX = screenX + 0.2;
            }
        }
    }

    if (mup) {
        if (test[2] == 0) {
            if (man.playerY > 0) {
                man.move(0, -0.2);
            }
            if (man.playerY <= boundaryY - (height / 2) && man.playerY >= height / 2) {
                screenY = screenY - 0.2;
            }
        }
    }

    if (mdown) {
        if (test[3] == 0) {
            if (man.playerY < boundaryY) {
                man.move(0, 0.2);
            }
            if (man.playerY <= boundaryY - (height / 2) && man.playerY >= height / 2) {
                screenY = screenY + 0.2;
            }
        }
    }

    if (interact) {
        
    }

    Sleep(10);

    mright = false;
    mleft = false;
    mup = false;
    mdown = false;
    interact = false;

}

void spawn(double spawnX, double spawnY) {

    if (spawnX >= boundaryX - (width / 2)) {
        screenX = boundaryX - width;
    }
    else if (spawnX < width / 2) {
        screenX = 0;
    }
    else {
        screenX = spawnX - width / 2;
    }
    if (spawnY >= boundaryY - (height / 2)) {
        screenY = boundaryY - height;
    }
    else if (spawnY < height/ 2) {
        screenY = 0;
    }
    else {
        screenY = spawnY - height / 2;
    }

    cout << screenX << " " << screenY << "\n";
}