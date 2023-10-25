// #include <SFML/Graphics.hpp>
// #include <iostream>

// void loginWindow()
// {
//     extern sf::RenderWindow window;
//     // Create the SFML window
//     sf::RenderWindow window(sf::VideoMode(400, 300), "Login Window");

//     // Create a font for the text input
//     sf::Font font;
//     if (!font.loadFromFile("arial.ttf"))
//     {
//         std::cerr << "Error loading font file" << std::endl;
//         return;
//     }

//     // Create a text input box
//     sf::Text inputText;
//     inputText.setFont(font);
//     inputText.setCharacterSize(20);
//     inputText.setPosition(50, 100);
//     inputText.setFillColor(sf::Color::Black);

//     // Create a submit button
//     sf::RectangleShape submitButton(sf::Vector2f(100, 50));
//     submitButton.setPosition(150, 200);
//     submitButton.setFillColor(sf::Color::Blue);

//     // Create a submit button text
//     sf::Text submitText("Submit", font, 20);
//     submitText.setPosition(165, 210);
//     submitText.setFillColor(sf::Color::White);

//     // Main loop
//     while (window.isOpen())
//     {
//         // Handle events
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             switch (event.type)
//             {
//             case sf::Event::Closed:
//                 window.close();
//                 break;
//             case sf::Event::TextEntered:
//                 // Handle text input
//                 if (event.text.unicode < 128)
//                 {
//                     inputText.setString(inputText.getString() + static_cast<char>(event.text.unicode));
//                 }
//                 break;
//             case sf::Event::MouseButtonPressed:
//                 // Handle submit button
//                 if (submitButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
//                 {
//                     std::cout << "Submitted: " << inputText.getString().toAnsiString() << std::endl;
//                 }
//                 break;
//             }
//         }

//         // Draw objects
//         window.clear(sf::Color::White);
//         window.draw(inputText);
//         window.draw(submitButton);
//         window.draw(submitText);
//         window.display();
//     }
// }
