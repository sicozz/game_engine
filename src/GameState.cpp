#include <iostream>
#include <sstream>
#include "DEFINITIONS.hpp"
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
        std::string land_name = "land";
        std::string bird0_name = "bird0";
        std::string bird1_name = "bird1";
        std::string bird2_name = "bird2";
        std::string bird3_name = "bird3";

        m_data->assets.LoadTexture(background_name, GAME_BACKGROUND_FILEPATH);
        m_data->assets.LoadTexture(pipe_up_name, PIPE_UP_FILEPATH);
        m_data->assets.LoadTexture(pipe_down_name, PIPE_DOWN_FILEPATH);
        m_data->assets.LoadTexture(land_name, LAND_FILEPATH);
        m_data->assets.LoadTexture(bird0_name, BIRD_FRAME_0_FILEPATH);
        m_data->assets.LoadTexture(bird1_name, BIRD_FRAME_1_FILEPATH);
        m_data->assets.LoadTexture(bird2_name, BIRD_FRAME_2_FILEPATH);
        m_data->assets.LoadTexture(bird3_name, BIRD_FRAME_3_FILEPATH);

        m_background.setTexture(m_data->assets.GetTexture(background_name));
        m_pipe = new Pipe(m_data);
        m_land = new Land(m_data);
        m_bird = new Bird(m_data);
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
                m_bird->Tap();
            }
        }
    }

    void GameState::Update(float delta)
    {
        m_pipe->MovePipes(delta);
        m_land->MoveLand(delta);

        if (m_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
        {
                m_pipe->RandomizePipeOffset();
                m_pipe->SpawnTopPipe();
                m_pipe->SpawnBottomPipe();

                m_clock.restart();
        }

        m_bird->Animate(delta);
        m_bird->Update(delta);
    }

    void GameState::Draw(float delta)
    {
        m_data->window.clear();
        m_data->window.draw(m_background);
        m_pipe->DrawPipes();
        m_land->DrawLand();
        m_bird->Draw();
        m_data->window.display();
    }
}