/*
 * Main.cpp
 *
 *  Created on: Nov 18, 2019
 *      Author: yuanhong
 */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

int main()
{
	sf::Vector2f viewSize(1024,768);
	sf::VideoMode vm(viewSize.x,viewSize.y);
	sf::RenderWindow window(vm,"Hello SFMLGame",sf::Style::Default);


	sf::RectangleShape rect(sf::Vector2f(500.0f, 300.0f));
	rect.setFillColor(sf::Color::Yellow);
	rect.setPosition(viewSize.x / 2, viewSize.y / 2);
	rect.setOrigin(sf::Vector2f(rect.getSize().x / 2,
	rect.getSize().y / 2));

    while(window.isOpen()){
    	window.clear(sf::Color::Red);
    	window.draw(rect);
    	window.display();
    }
    return 0;
}


