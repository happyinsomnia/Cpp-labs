#pragma once

#include <memory>
#include "state.hpp"
#include"segment.hpp"
#include "context.hpp"
#include <SFML/Graphics/Sprite.hpp>

class GamePlay : public engine::State
{
private:
	std::shared_ptr<Context> m_context;
	std::unique_ptr<sf::Sprite> m_grass;
	
	segment::Segment m_segment;

	sf::Vector2f m_segmentDirection;

	sf::Time m_elapsedTime;
	
public:
	GamePlay(std::shared_ptr<Context>& context);
	~GamePlay();

	void Initialize() override;
	void ProcessInput() override;
	void Update(sf::Time delTime) override;
	void Draw() override;
	void Start() override;
	void Pause() override;
};