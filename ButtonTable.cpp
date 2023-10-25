#include <ButtonTable.hpp>
#include <FrontendGlobal.hpp>

// Constructor ///////////////////////////////////////////////////////////////////////////////////////////////////

ButtonTable::ButtonTable()
{
}

void ButtonTable::create(unsigned int row, unsigned int col,
                         unsigned int w, unsigned int h,
                         unsigned int d_x, unsigned int d_y,
                         sf::Font &font, unsigned int fontsize)
{
    // Setup

    MAX_ROW = row;
    MAX_COL = col;
    MAX_CELL = row * col;
    width = w;
    height = h;
    Offset_x = d_x;
    Offset_y = d_y;
    numCell = 0;
    Fill = sf::Color::White;
    Cover = sf::Color(40, 40, 40, 255);
    Text = sf::Color::Black;

    // Background

    Texture.create(col * (w + Offset_x) - Offset_x, row * (h + Offset_y) - Offset_y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(col * (w + Offset_x) - Offset_x, row * (h + Offset_y) - Offset_y));
    Background.setFillColor(BackgroundColor);

    // Table

    Table = new Button[MAX_CELL];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            Table[i * col + j].create(j * (w + Offset_x), i * (h + Offset_y), w, h, font, fontsize, "");
            Table[i * col + j].drawTexture();
            Table[i * col + j].setFillColor(Fill);
            Table[i * col + j].setCoverColor(Cover);
            Table[i * col + j].setTextColor(Text);
        }
}

// Draw //////////////////////////////////////////////////////////////////////////////////

void ButtonTable::drawTexture(const List<Backend::Class> &list, int page)
{
    numCell = min(list.size() - (page - 1) * MAX_CELL, MAX_CELL);
    auto start = list.begin() + (page - 1) * MAX_CELL;
    Texture.draw(Background);
    for (int i = 0; i < numCell; ++i)
    {
        auto Tmp = start + i;
        Table[i].setText((*Tmp).getID());
        Table[i].setTextPos();
        Table[i].drawTexture();
        Texture.draw(Table[i]);
    }
    Texture.display();
}

void ButtonTable::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    sprite.setPosition(x, y);
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////

int ButtonTable::getHeight() const
{
    return (MAX_ROW * (height + Offset_y) - Offset_y);
}

sf::Vector2f ButtonTable::getPosition() const
{
    return sf::Vector2f(x, y);
}

void ButtonTable::setPosition(float a, float b)
{
    x = a;
    y = b;
    if (Table)
        for (int i = 0; i < MAX_CELL; i++)
            Table[i].setGlobalPosition(a, b);
}

bool ButtonTable::isPressed(sf::Event event)
{
    if (Table)
    {
        for (int i = 0; i < numCell; i++)
            Texture.draw(Table[i]);
        for (int i = 0; i < numCell; i++)
            if (Table[i].isPressed(event))
            {
                Choice = Table[i].getText();
                return true;
            }
    }
    return false;
}

sf::String ButtonTable::getText()
{
    return Choice;
}

void ButtonTable::setColString(unsigned int col, sf::String s)
{
    if (!Col)
        Col = new sf::String[MAX_COL];
    Col[col] = s;
}

void ButtonTable::setFillColor(sf::Color color)
{
    if (Table)
        for (int i = 0; i < MAX_CELL; i++)
            Table[i].setFillColor(color);
    else
        Fill = color;
}

void ButtonTable::setTextColor(sf::Color color)
{
    if (Table)
        for (int i = 0; i < MAX_CELL; i++)
            Table[i].setTextColor(color);
    else
        Text = color;
}

void ButtonTable::setCoverColor(sf::Color color)
{
    if (Table)
        for (int i = 0; i < MAX_CELL; i++)
            Table[i].setCoverColor(color);
    else
        Cover = color;
}

int ButtonTable::min(int x, int y)
{
    if (x < y)
        return x;
    return y;
}

// Destructor ///////////////////////////////////////////////////////////////////////////////////////////////////////////

ButtonTable::~ButtonTable()
{
    delete[] Table;
}