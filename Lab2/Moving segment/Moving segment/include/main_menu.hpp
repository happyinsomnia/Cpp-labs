#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>
#include "state.hpp"
#include "game.hpp"

class MainMenu : public engine::State
{
private:
	std::shared_ptr<Context> m_context;

	std::unique_ptr<sf::Text> m_gameTitle;
	std::unique_ptr<sf::Text> m_playButton;
	std::unique_ptr<sf::Text> m_exitButton;

	bool m_isPlayButtonSelected = true;
	bool m_isPlayButtonPressed = false;

	bool m_isExitButtonSelected = false;
	bool m_isExitButtonPressed = false;

	bool m_initialize = false;
public:
	MainMenu(std::shared_ptr<Context>& context);
	~MainMenu();

	void Initialize() override;
	void ProcessInput() override;
	void Update(sf::Time delTime) override;
	void Draw() override;
};