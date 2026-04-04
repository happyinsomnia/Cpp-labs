#include "game_play.hpp"
#include <SFML/Window/Keyboard.hpp>

GamePlay::GamePlay(std::shared_ptr<Context>& context) : m_context(context), m_segmentDirection({ 16.f,0.f }) {}

GamePlay::~GamePlay() = default;

void GamePlay::Initialize()
{
	m_context->m_assets->AddTexture(AssetID::GAME_TEXTURE, "assets\\textures\\green_square.png", true);

	m_grass = std::make_unique<sf::Sprite>(m_context->m_assets->GetTexture(AssetID::GAME_TEXTURE),
		m_context->m_window->getViewport(m_context->m_window->getDefaultView()));

	m_segment.Initialize(sf::RectangleShape({ 16,16 }));
}
void GamePlay::ProcessInput()
{
	while (auto event = m_context->m_window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			m_context->m_window->close();

		else if (const auto& keyEvent = event->getIf<sf::Event::KeyPressed>())
		{
			switch (keyEvent->code)
			{
			case sf::Keyboard::Key::Up:
			{
				m_segmentDirection = { 0.f, -16.f };
				break;
			}

			case sf::Keyboard::Key::Down:
			{
				m_segmentDirection = { 0.f, 16.f };
				break;
			}

			case sf::Keyboard::Key::Left:
			{
				m_segmentDirection = { -16.f, 0.f };
				break;
			}

			case sf::Keyboard::Key::Right:
			{
				m_segmentDirection = { 16.f, 0.f };
				break;
			}

			default:
				break;
			}
		}
	}
}
void GamePlay::Update(sf::Time delTime)
{
	m_elapsedTime += delTime;

	if (m_elapsedTime.asSeconds() > 10)
	{
		m_segment.Move(m_segmentDirection);
		m_elapsedTime = sf::Time::Zero;
	}
}
void GamePlay::Draw()
{
	m_context->m_window->clear();
	m_context->m_window->draw(*m_grass);
	m_context->m_window->draw(m_segment);
	m_context->m_window->display();
}
void GamePlay::Start()
{}
void GamePlay::Pause()
{}