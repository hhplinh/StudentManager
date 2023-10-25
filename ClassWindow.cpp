#include <ClassWindow.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>
#include <string>

// Constructor ///////////////////////////////////////////////////////////////////////////////////////

ClassWindow::ClassWindow()
{
}

void ClassWindow::create()
{
    // Background

    Texture.create(LeftWindowWidth, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(Texture.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("Class");
    Title.setFillColor(sf::Color::Black);
    Title.setFont(LightFont);
    Title.setCharacterSize(40);
    Title.setStyle(sf::Text::Bold);
    Title.setPosition(100, 100);

    // Create

    Create.create(200, 200, 250, 75, BoldFont, 36, "Create");
    Create.setFillColor(sf::Color(25, 89, 34, 255));
    Create.setTextColor(sf::Color::White);
    Create.setCoverColor(sf::Color(20, 85, 30, 200));

    //// Add Title

    Add.setString("Create class");
    Add.setFillColor(sf::Color::Black);
    Add.setFont(LightFont);
    Add.setCharacterSize(40);
    Add.setStyle(sf::Text::Bold);
    Add.setPosition(100, 100);

    // Remove

    Remove.create(200, 325, 250, 75, BoldFont, 36, "Remove");
    Remove.setFillColor(sf::Color(25, 89, 34, 255));
    Remove.setTextColor(sf::Color::White);
    Remove.setCoverColor(sf::Color(20, 85, 30, 200));

    //// Remove Title

    Delete.setString("Remove class");
    Delete.setFillColor(sf::Color::Black);
    Delete.setFont(LightFont);
    Delete.setCharacterSize(40);
    Delete.setStyle(sf::Text::Bold);
    Delete.setPosition(100, 100);

    // Class Name

    Name.setString("Class name:");
    Name.setFillColor(sf::Color::Black);
    Name.setFont(LightFont);
    Name.setCharacterSize(18);
    Name.setStyle(sf::Text::Bold);
    Name.setPosition(200, 235);

    ClassName.create(0, 0, 150, 50, 24, sf::Vector2f(8, 25));
    ClassName.setCaret();
    ClassName.setTyping();
    ClassName.setOpacity();
    ClassName.setFont(RegularFont);
    ClassName.setFillColor(BackgroundColor);
    ClassName.setTextColor();
    ClassName.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    ClassName.setPosition(350, 235);

    // Not found class

    Empty.setFont(RegularFont);
    Empty.setCharacterSize(20);
    Empty.setFillColor(sf::Color(168, 30, 20, 255));
    Empty.setString("Failed: Class name can not be empty!");
    Empty.setPosition(250, 315);

    // Not found class

    Fail.setFont(RegularFont);
    Fail.setCharacterSize(20);
    Fail.setFillColor(sf::Color(168, 30, 20, 255));
    Fail.setString("Failed: Class not found!");
    Fail.setPosition(250, 315);

    // Add Successfully

    ASuccess.setFont(RegularFont);
    ASuccess.setCharacterSize(20);
    ASuccess.setFillColor(sf::Color(168, 30, 20, 255));
    ASuccess.setString("Create class successfully!");
    ASuccess.setPosition(250, 315);

    // Delete Successfully

    DSuccess.setFont(RegularFont);
    DSuccess.setCharacterSize(20);
    DSuccess.setFillColor(sf::Color(168, 30, 20, 255));
    DSuccess.setString("Remove class successfully!");
    DSuccess.setPosition(250, 315);

    // Confirm button

    Confirm.create(325, 380, 150, 50, BoldFont, 24, "Confirm");
    Confirm.setFillColor(sf::Color(25, 89, 34, 255));
    Confirm.setTextColor(sf::Color::White);
    Confirm.setCoverColor(sf::Color(20, 85, 30, 200));

    // First Draw

    FirstDraw();

    // Setup

    fail = Clear;
}

// Draw /////////////////////////////////////////////////////////////////////////////////////////////

void ClassWindow::FirstDraw()
{
    Texture.draw(Background);
    Texture.draw(Title);
    Create.drawTexture();
    Texture.draw(Create);
    Remove.drawTexture();
    Texture.draw(Remove);
    ClassName.drawTexture();
    Confirm.drawTexture();
    Texture.display();
}

void ClassWindow::drawTexture(Layer &layer)
{
    Texture.draw(Background);
    if (layer == ACls)
    {
        Texture.draw(Add);
        Texture.draw(Name);
        Texture.draw(ClassName);
        if (fail == emptyname)
            Texture.draw(Empty);
        if (!fail)
            Texture.draw(ASuccess);
    }
    if (layer == DCls)
    {
        Texture.draw(Delete);
        Texture.draw(Name);
        Texture.draw(ClassName);
        if (fail == notFound)
            Texture.draw(Fail);
        if (!fail)
            Texture.draw(DSuccess);
    }
    Texture.display();
}

void ClassWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////////////////////////

void ClassWindow::processEvent(sf::Event event, Layer &layer)
{
    if (layer == Cls)
    {
        drawTexture(layer);
        Texture.draw(Create);
        Texture.draw(Remove);
        if (Create.isPressed(event))
        {
            layer = ACls;
            clearLine();
            drawTexture(layer);
        }
        if (Remove.isPressed(event))
        {
            layer = DCls;
            clearLine();
            drawTexture(layer);
        }
    }
    if (layer == ACls)
    {
        if (ClassName.checkEvent(event))
            Texture.draw(ClassName);
        Texture.draw(Confirm);
        if (Confirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            if (ClassName.getText() == "") fail = emptyname;
            if (!fail)
            {
                
            }
            drawTexture(layer);
        }
    }
    if (layer == DCls)
    {
        if (ClassName.checkEvent(event))
            Texture.draw(ClassName);
        Texture.draw(Confirm);
        if (Confirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            if (!fail)
            {
                
            }
            drawTexture(layer);
        }
    }
}

bool ClassWindow::mouseOn(const sf::Vector2i &MousePos, const Layer &layer)
{
    if (layer == ACls || layer == DCls)
        return (ClassName.mouseOn(MousePos));
    return false;
}

void ClassWindow::clearLine()
{
    fail = Clear;
    ClassName.erase();
}