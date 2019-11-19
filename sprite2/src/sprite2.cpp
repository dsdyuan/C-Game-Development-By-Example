#include <SFML/Graphics.hpp>    //留意自身OS环境和目录。


sf::Vector2f viewSize(1024, 768);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello SFML Game !!!", sf::Style::Default);

sf::Vector2f playerPosition;
bool playerMoving = false;
bool playerDir = false;

sf::Texture skyTexture;
sf::Sprite skySprite;

sf::Texture bgTexture;
sf::Sprite bgSprite;

sf::Texture heroTexture;
sf::Sprite heroSprite;


void init() {


	skyTexture.loadFromFile("Assets/graphics/sky.png");
	skySprite.setTexture(skyTexture);

	bgTexture.loadFromFile("Assets/graphics/bg.png");
	bgSprite.setTexture(bgTexture);

	heroTexture.loadFromFile("Assets/graphics/hero.png");
	heroSprite.setTexture(heroTexture);
	heroSprite.setPosition(sf::Vector2f(viewSize.x / 2, viewSize.y / 2));
	heroSprite.setOrigin(heroTexture.getSize().x / 2, heroTexture.getSize().y / 2);


}


void updateInput() {

	sf::Event event;

	// while there are pending events...
	while (window.pollEvent(event)) {

		//printf(" polling events \n");

		if (event.type == sf::Event::KeyPressed) {

			if (event.key.code == sf::Keyboard::Right) {

				playerMoving = true;
				playerDir = true;
			}
		}

		if (event.type == sf::Event::KeyReleased) {

			if (event.key.code == sf::Keyboard::Right) {

				playerMoving = false;
				playerDir = false;
			}

		}

		if (event.type == sf::Event::KeyPressed) {

			if (event.key.code == sf::Keyboard::Left) {

				playerMoving = true;
				playerDir = false;
			}
		}

		if (event.type == sf::Event::KeyReleased) {

			if (event.key.code == sf::Keyboard::Left) {

				playerMoving = false;
				playerDir = false;
			}

		}


		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
			window.close();


	}

}


void update(float dt) {


	if (playerMoving) {
		if(playerDir){

			heroSprite.move(100.0f * dt, 0);
		}
		else
		{
			heroSprite.move(-100.0f * dt, 0);

		}
	}

}

void draw() {


	window.draw(skySprite);
	window.draw(bgSprite);

	window.draw(heroSprite);

}



int main() {

	sf::Clock clock;

	init();

	while (window.isOpen()) {

		updateInput();

		sf::Time dt = clock.restart();
		update(dt.asSeconds());


		window.clear(sf::Color::Blue);

		draw();

		window.display();

	}

	return 0;
}
