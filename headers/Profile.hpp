#pragma once
#include <SFML/Graphics.hpp>
#include <TextBox.hpp>

class Profile : public sf::Drawable
{
public:
    // Constructor

    Profile();
    void create();

    // Draw

    void drawTexture();

    // Destructor

    ~Profile();
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;
private:
    sf::RectangleShape Background;
    sf::Text Title;
    TextBox *Content;
    TextBox *Subtitle;
    sf::RenderTexture Texture;
    const int numRow = 5;
};