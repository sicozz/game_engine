#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace GE
{
    class GameState : public State
    {
        GameDataRef m_data;
        sf::Sprite m_background;
    public:
        GameState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float delta);
        void Draw(float delta);
    };
}