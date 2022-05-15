//
// Created by mskar on 14/05/2022.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <sstream>
#include "GameOverView.h"
#include "Game.h"

GameOverView::GameOverView() {
    if (!font.loadFromFile("../resources/FlappyBirdy.ttf"))
    {
        std::exit(-1);
    }
    if (!font2.loadFromFile("../resources/flappy-bird-font.ttf"))
    {
        std::exit(-1);
    }

    text.setFont(font);
    text2.setFont(font);
    text.setString("Game over u loser");
    text2.setString("Press Enter to play again \n\n        Your score \n\n\n\n        Best score");
    text.setCharacterSize(100);
    text2.setCharacterSize(50);
    text.setPosition(62, 80);
    text2.setPosition(127, 200);
    color = sf::Color(111, 11, 0);
}

sf::Text GameOverView::getScoreText(int i) {
    std::ostringstream oss;
    oss << i;
    std::string str = oss.str();
    scoreText.setString(str);
    scoreText.setFont(font2);
    scoreText.setCharacterSize(35);
    scoreText.setPosition(284 , 350);
    return scoreText;
}

sf::Text GameOverView::getBestScoreText(int i) {
    std::ostringstream oss;
    oss << i;
    std::string str = oss.str();
    bestScoreText.setString(str);
    bestScoreText.setFont(font2);
    bestScoreText.setCharacterSize(35);
    bestScoreText.setPosition(260    , 500);
    return bestScoreText;
}


