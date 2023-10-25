#pragma once
#include <SFML/Graphics.hpp>
#include <TextBox.hpp>
#include <Button.hpp>
#include <Layer.hpp>
#include <Password.hpp>
#include <SchoolYearWindow.hpp>
#include <ClassWindow.hpp>
#include <SemesterWindow.hpp>
#include <Profile.hpp>
#include <SetStudentWindow.hpp>
#include <AddCourseWindow.hpp>

class StaffWindow : public sf::Drawable
{
public:
    // Constructor

    StaffWindow();
    void create();

    // Draw

    void FirstDraw();
    void drawTexture();

    // Misc

    void processEvent(sf::Event event);
    bool mouseOn(const sf::Vector2i &MousePos);
    void setMouseCursor(const sf::Vector2i &MousePos);
    void Show();
    void Hide();
    bool isHidden();
    // ~StaffWindow();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    Button Back;
    Button SchoolYear;
    Button Semester;
    Button Class;
    Button Student;
    Button addCourse;
    Button viewProfile;
    Button changePassword;
    Button LogOut;
    sf::RectangleShape Background, RightSide;
    sf::Text AccountName;
    Profile profile;
    PasswordWindow Password;
    SchoolYearWindow SchoolYearScreen;
    SemesterWindow SemesterScreen;
    ClassWindow ClassScreen;
    SetStudentWindow SetStudentScreen;
    AddCourseWindow AddCourseScreen;
    sf::RenderTexture Texture;
    bool hidden;
    Layer layer;
    const Layer Home = Layer(0,0),
                ScY = Layer(1,1),
                AScY = Layer(2,1),
                DScY = Layer(2,2),
                Cls = Layer(1,5),
                ACls = Layer(2,5),
                DCls = Layer(2,10),
                Smt = Layer(1,20),
                ASmt = Layer(2,20),
                DSmt = Layer(2,40),
                Std = Layer(1,50),
                LStd = Layer(2,50),
                AStdM = Layer(3,50),
                RStd = Layer(2,100),
                ACrs = Layer(1,0);
};