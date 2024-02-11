#include "Game.hpp"
#include "SplashState.hpp"

namespace GE
{
    Game::Game(int width, int height, std::string title)
    {
        m_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        m_data->machine.AddState(StateRef(new SplashState(this->m_data)));

        this->Run();
    }

    void Game::Run()
    {
        float check_point_time = this->m_clock.getElapsedTime().asSeconds();
        float current_time = 0;
        float frame_time = 0;
        float interpolation = 0;
        float waiting_time = 0;

        while (this->m_data->window.isOpen())
        {
            this->m_data->machine.ProcessStateChanges();

            current_time = this->m_clock.getElapsedTime().asSeconds();
            frame_time = current_time - check_point_time;
            waiting_time += frame_time;

            if (frame_time > 0.25f)
            {
                frame_time = 0.25f;
            }

            check_point_time = current_time;
            waiting_time += frame_time;

            while (waiting_time >= m_delta)
            {
                this->m_data->machine.GetActiveState()->HandleInput();
                this->m_data->machine.GetActiveState()->Update(m_delta);

                waiting_time -= m_delta;
            }

            interpolation = waiting_time / m_delta;
            this->m_data->machine.GetActiveState()->Draw(interpolation);
        }
    }
}