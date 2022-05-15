//
// Created by mskar on 14/05/2022.
//

#ifndef SFMLDEMO_GAMEOVERVIEW_H
#define SFMLDEMO_GAMEOVERVIEW_H


#include <SFML/Graphics/Text.hpp>

class GameOverView {
public:
    GameOverView();
    sf::Text getText(){return text;};
    sf::Text getText2(){return text2;};
    sf::Color getColor(){return color;};
    sf::Text getScoreText(int i);
    sf::Text getBestScoreText(int i);

private:
    sf::Text text;
    sf::Text text2;
    sf::Font font;
    sf::Font font2;
    sf::Text bestScoreText;
    sf::Text scoreText;
    sf::Color color;
};


#endif //SFMLDEMO_GAMEOVERVIEW_H
