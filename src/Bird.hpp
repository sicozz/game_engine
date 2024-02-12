#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace GE
{
    class Bird
    {
        GameDataRef m_data;
        sf::Sprite m_birdSprite;
    public:
        Bird(GameDataRef data);
        void Draw();
    };
}