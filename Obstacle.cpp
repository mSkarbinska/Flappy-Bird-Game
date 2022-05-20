//
// Created by mskar on 14/05/2022.
//

#include "Obstacle.h"

Obstacle::Obstacle(){
    if (!texture.loadFromFile("../resources/obstacle.png"))
        throw std::runtime_error("Failed to load image\n");

    setBottomObstacle();
    setTopObstacle();
}

void Obstacle::update(){
    bottomObstacle.move(velocity);
    topObstacle.setPosition(bottomObstacle.getPosition() - gap);
}

void Obstacle::reuse(){
    velocity = moveVelocity;
    const auto new_pos = rd() % 400 + 300;
    bottomObstacle.setPosition(bottomObstacleInitPosition.x , (float)new_pos);
    topObstacle.setPosition(bottomObstacle.getPosition()-gap);
}

void Obstacle::reset() {
    velocity = initVelocity;
    bottomObstacle.setPosition(bottomObstacleInitPosition);
    topObstacle.setPosition(bottomObstacleInitPosition-gap);
}

void Obstacle::setTopObstacle() {
    topObstacle = bottomObstacle;
    topObstacle.scale(1, -1);
    topObstacle.setPosition(bottomObstacleInitPosition-gap);
}

void Obstacle::setBottomObstacle() {
    bottomObstacle.setTexture(texture);
    bottomObstacle.scale(sf::Vector2f(1.7f, 1.7f));
    bottomObstacle.setPosition(bottomObstacleInitPosition);

}
