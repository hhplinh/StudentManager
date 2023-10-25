#pragma once
#include <TextBox.hpp>
#include <Button.hpp>

class AddStaffMember : public sf::Drawable
{
public:
    // Constructor

    AddStaffMember();
    void create();

    // Draw

    void drawTexture();
    void FirstDraw();

    // Misc

    void processEvent(sf::Event event);
    bool mouseOn(const sf::Vector2i &MousePos);
    void setMouseCursor(const sf::Vector2i &MousePos);
    void clearLine();

    // Destructor
    ~AddStaffMember();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    sf::RectangleShape Background;
    sf::RenderTexture Texture;
    sf::Text Title, *Subtitle, Success, Fail1, Fail2, Fail3, DOB;
    TextBox *Cell;
    Button Confirm, Male, Female;
    int fail;
    const int empty = 1,
              invalid = 2,
              existed = 3,
              Clear = INT_MAX,
              numCell = 7;
};