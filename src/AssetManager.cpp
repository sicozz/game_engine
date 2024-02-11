#include "AssetManager.hpp"

namespace GE
{
    void AssetManager::LoadTexture(std::string name, std::string filename)
    {
        sf::Texture texture;

        if (texture.loadFromFile(filename))
        {
            this->m_textures[name] = texture;
        }
    }

    sf::Texture &AssetManager::GetTexture(std::string name)
    {
        return this->m_textures.at(name);
    }

    void AssetManager::LoadFont(std::string name, std::string filename)
    {
        sf::Font font;

        if (font.loadFromFile(filename))
        {
            this->m_fonts[name] = font;
        }
    }

    sf::Font &AssetManager::GetFont(std::string name)
    {
        return this->m_fonts.at(name);
    }
}