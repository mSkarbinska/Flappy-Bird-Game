#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bird.h"
#include "Obstacle.h"

int main(){
    int groundHeight = 850;
    int groundWidth = 600;
    int score = 0;

    sf::Image icon;
    icon.loadFromFile("C:/Users/mskar/CLionProjects/Flappy-Bird-Game/images/Flappy.png");

    sf::RenderWindow Window(sf::VideoMode(groundWidth, groundHeight, 32), "Flappy Bird",
            sf::Style::Titlebar | sf::Style::Close);

    Window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    Window.setFramerateLimit(60);
    Window.setKeyRepeatEnabled(false);

    sf::Text text;
    sf::Text text2;
    sf::Font font;

    if (!font.loadFromFile("../FlappyBirdy.ttf"))
    {
        std::exit(-1);
    }

    text.setFont(font);
    text2.setFont(font);
    text.setString("Game over u loser");
    text2.setString("Press Enter to play again");
    text.setCharacterSize(100);
    text2.setCharacterSize(50);
    text.setPosition(60, 80);
    text2.setPosition(125, 200);

    Bird bird(groundHeight);
    Obstacle obstacle1;

    while(Window.isOpen()){
        sf::Event Event{};

        while(Window.pollEvent(Event)){
            //handle events
            switch(Event.type){
                case sf::Event::Closed:
                    Window.close();
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
            //game over view
            obstacle1.reset();

            Window.clear(sf::Color(111, 11, 0));
            Window.draw(text);
            Window.draw(text2);
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


            Window.clear(sf::Color(0, 240, 255));
            Window.draw(bird.getBody());
            Window.draw(obstacle1.bottom_obstacle);
            Window.draw(obstacle1.top_obstacle);
        }

        Window.display();
    }
}