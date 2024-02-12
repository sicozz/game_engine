#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"

namespace GE
{
    class Bird
    {
        GameDataRef m_data;
        sf::Clock m_clock;
        sf::Clock m_movementClock;
        sf::Sprite m_birdSprite;
        std::vector<sf::Texture> m_animationFrames;
        size_t m_animationIterator;
        int m_birdState;
        float m_rotation;
    public:
        Bird(GameDataRef data);
        void Draw();
        void Update(float delta);
        void Animate(float delta);
        void Tap();
        const sf::Sprite &GetSprite() const;
    };
}