#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace GE
{
    struct GameData
    {
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game
    {
        const float m_delta = 1.0f / 60.0f;
        sf::Clock m_clock;
        GameDataRef m_data = std::make_shared<GameData>();

        void Run();
    public:
        Game(int width, int height, std::string title);
    };
}