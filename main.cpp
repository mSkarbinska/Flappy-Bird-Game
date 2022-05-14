#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bird.h"

int main(){
    int groundHeight = 850;
    int groundWidth = 600;
    sf::RenderWindow Window(sf::VideoMode(groundWidth, groundHeight, 32), "Flappy Bird",
            sf::Style::Titlebar | sf::Style::Close);

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
                    }
                    break;

                default: break;
            }
        }


        if(bird.isDead()){
            //game over view
            Window.clear(sf::Color(111, 11, 0));
            Window.draw(text);
            Window.draw(text2);
        }else{
            bird.update();

            Window.clear(sf::Color(0, 240, 255));
            Window.draw(bird.getBody());
        }
        Window.display();
    }
}