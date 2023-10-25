#pragma once
#include <SFML/Graphics.hpp>
#include <TextBox.hpp>
#include <Course.hpp>

class CoursesTable : public sf::Drawable
{
public:
    // Constructor

    CoursesTable();
    void create(sf::Font &font);

    // Text

    void setFont(sf::Font &font);

    // Draw

    void drawTexture(const List<Backend::Course *> &list, int page);

    // Misc

    int getHeight() const;
    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);

    // Destructor

    ~CoursesTable();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    float x, y;
    int size, *width, *pos, height, numRow;
    const int numCell = 7, MAX_ROW = 15, Offset = 75;
    TextBox *Cell;
    sf::RectangleShape Background;
    sf::Text Title;
    sf::RenderTexture Texture;
    int min(int x, int y);
};