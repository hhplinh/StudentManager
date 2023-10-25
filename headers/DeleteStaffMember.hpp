#pragma once
#include <TextBox.hpp>
#include <Button.hpp>

class DeleteStaffMember : public sf::Drawable
{
public:
    // Constructor

    DeleteStaffMember();
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
    sf::RectangleShape Background;
    sf::RenderTexture Texture;
    sf::Text Title, Success, Fail, Subtitle;
    TextBox Username;
    Button Confirm;
    int fail;
    const int invalid = 1,
              Clear = INT_MAX;
};