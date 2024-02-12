#include "Collision.hpp"

namespace GE
{
    Collision::Collision()
    {

    }

    bool Collision::CheckSpriteCollision(sf::Sprite spriteA, sf::Sprite spriteB)
    {
        sf::Rect<float> rectA = spriteA.getGlobalBounds();
        sf::Rect<float> rectB = spriteB.getGlobalBounds();

        if (rectA.intersects(rectB))
        {
            return true;
        }
        return false;
    }

    bool Collision::CheckSpriteCollision(
        sf::Sprite spriteA,
        sf::Sprite spriteB,
        float scaleX,
        float scaleY)
    {
        spriteA.setScale(scaleX, scaleY);
        spriteB.setScale(scaleX, scaleY);
        sf::Rect<float> rectA = spriteA.getGlobalBounds();
        sf::Rect<float> rectB = spriteB.getGlobalBounds();

        if (rectA.intersects(rectB))
        {
            return true;
        }
        return false;
    }
}