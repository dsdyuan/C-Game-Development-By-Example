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


sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello Game SFML !!!",
sf::Style::Default);
sf::Texture skyTexture;
sf::Sprite skySprite;


void init() {
	skyTexture.loadFromFile("Assets/graphics/sky.png");
	skySprite.setTexture(skyTexture);
}

void draw() {
	window.draw(skySprite);
}


int main()
{

	init();
	while (window.isOpen()) {
		window.clear(sf::Color::Blue);
		draw();
		window.display();
	}

    return 0;
}


