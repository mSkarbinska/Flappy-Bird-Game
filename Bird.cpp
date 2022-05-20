//
// Created by mskar on 13/05/2022.
//

#include "Bird.h"

Bird::Bird() {
    if (!texture.loadFromFile("../resources/Flappy.png"))
        throw std::runtime_error("Failed to load image.");

    body.setTexture(texture);
    body.setOrigin(middleOfBody);
    body.scale(sf::Vector2f(1.2f, 1.2f));
    body.setPosition(center);
}

void Bird::update() {
    if (!locked) {
        if (!onTheGround() && !outOfBounds()) {
            velocity.y += gravity;

            if(velocity.y<0)
                body.setRotation(fly_rot);
            else
                body.rotate(fall_rot);

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
    body.setRotation(0);
    body.setPosition(center);
}

void Bird::kill() {
    velocity.x = 0;
    dead = true;
}

bool Bird::hitsObstacle( Obstacle& obstacle) const {
    const auto &bird_bounds = body.getGlobalBounds();

    return bird_bounds.intersects(obstacle.getTopObstacle().getGlobalBounds()) ||
           bird_bounds.intersects(obstacle.getBottomObstacle().getGlobalBounds());
}

bool Bird::outOfBounds() const {
    return body.getPosition().x < 0 || body.getPosition().y < 0;
}
