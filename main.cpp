#include <SFML/Graphics.hpp>
#include <iostream>

int main(){
    sf::RenderWindow Window(sf::VideoMode(640, 680, 32), "Flappy Bird");

    const float gravity =0.5;
    float groundHeight = 680;
    int gameOver=0;
    auto velocity(sf::Vector2f(0,0));

    Window.setFramerateLimit(60);

    sf::Text text;
    sf::Font font;

    if (!font.loadFromFile("../FlappyBirdy.ttf"))
    {
        std::exit(-1);
    }

    text.setFont(font);
    text.setString("Game over u loser");
    text.setCharacterSize(100);

    sf::RectangleShape rect(sf::Vector2f(20, 20));
    rect.setPosition(300,0);
    rect.setFillColor(sf::Color::Blue);

    float jumpSpeed = 8.0f;

    while(Window.isOpen()){
        sf::Event Event{};
        while(Window.pollEvent(Event)){
            switch(Event.type){
                case sf::Event::Closed:
                    Window.close();
                    break;
                default: break;
            }
        }
        if(!gameOver) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                velocity.y = -jumpSpeed;

            if ((rect.getPosition().y + rect.getSize().y < groundHeight &&
                 rect.getPosition().y + rect.getSize().y > 0) || velocity.y < 0) {
                velocity.y += gravity;
                rect.move(velocity.x, velocity.y);

                Window.clear(sf::Color(0, 240, 255));
                Window.draw(rect);

            } else {
                rect.setPosition(rect.getPosition().x, groundHeight - rect.getSize().y);
                velocity.y = 0;
                gameOver=1;

            }
        }else{
            Window.clear(sf::Color(111, 11, 0));
            Window.draw(text);
        }
        Window.display();

    }

}