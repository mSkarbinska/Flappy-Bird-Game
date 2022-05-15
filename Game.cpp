//
// Created by mskar on 13/05/2022.
//

#include "Game.h"

Game::Game() {
    icon.loadFromFile("C:/Users/mskar/CLionProjects/Flappy-Bird-Game/images/Flappy.png");

    window.create(sf::VideoMode(groundWidth, groundHeight, 32), "Flappy Bird",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
    
}

void Game::drawGameOverView() {
    window.clear(gameOver.getColor());
    window.draw(gameOver.getText());
    window.draw(gameOver.getText2());
}

void Game::mainloop() {
    Bird bird(groundHeight);
    Obstacle obstacle1;

    while(window.isOpen()){
        sf::Event Event{};

        while(window.pollEvent(Event)){
            //handle events
            switch(Event.type){
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if(Event.key.code == sf::Keyboard::Space){
                        bird.fly();

                    }else if(Event.key.code == sf::Keyboard::Enter && bird.isDead()){
                        bird.reset();
                        obstacle1.reuse();
                    }
                    break;

                default: break;
            }
        }


        const auto &bird_bounds = bird.getBody().getGlobalBounds();
        if(  bird_bounds.intersects(obstacle1.top_obstacle.getGlobalBounds()) ||
             bird_bounds.intersects(obstacle1.bottom_obstacle.getGlobalBounds())
                )
            bird.kill();


        if(bird.isDead()){
            obstacle1.reset();

            drawGameOverView();
        }else{
            bird.update();

            if(!bird.isLocked()) {
                obstacle1.update();
            }

            if (obstacle1.bottom_obstacle.getPosition().x < bird.getBody().getPosition().x)
                ++score;


            if (obstacle1.bottom_obstacle.getPosition().x < -80){
                obstacle1.reuse();
            }


            window.clear(sf::Color(0, 240, 255));
            window.draw(bird.getBody());
            window.draw(obstacle1.bottom_obstacle);
            window.draw(obstacle1.top_obstacle);
        }

        window.display();
    }
}
