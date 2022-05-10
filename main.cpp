#include "SFML/Graphics.hpp"

int main(int argc, char ** argv){
    sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");

    sf::Event event;

    sf::CircleShape circleShape(200);
    circleShape.setFillColor(sf::Color::Blue);

    while (renderWindow.isOpen()){
        while (renderWindow.pollEvent(event)){
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();
        }

        renderWindow.clear();
        renderWindow.draw(circleShape);
        renderWindow.display();
    }}