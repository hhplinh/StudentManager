#pragma once
#include <SFML/Graphics.hpp>
#include <TextBox.hpp>
#include <Button.hpp>

class PasswordWindow : public sf::Drawable
{
public:
    // Constructor

    PasswordWindow();
    void create();

    // Draw

    void drawTexture();
    void FirstDraw();

    // Misc

    void processEvent(sf::Event event);
    bool mouseOn(const sf::Vector2i &MousePos);
    void setMouseCursor(const sf::Vector2i &MousePos);
    void clearLine();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;
private:
    sf::RenderTexture Texture;
    sf::RectangleShape Background;
    sf::Text Title, Subtitle1, Subtitle2, Subtitle3, Fail1, Fail2, Success;
    TextBox Current;
    TextBox NewPassword;
    TextBox confirmPassword;
    Button Confirm;
    int fail;
    const int Clear = INT_MAX;
};