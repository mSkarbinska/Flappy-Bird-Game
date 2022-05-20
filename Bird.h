//
// Created by mskar on 13/05/2022.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Obstacle.h"

#ifndef SFMLDEMO_BIRD_H
#define SFMLDEMO_BIRD_H


class Bird {
public:
    explicit Bird();

    void reset();

    void fly();

    void update();

    void kill();

    sf::Sprite getBody() const { return body; };

    bool isDead() const { return dead; };

    bool hitsObstacle(const Obstacle& obstacle);

    bool outOfBounds();

    bool onTheGround(){return body.getPosition().y > groundLvl;};

    bool isLocked() const { return locked; };

private:
    float groundLvl = 750.0;
    int levelHeight= 850.0;
    const float fly_rot{ -11.5f };
    const float fall_rot{ 1.0f };
    bool locked = true;
    bool dead = false;
    const float gravity = 0.8;
    const float jumpSpeed = -13.0;
    const sf::Vector2f center = {260, 425};
    sf::Vector2f velocity = {0, 0};
    sf::Texture texture_wing_up;
    sf::Texture texture_wing_down;
    const sf::Vector2f middle = {40, 28};
    sf::Texture texture;
    sf::Sprite body;

};

#endif //SFMLDEMO_BIRD_H
