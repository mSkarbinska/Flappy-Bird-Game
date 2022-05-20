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

    bool isDead() const { return dead; };

    bool hitsObstacle( Obstacle& obstacle) const;

    bool outOfBounds() const;

    bool onTheGround(){return body.getPosition().y > groundLvl;};

    bool isLocked() const { return locked; };

    sf::Sprite getBody() const { return body; };

private:
    sf::Texture texture;
    sf::Sprite body;
    sf::Vector2f velocity = {0, 0};
    bool dead = false;
    bool locked = true;
    float groundLvl = 750.0;
    float levelHeight= 850.0;
    const float fly_rot{ -11.5f };
    const float fall_rot{ 1.0f };
    const float gravity = 0.8;
    const float jumpSpeed = -13.0;
    const sf::Vector2f center = {260, 425};
    const sf::Vector2f middleOfBody = {40, 28};
};

#endif //SFMLDEMO_BIRD_H
