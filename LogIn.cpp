#include <LogIn.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>

// Constructor ///////////////////////////////////////////////////////////////////////////////////////////////////

LogIn::LogIn()
{
}

void LogIn::create()
{
    // Background

    Texture.create(window.getSize().x, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(window.getSize()));
    Background.setFillColor(BackgroundColor);

    // Bound

    Bound.setSize(sf::Vector2f(800, 400));
    Bound.setOrigin(400, 200);
    Bound.setFillColor(BackgroundColor);
    Bound.setOutlineColor(sf::Color(25, 89, 34, 255));
    Bound.setOutlineThickness(1);
    Bound.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    // Title

    Title.setString("Log in");
    Title.setFillColor(sf::Color(25, 89, 34, 255));
    Title.setFont(LightFont);
    Title.setCharacterSize(40);
    Title.setStyle(sf::Text::Bold);
    Title.setOrigin(Title.getLocalBounds().width / 2, Title.getLocalBounds().height / 2);
    Title.setPosition(Bound.getPosition().x, Bound.getPosition().y - 170);

    Title1.setString("Username: ");
    Title1.setFillColor(sf::Color::Black);
    Title1.setFont(RegularFont);
    Title1.setCharacterSize(20);
    Title1.setPosition(Bound.getPosition().x - 350, Bound.getPosition().y - 135);

    Title2.setString("Password: ");
    Title2.setFillColor(sf::Color::Black);
    Title2.setFont(RegularFont);
    Title2.setCharacterSize(20);
    Title2.setPosition(Bound.getPosition().x - 350, Bound.getPosition().y - 30);

    // Username

    Username.create(0, 0, 700, 50, 18, sf::Vector2f(8, 25));
    Username.setCaret();
    Username.setTyping();
    Username.setOpacity();
    Username.setFont(RegularFont);
    Username.setFillColor(BackgroundColor);
    Username.setTextColor();
    Username.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    Username.setPosition(Bound.getPosition().x - 350, Bound.getPosition().y - 100);

    // Password

    Password.create(0, 0, 700, 50, 18, sf::Vector2f(8, 25));
    Password.setCaret();
    Password.setTyping();
    Password.setOpacity();
    Password.setPassword();
    Password.setFont(RegularFont);
    Password.setFillColor(BackgroundColor);
    Password.setTextColor();
    Password.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    Password.setPosition(Bound.getPosition().x - 350, Bound.getPosition().y + 5);

    // Log in failed

    Fail.setFont(RegularFont);
    Fail.setCharacterSize(20);
    Fail.setFillColor(sf::Color(168, 30, 20, 255));
    Fail.setString("Failed: Wrong Username or Password!");
    Fail.setPosition(Bound.getPosition().x - 320, Bound.getPosition().y + 70);

    // Button

    Confirm.create(Bound.getPosition().x - 50, Bound.getPosition().y + 115, 100, 50, BoldFont, 24, "Log In");
    Confirm.setFillColor(sf::Color(25, 89, 34, 255));
    Confirm.setTextColor(sf::Color::White);
    Confirm.setCoverColor(sf::Color(50, 120, 60, 255));

    // First Draw

    FirstDraw();

    // Set showed

    hidden = 0;
    fail = 0;
}

// Misc //////////////////////////////////////////////////////////////////////////////////////////////////

void LogIn::processEvent(sf::Event event)
{
    if (Username.checkEvent(event))
        drawTexture();
    if (Password.checkEvent(event))
        drawTexture();
    Texture.draw(Confirm);
    if (Confirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
    {
        const std::string user = Username.getText(), pass = Password.getText();
        if (!Backend::activeUser->signIn(user, pass))
            fail = 1;
        else
        {
            fail = 0;
            Username.erase();
            Password.erase();
            Username.drawTexture();
            Password.drawTexture();
            hide();
            if (Backend::activeUser->getType() == Backend::Account::Type::Admin)
            {
                AdminScreen.Show();
                std::cerr << 1 << '\n';
            }
            if (Backend::activeUser->getType() == Backend::Account::Type::Student)
            {
                StudentScreen.Show();
                std::cerr << 2 << '\n';
            }
            if (Backend::activeUser->getType() == Backend::Account::Type::StaffMember)
            {
                StaffScreen.Show();
                std::cerr << 3 << '\n';
            }
        }
        drawTexture();
    }
}

bool LogIn::mouseOn(const sf::Vector2i &MousePos)
{
    if (Username.mouseOn(MousePos) || Password.mouseOn(MousePos))
        return true;
    return false;
}

void LogIn::setMouseCursor(const sf::Vector2i &MousePos)
{
    sf::Cursor cursor;
    if (mouseOn(MousePos))
    {
        cursor.loadFromSystem(sf::Cursor::Text);
        window.setMouseCursor(cursor);
    }
}

bool LogIn::isHidden()
{
    return hidden;
}

void LogIn::hide()
{
    hidden = 1;
}

void LogIn::show()
{
    hidden = 0;
}

// Draw //////////////////////////////////////////////////////////////////////////////////////////////////

void LogIn::drawTexture()
{
    Texture.draw(Background);
    Texture.draw(Bound);
    Texture.draw(Title);
    Texture.draw(Title1);
    Texture.draw(Username);
    Texture.draw(Title2);
    if (fail)
        Texture.draw(Fail);
    Texture.draw(Password);
    Texture.display();
}

void LogIn::FirstDraw()
{
    Texture.draw(Background);
    Texture.draw(Bound);
    Texture.draw(Title);
    Texture.draw(Title1);
    Username.drawTexture();
    Texture.draw(Username);
    Texture.draw(Title2);
    Password.drawTexture();
    Texture.draw(Password);
    Confirm.drawTexture();
    Texture.draw(Confirm);
    Texture.display();
}

void LogIn::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}