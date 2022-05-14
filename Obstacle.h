//
// Created by mskar on 14/05/2022.
//

#ifndef SFMLDEMO_OBSTACLE_H
#define SFMLDEMO_OBSTACLE_H


#include <SFML/Graphics.hpp>

class Obstacle
{
public:
    sf::Texture texture;
    sf::Sprite bottom_obstacle;
    sf::Sprite top_obstacle;
    sf::Vector2f velocity;

    Obstacle();

    void update();
    void reuse();
    void reset();

};

#endif //SFMLDEMO_OBSTACLE_H
