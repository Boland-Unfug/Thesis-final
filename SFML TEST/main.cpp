#include <SFML/Graphics.hpp>

int main() {
    // Create a window with the same pixel depth as the desktop
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Main loop that continues until we close the window
    while (window.isOpen()) {
        // Event processing
        sf::Event event;
        while (window.pollEvent(event)) {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the whole window before rendering a new frame
        window.clear();

        // Draw your sprites and other shapes here

        // End the current frame and display its contents on screen
        window.display();
    }
    return 0;
}
