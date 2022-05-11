#include <SFML/Graphics.hpp>
#include <iostream>

int main(){
    float groundHeight = 850;
    float groundWidth = 600;

    sf::RenderWindow Window(sf::VideoMode((int)groundWidth, (int)groundHeight, 32), "Flappy Bird",
            sf::Style::Titlebar | sf::Style::Close);

    float gravity =0;

    auto velocity(sf::Vector2f(0,0));

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

    sf::RectangleShape rect(sf::Vector2f(20, 20));
    rect.setPosition(280,400);
    rect.setFillColor(sf::Color::Blue);

    float jumpSpeed = 8.0f;

    while(Window.isOpen()){
        sf::Event Event{};

        while(Window.pollEvent(Event)){
            switch(Event.type){
                case sf::Event::Closed:
                    Window.close();
                    break;

                case sf::Event::KeyPressed:
                    if(Event.key.code == sf::Keyboard::Space){
                        velocity.y = -jumpSpeed;
                        //set gravity after first press
                        gravity = 0.5;
                    }

                    break;

                default: break;
            }
        }

            if ((rect.getPosition().y + rect.getSize().y < groundHeight &&
                 rect.getPosition().y - rect.getSize().y >= 0) || velocity.y < 0) {

                velocity.y += gravity;
                rect.move(velocity.x, velocity.y);

                Window.clear(sf::Color(0, 240, 255));
                Window.draw(rect);
                Window.display();
            } else {
                while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                    Window.clear(sf::Color(111, 11, 0));
                    Window.draw(text);
                    Window.draw(text2);
                    Window.display();
                }
                velocity.y = 0;
                gravity = 0;
                rect.setPosition(300,400);
            }

    }

}