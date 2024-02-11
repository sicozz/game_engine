#include <iostream>
#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

namespace GE
{
    GameState::GameState(GameDataRef data)
        : m_data(data)
    {
    }

    void GameState::Init()
    {
        std::string background_name = "game state background";
        m_data->assets.LoadTexture(background_name, GAME_BACKGROUND_FILEPATH);
        m_background.setTexture(m_data->assets.GetTexture(background_name));
    }

    void GameState::HandleInput()
    {
        sf::Event event;

        while (m_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                m_data->window.close();
            }
        }
    }

    void GameState::Update(float dealta)
    {
    }

    void GameState::Draw(float delta)
    {
        m_data->window.clear();
        m_data->window.draw(m_background);
        m_data->window.display();
    }
}