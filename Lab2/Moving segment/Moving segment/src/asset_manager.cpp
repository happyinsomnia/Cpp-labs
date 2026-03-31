#include "asset_manager.hpp"

engine::AssetManager::AssetManager() {}

engine::AssetManager::~AssetManager() {}

void engine::AssetManager::AddTexture(AssetID id, const std::string& filePath, bool wantRepeated)
{
	auto texture = std::make_unique<sf::Texture>();

	if (texture->loadFromFile(filePath))
	{
		texture->setRepeated(wantRepeated);
		m_textures[id] = std::move(texture);
	}
}

void engine::AssetManager::AddFont(AssetID id, const std::string& filePath)
{
	auto font = std::make_unique<sf::Font>();

	if (font->openFromFile(filePath))
	{
		m_fonts[id] = std::move(font);
	}
}

const sf::Texture& engine::AssetManager::GetTexture(AssetID id) const
{
	return *m_textures.at(id);
}

const sf::Font& engine::AssetManager::GetFont(AssetID id) const
{
	return *m_fonts.at(id);
}