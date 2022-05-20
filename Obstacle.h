//
// Created by mskar on 14/05/2022.
//

#ifndef SFMLDEMO_OBSTACLE_H
#define SFMLDEMO_OBSTACLE_H

#include <algorithm>
#include <random>
#include <SFML/Graphics.hpp>

class Obstacle
{
public:
    Obstacle();

    void update();
    void reuse();
    void reset();
    void setTopObstacle();
    void setBottomObstacle();
    void setMoveVelocity() {this->velocity = moveVelocity;};
    void setInitVelocity() {this->velocity = initVelocity;};
    sf::Sprite getBottomObstacle() {return bottomObstacle;};
    sf::Sprite getTopObstacle() {return topObstacle;};

private:
    std::random_device rd;
    sf::Texture texture;
    sf::Sprite bottomObstacle;
    sf::Sprite topObstacle;
    sf::Vector2f initVelocity = { 0,0 };
    sf::Vector2f moveVelocity = { -3.5,0 };
    sf::Vector2f velocity = { -3.5,0 };
    sf::Vector2f bottomObstacleInitPosition = {700 , 450};
    sf::Vector2f gap = {0, 250};
};

#endif //SFMLDEMO_OBSTACLE_H
