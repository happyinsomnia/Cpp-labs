#pragma once

#include <string>
#include <map>
#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include "enum_asset_id.hpp"

namespace engine
{
	class AssetManager
	{
	private:
		std::map<AssetID, std::unique_ptr<sf::Texture>> m_textures;
		std::map<AssetID, std::unique_ptr<sf::Font>> m_fonts;
	public:
		AssetManager();
		~AssetManager();

		void AddTexture(AssetID id, const std::string& filePath, bool isRepeated = false);
		void AddFont(AssetID id, const std::string& filePath);

		const sf::Texture& GetTexture(AssetID id) const;
		const sf::Font& GetFont(AssetID id) const;
	};
}