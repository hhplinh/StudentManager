#include <Password.hpp>
#include <BackendGlobal.hpp>
#include <FrontendGlobal.hpp>

// Constructor ////////////////////////////////////////////////////////////////////////////////////////////////

PasswordWindow::PasswordWindow()
{
}

void PasswordWindow::create()
{
    // Background

    Texture.create(LeftWindowWidth, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(Texture.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("Change Password");
    Title.setFillColor(sf::Color::Black);
    Title.setFont(LightFont);
    Title.setCharacterSize(40);
    Title.setStyle(sf::Text::Bold);
    Title.setPosition(100, 100);

    // Current Password

    Subtitle1.setString("Current Password:");
    Subtitle1.setFillColor(sf::Color::Black);
    Subtitle1.setFont(RegularFont);
    Subtitle1.setCharacterSize(20);
    Subtitle1.setPosition(200, 200);

    Current.create(0, 0, 700, 50, 18, sf::Vector2f(8, 25));
    Current.setCaret();
    Current.setTyping();
    Current.setOpacity();
    Current.setFont(RegularFont);
    Current.setFillColor(BackgroundColor);
    Current.setTextColor();
    Current.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    Current.setPosition(200, 235);

    // New Password

    Subtitle2.setString("New Password:");
    Subtitle2.setFillColor(sf::Color::Black);
    Subtitle2.setFont(RegularFont);
    Subtitle2.setCharacterSize(20);
    Subtitle2.setPosition(200, 305);

    NewPassword.create(0, 0, 700, 50, 18, sf::Vector2f(8, 25));
    NewPassword.setCaret();
    NewPassword.setTyping();
    NewPassword.setOpacity();
    NewPassword.setFont(RegularFont);
    NewPassword.setFillColor(BackgroundColor);
    NewPassword.setTextColor();
    NewPassword.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    NewPassword.setPosition(200, 340);

    // Confirm Password

    Subtitle3.setString("Confirm Password:");
    Subtitle3.setFillColor(sf::Color::Black);
    Subtitle3.setFont(RegularFont);
    Subtitle3.setCharacterSize(20);
    Subtitle3.setPosition(200, 410);

    confirmPassword.create(0, 0, 700, 50, 18, sf::Vector2f(8, 25));
    confirmPassword.setCaret();
    confirmPassword.setTyping();
    confirmPassword.setOpacity();
    confirmPassword.setFont(RegularFont);
    confirmPassword.setFillColor(BackgroundColor);
    confirmPassword.setTextColor();
    confirmPassword.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    confirmPassword.setPosition(200, 445);

    // Fail type 1: wrong Password

    Fail1.setFont(RegularFont);
    Fail1.setCharacterSize(20);
    Fail1.setFillColor(sf::Color(168, 30, 20, 255));
    Fail1.setString("Failed: Wrong Password!");
    Fail1.setPosition(250, 500);

    // Fail type 2: New Password and Confirm Password are not the same

    Fail2.setFont(RegularFont);
    Fail2.setCharacterSize(20);
    Fail2.setFillColor(sf::Color(168, 30, 20, 255));
    Fail2.setString("Failed: Confirm Password do not match!");
    Fail2.setPosition(250, 500);

    // Success

    Success.setFont(RegularFont);
    Success.setCharacterSize(20);
    Success.setFillColor(sf::Color(144, 212, 58, 255));
    Success.setString("Change password successfully!");
    Success.setPosition(250, 500);

    // Confirm Button

    Confirm.create(480, 540, 150, 50, BoldFont, 24, "Confirm");
    Confirm.setFillColor(sf::Color(25, 89, 34, 255));
    Confirm.setTextColor(sf::Color::White);
    Confirm.setCoverColor(sf::Color(20, 85, 30, 200));

    // First Draw

    FirstDraw();

    // Set up

    fail = Clear;
}

// Draw ///////////////////////////////////////////////////////////////////////////////////////////////////////////

void PasswordWindow::drawTexture()
{
    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(Subtitle1);
    Texture.draw(Current);
    Texture.draw(Subtitle2);
    Texture.draw(NewPassword);
    Texture.draw(Subtitle3);
    Texture.draw(confirmPassword);
    // Texture.draw(Confirm);
    if (fail == 0)
        Texture.draw(Success);
    if (fail == 1)
        Texture.draw(Fail1);
    if (fail == 2)
        Texture.draw(Fail2);
    Texture.display();
}

void PasswordWindow::FirstDraw()
{
    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(Subtitle1);
    Current.drawTexture();
    Texture.draw(Current);
    Texture.draw(Subtitle2);
    NewPassword.drawTexture();
    Texture.draw(NewPassword);
    Texture.draw(Subtitle3);
    confirmPassword.drawTexture();
    Texture.draw(confirmPassword);
    Confirm.drawTexture();
    Texture.draw(Confirm);
    Texture.display();
}

void PasswordWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc ///////////////////////////////////////////////////////////////////////////////////////////////

void PasswordWindow::processEvent(sf::Event event)
{
    if (Current.checkEvent(event))
        Texture.draw(Current);
    if (NewPassword.checkEvent(event))
        Texture.draw(NewPassword);
    if (confirmPassword.checkEvent(event))
        Texture.draw(confirmPassword);
    Texture.draw(Confirm);
    if (Confirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
    {
        fail = 0;
        if (!Backend::activeUser->changePassword(Current.getText(), NewPassword.getText(), confirmPassword.getText()))
            fail = 1;
        if (NewPassword.getText() != confirmPassword.getText())
            fail = 2;
        drawTexture();
    }
    Texture.display();
}

bool PasswordWindow::mouseOn(const sf::Vector2i &MousePos)
{
    return (Current.mouseOn(MousePos) ||
            NewPassword.mouseOn(MousePos) ||
            confirmPassword.mouseOn(MousePos));
}

void PasswordWindow::setMouseCursor(const sf::Vector2i &MousePos)
{
    sf::Cursor cursor;
    if (mouseOn(MousePos))
    {
        cursor.loadFromSystem(sf::Cursor::Text);
        window.setMouseCursor(cursor);
    }
}

void PasswordWindow::clearLine()
{
    fail = Clear;
    Current.erase();
    NewPassword.erase();
    confirmPassword.erase();
    drawTexture();
}
