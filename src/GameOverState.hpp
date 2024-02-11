#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "State.hpp"
#include "Game.hpp"

namespace GE
{
    class GameOverState : public State
    {
        GameDataRef m_data;
        sf::Sprite m_background;
    public:
        GameOverState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float delta);
        void Draw(float delta);
    };
}