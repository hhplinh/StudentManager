#pragma once
#include <SFML/Graphics.hpp>
#include <Button.hpp>

class Page : public sf::Drawable
{
public:
    // Constructor

    Page();
    void create();

    // Draw

    void drawTexture();
    void FirstDraw();

    // Misc

    void setPosition(float a, float b);
    bool mouseOn(const sf::Vector2i &MousePos);
    void processEvent(sf::Event event, int &page, const int &totalpage, bool &check);
    bool isPressed(sf::Event event, int &page, const int &totalpage);
    void setPage(const int &page, const int &totalpage);

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    Button PageCount;
    sf::String NumPage, TotalPage;
    Button LeftArrow, RightArrow;
    sf::RenderTexture Texture;
    sf::RectangleShape Background;
    bool Left, Right;
    float x, y;
};