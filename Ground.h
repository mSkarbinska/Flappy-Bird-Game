//
// Created by mskar on 20/05/2022.
//

#ifndef SFMLDEMO_GROUND_H
#define SFMLDEMO_GROUND_H


#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Ground {
public:
    Ground();
    sf::Sprite getGround(){return ground;};
    void updateGround();
    void setMoveVelocity(){velocity=moveVelocity;};
    void stopGround(){velocity=initVelocity;};
    void moveGround(){ground.move(this->velocity);};

private:
    float groundLevel=750.0;
    int groundHeight = 850;
    int groundWidth = 600;
    sf::Texture texture;
    sf::Sprite ground;
    sf::Vector2f velocity=initVelocity;
    sf::Vector2f moveVelocity={-3.5,0};
    sf::Vector2f initVelocity={0,0};
};


#endif //SFMLDEMO_GROUND_H
