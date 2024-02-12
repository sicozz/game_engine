#include "DEFINITIONS.hpp"
#include "Bird.hpp"

namespace GE
{
    Bird::Bird(GameDataRef data)
        : m_data(data)
    {
        m_animationIterator = 0;
        m_animationFrames.push_back(m_data->assets.GetTexture("bird0"));
        m_animationFrames.push_back(m_data->assets.GetTexture("bird1"));
        m_animationFrames.push_back(m_data->assets.GetTexture("bird2"));
        m_animationFrames.push_back(m_data->assets.GetTexture("bird3"));
        m_birdSprite.setTexture(m_animationFrames.at(m_animationIterator));
        m_birdSprite.setPosition(
            (m_data->window.getSize().x / 4) - (m_birdSprite.getGlobalBounds().width / 2),
            (m_data->window.getSize().y / 2) - (m_birdSprite.getGlobalBounds().height / 2));

        m_birdState = BIRD_STATE_STILL;
        sf::Vector2f origin = sf::Vector2f(
            m_birdSprite.getGlobalBounds().width / 2,
            m_birdSprite.getGlobalBounds().height / 2);

        m_birdSprite.setOrigin(origin);
        m_rotation = 0;
    }

    void Bird::Draw()
    {
        m_data->window.draw(m_birdSprite);
    }

    void Bird::Update(float delta)
    {
        if (BIRD_STATE_FALLING == m_birdState)
        {
            m_birdSprite.move(0, GRAVITY * delta);
            m_rotation += ROTATION_SPEED * delta;
            if (m_rotation > 25.0f)
            {
                m_rotation = 25.0f;
            }
            m_birdSprite.setRotation(m_rotation);
        }
        else if (BIRD_STATE_FLYING == m_birdState)
        {
            m_birdSprite.move(0, -FLYING_SPEED * delta);
            m_rotation -= ROTATION_SPEED * delta;
            if (m_rotation < -25.0f)
            {
                m_rotation = -25.0f;
            }
            m_birdSprite.setRotation(m_rotation);
        }

        if (m_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION)
        {
            m_movementClock.restart();
            m_birdState = BIRD_STATE_FALLING;
        }
    }

    void Bird::Animate(float delta)
    {
        if (m_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / m_animationFrames.size())
        {
            if (m_animationIterator < m_animationFrames.size() - 1)
            {
                m_animationIterator++;
            }
            else
            {
                m_animationIterator = 0;
            }

            m_birdSprite.setTexture(m_animationFrames.at(m_animationIterator));
            m_clock.restart();
        }
    }

    void Bird::Tap()
    {
        m_movementClock.restart();
        m_birdState = BIRD_STATE_FLYING;
    }
}