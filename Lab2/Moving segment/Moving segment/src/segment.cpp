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

	void Segment::Move(const sf::Vector2f& direction, const sf::Vector2u& windowSize)
	{
		if (m_head->getPosition().x < 0)
		{
			m_tail->setPosition({ windowSize.x - 0.f , m_head->getPosition().y });
			m_head = m_tail;
		}

		else if (m_head->getPosition().x > windowSize.x)
		{
			m_tail->setPosition({ 0.f, m_head->getPosition().y });
			m_head = m_tail;
		}

		if (m_head->getPosition().y < 0)
		{
			m_tail->setPosition({ m_head->getPosition().x, windowSize.y - 0.f });
			m_head = m_tail;
		}

		else if (m_head->getPosition().y > windowSize.y)
		{
			m_tail->setPosition({ m_head->getPosition().x, 0.f });
			m_head = m_tail;
		}

		m_tail->setPosition(m_head->getPosition() + direction);
		m_head = m_tail;

		++m_tail;

		if (m_tail == m_body.end())
		{
			m_tail = m_body.begin();
		}
	}

	void Segment::Grow(const sf::Vector2f& direction)
	{
		sf::RectangleShape newPiece = *m_body.begin();

		newPiece.setPosition(m_head->getPosition() + direction);

		m_head = m_body.insert(++m_head, newPiece);
	}

	void Segment::Shrink()
	{
		if (m_body.size() < 5)
			return;

		m_body.erase(m_tail++);

		if (m_tail == m_body.end())
		{
			m_tail = m_body.begin();
		}
	}

	void Segment::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto& piece : m_body)
		{
			target.draw(piece);
		}
	}
}