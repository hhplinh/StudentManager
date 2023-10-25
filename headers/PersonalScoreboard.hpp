#pragma once
#include <SFML/Graphics.hpp>
#include <TextBox.hpp>
#include <Student.hpp>

class PersonalScoreboard : public sf::Drawable
{
public:
    // Constructor

    PersonalScoreboard();
    void create(sf::Font &font);

    // Text

    void setFont(sf::Font &font);

    // Draw

    void drawTexture(const List<Backend::Student::CourseInfo> &list, int page);

    // Misc

    int getHeight() const;
    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);

    // Destructor

    ~PersonalScoreboard();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    float x, y;
    int size, *width, *pos, height, numRow;
    const int numCell = 6, MAX_ROW = 15, Offset_x = 100, Offset_y = 75;
    TextBox *Cell;
    sf::RectangleShape Background;
    sf::Text Title;
    sf::RenderTexture Texture;
    int min(int x, int y);
};
