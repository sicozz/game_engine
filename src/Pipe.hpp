#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.hpp"

namespace GE
{
    class Pipe
    {
        GameDataRef m_data;
        std::vector<sf::Sprite> m_pipeSprites;
    public:
        Pipe(GameDataRef data);
        void DrawPipes();
        void SpawnTopPipe();
        void SpawnBottomPipe();
        void MovePipes(float delta);
    };
}