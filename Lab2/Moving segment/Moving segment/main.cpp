#include<SFML/Graphics.hpp>


int main()
{
	setlocale(LC_ALL, "rus");
	sf::RenderWindow window(sf::VideoMode({200,200}), "SFML works");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);
	
	while (window.isOpen())
	{
		
		while (auto event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear(sf::Color::Black);
		window.draw(shape);
		window.display();
	}
	return 0;
}