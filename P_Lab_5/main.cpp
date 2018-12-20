#include <iostream>
#include <cstdlib>
#include <utility>
#include <SFML/Graphics.hpp>
#include "dru_lib_body.h"
#include "map_game.h"
using namespace std;

int main()
{
    //minimap MAP;
    sf::RenderWindow window(sf::VideoMode(1360, 640), "Game");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::White);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
