#pragma once

#include <map>

#include <SFML/Graphics.hpp>

namespace GE
{
    class AssetManager
    {
        std::map<std::string, sf::Texture> m_textures;
        std::map<std::string, sf::Font> m_fonts;
    public:
        AssetManager() {}
        ~AssetManager() {}
        void LoadTexture(std::string name, std::string filename);
        sf::Texture &GetTexture(std::string name);
        void LoadFont(std::string name, std::string filename);
        sf::Font &GetFont(std::string name);
    };
}