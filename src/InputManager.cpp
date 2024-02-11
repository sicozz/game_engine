#include "InputManager.hpp"

namespace GE
{
    bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
    {
        if (sf::Mouse::isButtonPressed(button))
        {
            sf::Vector2f objectPosition = object.getPosition();
            sf::FloatRect objectGlobalBounds = object.getGlobalBounds();
            sf::IntRect rect(
                objectPosition.x,
                objectPosition.y,
                objectGlobalBounds.width,
                objectGlobalBounds.height);

            if (rect.contains(sf::Mouse::getPosition(window)))
            {
                return true;
            }
        }

        return false;
    }

    sf::Vector2i GetMousePosition(sf::RenderWindow &window)
    {
        return sf::Mouse::getPosition(window);
    }
}