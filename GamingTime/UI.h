#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>
#include <fstream>
#include "global.h"

using namespace std;

int test[4];

void popUpMenu(int amount) {

}

class menuUI {

public:
    sf::RectangleShape button;
    sf::RectangleShape button2;
    sf::RectangleShape button3;
    sf::RectangleShape button4;
    sf::RectangleShape button5;
    sf::RectangleShape tint;
    sf::Font font;
    sf::Text text;
    sf::FloatRect textRect;

    void createUI() {
        //SIZE
        button.setSize(sf::Vector2f(desktopWidth / 5, desktopHeight / 8));
        button2.setSize(sf::Vector2f(desktopWidth / 5, desktopHeight / 8));
        button3.setSize(sf::Vector2f(desktopWidth / 5, desktopHeight / 8));
        button4.setSize(sf::Vector2f(desktopWidth / 5, desktopHeight / 8));
        button5.setSize(sf::Vector2f(desktopWidth / 5, desktopHeight / 8));
        tint.setSize(sf::Vector2f(desktopWidth, desktopHeight));

        //POSITION
        button.setPosition(0, (desktopHeight / 8) * 7);
        button2.setPosition(1 * (desktopWidth / 5), (desktopHeight / 8) * 7);
        button3.setPosition(2 * (desktopWidth / 5), (desktopHeight / 8) * 7);
        button4.setPosition(3 * (desktopWidth / 5), (desktopHeight / 8) * 7);
        button5.setPosition(4 * (desktopWidth / 5), (desktopHeight / 8) * 7);

        //COLOR
        button.setFillColor(sf::Color::Red);
        button2.setFillColor(sf::Color::Yellow);
        button3.setFillColor(sf::Color::Green);
        button4.setFillColor(sf::Color::Blue);
        button5.setFillColor(sf::Color::Magenta);
        tint.setFillColor(sf::Color(0, 0, 0, 120));

        //BORDER
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

        //TEXT
        text.setCharacterSize(25);
        text.setFillColor(sf::Color::Black);
        text.setFont(font);
        text.setString("No Button");
        textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
            textRect.top + textRect.height / 2.0f);
        text.setPosition(desktopWidth / 2, desktopHeight / 2);
    }

    void printUI() {
        window.draw(tint);
        window.draw(button);
        window.draw(button2);
        window.draw(button3);
        window.draw(button4);
        window.draw(button5);
        window.draw(text);
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

    void setText(string newText) {
        text.setString(newText);
        textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
            textRect.top + textRect.height / 2.0f);
        text.setPosition(desktopWidth / 2, desktopHeight / 2);
    }

    void clickUI(int button) {

    }
};

class player {
public:
    sf::RectangleShape guy;
    float playerX;
    float playerY;
    float playerH;
    float playerW;
    
    player(float x, float y, float w, float h) {
        playerX = x;
        playerY = y;
        playerW = w;
        playerH = h;
    }

    void move(float x, float y) {
        playerX += x;
        playerY += y;
    }

    void print(sf::RenderWindow& window, float screenX, float screenY) {
        guy.setSize(sf::Vector2f(playerW * block, playerH * block));
        cout << playerX - screenX << " " << playerY - screenY << "\n";
        guy.setPosition((playerX - screenX)*block, (playerY - screenY)*block);
        guy.setFillColor(sf::Color::Blue);
        window.draw(guy);
        cout << guy.getPosition().x / block << " " << guy.getPosition().y / block << "\n";
    }

    sf::Vector2f getLocation() {
        return guy.getPosition();
    }

    sf::Vector2f getSize() {
        return guy.getSize();
    }
};

class rectangleObject {
public:
    sf::RectangleShape shape;
    bool real;
    float objectX;
    float objectY;
    float objectW;
    float objectH;

    rectangleObject() {
        real = false;
    }

    rectangleObject(float x, float y, float width, float height) {
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::Black);

        objectX = x;
        objectY = y;
        objectW = width;
        objectH = height;

