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
float offsetx;
float offsety;
bool exitgame = false;

void buttonPressed(int x, int y, int width, int height, int& paused);

void keyPressed(player& man, boundry& tester, npc& josh);

void movePlayer(player& man, boundry& tester, npc& josh);

void game()
{
    int paused = 0;

    boundry tester("walls.txt");

    offsetx = 0;
    offsety = 0;

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
    float settingsScale = settings.getLocalBounds().width / (desktopWidth / 12);
    cout << settingsScale;
    settings.setScale(1 / settingsScale, 1 / settingsScale);
    
    npc josh("joshua");

    player man;

    menuUI pause;

    man.create(sf::Vector2f(desktopWidth / 2 - 50, desktopHeight / 2 - 50), block * 2, block);

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

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            buttonPressed(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, gameWidth, gameHeight, paused);
            Sleep(100);
        }

        if (paused == 0) {
            keyPressed(man, tester, josh);
            movePlayer(man, tester, josh);
        }

        if (exitgame == true) {
            exitgame = false;
            return;
        }

        window.clear();

        window.draw(mainBackground);
        tester.print();
        man.print(window);
        josh.print();


        if (paused == 1) {
            pause.printUI();
        }

        window.draw(settings);
        window.display();
    }

    
}

void buttonPressed(int x, int y, int width, int height, int& paused) {

    if (paused == 0) {
        if (x > 0 && y > 0 && x < desktopWidth / 12 && y < desktopWidth / 12) {
            paused = 1;
            cout << "pause";
        }
    }

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

void movePlayer(player& man, boundry& tester, npc& josh) {
    sf::Vector2f location = man.getLocation();
    sf::Vector2f size = man.getSize();
    tester.colision(location.x, location.y, size.x, size.y);
    josh.colision(location.x, location.y, size.x, size.y);
    if (mleft) {
        if (test[0] == 0) {
            //man.movebox(-10, 0);
            offsetx += 10;
            tester.move(10, 0);
            josh.move(10, 0);
        }
    }

    if (mright) {
        if (test[1] == 0) {
            //man.movebox(10, 0);
            offsetx -= 10;
            tester.move(-10, 0);
            josh.move(-10, 0);
        }
    }

    if (mup) {
        if (test[2] == 0) {
            //man.movebox(0, -10);
            offsety += 10;
            tester.move(0, 10);
            josh.move(0, 10);
        }
    }

    if (mdown) {
        if (test[3] == 0) {
            //man.movebox(0, 10);
            offsety -= 10;
            tester.move(0, -10);
            josh.move(0, -10);
        }
    }

    if (interact) {
        josh.interaction(location.x, location.y, size.x, size.y);
    }

    Sleep(10);

    mright = false;
    mleft = false;
    mup = false;
    mdown = false;
    interact = false;

}