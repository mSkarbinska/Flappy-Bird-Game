//
// Created by mskar on 13/05/2022.
//

#include "Bird.h"

Bird::Bird(int levelHeight) {
    if (!texture.loadFromFile("../resources/Flappy.png"))
        throw std::runtime_error("Failed to load image.");

    this->levelHeight = levelHeight;
    body.setTexture(texture);
    body.setOrigin(middle);
    body.scale(sf::Vector2f(1.2f, 1.2f));

    body.setPosition(center);
}

void Bird::update() {
    if (!locked) {
        if (body.getPosition().y + texture.getSize().y < levelHeight &&
            body.getPosition().y + texture.getSize().y >= 0) {
            velocity.y += gravity;

            if(velocity.y<0){
                body.setRotation(fly_rot);
            }else{
                body.rotate(fall_rot);
            }

            if(!onTheGround())body.move(velocity);
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
    velocity.x =0;
    this->dead = true;
}


bool Bird::hitsObstacle(const Obstacle& obstacle) {
    const auto &bird_bounds = body.getGlobalBounds();

    return bird_bounds.intersects(obstacle.top_obstacle.getGlobalBounds()) ||
           bird_bounds.intersects(obstacle.bottom_obstacle.getGlobalBounds());
}

 void Bird::bump() {
    velocity.y+=3*gravity;
    fall_rot =2*fall_rot;
    fly();
    update();
}
