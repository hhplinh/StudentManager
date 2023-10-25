#include <DeleteStaffMember.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>

DeleteStaffMember::DeleteStaffMember()
{
}

void DeleteStaffMember::create()
{
    // Background

    Texture.create(LeftWindowWidth, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(Texture.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("Delete Staff member");
    Title.setFillColor(sf::Color::Black);
    Title.setFont(LightFont);
    Title.setCharacterSize(40);
    Title.setStyle(sf::Text::Bold);
    Title.setPosition(100, 100);

    // Username

    Subtitle.setFillColor(sf::Color::Black);
    Subtitle.setFont(RegularFont);
    Subtitle.setCharacterSize(20);
    Subtitle.setString("Social ID (Username):");
    Subtitle.setPosition(300, 200);

    Username.create(0, 0, 500, 50, 18, sf::Vector2f(8, 25));
    Username.setPosition(300, 235);
    Username.setNumber();
    Username.setCaret();
    Username.setTyping();
    Username.setOpacity();
    Username.setFont(RegularFont);
    Username.setFillColor(BackgroundColor);
    Username.setTextColor();
    Username.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);

    // Fail

    Fail.setFont(RegularFont);
    Fail.setCharacterSize(20);
    Fail.setFillColor(sf::Color(168, 30, 20, 255));
    Fail.setString("Failed: Can not find staff member!");
    Fail.setPosition(350, 300);

    // Success

    Success.setFont(RegularFont);
    Success.setCharacterSize(20);
    Success.setFillColor(sf::Color(144, 212, 58, 255));
    Success.setString("Delete Staff member successfully!");
    Success.setPosition(350, 300);

    // Confirm Button

    Confirm.create(425, 335, 150, 50, BoldFont, 24, "Confirm");
    Confirm.setFillColor(sf::Color(25, 89, 34, 255));
    Confirm.setTextColor(sf::Color::White);
    Confirm.setCoverColor(sf::Color(20, 85, 30, 200));

    // First Draw

    FirstDraw();

    // Setup

    fail = Clear;
}

// Draw /////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteStaffMember::drawTexture()
{
    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(Subtitle);
    Texture.draw(Username);
    Texture.draw(Confirm);
    if (fail == 0)
        Texture.draw(Success);
    if (fail == invalid)
        Texture.draw(Fail);
    Texture.display();
}

void DeleteStaffMember::FirstDraw()
{
    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(Subtitle);
    Username.drawTexture();
    Texture.draw(Username);
    Confirm.drawTexture();
    Texture.draw(Confirm);
    Texture.display();
}

void DeleteStaffMember::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc ///////////////////////////////////////////////////////////////////////////////////////////

void DeleteStaffMember::processEvent(sf::Event event)
{
    if (Username.checkEvent(event))
        Texture.draw(Username);
    Texture.draw(Confirm);
    if (Confirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
    {
        fail = 0;
        if (!Backend::StaffMember::deleteStaffMember(Username.getText()))
            fail = invalid;
        drawTexture();
    }
}

bool DeleteStaffMember::mouseOn(const sf::Vector2i &MousePos)
{
    return Username.mouseOn(MousePos);
}

void DeleteStaffMember::clearLine()
{
    fail = Clear;
    Username.erase();
    Username.drawTexture();
    drawTexture();
}