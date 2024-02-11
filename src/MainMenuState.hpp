#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "State.hpp"
#include "Game.hpp"

namespace GE
{
    class MainMenuState : public State
    {
        GameDataRef m_data;
        sf::Sprite m_background;
        sf::Sprite m_title;
        sf::Sprite m_playButton;
    public:
        MainMenuState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float delta);
        void Draw(float delta);
    };
}