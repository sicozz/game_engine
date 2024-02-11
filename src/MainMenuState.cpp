#include <iostream>
#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"

namespace GE
{
    MainMenuState::MainMenuState(GameDataRef data)
        : m_data(data)
    {
    }

    void MainMenuState::Init()
    {
        std::string background_name = "main menu background";
        std::string game_title_name = "game title";
        std::string play_button_name = "play button";
        sf::Vector2f game_title_position;
        sf::Vector2f play_button_position;

        m_data->assets.LoadTexture(background_name, MAIN_MENU_BACKGROUND_FILEPATH);
        m_background.setTexture(m_data->assets.GetTexture(background_name));

        m_data->assets.LoadTexture(game_title_name, GAME_TITLE_FILEPATH);
        m_title.setTexture(m_data->assets.GetTexture(game_title_name));
        game_title_position = sf::Vector2f(
            (SCREEN_WIDTH / 2) - m_title.getGlobalBounds().width / 2,
            m_title.getGlobalBounds().height / 2);
        m_title.setPosition(game_title_position);

        m_data->assets.LoadTexture(play_button_name, PLAY_BUTTON_FILEPATH);
        m_playButton.setTexture(m_data->assets.GetTexture(play_button_name));
        play_button_position = sf::Vector2f(
            (SCREEN_WIDTH / 2) - m_playButton.getGlobalBounds().width / 2,
            (SCREEN_HEIGHT / 2) - m_playButton.getGlobalBounds().height / 2);
        m_playButton.setPosition(play_button_position);
    }

    void MainMenuState::HandleInput()
    {
        sf::Event event;

        while (m_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                m_data->window.close();
            }

            if (m_data->input.IsSpriteClicked(
                    m_playButton,
                    sf::Mouse::Left,
                    m_data->window))
            {
                m_data->machine.AddState(StateRef(new GameState(m_data)), true);
            }
        }
    }

    void MainMenuState::Update(float dealta)
    {
    }

    void MainMenuState::Draw(float delta)
    {
        m_data->window.clear();
        m_data->window.draw(m_background);
        m_data->window.draw(m_title);
        m_data->window.draw(m_playButton);
        m_data->window.display();
    }
}