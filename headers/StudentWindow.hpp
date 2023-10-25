#pragma once
#include <SFML/Graphics.hpp>
#include <BackendGlobal.hpp>
#include <CoursesTable.hpp>
#include <TextBox.hpp>
#include <Button.hpp>
#include <Password.hpp>
#include <Layer.hpp>
#include <Page.hpp>
#include <Profile.hpp>
#include <PersonalScoreboard.hpp>

class StudentWindow : public sf::Drawable
{
public:
    // Constructor

    StudentWindow();
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
    Button LogOut;
    Button changePassword;
    Button viewScoreboard;
    Button viewCourse;
    Button viewProfile;
    sf::RectangleShape Background, RightSide;
    sf::Text AccountName;
    int NumPage, TotalPage;
    CoursesTable Courses;
    PersonalScoreboard Scoreboard;
    PasswordWindow Password;
    Profile profile;
    Page pages;
    sf::RenderTexture Texture;
    Layer layer;
    int page;
    const int Home = 0,
              Function = 1,
              Crs = 1,
              Scb = 2,
              Prf = 3,
              Pass = 4,
              MAX_ROW = 15;
    bool hidden;
};