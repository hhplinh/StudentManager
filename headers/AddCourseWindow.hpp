#pragma once
#include <TextBox.hpp>
#include <Button.hpp>
#include <Layer.hpp>

class AddCourseWindow : public sf::Drawable
{
public:
    // Constructor

    AddCourseWindow();
    void create();

    // Draw

    void Prepare();
    void FirstDraw();
    void drawTexture();

    // Misc

    void processEvent(sf::Event event);
    bool mouseOn(const sf::Vector2i &MousePos, const Layer &layer);
    void clearLine();

    // Destructor

    ~AddCourseWindow();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    sf::RenderTexture Texture;
    sf::RectangleShape Background;
    sf::Text Title, Smt, ScY, *Subtitle, EmptyFail, ClassFail, ExistFail, Success;
    Button Semester;
    Button SchoolYear;
    TextBox *Cell;
    Button Confirm;
    Button *DoW;
    Button *Session;
    int fail;
    const int numCell = 8, numDoW = 6, numSes = 4,
              empty = 1, ClassNotFound = 2, existed = 3, Clear = INT_MAX;
    const Layer ACrs = Layer(1,0);
};