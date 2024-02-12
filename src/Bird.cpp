#include "Bird.hpp"

namespace GE
{
    Bird::Bird(GameDataRef data)
        : m_data(data)
    {
        m_birdSprite.setTexture(m_data->assets.GetTexture("bird0"));
    }

    void Bird::Draw()
    {
        m_data->window.draw(m_birdSprite);
    }
}