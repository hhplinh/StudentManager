#include <SFML/Graphics.hpp>

void runStudentManager()
{
    // Create a window with the size of 800x600 pixels
    sf::RenderWindow window(sf::VideoMode(800, 600), "Student Manager");

    // Create a font object to be used for text rendering
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // handle font loading error
        return;
    }

    // Create a text object for the title
    sf::Text title("Student Manager", font, 36);
    title.setPosition(100, 50);

    // Create a text box for the student's name
    sf::RectangleShape nameBox(sf::Vector2f(300, 40));
    nameBox.setPosition(100, 150);
    sf::Text nameLabel("Name:", font, 24);
    nameLabel.setPosition(100, 120);
    sf::Text nameText("", font, 24);
    nameText.setPosition(110, 155);

    // Create a button to add a new student
    sf::RectangleShape addButton(sf::Vector2f(100, 50));
    addButton.setPosition(100, 220);
    sf::Text addButtonText("Add", font, 24);
    addButtonText.setPosition(130, 230);

    // Create a list of students
    sf::RectangleShape studentList(sf::Vector2f(400, 300));
    studentList.setPosition(300, 150);

    // Main loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::TextEntered)
            {
                // Handle typing in the name box
                if (event.text.unicode < 128)
                {
                    nameText.setString(nameText.getString() + static_cast<char>(event.text.unicode));
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                // Handle button clicks
                if (addButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    // TODO: Add new student to list
                }
            }
        }

        // Clear the window
        window.clear(sf::Color::White);

        // Draw the GUI elements
        window.draw(title);
        window.draw(nameBox);
        window.draw(nameLabel);
        window.draw(nameText);
        window.draw(addButton);
        window.draw(addButtonText);
        window.draw(studentList);

        // Display the window
        window.display();
    }
}