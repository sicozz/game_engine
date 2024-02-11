#include "DEFINITIONS.hpp"
#include "Land.hpp"

namespace GE
{
    Land::Land(GameDataRef data)
        : m_data(data)
    {
        std::string land_texture_name = "land";
        sf::Sprite sprite0(m_data->assets.GetTexture(land_texture_name));
        sf::Sprite sprite1(m_data->assets.GetTexture(land_texture_name));

        sprite0.setPosition(
            0,
            m_data->window.getSize().y - sprite0.getGlobalBounds().height);
        sprite1.setPosition(
            sprite0.getGlobalBounds().width,
            m_data->window.getSize().y - sprite1.getGlobalBounds().height);

        m_landSprites.push_back(sprite0);
        m_landSprites.push_back(sprite1);
    }

    void Land::MoveLand(float delta)
    {
        for (size_t i = 0; i < m_landSprites.size(); i++)
        {
            float movement = PIPE_MOVEMENT_SPEED * delta;

            m_landSprites.at(i).move(-movement, 0.0f);

            if (m_landSprites.at(i).getPosition().x < -m_landSprites.at(i).getGlobalBounds().width)
            {
                sf::Vector2f position(
                    m_data->window.getSize().x,
                    m_landSprites.at(i).getPosition().y);

                m_landSprites.at(i).setPosition(position);
            }
        }
    }

    void Land::DrawLand()
    {
        for (size_t i = 0; i < m_landSprites.size(); i++)
        {
            m_data->window.draw(m_landSprites.at(i));
        }
    }
}