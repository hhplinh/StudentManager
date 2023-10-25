#pragma once
#include <SFML/Graphics.hpp>
#include <TextBox.hpp>
#include <Button.hpp>

class LogIn : public sf::Drawable
{
public:
    // Constructor

    LogIn();
    void create();

    // Misc

    void processEvent(sf::Event event);
    bool mouseOn(const sf::Vector2i &MousePos);
    void setMouseCursor(const sf::Vector2i &MousePos);
    bool isHidden();
    void hide();
    void show();

    // Draw

    void drawTexture();
    void FirstDraw();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::RenderTexture Texture;
    TextBox Username;
    TextBox Password;
    sf::RectangleShape Bound, Background;
    sf::Text Title, Title1, Title2, Fail;
    Button Confirm;
    bool hidden, fail;
};