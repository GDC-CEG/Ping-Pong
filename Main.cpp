#include <iostream>

#include "SFML\Graphics.hpp"
#include "PingPong.h"

int main()
{
    // create the window to show your game 
    sf::RenderWindow *window;

    window=new sf::RenderWindow(sf::VideoMode(600, 600),"My window");
    window->setFramerateLimit(20);
    
    //Initialise the game objects
    init_players();

    // run the program as long as the window is open
    while (window->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
        }


        handle_input();

        update();

        perform_ai();

        // clear the window with black color
        window->clear(sf::Color::White);
	    
        // draw everything here...
        display(window);

        // end the current frame
        window->display();
    }

    return 0;
}

