//
// Created by mskar on 13/05/2022.
//

#ifndef SFMLDEMO_GAME_H
#define SFMLDEMO_GAME_H


#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include "GameOverView.h"
#include "Bird.h"

class Game {
public:
    Game();
    void drawGameOverView();
    int getGroundHeight()const {return groundHeight;};
    void mainloop();
private:
    int groundHeight = 850;
    int groundWidth = 600;
    int score = 0;
    sf::Image icon;
    sf::RenderWindow window;
    GameOverView gameOver;
};


#endif //SFMLDEMO_GAME_H
