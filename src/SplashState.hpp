#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace GE
{
    class SplashState : public State
    {
        GameDataRef m_data;
        sf::Clock m_clock;
        sf::Sprite m_background;
    public:
        SplashState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float delta);
        void Draw(float delta);
    };
}