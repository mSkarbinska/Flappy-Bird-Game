//
// Created by mskar on 14/05/2022.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameOverView.h"
#include "Game.h"

GameOverView::GameOverView() {
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
    color = sf::Color(111, 11, 0);
}

