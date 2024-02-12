#pragma once

#include <SFML/Graphics.hpp>

namespace GE
{
    class Collision
    {
    public:
        Collision();
        bool CheckSpriteCollision(sf::Sprite spriteA, sf::Sprite spriteB);
        bool CheckSpriteCollision(
            sf::Sprite spriteA,
            sf::Sprite spriteB,
            float scaleX,
            float scaleY);
    };
}