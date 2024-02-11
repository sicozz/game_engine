#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "DEFINITIONS.hpp"
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
        void SpawnInvisiblePipe();
        void MovePipes(float delta);
    };
}