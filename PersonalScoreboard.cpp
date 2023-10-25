#include <PersonalScoreboard.hpp>
#include <FrontendGlobal.hpp>
#include <string>

// Constructor

PersonalScoreboard::PersonalScoreboard()
{
    x = 0;
    y = 0;
}

void PersonalScoreboard::create(sf::Font &font)
{
    // Setup

    numRow = 1;
    height = 35;
    Cell = new TextBox[numCell];
    width = new int[numCell];
    pos = new int[numCell];

    // Title

    Title.setString("Scoreboard");
    Title.setFont(RegularFont);
    Title.setFillColor(sf::Color::Black);
    Title.setPosition(0, 0);
    Title.setCharacterSize(30);

    // First Row

    for (int i = 0; i < numCell; i++)
        Cell[i].setFontSize(18);
    width[0] = 150;
    width[1] = 450;
    width[2] = 120;
    width[3] = 120;
    width[4] = 120;
    width[5] = 120;
    pos[0] = 0;
    for (int i = 1; i < numCell; i++)
        pos[i] = pos[i - 1] + width[i - 1];
    for (int i = 0; i < numCell; i++)
    {
        // Cell[i].setFillColor(BackgroundColor);
        Cell[i].setFontSize(15);
        Cell[i].createTexture(width[i], height);
        Cell[i].setSize(width[i], height);
        Cell[i].setPosition(pos[i] + Offset_x, Offset_y);
        Cell[i].setTextPos((i > 1 ? 30 : 8));
        Cell[i].setTextColor(sf::Color::Black);
    }
    setFont(font);
    Cell[0].setText("Course ID");
    Cell[1].setText("Course name");
    Cell[2].setText("Midterm");
    Cell[3].setText("Final");
    Cell[4].setText("Other");
    Cell[5].setText("Total");

    // Background

    Background.setSize(sf::Vector2f(pos[5] + width[5], height * MAX_ROW));
    Background.setPosition(Offset_x, height + Offset_y);
    Background.setFillColor(BackgroundColor);

    // Texture

    Texture.create(pos[5] + width[5] + Offset_x, Offset_y + (MAX_ROW + 1) * height);
    Texture.draw(Title);
    for (int i = 0; i < numCell; i++)
    {
        Cell[i].drawTexture();
        Texture.draw(Cell[i]);
    }
    Texture.display();
}

// Text /////////////////////////////////////////////////////////////////////////////////

void PersonalScoreboard::setFont(sf::Font &font)
{
    for (int i = 0; i < numCell; i++)
        Cell[i].setFont(font);
}

void PersonalScoreboard::drawTexture(const List<Backend::Student::CourseInfo> &list, int page)
{
    int steps = min(list.size() - (page - 1) * MAX_ROW, MAX_ROW);
    numRow = steps + 1;
    auto start = list.begin() + (page - 1) * MAX_ROW;
    Texture.draw(Background);
    for (int i = 0; i < steps; ++i)
    {
        auto Tmp = start + i;
        Cell[0].setText((*Tmp).course->getID());
        Cell[1].setText((*Tmp).course->getCourseName()); //(*Tmp)->getCourseName()
        Cell[2].setText(std::to_string((*Tmp).studentInfo->midtermMark));
        Cell[3].setText(std::to_string((*Tmp).studentInfo->finalMark)); //(*Tmp)->getTeacherName()
        Cell[4].setText(std::to_string((*Tmp).studentInfo->otherMark)); //(*Tmp)->getNumberOfCredits()
        Cell[5].setText(std::to_string((*Tmp).studentInfo->totalMark));
        for (int j = 0; j < numCell; j++)
        {
            Cell[j].setPosition(pos[j] + Offset_x, Offset_y + (i + 1) * height);
            Cell[j].drawTexture();
            Texture.draw(Cell[j]);
        }
    }
    Texture.display();
}

void PersonalScoreboard::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    // sprite.setTextureRect(sf::IntRect(0, 0, pos[numCell - 1] + width[numCell - 1], height * numRow));
    sprite.setPosition(x, y);
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////

int PersonalScoreboard::getHeight() const
{
    return Offset_y + height * (MAX_ROW + 1);
}

sf::Vector2f PersonalScoreboard::getPosition() const
{
    return sf::Vector2f(x, y);
}

int PersonalScoreboard::min(int x, int y)
{
    if (x < y)
        return x;
    return y;
}

void PersonalScoreboard::setPosition(float a, float b)
{
    x = a;
    y = b;
}

// Destructor ////////////////////////////////////////////////////////////////////////////////////

PersonalScoreboard::~PersonalScoreboard()
{
    delete[] Cell;
    delete[] width;
    delete[] pos;
}

