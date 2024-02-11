#include <iostream>
#include <sstream>
#include "SplashState.hpp"
#include "MainMenuState.hpp"

namespace GE
{
    SplashState::SplashState(GameDataRef data)
        : m_data(data)
    {
    }

    void SplashState::Init()
    {
        std::string background_name = "splash state background";
        m_data->assets.LoadTexture(
            background_name,
            SPLASH_SCENE_BACKGROUND_FILEPATH);
        m_background.setTexture(m_data->assets.GetTexture(background_name));
    }

    void SplashState::HandleInput()
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

    void SplashState::Update(float dealta)
    {
        if (m_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            m_data->machine.AddState(StateRef(new MainMenuState(m_data)), true);
        }
    }

    void SplashState::Draw(float delta)
    {
        m_data->window.clear();
        m_data->window.draw(m_background);
        m_data->window.display();
    }
}