        real = true;
    }

    void set(float x, float y, float width, float height) {
        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color::Black);

        objectX = x;
        objectY = y;
        objectW = width;
        objectH = height;

        real = true;
    }

    void print(float screenX, float screenY) {
        shape.setPosition((objectX - screenX) * block, (objectY - screenY) * block);
        shape.setSize(sf::Vector2f(objectW * block, objectH * block));
        shape.setFillColor(sf::Color::Black);
        window.draw(shape);

        cout << objectX - screenX << " " << objectY - screenY << "\n";
    }

    void move(float deltaX, float deltaY) {
        shape.move(deltaX, deltaY);
    }

    void colision(float x, float y, float width, float height){
        if (real == true) {
            float x1 = objectX;
            float x2 = objectX + objectW;
            float y1 = objectY;
            float y2 = objectY + objectH;

            if (y > y1 - height && y < y2 && x < x2 +0.2 ) {
                test[0] = 1;
            }

            if (y > y1 - height && y < y2 && x > x1 - width - 0.2) {
                test[1] = 1;
            }

            if (x > x1 - width && x < x2 && y < y2 + 0.2) {
                test[2] = 1;
            }

            if (x > x1 - width && x < x2 && y > y1 - height - 0.2) {
                test[3] = 1;
            }
        }
        //cout << test[0] << " " << test[2] << " " << test[3] << " " << test[4] << "\n";
        //cout << x + width << " " << y + height << " " << shape.getPosition().x << " " << shape.getPosition().y << "\n";
    }

};

class npc {
public:
    string name;
    string age;
    string gender;
    rectangleObject block;
    float x;
    float y;

    npc(string filename) {
        ifstream file;
        file.open("characters/" + filename + ".txt");
        string startx;
        string starty;
        if (file.is_open()) {
            getline(file, name);
            getline(file, age);
            getline(file, gender);
            getline(file, startx);
            getline(file, starty);
            x = stof(startx);
            y = stof(starty);
            block.set(stof(startx), stof(starty), 100, 100);
            cout << "Character, " + name + ", loaded.";
        }
        else {
            cout << "Character, " + filename + ", failed to load.";
        }
        
    }

    void print() {
        block.print(0,0);
    }

    void move(float deltaX, float deltaY) {
        block.move(deltaX, deltaY);
    }

    void colision(float x, float y, float width, float height) {
        block.colision(x, y, width, height);
    }

    void interaction(float x, float y, float width, float height) {

        interact = false;

        float x1 = block.shape.getPosition().x - 10;
        float x2 = block.shape.getPosition().x + block.shape.getSize().x + 10;
        float y1 = block.shape.getPosition().y - 10;
        float y2 = block.shape.getPosition().y + block.shape.getSize().y + 10;

        cout << x1 << "\n" << x2 << "\n" << y1 << "\n" << y2 << "\n";

        if (y > y1 - height && y < y2 && x == x2) {
            interact = true;
        }

        if (y > y1 - height && y < y2 && x == x1 - width) {
            interact = true;
        }

        if (x > x1 - width && x < x2 && y == y2) {
            interact = true;
        }

        if (x > x1 - width && x < x2 && y == y1 - height) {
            interact = true;
        } 

        if (interact == true) {
            cout << "hello there \n";
        }

    }
};

class boundry {
public:
    vector<rectangleObject> blocks;
    string name;

    boundry(string filename) {
        ifstream file;
        float x;
        float y;
        float width;
        float height;
        rectangleObject temp;
        file.open(filename);
        if (file.is_open()) {
            while (file >> width >> height >> x >> y) {
                temp.set(x, y, width, height);
                blocks.push_back(temp);
            }
        }
        else {
            cout << "file did not open";
        }
    }

    void print(float screenX, float screenY) {
        for (rectangleObject test : blocks) {
            test.print(screenX, screenY);
        }
    }

    void move(int deltaX, int deltaY) {
        for (rectangleObject& test : blocks) {
            test.move(deltaX, deltaY);
        }
    }

    void colision(float x, float y, float width, float height) {
        for (int a = 0; a < 4; a++) {
            test[a] = 0;
        }

        for (rectangleObject temp : blocks) {
            temp.colision(x, y, width, height);
        }

    }
};
