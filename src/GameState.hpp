#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"

namespace GE
{
    class GameState : public State
    {
        GameDataRef m_data;
        int m_gameState;
        sf::Clock m_clock;
        sf::Sprite m_background;
        Pipe* m_pipe;
        Land* m_land;
        Bird* m_bird;
        Collision m_collision;
    public:
        GameState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float delta);
        void Draw(float delta);
    };
}