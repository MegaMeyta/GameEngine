/*This header file contains most of the objects used to create the game level and character*/
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>
#include <fstream>
#include "global.h"
#include <cmath>

using namespace std;

int test[4];

/// <summary>
/// Compares two doubles
/// </summary>
/// <param name="x">number being compared</param>
/// <param name="y">number being compared</param>
/// <param name="epsilon">maximum difference</param>
/// <returns>whether or not the two doubles are within the given difference</returns>
bool compareDouble(double x, double y, double epsilon){
    if (abs(x - y) < epsilon) {
        return true;
    }
    
    return false;
}

void popUpMenu(int amount) {

}

/// <summary>
/// The pause menu
/// </summary>
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
        button.setSize(sf::Vector2f(resolutionX / 5, resolutionY / 8));
        button2.setSize(sf::Vector2f(resolutionX / 5, resolutionY / 8));
        button3.setSize(sf::Vector2f(resolutionX / 5, resolutionY / 8));
        button4.setSize(sf::Vector2f(resolutionX / 5, resolutionY / 8));
        button5.setSize(sf::Vector2f(resolutionX / 5, resolutionY / 8));
        tint.setSize(sf::Vector2f(resolutionX, resolutionY));

        //POSITION
        button.setPosition(0, (resolutionY / 8) * 7);
        button2.setPosition(1 * (resolutionX / 5), (resolutionY / 8) * 7);
        button3.setPosition(2 * (resolutionX / 5), (resolutionY / 8) * 7);
        button4.setPosition(3 * (resolutionX / 5), (resolutionY / 8) * 7);
        button5.setPosition(4 * (resolutionX / 5), (resolutionY / 8) * 7);

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
        text.setPosition(resolutionX / 2, resolutionY / 2);
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

    /// <summary>
    /// Resizes the UI
    /// </summary>
    /// <param name="x">the x scale</param>
    /// <param name="y">the y scale</param>
    void resizeUI(float x, float y) {
        
        button.setScale(x,y);
        button2.setScale(x, y);
        button3.setScale(x, y);
        button4.setScale(x, y);
        button5.setScale(x, y);
        button.setPosition(0, (resolutionY / 8) * 7 * y);
        button2.setPosition(1 * (resolutionX / 5) * x, (resolutionY / 8) * 7 * y);
        button3.setPosition(2 * (resolutionX / 5) * x, (resolutionY / 8) * 7 * y);
        button4.setPosition(3 * (resolutionX / 5) * x, (resolutionY / 8) * 7 * y);
        button5.setPosition(4 * (resolutionX / 5) * x, (resolutionY / 8) * 7 * y);
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
        text.setPosition(resolutionX / 2, resolutionY / 2);
    }

    void clickUI(int button) {

    }
};

/// <summary>
/// The object that handles the parameters for the player
/// </summary>
class player {
public:
    sf::RectangleShape guy;
    double playerX;
    double playerY;
    double playerH;
    double playerW;
    
    /// <summary>
    /// The constructor
    /// </summary>
    /// <param name="x">position on x axis</param>
    /// <param name="y">position on y axis</param>
    /// <param name="w">width based on grid squares</param>
    /// <param name="h">height based on grid squares</param>
    player(double x, double y, double w, double h) {
        playerX = x;
        playerY = y;
        playerW = w;
        playerH = h;
    }

    /// <summary>
    /// Moves the player
    /// </summary>
    /// <param name="x">how far the player moves in the x direction</param>
    /// <param name="y">how far the player moves in the y direction</param>
    void move(double x, double y) {
        playerX += x;
        playerY += y;
    }

    /// <summary>
    /// draws the player on the window
    /// </summary>
    /// <param name="window">the window to be drawn on</param>
    /// <param name="screenX">screen x position on the grid </param>
    /// <param name="screenY">screen y position on the grid</param>
    void print(sf::RenderWindow& window, double screenX, double screenY) {
        guy.setSize(sf::Vector2f(playerW * block, playerH * block));
        guy.setPosition((playerX - screenX)*block, (playerY - screenY)*block);
        guy.setFillColor(sf::Color::Blue);
        window.draw(guy);
    }

    /// <summary>
    /// Gets player location
    /// </summary>
    /// <returns>vector containing player x and y location</returns>
    sf::Vector2f getLocation() {
        return guy.getPosition();
    }

    /// <summary>
    /// gets player size
    /// </summary>
    /// <returns>vector containing player width and height</returns>
    sf::Vector2f getSize() {
        return guy.getSize();
    }
};

/// <summary>
/// a basic rectangle object and functions to manipulate it
/// </summary>
class rectangleObject {
public:
    
    bool real;
    double objectX;
    double objectY;
    double objectW;
    double objectH;

    /// <summary>
    /// Creates a blank rectangle object
    /// </summary>
    rectangleObject() {
        real = false;
        objectX = 0;
        objectY = 0;
        objectW = 0;
        objectH = 0;
    }

    /// <summary>
    /// Creates a rectangle object with the given parameters
    /// </summary>
    /// <param name="x">x position</param>
    /// <param name="y">y position</param>
    /// <param name="width">rectangle width</param>
    /// <param name="height">rectangle height</param>
    /// <param name="type">whether the object can be collided with</param>
    rectangleObject(double x, double y, double width, double height, bool type) {
        objectX = x;
        objectY = y;
        objectW = width;
        objectH = height;

        real = type;
    }

