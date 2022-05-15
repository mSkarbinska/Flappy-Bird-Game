//
// Created by mskar on 13/05/2022.
//

#include "Bird.h"

Bird::Bird(int levelHeight) {
    if (!texture.loadFromFile("C:/Users/mskar/CLionProjects/Flappy-Bird-Game/images/Flappy.png"))
        throw std::runtime_error("Failed to load image.");

    this->levelHeight = levelHeight;
    body.setTexture(texture);
    body.scale(sf::Vector2f(1.2f, 1.2f));

    body.setPosition(center);
}

void Bird::update() {
    if (!locked) {
        if (body.getPosition().y + texture.getSize().y < levelHeight &&
            body.getPosition().y + texture.getSize().y >= 0) {
            velocity.y += gravity;
            body.move(velocity);
        } else {
            dead = true;
            locked = true;
        }
    }
}

void Bird::fly() {
    locked = false;
    velocity.y = jumpSpeed;
}

void Bird::reset() {
    locked = true;
    dead = false;
    body.setPosition(center);
}

