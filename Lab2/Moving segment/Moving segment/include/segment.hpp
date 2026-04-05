#pragma once

#include<SFML/Graphics/Sprite.hpp>
#include<SFML/Graphics/Texture.hpp>
#include<SFML/Graphics/Drawable.hpp>
#include<SFML/Graphics/RenderTarget.hpp>
#include<SFML/Graphics/RenderStates.hpp>
#include<SFML/Graphics/RectangleShape.hpp>
#include <list>

namespace segment
{
	class Segment : public sf::Drawable
	{
	private:
		std::list<sf::RectangleShape> m_body;
		std::list<sf::RectangleShape>::iterator m_head;
		std::list<sf::RectangleShape>::iterator m_tail;

	public:

		Segment();
		~Segment();

		void Initialize(const sf::RectangleShape& shape);
		void Move(const sf::Vector2f& direction, const sf::Vector2u& windowSize);
		void Grow(const sf::Vector2f& direction);
		void Shrink();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}