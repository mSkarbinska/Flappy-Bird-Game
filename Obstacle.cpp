//
// Created by mskar on 14/05/2022.
//

#include "Obstacle.h"

Obstacle::Obstacle(int id){
    velocity = { -3.0,0 };
    this->id = id;

    if (!texture.loadFromFile("C:/Users/mskar/CLionProjects/Flappy-Bird-Game/images/obstacle.png"))
        throw std::runtime_error("Failed to load image\n");

    bottom_obstacle.setTexture(texture);
    bottom_obstacle.scale(sf::Vector2f(1.7f, 1.7f));
    bottom_obstacle.setPosition(400 * id + 400, 450);

    top_obstacle = bottom_obstacle;
    top_obstacle.rotate(180);

    const auto&  bottom_position = bottom_obstacle.getPosition();
    top_obstacle.setPosition(bottom_position.x+75, bottom_position.y - 250);

}

void Obstacle::update(){
    bottom_obstacle.move(velocity);
    auto bottom_position = bottom_obstacle.getPosition();
    top_obstacle.setPosition(bottom_position.x + 75, bottom_position.y - 250);

}

void Obstacle::reuse(){
    velocity = { -3.0,0 };
    const auto new_pos = rand() % 400 + 300;
    bottom_obstacle.setPosition(400 * id + 400, (float)new_pos);
    const auto& bottom_position = bottom_obstacle.getPosition();
    top_obstacle.setPosition(bottom_position.x+75, bottom_position.y - 250);

}

void Obstacle::reset() {
    velocity = { 0,0 };
    bottom_obstacle.setPosition(400 * id + 400, 450);
    const auto&  bottom_position = bottom_obstacle.getPosition();
    top_obstacle.setPosition(bottom_position.x+75, bottom_position.y - 250);
}
