#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>
#include "state.hpp"
#include "game.hpp"

class MainMenu : public engine::State
{
private:
	std::shared_ptr<Context> m_context;
	std::unique_ptr<sf::Text> m_gameTitle = std::make_unique<sf::Text>();
	bool m_initialize = false;
public:
	MainMenu(std::shared_ptr<Context>& context);
	~MainMenu();

	void Initialize() override;
	void ProcessInput() override;
	void Update(sf::Time delTime) override;
	void Draw() override;
};