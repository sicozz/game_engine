#include <iostream>
#include <sstream>
#include "GameState.hpp"

namespace GE
{
    GameState::GameState(GameDataRef data)
        : m_data(data)
    {
    }

    void GameState::Init()
    {
        std::string background_name = "game state background";
        std::string pipe_up_name = "pipe up sprite";
        std::string pipe_down_name = "pipe down sprite";

        m_data->assets.LoadTexture(background_name, GAME_BACKGROUND_FILEPATH);
        m_data->assets.LoadTexture(pipe_up_name, PIPE_UP_FILEPATH);
        m_data->assets.LoadTexture(pipe_down_name, PIPE_DOWN_FILEPATH);

        m_background.setTexture(m_data->assets.GetTexture(background_name));
        m_pipe = new Pipe(m_data);
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

            if (m_data->input.IsSpriteClicked(
                    m_background,
                    sf::Mouse::Left,
                    m_data->window))
            {
                m_pipe->SpawnTopPipe();
                m_pipe->SpawnBottomPipe();
                m_pipe->SpawnInvisiblePipe();
            }
        }
    }

    void GameState::Update(float delta)
    {
        m_pipe->MovePipes(delta);
    }

    void GameState::Draw(float delta)
    {
        m_data->window.clear();
        m_data->window.draw(m_background);
        m_pipe->DrawPipes();
        m_data->window.display();
    }
}