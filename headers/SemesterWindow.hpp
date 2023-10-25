#pragma once
#include <TextBox.hpp>
#include <Button.hpp>
#include <Layer.hpp>

class SemesterWindow : public sf::Drawable
{
public:
    // Constructor

    SemesterWindow();
    void create();

    // Draw

    void FirstDraw();
    void drawTexture(const Layer &layer);

    // Misc

    void processEvent(sf::Event event, Layer &layer);
    bool mouseOn(const sf::Vector2i &MousePos, const Layer &layer);
    void setMouseCursor(const sf::Vector2i &MousePos);
    void clearLine();

    // Destructor

    ~SemesterWindow();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    Button AddSemester;
    Button DeleteSemester;
    Button AddConfirm, DeleteConfirm;
    Button s1, s2, s3;
    sf::RectangleShape Background;
    sf::RenderTexture Texture;
    Button SchoolYear;
    sf::Text Title,
        Add, Delete,
        SCY, StartDate, EndDate,
        // Day1, Day2, Month1, Month2, Year1, Year2,
        EmptyFail, DateFail, FoundFail;
    sf::Text *Subtitle;
    TextBox *Cell;
    const Layer Smt = Layer(1, 20),
                ASmt = Layer(2, 20),
                DSmt = Layer(2, 40);
    int fail;
    const int empty = 1, date = 2, notFound = 2, Clear = INT_MAX, numCell = 7;
};