#include "main_menu.hpp"
#include <stdexcept>

MainMenu::MainMenu(std::shared_ptr<Context>& context) : m_context(context) {}

MainMenu::~MainMenu() = default;

void MainMenu::Initialize()
{
	if (m_initialize)
		throw std::logic_error("Already initialized");

	m_context->m_assets->AddFont(AssetID::MAIN_FONT, "assets\\fonts\\PlaywriteIE-VariableFont_wght.ttf");
	m_gameTitle->setFont(m_context->m_assets->GetFont(AssetID::MAIN_FONT));
	m_gameTitle->setString("Moving Segment");
}

void MainMenu::ProcessInput()
{
	while (auto event = m_context->m_window->pollEvent())
	{
		if (event->is<sf::Event::Closed>())
			m_context->m_window->close();
	}
}

void MainMenu::Update(sf::Time delTime)
{
}

void MainMenu::Draw()
{
	m_context->m_window->clear();
	m_context->m_window->draw(*m_gameTitle);
	m_context->m_window->display();
}