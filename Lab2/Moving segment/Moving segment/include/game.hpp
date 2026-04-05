#pragma once

#include <memory>

#include "context.hpp"

class Game
{
private:
	std::shared_ptr<Context> m_context;
	const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

public:

	Game();
	~Game();

	void Run();
};