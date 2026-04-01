#include "main_menu.hpp"
#include <stdexcept>

MainMenu::MainMenu(std::shared_ptr<Context>& context) : m_context(context) {}

MainMenu::~MainMenu() = default;

void MainMenu::Initialize()
{
	if (m_initialize)
		throw std::logic_error("Already initialized");

	m_initialize = true;

	m_context->m_assets->AddFont(AssetID::MAIN_FONT, "assets\\fonts\\Unkempt-Bold.ttf");

	//Title:

	m_gameTitle = std::make_unique<sf::Text>(m_context->m_assets->GetFont(AssetID::MAIN_FONT), "Snake", 100);

	m_gameTitle->setOrigin(sf::Vector2f(m_gameTitle->getLocalBounds().size.x / 2, m_gameTitle->getLocalBounds().size.y / 2));

	m_gameTitle->setPosition(sf::Vector2f(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 - 300.f));

	//Play Button

	m_playButton = std::make_unique<sf::Text>(m_context->m_assets->GetFont(AssetID::MAIN_FONT), "Play", 60);

	m_playButton->setOrigin(sf::Vector2f(m_playButton->getLocalBounds().size.x / 2, m_playButton->getLocalBounds().size.y / 2));

	m_playButton->setPosition(sf::Vector2f(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 - 50.f));

	//Exit Button

	m_exitButton = std::make_unique<sf::Text>(m_context->m_assets->GetFont(AssetID::MAIN_FONT), "Exit", 60);

	m_exitButton->setOrigin(sf::Vector2f(m_exitButton->getLocalBounds().size.x / 2, m_exitButton->getLocalBounds().size.y / 2));

	m_exitButton->setPosition(sf::Vector2f(m_context->m_window->getSize().x / 2, m_context->m_window->getSize().y / 2 + 100.f));
}

void MainMenu::ProcessInput()
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
				if (!m_isPlayButtonSelected)
				{
					m_isPlayButtonSelected = true;
					m_isExitButtonSelected = false;
				}
				break;
			}
			case sf::Keyboard::Key::Down:
			{
				if (!m_isExitButtonSelected)
				{
					m_isExitButtonSelected = true;
					m_isPlayButtonSelected = false;
				}
				break;
			}
			case sf::Keyboard::Key::Enter:
			{
				m_isPlayButtonPressed = false;
				m_isExitButtonPressed = false;

				m_isPlayButtonSelected ? m_isPlayButtonPressed = true : m_isExitButtonPressed = true;
			}
			default:
				break;
			}
		}
	}
}

void MainMenu::Update(sf::Time delTime)
{
	if (m_isPlayButtonSelected)
	{
		m_playButton->setFillColor(sf::Color::Yellow);
		m_exitButton->setFillColor(sf::Color::White); 
	}

	else
	{
		m_exitButton->setFillColor(sf::Color::Yellow);
		m_playButton->setFillColor(sf::Color::White);
	}

	if (m_isPlayButtonPressed)
	{
		//TODO:
		//Go to play State
	}
	if (m_isExitButtonPressed)
		m_context->m_window->close();
}

void MainMenu::Draw()
{
	m_context->m_window->clear();
	m_context->m_window->draw(*m_gameTitle);
	m_context->m_window->draw(*m_playButton);
	m_context->m_window->draw(*m_exitButton);
	m_context->m_window->display();
}