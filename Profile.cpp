#include <Profile.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>

// Constructor ////////////////////////////////////////////////////////////////////////////////////////////

Profile::Profile()
{
}

void Profile::create()
{
    // Setup

    Content = new TextBox[numRow];
    Subtitle = new TextBox[numRow];

    // Background

    Texture.create(LeftWindowWidth, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(Texture.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("Profile");
    Title.setFillColor(sf::Color::Black);
    Title.setFont(LightFont);
    Title.setStyle(sf::Text::Bold);
    Title.setCharacterSize(40);
    Title.setPosition(75, 75);

    Texture.draw(Title);

    // Subtitle + Content

    Subtitle[0].setText("Student ID:");
    Subtitle[1].setText("Name:");
    Subtitle[2].setText("Gender:");
    Subtitle[3].setText("Date of birth:");
    Subtitle[4].setText("Social ID:");

    for (int i = 0; i < numRow; i++)
    {
        Subtitle[i].create(150, 175 + 60 * i, 200, 40, 18, sf::Vector2f(8, 20));
        Subtitle[i].setFillColor(BackgroundColor);
        Subtitle[i].setTextColor(sf::Color::Black);
        Subtitle[i].setFont(RegularFont);
        Subtitle[i].drawTexture();
        Subtitle[i].setOutlineColor(sf::Color::Transparent);

        Subtitle[i].drawTexture();
        Texture.draw(Subtitle[i]);

        Content[i].create(400, 175 + 60 * i, 500, 40, 18, sf::Vector2f(8, 20));
        Content[i].setFillColor(BackgroundColor);
        Content[i].setTextColor(sf::Color::Black);
        Content[i].setFont(RegularFont);
        Content[i].setOutlineColor(sf::Color::Black);
        Content[i].drawTexture();
    }
    Texture.display();
}

// Draw //////////////////////////////////////////////////////////////////////////////////////

void Profile::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

void Profile::drawTexture()
{
    Content[0].setText(dynamic_cast<Backend::Student*>(Backend::activeUser)->getID());         // reinterpret_cast<Backend::Student*>(Backend::activeUser)->getID()
    Content[1].setText(Backend::activeUser->getName()); // Backend::activeUser->getName()
    if (Backend::activeUser->getGender() == Backend::Account::Gender::Male)
        Content[2].setText("Male");
    else
        Content[2].setText("Female");
    Date Tmp = Backend::activeUser->getDateOfBirth();
    Content[3].setText(std::to_string(Tmp.day) + '/' + std::to_string(Tmp.month) + '/' + std::to_string(Tmp.year));
    Content[4].setText(Backend::activeUser->getSocialID()); // Backend::activeUser->getSocialID()
    for (int i = (Backend::activeUser->getType() == Backend::Account::Type::Student ? 0 : 1); i < numRow; i++)
    {
        Content[i].drawTexture();
        Texture.draw(Content[i]);
    }
    Texture.display();
}

// Destructor /////////////////////////////////////////////////////////////////////////////

Profile::~Profile()
{
    delete[] Content;
    delete[] Subtitle;
}