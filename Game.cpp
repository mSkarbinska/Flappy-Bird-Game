//
// Created by mskar on 13/05/2022.
//
#include <sstream>
#include <string>
#include "Game.h"
#include <fstream>
using std::ifstream;
Game::Game() {
    backgroundTexture.loadFromFile("../resources/bck.jpg");
    background.setTexture(backgroundTexture);

    icon.loadFromFile("../resources/Flappy.png");

    window.create(sf::VideoMode(groundWidth, groundHeight, 32), "Flappy Bird",
                            sf::Style::Titlebar | sf::Style::Close);

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    if (!font.loadFromFile("../resources/flappy-bird-font.ttf")){
        std::exit(-1);
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(50);
    scoreText.setPosition(25, 25);

}

void Game::drawGameOverView() {
    window.clear(gameOver.getColor());
    window.draw(gameOver.getText());
    window.draw(gameOver.getText2());
    window.draw(gameOver.getScoreText(score));
    window.draw(gameOver.getBestScoreText(getBestScore()));
}

void Game::mainloop() {
    Bird bird(groundHeight);
    Obstacle obstacle1;
    bool cleared = false;

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
                        score = 0;
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
            saveScore();
            drawGameOverView();

        }else{
            bird.update();

            if(!bird.isLocked()) {
                obstacle1.update();
            }

            if (obstacle1.bottom_obstacle.getPosition().x < bird.getBody().getPosition().x && !cleared) {
                ++score;
                cleared = true;
            }

            std::ostringstream oss;
            oss << score;
            std::string str = oss.str();
            scoreText.setString(str);

            if (obstacle1.bottom_obstacle.getPosition().x < -80){
                obstacle1.reuse();
                cleared = false;
            }


            window.clear(sf::Color(0,0,0));
            window.draw(background);
            window.draw(bird.getBody());
            window.draw(obstacle1.bottom_obstacle);
            window.draw(obstacle1.top_obstacle);
            window.draw(scoreText);

        }

        window.display();
    }
}

int Game::getBestScore() const {
    std::ifstream ff;
    ff.open("highestScore.txt");
    int best;
    ff >> best;
    return best;
}

void Game::saveScore() const {
    int best = getBestScore();

    std::ofstream f;
    f.open("highestScore.txt");

    if(!f.is_open()){
        std::cout<<"Unable to read file";
        return;
    }
    if(score > best){
        f << score;
    }else{
        f << best;
    }

}
