#include <AdminWindow.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>

AdminWindow::AdminWindow()
{
}

void AdminWindow::create()
{
    // Background

    Texture.create(window.getSize().x, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(window.getSize()));
    Background.setFillColor(BackgroundColor);

    // Back Button

    Back.create(0, 0, 60, 40, RegularFont, 25, "<-");
    Back.setFillColor(sf::Color(60, 60, 60, 255));
    Back.setTextColor(sf::Color::White);
    Back.setCoverColor(sf::Color(55, 55, 55, 200));
    Back.setTextPos(16);

    // Home // sf::Color(9, 66, 55, 255)
    //// Add Staff members

    AddStaff.create(150, 150, 450, 75, BoldFont, 30, "Add Staff Member");
    AddStaff.setFillColor(sf::Color(9, 66, 55, 255));
    AddStaff.setTextColor(sf::Color::White);
    AddStaff.setCoverColor(sf::Color(30, 100, 70, 200));

    //// Delete Staff members

    DeleteStaff.create(150, 225, 450, 75, BoldFont, 30, "Delete Staff Member");
    DeleteStaff.setFillColor(sf::Color(9, 66, 55, 255));
    DeleteStaff.setTextColor(sf::Color::White);
    DeleteStaff.setCoverColor(sf::Color(30, 100, 70, 200));

    ////// Add Staff Window

    AddWindow.create();

    //// Delete Staff Members

    DeleteStaff.create(150, 250, 450, 75, BoldFont, 30, "Delete Staff Member");
    DeleteStaff.setFillColor(sf::Color(9, 66, 55, 255));
    DeleteStaff.setTextColor(sf::Color::White);
    DeleteStaff.setCoverColor(sf::Color(30, 100, 70, 200));

    ////// Delete Staff Window

    DeleteWindow.create();

    // Account Window
    //// Rectangle

    RightSide.setSize(sf::Vector2f(RightWindowWidth, window.getSize().y));
    RightSide.setFillColor(sf::Color(9, 66, 55, 255));
    RightSide.setPosition(LeftWindowWidth, 0);

    //// Name

    AccountName.setPosition(LeftWindowWidth + 25, 50);
    AccountName.setFillColor(sf::Color(248, 117, 26, 255));
    AccountName.setString("Admin");
    AccountName.setFont(RegularFont);

    //// Change Password Button

    changePassword.create(LeftWindowWidth + 72, 150, 250, 50, RegularFont, 24, "Change Password");
    changePassword.setFillColor(sf::Color(248, 117, 26, 255));
    changePassword.setCoverColor(sf::Color(240, 110, 20, 200));
    changePassword.setTextColor(sf::Color(9, 66, 55, 255));

    //// Log out Button

    LogOut.create(LeftWindowWidth + 72, 225, 250, 50, MediumFont, 24, "Log out");
    LogOut.setFillColor(sf::Color(248, 117, 26, 255));
    LogOut.setCoverColor(sf::Color(240, 110, 20, 200));
    LogOut.setTextColor(sf::Color(9, 66, 55, 255));

    // Change Password Window

    Password.create();

    // First Draw

    FirstDraw();

    // Setup

    hidden = 1;
    layer.lvl = Home;
}

// Draw //////////////////////////////////////////////////////////////////////////////////////

void AdminWindow::FirstDraw()
{
    Texture.draw(Background);
    Back.drawTexture();
    AddStaff.drawTexture();
    Texture.draw(AddStaff);
    DeleteStaff.drawTexture();
    Texture.draw(DeleteStaff);
    Texture.draw(RightSide);
    Texture.draw(AccountName);
    changePassword.drawTexture();
    Texture.draw(changePassword);
    LogOut.drawTexture();
    Texture.draw(LogOut);
    Texture.display();
}

void AdminWindow::drawTexture()
{
    Texture.draw(Background);
    if (layer.lvl)
        Texture.draw(Back);
    if (layer.lvl == Home)
    {
        Texture.draw(AddStaff);
        Texture.draw(DeleteStaff);
    }
    if (layer.lvl == Function && layer.type == Add)
    {
        Texture.draw(AddWindow);
    }
    if (layer.lvl == Function && layer.type == Pass)
    {
        Texture.draw(Password);
    }
    Texture.draw(RightSide);
    Texture.draw(AccountName);
}

void AdminWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc /////////////////////////////////////////////////////////////////////////////////////////////

void AdminWindow::processEvent(sf::Event event)
{
    if (LogOut.isPressed(event))
    {
        layer.lvl = 0;
        layer.type = 0;
        drawTexture();
        Hide();
        Backend::activeUser->logOut();
        LogInWindow.show();
    }
    if (changePassword.isPressed(event))
    {
        layer.lvl = Function;
        layer.type = Pass;
        Password.clearLine();
        drawTexture();
    }
    if (layer.lvl && Back.isPressed(event))
    {
        layer.lvl--;
        drawTexture();
    }
    if (layer.lvl == Function && layer.type == Pass)
    {
        Password.processEvent(event);
        Texture.draw(Password);
    }
    if (layer.lvl == Function && layer.type == Add)
    {
        AddWindow.processEvent(event);
        Texture.draw(AddWindow);
    }
    if (layer.lvl == Function && layer.type == Delete)
    {
        DeleteWindow.processEvent(event);
        Texture.draw(DeleteWindow);
    }
    if (layer.lvl)
        Texture.draw(Back);
    if (layer.lvl == Home)
    {
        Texture.draw(AddStaff);
        Texture.draw(DeleteStaff);
        if (AddStaff.isPressed(event))
        {
            layer.lvl = Function;
            layer.type = Add;
            AddWindow.clearLine();
            drawTexture();
        }
        if (DeleteStaff.isPressed(event))
        {
            layer.lvl = Function;
            layer.type = Delete;
            DeleteWindow.clearLine();
            drawTexture();
        }
    }
    Texture.draw(changePassword);
    Texture.draw(LogOut);
}

bool AdminWindow::mouseOn(const sf::Vector2i &MousePos)
{
    if (layer.lvl == Function && layer.type == Add)
        return AddWindow.mouseOn(MousePos);
    if (layer.lvl == Function && layer.type == Pass)
        return Password.mouseOn(MousePos);
    return false;
}

void AdminWindow::Show()
{
    hidden = 0;
}

void AdminWindow::Hide()
{
    hidden = 1;
}

bool AdminWindow::isHidden()
{
    return hidden;
}