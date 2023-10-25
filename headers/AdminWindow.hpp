#pragma once
#include <SFML/Graphics.hpp>
#include <TextBox.hpp>
#include <Button.hpp>
#include <Password.hpp>
#include <Layer.hpp>
#include <AddStaffMember.hpp>
#include <DeleteStaffMember.hpp>

class AdminWindow : public sf::Drawable
{
public:
    // Constructor

    AdminWindow();
    void create();

    // Draw

    void FirstDraw();
    void drawTexture();

    // Misc

    bool mouseOn(const sf::Vector2i &MousePos);
    void processEvent(sf::Event event);
    void setMouseCursor(const sf::Vector2i &MousePos);
    void Show();
    void Hide();
    bool isHidden();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    Button Back;
    Button AddStaff;
    Button DeleteStaff;
    Button LogOut;
    Button changePassword;
    sf::RectangleShape Background, RightSide;
    sf::Text AccountName;
    AddStaffMember AddWindow;
    DeleteStaffMember DeleteWindow;
    PasswordWindow Password;
    sf::RenderTexture Texture;
    bool hidden;
    Layer layer;
    const int Home = 0,
              Function = 1,
              Add = 1,
              Delete = 2,
              Pass = 3;
};