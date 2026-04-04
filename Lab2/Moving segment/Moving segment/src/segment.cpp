#include "segment.hpp"

namespace segment
{
	Segment::Segment() : m_body(std::list<sf::RectangleShape>(4))
	{
		m_head = --m_body.end();
		m_tail = m_body.begin();
	}

	Segment::~Segment() = default;

	void Segment::Initialize(const sf::RectangleShape& shape)
	{
		float x = 16.f;
		for (auto& piece : m_body)
		{
			piece = shape;
			piece.setPosition({ x,16.f });
			x += 16.f;
		}
	}

	void Segment::Move(const sf::Vector2f& direction)
	{
		m_tail->setPosition(m_head->getPosition() + direction);
		m_head = m_tail;

		++m_tail;

		if (m_tail == m_body.end())
		{
			m_tail = m_body.begin();
		}
	}

	void Segment::Grow(const sf::Vector2f& direction)
	{}

	void Segment::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto& piece : m_body)
		{
			target.draw(piece);
		}
	}
}