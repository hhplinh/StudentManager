// #include <SFML/Graphics.hpp>
#include <StudentManager.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>
#include <Password.hpp>
#include <CoursesTable.hpp>
#include <StudentWindow.hpp>

class Circle : public sf::Drawable
{
public:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        sf::Sprite sprite(Texture.getTexture());
        target.draw(sprite, states);
    }

    Circle()
    {
        circle_.setRadius(50.0f);
        Texture.create(200, 200);
        Texture.draw(circle_);
    }

private:
    sf::RenderTexture Texture;
    sf::CircleShape circle_;
    sf::Text text;
};

// Windows
// extern List<Backend::Course *> list;
sf::Image icon;

int main()
{
	Backend::loadData();
	
    // Initialize Window
    window.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height * 93 / 100),
                  "Student Manager",
                  sf::Style::Default ^ sf::Style::Resize);
    window.setPosition(sf::Vector2i(0, 0));
    window.setFramerateLimit(60);

    LeftWindowWidth = (window.getSize().x * 4) / 5;
    RightWindowWidth = window.getSize().x - LeftWindowWidth;
    BackgroundColor = sf::Color::White;

    icon.loadFromFile("../resources/Logo/Exe's Logo.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load Data

    if (!Backend::loadData()) std::cerr << "Fail";

    // Load Fonts
    LoadFonts(RegularFont, BoldFont, MediumFont, LightFont, HeavyFont);

    // Test

    // LogIn LogInWindow;
    LogInWindow.create();

    // Student Window
    StudentScreen.create();

    // Admin Window
    AdminScreen.create();

    // Staff Window
    StaffScreen.create();

    ///////////////////////////////////////////////////////////////////////////////////////

    while (window.isOpen())
    {
        sf::Mouse mouse;
        sf::Vector2i MousePos = mouse.getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
            if (!LogInWindow.isHidden())
                LogInWindow.processEvent(event);
            if (!StudentScreen.isHidden())
                StudentScreen.processEvent(event);
            if (!AdminScreen.isHidden())
                AdminScreen.processEvent(event);
            if (!StaffScreen.isHidden())
                StaffScreen.processEvent(event);
        }
        // if (TestWindow.mouseOn(MousePos))
        // {
        //     cursor.loadFromSystem(sf::Cursor::Text);
        //     window.setMouseCursor(cursor);
        // }
        // else
        // {
        //     cursor.loadFromSystem(sf::Cursor::Arrow);
        //     window.setMouseCursor(cursor);
        // }
        window.clear(BackgroundColor);
        // window.clear(sf::Color::Yellow);
        if (!LogInWindow.isHidden())
            window.draw(LogInWindow);
        if (!StudentScreen.isHidden())
            window.draw(StudentScreen);
        if (!AdminScreen.isHidden())
            window.draw(AdminScreen);
        if (!StaffScreen.isHidden())
            window.draw(StaffScreen);
        window.display();
    }
    // Backend::saveData();
}
