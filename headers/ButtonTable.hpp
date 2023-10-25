#pragma once
#include <Button.hpp>
#include <Class.hpp>

class ButtonTable : public sf::Drawable
{
public:
    // Constructor

    ButtonTable();
    void create(unsigned int row, unsigned int col,
                unsigned int w, unsigned int h,
                unsigned int d_x, unsigned int d_y,
                sf::Font &font, unsigned int fontsize);

    // Draw

    void drawTexture(const List<Backend::Class> &list, int page);

    // Misc

    int getHeight() const;
    sf::Vector2f getPosition() const;
    void setPosition(float a, float b);
    bool isPressed(sf::Event event);
    sf::String getText();
    void setColString(unsigned int col, sf::String s);
    void setFillColor(sf::Color color);
    void setTextColor(sf::Color color);
    void setCoverColor(sf::Color color);

    // Destructor

    ~ButtonTable();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;
private:
    float x, y;
    Button *Table = nullptr;
    unsigned int MAX_ROW, MAX_COL, MAX_CELL, numCell, width, height, Offset_x, Offset_y;
    sf::RenderTexture Texture;
    sf::RectangleShape Background;
    sf::String Choice, *Col = nullptr;
    sf::Color Fill, Text, Cover;
    int min(int x, int y);
};