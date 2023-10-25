#pragma once
#include <TextBox.hpp>
#include <Button.hpp>
#include <Layer.hpp>

class ClassWindow : public sf::Drawable
{
public:
    // Constructor

    ClassWindow();
    void create();

    // Draw

    void FirstDraw();
    void drawTexture(Layer &layer);

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
    TextBox ClassName;
    sf::RenderTexture Texture;
    sf::RectangleShape Background;
    sf::Text Title, Add, Delete, Name, ASuccess, DSuccess, Fail, Empty;
    int fail;
    const int notFound = 1, emptyname = 2, Clear = INT_MAX;
    const Layer Cls = Layer(1,5),
                ACls = Layer(2,5),
                DCls = Layer(2,10);
};