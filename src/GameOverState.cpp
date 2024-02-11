#include <iostream>
#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"

namespace GE
{
    GameOverState::GameOverState(GameDataRef data)
        : m_data(data)
    {
    }

    void GameOverState::Init()
    {
        std::string background_name = "game over state background";
        m_data->assets.LoadTexture(background_name, GAME_OVER_BACKGROUND_FILEPATH);
        m_background.setTexture(m_data->assets.GetTexture(background_name));
    }

    void GameOverState::HandleInput()
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

    void GameOverState::Update(float dealta)
    {
    }

    void GameOverState::Draw(float delta)
    {
        m_data->window.clear();
        m_data->window.draw(m_background);
        m_data->window.display();
    }
}