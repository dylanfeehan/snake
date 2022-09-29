#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Snake Game");
    sf::RectangleShape background(sf::Vector2f(200, 100));;
    background.setFillColor(sf::Color(96, 102, 2));


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
        window.display();
    }
    return 0;
}
