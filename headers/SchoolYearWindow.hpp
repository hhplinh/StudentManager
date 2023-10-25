#pragma once
#include <TextBox.hpp>
#include <Button.hpp>
#include <Layer.hpp>

class SchoolYearWindow : public sf::Drawable
{
public:
    // Constructor

    SchoolYearWindow();
    void create();

    // Draw

    void FirstDraw();
    void drawTexture(const Layer &layer);

    // Misc

    void processEvent(sf::Event event, Layer &layer);
    bool mouseOn(const sf::Vector2i &MousePos, const Layer &layer);
    void setMouseCursor(const sf::Vector2i &MousePos);
    void clearLine();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;
private:
    Button Create;
    Button Remove;
    Button Confirm;
    TextBox Start;
    sf::RenderTexture Texture;
    sf::RectangleShape Background;
    sf::Text Title, Add, Delete, FirstYear, ASuccess, DSuccess, Fail, Fail1;
    int check = 0;
    const int fail = 1, done = 0, notFound = 2, Clear = INT_MAX;
    const Layer ScY = Layer(1, 1),
                AScY = Layer(2, 1),
                DScY = Layer(2, 2);
};