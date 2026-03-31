#pragma once

#include <SFML/System/Time.hpp>

namespace engine
{
	class State
	{
	public:
		State() {};
		virtual ~State() {};

		virtual void Initialize() = 0;
		virtual void ProcessInput() = 0;
		virtual void Update(sf::Time delTime) = 0;
		virtual void Draw() = 0;

		virtual void Start() {};
		virtual void Pause() {};
	};
}