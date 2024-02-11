#include "Pipe.hpp"

namespace GE
{
    Pipe::Pipe(GameDataRef data)
        : m_data(data)
    {
    }

    void Pipe::DrawPipes()
    {
        for (size_t i = 0; i < m_pipeSprites.size(); i++)
        {
            m_data->window.draw(m_pipeSprites.at(i));
        }
    }

    void Pipe::SpawnTopPipe()
    {
        sf::Sprite sprite(m_data->assets.GetTexture("pipe down sprite"));
        sprite.setPosition(m_data->window.getSize().x, 0);
        m_pipeSprites.push_back(sprite);
    }

    void Pipe::SpawnBottomPipe()
    {
        sf::Sprite sprite(m_data->assets.GetTexture("pipe up sprite"));
        sprite.setPosition(
            m_data->window.getSize().x,
            m_data->window.getSize().y - sprite.getGlobalBounds().height);
        m_pipeSprites.push_back(sprite);
    }

    void Pipe::SpawnInvisiblePipe()
    {
        sf::Sprite sprite(m_data->assets.GetTexture("pipe down sprite"));
        sprite.setPosition(
            m_data->window.getSize().x,
            m_data->window.getSize().y - sprite.getGlobalBounds().height);
        sprite.setColor(sf::Color(0, 0, 0, 0));
        m_pipeSprites.push_back(sprite);
    }

    void Pipe::MovePipes(float delta)
    {
        for (size_t i = 0; i < m_pipeSprites.size(); i++)
        {
            sf::Vector2f position = m_pipeSprites.at(i).getPosition();
            float movement = PIPE_MOVEMENT_SPEED * delta;
            
            m_pipeSprites.at(i).move(-movement, 0);
        }
    }
}