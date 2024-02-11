#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.hpp"

namespace GE
{
    class Land
    {
        GameDataRef m_data;
        std::vector<sf::Sprite> m_landSprites;
    public:
        Land(GameDataRef data);
        void MoveLand(float delta);
        void DrawLand();
    };
}