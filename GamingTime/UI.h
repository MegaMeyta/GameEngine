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

class boundry {
public:
    sf::RectangleShape wall;
    ifstream file;
    string fileName;

    void create(string name) {
        fileName = name;
    }

    void print(int offsetx, int offsety) {
        
        file.open(fileName);
        if (file.is_open()) {
            int end = 0;
            float width;
            float height;
            float x;
            float y;
            while (file >> width >> height >> x >> y) {
                    
                    wall.setSize(sf::Vector2f(width, height));
                    wall.setPosition(x + offsetx, y + offsety);
                    wall.setFillColor(sf::Color::Black);
                    window.draw(wall);
            }
            file.close();
        }

        else {
            cout << "file did not open";
        }
    }

    bool colision(float x, float y, float width, float height, int face) {

        float wallW;
        float wallH;
        float wallX;
        float wallY;
        int count = 0;
        file.open(fileName);
        if (file.is_open()) {
            while (file >> wallW >> wallH >> wallX >> wallY || count < 5) {
                
                float x1 = wallX ;
                float x2 = wallX + wallW;
                float y1 = wallY;
                float y2 = wallY + wallH;

                if (face == 1) {
                    if (y > y1 - height && y < y2 && x == x2) {
                        
                        cout << "stop left\n"; 
                        return true;
                        

                    }
                }

                if (face == 2) {
                    if (y > y1 - height && y < y2 && x == x1 - width) {
                        cout << "stop right\n";
                        return true;
                        

                    }
                }

                if (face == 3) {
                    if (x > x1 - width && x < x2 && y == y2) {
                        cout << "stop up\n";
                        return true;
                        
                    }
                }

                if (face == 4) {
                    if (x > x1 - width && x < x2 && y == y1 - height) {
                        cout << "stop down\n";
                        return true;
                        
                    }
                }

                count++;
            }
            file.close();
            return false;
        }
    }

    void testcolision(float x, float y, float width, float height, int offsetx, int offsety) {
        for (int a = 0; a < 4; a++) {
            test[a] = 0;
        }
        float wallW;
        float wallH;
        float wallX;
        float wallY;
        int count = 0;
        file.open(fileName);
        if (file.is_open()) {
            while (file >> wallW >> wallH >> wallX >> wallY || count < 5) {

                float x1 = wallX + offsetx;
                float x2 = wallX + wallW + offsetx;
                float y1 = wallY + offsety;
                float y2 = wallY + wallH + offsety;
               
                if (y > y1 - height && y < y2 && x == x2) {
                    test[0] = 1;
                }
                               
                if (y > y1 - height && y < y2 && x == x1 - width) {
                    test[1] = 1;
                }
               
                if (x > x1 - width && x < x2 && y == y2) {
                    test[2] = 1;
                }
                
                if (x > x1 - width && x < x2 && y == y1 - height) {
                    test[3] = 1;
                }
               

                count++;
            }
            file.close();
            
        }
    }
};

class player {
public:
    sf::RectangleShape guy;

    void create(sf::Vector2f position, int height, int width) {
        guy.setSize(sf::Vector2f(height, width));
        guy.setFillColor(sf::Color::Blue);
        guy.setPosition(position);
    }

    void movebox(int x, int y) {
        guy.move(x, y);
    }

    void print(sf::RenderWindow& window) {
        window.draw(guy);
    }

    sf::Vector2f getLocation() {
        return guy.getPosition();
    }

    sf::Vector2f getSize() {
        return guy.getSize();
    }
};

