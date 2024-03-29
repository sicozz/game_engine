#include "DEFINITIONS.hpp"
#include "Pipe.hpp"

namespace GE
{
    Pipe::Pipe(GameDataRef data)
        : m_data(data)
    {
        m_landHeight = m_data->assets.GetTexture("land").getSize().y;
        m_pipeSpawnYOffset = 0;
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
        sprite.setPosition(m_data->window.getSize().x, -m_pipeSpawnYOffset);
        m_pipeSprites.push_back(sprite);
    }

    void Pipe::SpawnBottomPipe()
    {
        sf::Sprite sprite(m_data->assets.GetTexture("pipe up sprite"));
        sprite.setPosition(
            m_data->window.getSize().x,
            m_data->window.getSize().y - sprite.getGlobalBounds().height - m_pipeSpawnYOffset);
        m_pipeSprites.push_back(sprite);
    }

    void Pipe::MovePipes(float delta)
    {
        for (size_t i = 0; i < m_pipeSprites.size(); i++)
        {
            if (m_pipeSprites.at(i).getPosition().x < -m_pipeSprites.at(i).getGlobalBounds().width)
            {
                m_pipeSprites.erase(m_pipeSprites.begin() + i);
            }
            else
            {
                float movement = PIPE_MOVEMENT_SPEED * delta;

                m_pipeSprites.at(i).move(-movement, 0);
            }
        }
    }

    void Pipe::RandomizePipeOffset()
    {
        m_pipeSpawnYOffset = rand() % (m_landHeight + 1);
    }

    const std::vector<sf::Sprite> &Pipe::GetSprites() const
    {
        return m_pipeSprites;
    }
}