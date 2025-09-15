#include "GameWindow.h"
#include <iostream>

GameWindow::GameWindow(const sf::VideoMode& mode, std::string header) : window(mode, header)
{
   window.handleEvents(keyboardBindings);
}

void GameWindow::Run()
{
    sf::SoundBuffer soundBuffer("sound.mp3");
    sf::Sound sound(soundBuffer);

    sf::Texture sphere("sphere.png");
    sphere.setSmooth(true);

    const sf::Vector2f imageSize = sf::Vector2f(sphere.getSize());
    const sf::Vector2f winSize = sf::Vector2f(window.getSize());
    const sf::Vector2f sprintScale = { winSize.x / imageSize.x, winSize.y / imageSize.y };

    sf::Sprite sprite(sphere);
    sprite.setScale(sprintScale);

    const auto onCloseLambda = [&](const sf::Event::Closed&)
    {
        window.close();
    };

    const auto keyPressedLambda = [&](const sf::Event::KeyPressed& keyPressedEvent)
    {
        std::cout << "the escape key was pressed" << std::endl;
        std::cout << "scancode: " << static_cast<int>(keyPressedEvent.scancode) << std::endl;
        std::cout << "code: " << static_cast<int>(keyPressedEvent.code) << std::endl;
        std::cout << "control: " << keyPressedEvent.control << std::endl;
        std::cout << "alt: " << keyPressedEvent.alt << std::endl;
        std::cout << "shift: " << keyPressedEvent.shift << std::endl;
        std::cout << "system: " << keyPressedEvent.system << std::endl;
        std::cout << "description: " << sf::Keyboard::getDescription(keyPressedEvent.scancode).toAnsiString() << std::endl;
        std::cout << "localize: " << static_cast<int>(sf::Keyboard::localize(keyPressedEvent.scancode)) << std::endl;
        std::cout << "delocalize: " << static_cast<int>(sf::Keyboard::delocalize(keyPressedEvent.code)) << std::endl;

        if (keyPressedEvent.scancode == sf::Keyboard::Scancode::Enter)
        {
            sound.play();
        }
    };

    while (window.isOpen())
    {
        window.handleEvents(onCloseLambda, keyPressedLambda);

        window.clear();
        window.draw(sprite);
        window.display();
    }
}
