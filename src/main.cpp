#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Snake Game");
    sf::RectangleShape background(sf::Vector2f(640, 480));;
    background.setFillColor(sf::Color(96, 102, 2));

    sf::RectangleShape square(sf::Vector2f(25, 25));
    square.setFillColor(sf::Color(0, 0, 0));

    sf::RectangleShape box_top(sf::Vector2f(200, 5));
    box_top.setFillColor(sf::Color(0, 0, 0));
    box_top.setPosition(10, 10);
    sf::RectangleShape box_bottom(sf::Vector2f(205, 5));
    box_bottom.setFillColor(sf::Color(0, 0, 0));
    box_bottom.setPosition(5, 210);
    sf::RectangleShape box_left(sf::Vector2f(200, 5));
    box_left.rotate(90);
    box_left.setFillColor(sf::Color(0, 0, 0));
    box_left.setPosition(10, 10);
    sf::RectangleShape box_right(sf::Vector2f(200, 5));
    box_right.rotate(90);
    box_right.setFillColor(sf::Color(0, 0, 0));
    box_right.setPosition(210, 10);



    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            if(event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        window.clear();
        window.draw(background);
        window.draw(box_top);
        window.draw(box_bottom);
        window.draw(box_left);
        window.draw(box_right);
        window.display();
    }
    return 0;
}
