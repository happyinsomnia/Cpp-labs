#pragma once

#include <memory>
#include "state_manager.hpp"
#include "asset_manager.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

struct Context
{
	std::unique_ptr<engine::AssetManager> m_assets = std::make_unique<engine::AssetManager>();
	std::unique_ptr<engine::StateManager> m_states = std::make_unique<engine::StateManager>();
	std::unique_ptr<sf::RenderWindow> m_window = std::make_unique<sf::RenderWindow>();
};