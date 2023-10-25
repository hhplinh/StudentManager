#include "CoursesTable.hpp"
#include <FrontendGlobal.hpp>
#include <string>

// Constructor ////////////////////////////////////////////////////////////////////////////////////////////

CoursesTable::CoursesTable()
{
    x = 0;
    y = 0;
}

void CoursesTable::create(sf::Font &font)
{
    // Setup

    numRow = 1;
    height = 35;
    Cell = new TextBox[numCell];
    width = new int[numCell];
    pos = new int[numCell];

    // Title

    Title.setString("Courses");
    Title.setFont(RegularFont);
    Title.setFillColor(sf::Color::Black);
    Title.setPosition(0, 0);
    Title.setCharacterSize(30);

    // First Row

    for (int i = 0; i < numCell; i++)
        Cell[i].setFontSize(18);
    width[0] = 180;
    width[1] = 400;
    width[2] = 115;
    width[3] = 250;
    width[4] = 120;
    width[5] = 120;
    width[6] = 150;
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
    Cell[1].setText("Name");
    Cell[2].setText("Class name");
    Cell[3].setText("Teacher name");
    Cell[4].setText("No. Credits");
    Cell[5].setText("No. Students");
    Cell[6].setText("Session");

    // Background

    Background.setSize(sf::Vector2f(pos[6] + width[6], height * MAX_ROW));
    Background.setPosition(0, height + Offset);
    Background.setFillColor(BackgroundColor);

    // Texture

    Texture.create(pos[6] + width[6], Offset + (MAX_ROW + 1) * height);
    Texture.draw(Title);
    for (int i = 0; i < numCell; i++)
    {
        Cell[i].drawTexture();
        Texture.draw(Cell[i]);
    }
    Texture.display();
}

// Text /////////////////////////////////////////////////////////////////////////////////

void CoursesTable::setFont(sf::Font &font)
{
    for (int i = 0; i < numCell; i++)
        Cell[i].setFont(font);
}

// Draw /////////////////////////////////////////////////////////////////////////////////

void CoursesTable::drawTexture(const List<Backend::Course *> &list, int page)
{
    int steps = min(list.size() - (page - 1) * MAX_ROW, MAX_ROW);
    numRow = steps + 1;
    auto start = list.begin() + (page - 1) * MAX_ROW;
    Texture.draw(Background);
    for (int i = 0; i < steps; ++i)
    {
        auto Tmp = start + i;
        Cell[0].setText((*Tmp)->getID());
        Cell[1].setText((*Tmp)->getCourseName()); //(*Tmp)->getCourseName()
        Cell[2].setText("");
        Cell[3].setText((*Tmp)->getTeacherName()); //(*Tmp)->getTeacherName()
        Cell[4].setText(std::to_string((*Tmp)->getNumberOfCredits())); //(*Tmp)->getNumberOfCredits()
        Cell[5].setText(std::to_string((*Tmp)->getMaxStudents()));
        Cell[6].setText((*Tmp)->session().getTime());
        for (int j = 0; j < numCell; j++)
        {
            Cell[j].setPosition(pos[j], Offset + (i + 1) * height);
            Cell[j].drawTexture();
            Texture.draw(Cell[j]);
        }
    }
    Texture.display();
}

void CoursesTable::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    // sprite.setTextureRect(sf::IntRect(0, 0, pos[numCell - 1] + width[numCell - 1], height * numRow));
    sprite.setPosition(x, y);
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////

int CoursesTable::getHeight() const
{
    return Offset + height * (MAX_ROW + 1);
}

sf::Vector2f CoursesTable::getPosition() const
{
    return sf::Vector2f(x, y);
}

int CoursesTable::min(int x, int y)
{
    if (x < y)
        return x;
    return y;
}

void CoursesTable::setPosition(float a, float b)
{
    x = a;
    y = b;
}

// Destructor ////////////////////////////////////////////////////////////////////////////////////

CoursesTable::~CoursesTable()
{
    delete[] Cell;
    delete[] width;
    delete[] pos;
}