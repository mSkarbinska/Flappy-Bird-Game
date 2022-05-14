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
    explicit Bird(int levelHeight);

    void reset();

    void fly();

    bool isDead() const { return dead; };

    bool isLocked() const { return locked; };

    void update();

    void kill(){this->dead = true;};

    sf::Sprite getBody() const { return body; };

private:
    int levelHeight;
    bool locked = true;
    bool dead = false;
    const float gravity = 0.8;
    const float jumpSpeed = -13.0;
    const sf::Vector2f center = {260, 425};
    sf::Vector2f velocity = {0, 0};
    sf::Texture texture;
    sf::Sprite body;
};

#endif //SFMLDEMO_BIRD_H