    /// <summary>
    /// Resets or sets the parameters of a already created rectangle object
    /// </summary>
    /// <param name="x">x position</param>
    /// <param name="y">y position</param>
    /// <param name="width">rectangle width</param>
    /// <param name="height">rectangle height</param>
    /// <param name="type">whether the object can be collided with</param>
    void set(double x, double y, double width, double height, bool type) {
        objectX = x;
        objectY = y;
        objectW = width;
        objectH = height;

        real = type;
    }

    /// <summary>
    /// draws the rectangle object on the screen after translating grid co-ordinates to pixel coordinates
    /// </summary>
    /// <param name="screenX">x position of screen on the grid</param>
    /// <param name="screenY">y position of screen on the grid</param>
    void print(double screenX, double screenY) {
        sf::RectangleShape shape;
        shape.setPosition((objectX - screenX) * block, (objectY - screenY) * block);
        shape.setSize(sf::Vector2f(objectW * block, objectH * block));
        shape.setFillColor(sf::Color::Black);
        window.draw(shape);
    }

    /// <summary>
    /// calculates collision of player and rectangle and records collision direction in 1x4 array
    /// </summary>
    /// <param name="x">player x position</param>
    /// <param name="y">player y position</param>
    /// <param name="width">player width</param>
    /// <param name="height">player height</param>
    void colision(double x, double y, double width, double height) {
        if (real == true) {
            double x1 = objectX;
            double x2 = objectX + objectW;
            double y1 = objectY;
            double y2 = objectY + objectH;

            if (y + height >= y1 && y <= y2 && x <= x2 && x >= x2 - (objectW / 4)) {
                test[0] = 1;
            }

            if (y > y1 - height && y < y2 && x <= x1 + (objectW / 4) && x + width >= x1) {
                test[1] = 1;
            }

            if (x > x1 - width && x < x2 && y <= y2 && y >= y2 - (objectH / 4)) {
                test[2] = 1;
            }

            if (x > x1 - width && x < x2 && y <= y1 + (objectH / 4) && y + height >= y1) {
                test[3] = 1;
            }
        }
    }

};

/*class npc {
public:
    string name;
    string age;
    string gender;
    rectangleObject block;
    double x;
    double objectHeight;
    double objectWidth;
    double y;

    npc(string filename) {
        ifstream file;
        file.open("characters/" + filename + ".txt");
        string startx;
        string starty;
        string temp;
        if (file.is_open()) {
            getline(file, name);
            getline(file, age);
            getline(file, gender);
            getline(file, temp);
            x = stof(temp);
            getline(file, temp);
            y = stof(temp);
            getline(file, temp);
            objectWidth = stof(temp);
            getline(file, temp);
            objectHeight = stof(temp);
            y = stof(starty);
            block.set(stof(startx), stof(starty), 100, 100);
            cout << "Character, " + name + ", loaded.";
        }
        else {
            cout << "Character, " + filename + ", failed to load.";
            x = 0;
            y = 0;
        }
        
    }

    void print() {
        block.print(0,0);
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
};*/

/// <summary>
/// class that will handle interactable objects in the level
/// </summary>
class interactable {
public:
    string name;
    rectangleObject block;
    double x;
    double objectHeight;
    double objectWidth;
    double y;
    //This integer changes the behavior of an object
    //1: A floor object (must be within bounds to interact and no colision)
    //2: A normal object (must be against object to interact and has colisions)
    //3: A wall object (must be against object to interact with and no colision)
    int type;

    /// <summary>
    /// Constructs the interactable based on the file specified
    /// </summary>
    /// <param name="filename">the file that contains the data for the interactable</param>
    interactable(string filename) {
        ifstream file;
        string temp;
        file.open(filename);
        if (file.is_open()) {
            getline(file, name);
            getline(file, temp);
            x = stod(temp);
            getline(file, temp);
            y = stod(temp);
            getline(file, temp);
            objectWidth = stod(temp);
            getline(file, temp);
            objectHeight = stod(temp);
            getline(file, temp);
            type = stoi(temp);
            if (type == 2) {
                block.set(x, y, objectWidth, objectHeight, true);
            }
            else {
                block.set(x, y, objectWidth, objectHeight, false);
            }
            cout << name << " " << x << " " << y << " " << objectWidth << " " << objectHeight << " " << type << "\n";
        }
        else {
            cout << "File Doesn't Exist\n";
        }
    }

    /// <summary>
    /// draws the interactable
    /// </summary>
    /// <param name="screenX">screen x position</param>
    /// <param name="screenY">screen y position</param>
    void print(double screenX, double screenY) {
        block.print(screenX, screenY);
    }

    /// <summary>
    /// runs the function for object collision
    /// </summary>
    /// <param name="x">player x position</param>
    /// <param name="y">player y positon</param>
    /// <param name="width">player width</param>
    /// <param name="height">player height</param>
    void colision(double x, double y, double width, double height) {
        block.colision(x, y, width, height);
    }
};

/// <summary>
/// The boundaries for the level
/// </summary>
class boundry {
public:
    vector<rectangleObject> blocks;
    string name;

    boundry(string filename) {
        ifstream file;
        double x;
        double y;
        double width;
        double height;
        rectangleObject temp;
        file.open(filename);
        if (file.is_open()) {
            while (file >> width >> height >> x >> y) {
                temp.set(x, y, width, height, true);
                blocks.push_back(temp);
            }
        }
        else {
            cout << "file did not open";
        }
    }

    void print(double screenX, double screenY) {
        for (rectangleObject test : blocks) {
            test.print(screenX, screenY);
        }
    }

    void colision(double x, double y, double width, double height) {
        for (int a = 0; a < 4; a++) {
            test[a] = 0;
        }

        for (rectangleObject temp : blocks) {
            temp.colision(x, y, width, height);
        }

    }
};
