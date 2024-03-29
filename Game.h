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
#include "Ground.h"

class Game {
public:
    Game();
    void drawGameOverView();
    void mainloop();
    void drawGameView();
    void saveScore() const;
    int getBestScore() const;
    void updateScoreText();
private:
    float groundLevel=750.0;
    int groundHeight = 850;
    int groundWidth = 600;
    int score = 0;
    Bird bird;
    Obstacle obstacle1;
    sf::Image icon;
    sf::RenderWindow window;
    GameOverView gameOver;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Text scoreText;
    sf::Font font;
    sf::Vector2f groundVelocity={-3.5,0};
    Ground ground;


};


#endif //SFMLDEMO_GAME_H
