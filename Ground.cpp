//
// Created by mskar on 20/05/2022.
//

#include "Ground.h"

Ground::Ground() {
    texture.loadFromFile("../resources/ground.png");
    ground.setTexture(texture);
    ground.setScale(2.5,2.5);
    ground.setPosition(0, groundLevel);
}

void Ground::updateGround() {
    if ((ground.getPosition().x + texture.getSize().x*0.71) < 0) {
        ground.setPosition(0, 750);
    }
}

