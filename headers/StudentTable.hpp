#pragma once
#include <TextBox.hpp>
#include <Student.hpp>

class StudentTable : public sf::Drawable
{
public:
    // Constructor

    StudentTable();
    void create(sf::Font &font);

    // Text

    void setFont(sf::Font &font);

    // Draw

    void drawTexture(const List<Backend::Student*> &list, int page);

    // Misc

    int getHeight() const;
    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);

    // Destructor

    ~StudentTable();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    float x, y;
    int size, *width, *pos, height, numRow;
    const int numCell = 6, MAX_ROW = 15, Offset = 75;
    TextBox *Cell;
    sf::RectangleShape Background;
    sf::Text Title;
    sf::RenderTexture Texture;
    int min(int x, int y);
};