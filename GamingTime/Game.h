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

void keyPressed(sf::Keyboard::Key key, bool isPressed);

void movePlayer(player& man, boundry& tester, interactable& josh, double time);

void processEvents(int& paused);

void spawn(double spawnX, double spawnY);

void game()
{
    int paused = 0;

    boundry tester("walls.txt");

    interact = false;

    //BACKGROUND
    sf::Texture paper;
    sf::RectangleShape mainBackground(sf::Vector2f(resolutionX, resolutionY));
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
    double settingsScale = settings.getLocalBounds().width / (resolutionX / 12);
    settings.setScale(1 / settingsScale, 1 / settingsScale);
    
    player man(24, 24, 1,2);

    interactable josh("interactable.txt");

    menuUI pause;

    spawn(24, 24);

    pause.createUI();

    sf::Clock clock;

    double updateTime = 0;
    double totalTime = 0;
    int frames = 0;

    while (window.isOpen())
    {
        processEvents(paused);

        totalTime += clock.getElapsedTime().asSeconds();
        updateTime += clock.restart().asSeconds();
        while (updateTime >= 0.017) {
            processEvents(paused);
            movePlayer(man, tester, josh, 0.017);
            updateTime -= 0.017;

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
        josh.print(screenX, screenY);

        //Draws pause menu
        if (paused == 1) {
            pause.printUI();
        }

        window.draw(settings);
        window.display();
        //cout << man.playerX - screenX << " " << man.playerY - screenY << " " << screenX << " " << screenY << "\n";
    }

    
}

//This function dictates the function called when the mouse left click is registered 
void buttonPressed(double x, double y, double width, double height, int& paused) {

    //Pauses game if mouse is clicked in the right place
    if (paused == 0) {
        if (x > 0 && y > 0 && x < resolutionX / 12 && y < resolutionX / 12) {
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
        else if (x < resolutionX / 12 && y < resolutionX / 12) {
            paused = 0;
            cout << "unpause";
        }
        else {
            cout << "nothing pressed";
        }
    }
}

//This function enables different functions depending on what keys were registered at one time
void keyPressed(sf::Keyboard::Key key, bool isPressed) {

    if (key == sf::Keyboard::Left || key == sf::Keyboard::A) {
        mleft = isPressed;
    }

    if (key == sf::Keyboard::Right || key == sf::Keyboard::D) {
        mright = isPressed;
    }

    if (key == sf::Keyboard::Up || key == sf::Keyboard::W) {
        mup = isPressed;
    }

    if (key == sf::Keyboard::Down || key == sf::Keyboard::S) {
        mdown = isPressed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        interact = isPressed;
    }
}

//This function moves the player depending on which functions were enabled by keyPressed
void movePlayer(player& man, boundry& tester, interactable& josh, double time) {
    tester.colision(man.playerX, man.playerY, man.playerW, man.playerH);
    josh.colision(man.playerX, man.playerY, man.playerW, man.playerH);
    cout << test[0] << " " << test[1] << " " << test[2] << " " << test[3] << "\n";
    if (mleft) {
        if (test[0] == 0) {
            if (man.playerX >= 0.1) {
                man.move(-playerVelocity * time, 0);
            }
            if (man.playerX <= boundaryX - (width / 2) && man.playerX >= width / 2) {
                screenX = screenX - (playerVelocity * time);
            }
        }
    }

    if (mright) {
        if (test[1] == 0) {
            if (man.playerX <= boundaryX - block - 0.1) {
                man.move(playerVelocity * time, 0);
            }
            if (man.playerX <= boundaryX - (width / 2) && man.playerX >= width / 2) {
                screenX = screenX + (playerVelocity * time);
            }
        }
    }

    if (mup) {
        if (test[2] == 0) {
            if (man.playerY >= 0.1) {
                man.move(0, -playerVelocity * time);
            }
            if (man.playerY <= boundaryY - (height / 2) && man.playerY >= height / 2) {
                screenY = screenY - (playerVelocity * time);
            }
        }
    }

    if (mdown) {
        if (test[3] == 0) {
            if (man.playerY <= boundaryY) {
                man.move(0, playerVelocity * time);
            }
            if (man.playerY <= boundaryY - (height / 2) && man.playerY >= height / 2) {
                screenY = screenY + (playerVelocity * time);
            }
        }
    }

    if (interact) {

    }
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

void processEvents(int& paused) {
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type) {
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) {
                cout << paused << " " <<"escape\n";
                if (paused == 0) {
                    paused = 1;
                }
                else if (paused == 1) {
                    paused = 0;
                }
            }
            if (paused == 0) {
                keyPressed(event.key.code, true);
            }
            break;
        case sf::Event::KeyReleased:
            keyPressed(event.key.code, false);
            break;
        case sf::Event::MouseLeft:
            buttonPressed(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, gameWidth, gameHeight, paused);
            break;
        case sf::Event::Closed:
            window.close();
            break;
        }
    }
}