#include <StudentTable.hpp>
#include <FrontendGlobal.hpp>
#include <Date.hpp>
#include <string>

// Constructor ////////////////////////////////////////////////////////////////////////////////////////////

StudentTable::StudentTable()
{
    x = 0;
    y = 0;
}

void StudentTable::create(sf::Font &font)
{
    // Setup

    numRow = 1;
    height = 35;
    Cell = new TextBox[numCell];
    width = new int[numCell];
    pos = new int[numCell];

    // Title

    Title.setString("List of Students");
    Title.setFont(RegularFont);
    Title.setFillColor(sf::Color::Black);
    Title.setPosition(0, 0);
    Title.setCharacterSize(30);

    // First Row

    for (int i = 0; i < numCell; i++)
        Cell[i].setFontSize(18);
    width[0] = 150;
    width[1] = 100;
    width[2] = 450;
    width[3] = 100;
    width[4] = 250;
    width[5] = 250;
    pos[0] = 0;
    for (int i = 1; i < numCell; i++)
        pos[i] = pos[i - 1] + width[i - 1];
    for (int i = 0; i < numCell; i++)
    {
        // Cell[i].setFillColor(BackgroundColor);
        Cell[i].setFontSize(15);
        Cell[i].createTexture(width[i], height);
        Cell[i].setSize(width[i], height);
        Cell[i].setPosition(pos[i], Offset);
        Cell[i].setTextPos();
        Cell[i].setTextColor(sf::Color::Black);
    }
    setFont(font);
    Cell[0].setText("ID");
    Cell[1].setText("Class");
    Cell[2].setText("Name");
    Cell[3].setText("Gender");
    Cell[4].setText("Date of birth");
    Cell[5].setText("Social ID");

    // Background

    Background.setSize(sf::Vector2f(pos[5] + width[5], height * MAX_ROW));
    Background.setPosition(0, height + Offset);
    Background.setFillColor(BackgroundColor);

    // Texture

    Texture.create(pos[5] + width[5], Offset + (MAX_ROW + 1) * height);
    Texture.draw(Title);
    for (int i = 0; i < numCell; i++)
    {
        Cell[i].drawTexture();
        Texture.draw(Cell[i]);
    }
    Texture.display();
}

// Text /////////////////////////////////////////////////////////////////////////////////

void StudentTable::setFont(sf::Font &font)
{
    if (Cell)
        for (int i = 0; i < numCell; i++)
            Cell[i].setFont(font);
}

// Draw /////////////////////////////////////////////////////////////////////////////////

void StudentTable::drawTexture(const List<Backend::Student*> &list, int page)
{
    int steps = min(list.size() - (page - 1) * MAX_ROW, MAX_ROW);
    numRow = steps + 1;
    auto start = list.begin() + (page - 1) * MAX_ROW;
    Texture.draw(Background);
    for (int i = 0; i < steps; ++i)
    {
        auto Tmp = start + i;
        Cell[0].setText((*Tmp)->getID());
        Cell[1].setText((*Tmp)->getClass()->getID());
        Cell[2].setText((*Tmp)->getName());
        Cell[3].setText(((*Tmp)->getGender() == Backend::Student::Gender::Male ? "Male" : "Female"));
        Date DOB = (*Tmp)->getDateOfBirth();
        Cell[4].setText(std::to_string(DOB.day) + "/" + std::to_string(DOB.month) + "/" + std::to_string(DOB.year));
        Cell[5].setText((*Tmp)->getSocialID());
        for (int j = 0; j < numCell; j++)
        {
            Cell[j].setPosition(pos[j], Offset + (i + 1) * height);
            Cell[j].drawTexture();
            Texture.draw(Cell[j]);
        }
    }
    Texture.display();
}

void StudentTable::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    // sprite.setTextureRect(sf::IntRect(0, 0, pos[numCell - 1] + width[numCell - 1], height * numRow));
    sprite.setPosition(x, y);
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////

int StudentTable::getHeight() const
{
    return Offset + height * (MAX_ROW + 1);
}

sf::Vector2f StudentTable::getPosition() const
{
    return sf::Vector2f(x, y);
}

int StudentTable::min(int x, int y)
{
    if (x < y)
        return x;
    return y;
}

void StudentTable::setPosition(float a, float b)
{
    x = a;
    y = b;
}

// Destructor ////////////////////////////////////////////////////////////////////////////////////

StudentTable::~StudentTable()
{
    delete[] Cell;
    delete[] width;
    delete[] pos;
}