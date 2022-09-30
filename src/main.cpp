#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int y_res = 480;
int x_res = 640;
int box_width = 535;
int box_height = 385;
int box_thickness = 5;
int border_top = 48;
int border_left = 52;
int snake_border = 1;

int ycoord(int y) {
    printf("box thickness: %i\nsnake border: %i\nborder top: %i\ny: %i\n", box_thickness, snake_border, border_top, y);
    return y + border_top + box_thickness + snake_border;
}
int xcoord(int x) {
    printf("box thickness: %i\nsnake border: %i\nborder left: %i\nx: %i\n", box_thickness, snake_border, border_left, x);
    return x + border_left + box_thickness + snake_border;
}

void draw_unit(sf::RenderWindow& window, int x, int y);

int setup_screen(sf::RenderWindow& window) {
    sf::RectangleShape background(sf::Vector2f(640, 480));;
    background.setFillColor(sf::Color(96, 102, 2));

    sf::RectangleShape box_top(sf::Vector2f(box_width, box_thickness));
    box_top.setFillColor(sf::Color(0, 0, 0));
    box_top.setPosition(border_left, border_top);

    sf::RectangleShape box_left(sf::Vector2f(box_height, box_thickness));
    box_left.setFillColor(sf::Color(0, 0, 0));
    // because the way it handles setting position is stupid.. probably has something to do with rotation
    box_left.setPosition(border_left + 5, border_top);
    box_left.rotate(90);

    sf::RectangleShape box_bottom(sf::Vector2f(box_width, box_thickness));
    box_bottom.setFillColor(sf::Color(0, 0, 0));
    box_bottom.setPosition(border_left, (border_top + box_height) - box_thickness);


    sf::RectangleShape box_right(sf::Vector2f(box_height, box_thickness));
    box_right.rotate(90);
    box_right.setFillColor(sf::Color(0, 0, 0));
    box_right.setPosition(border_left + box_width, border_top);

    window.clear();
    window.draw(background);
    window.draw(box_top);
    window.draw(box_bottom);
    window.draw(box_left);
    window.draw(box_right);
    draw_unit(window, 0, 0);
    window.display();
    return 0;
}
void draw_unit(sf::RenderWindow& window, int x, int y) {
    x = xcoord(x);
    y = ycoord(y);
    sf::RectangleShape unit(sf::Vector2f(24, 24));
    unit.setPosition(x, y);
    unit.setFillColor(sf::Color(0, 0, 0));
    window.draw(unit);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Snake Game");
    setup_screen(window);


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
        window.display();
    }
    return 0;
}
