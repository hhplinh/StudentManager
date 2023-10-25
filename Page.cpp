#include <Page.hpp>
#include <FrontendGlobal.hpp>
#include <string>

// Constructor ///////////////////////////////////////////////////////////////////////////////////

Page::Page()
{
}

void Page::create()
{
    // Background

    Texture.create(180, 30);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(180, 30));
    Background.setFillColor(BackgroundColor);

    // Position

    x = 0;
    y = 0;

    // String

    NumPage = "1";
    TotalPage = "of 1";

    // Page

    PageCount.create(0, 0, 120, 30, RegularFont, 18, NumPage + " " + TotalPage);
    PageCount.setFillColor(BackgroundColor);
    PageCount.setTextColor(sf::Color::Black);
    PageCount.setPosition(30, 0);
    PageCount.setTextPos();
    PageCount.drawTexture();
    PageCount.setOutline(sf::Color::Transparent, 0);

    // Left Arrow

    LeftArrow.create(0, 0, 30, 30, RegularFont, 18, "<");
    LeftArrow.setFillColor(sf::Color(60, 60, 60, 255));
    LeftArrow.setTextColor(sf::Color::White);
    LeftArrow.setCoverColor(sf::Color(55, 55, 55, 200));
    LeftArrow.setTextPos(12);
    LeftArrow.drawTexture();

    // Right Arrow

    RightArrow.create(150, 0, 30, 30, RegularFont, 18, ">");
    RightArrow.setFillColor(sf::Color(60, 60, 60, 255));
    RightArrow.setTextColor(sf::Color::White);
    RightArrow.setCoverColor(sf::Color(55, 55, 55, 200));
    RightArrow.setTextPos(12);
    RightArrow.drawTexture();

    // Appear

    Left = 0;
    Right = 0;

    // First Draw

    drawTexture();
}

// Draw /////////////////////////////////////////////////////////////////////////////////////////////

void Page::drawTexture()
{
    Texture.draw(Background);
    PageCount.drawTexture();
    Texture.draw(PageCount);
    if (Left)
        Texture.draw(LeftArrow);
    if (Right)
        Texture.draw(RightArrow);
    Texture.display();
}

void Page::FirstDraw()
{
    Texture.draw(Background);
    PageCount.drawTexture();
    Texture.draw(PageCount);
    if (Left)
        Texture.draw(LeftArrow);
    if (Right)
        Texture.draw(RightArrow);
    Texture.display();
}

void Page::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    sprite.setPosition(x, y);
    target.draw(sprite);
}

// Misc /////////////////////////////////////////////////////////////////////////////////////////////

void Page::setPosition(float a, float b)
{
    x = a;
    y = b;
    LeftArrow.setGlobalPosition(a, b);
    RightArrow.setGlobalPosition(a, b);
}

bool Page::mouseOn(const sf::Vector2i &MousePos)
{
    return (LeftArrow.mouseOn(MousePos) ||
            RightArrow.mouseOn(MousePos));
}

void Page::processEvent(sf::Event event, int &page, const int &totalpage, bool &check)
{
    if (Left && LeftArrow.isPressed(event))
    {
        page--;
        Right = 1;
        if (page == 1)
            Left = 0;
        NumPage = std::to_string(page);
        TotalPage = std::to_string(totalpage);
        PageCount.setText(NumPage + " of " + TotalPage);
        PageCount.setTextPos();
        drawTexture();
        check = 1;
    }
    if (Right && RightArrow.isPressed(event))
    {
        page++;
        Left = 1;
        if ((page == totalpage))
            Right = 0;
        NumPage = std::to_string(page);
        TotalPage = std::to_string(totalpage);
        PageCount.setText(NumPage + " of " + TotalPage);
        PageCount.setTextPos();
        drawTexture();
        check = 1;
    }
    if (Left)
        Texture.draw(LeftArrow);
    if (Right)
        Texture.draw(RightArrow);
}

bool Page::isPressed(sf::Event event, int &page, const int &totalpage)
{
    if (page > 1)
        Left = 1;
    else
        Left = 0;
    if (page < totalpage)
        Right = 1;
    else
        Right = 0;
    if (Left)
        Texture.draw(LeftArrow);
    if (Right)
        Texture.draw(RightArrow);
    if (Left && LeftArrow.isPressed(event))
    {
        page--;
        NumPage = std::to_string(page);
        PageCount.setText(NumPage + " of " + TotalPage);
        PageCount.setTextPos();
        drawTexture();
        return true;
    }
    if (Right && RightArrow.isPressed(event))
    {
        page++;
        NumPage = std::to_string(page);
        PageCount.setText(NumPage + " of " + TotalPage);
        PageCount.setTextPos();
        drawTexture();
        return true;
    }
    return false;
}

void Page::setPage(const int &page, const int &totalpage)
{
    if (page < totalpage)
        Right = 1;
    NumPage = std::to_string(page);
    TotalPage = std::to_string(totalpage);
    PageCount.setText(NumPage + " of " + TotalPage);
    PageCount.setTextPos();
    FirstDraw();
}