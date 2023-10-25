#include <AddStaffMember.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>

AddStaffMember::AddStaffMember()
{
}

void AddStaffMember::create()
{
    // Background

    Texture.create(LeftWindowWidth, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(Texture.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("Add Staff member");
    Title.setFillColor(sf::Color::Black);
    Title.setFont(LightFont);
    Title.setCharacterSize(40);
    Title.setStyle(sf::Text::Bold);
    Title.setPosition(100, 100);

    // Subtitle

    Subtitle = new sf::Text[numCell];
    Cell = new TextBox[numCell];

    for (int i = 0; i < numCell; i++)
    {
        Subtitle[i].setFillColor(sf::Color::Black);
        Subtitle[i].setFont(RegularFont);
        Subtitle[i].setCharacterSize(20);
    }

    // Cells
    {
        // Username
        {
            Subtitle[0].setString("Social ID (Username):");
            Subtitle[0].setPosition(300, 200);

            Cell[0].create(0, 0, 500, 50, 18, sf::Vector2f(8, 25));
            Cell[0].setPosition(300, 235);
            Cell[0].setNumber();
        }
        // First Name
        {
            Subtitle[1].setString("First name:");
            Subtitle[1].setPosition(300, 300);

            Cell[1].create(0, 0, 500, 50, 18, sf::Vector2f(8, 25));
            Cell[1].setPosition(300, 335);
        }
        // Last Name
        {
            Subtitle[2].setString("Last name:");
            Subtitle[2].setPosition(900, 300);

            Cell[2].create(0, 0, 250, 50, 18, sf::Vector2f(8, 25));
            Cell[2].setPosition(900, 335);
        }
        // Gender
        {
            Subtitle[3].setString("Gender:");
            Subtitle[3].setPosition(300, 400);

            Cell[3].create(0, 0, 100, 50, 18, sf::Vector2f(8, 25));
            Cell[3].setPosition(300, 435);

            // Male
            {
                Male.create(450, 398, 70, 30, RegularFont, 16, "Male");
                Male.setFillColor(sf::Color(25, 89, 34, 255));
                Male.setTextColor(sf::Color::White);
                Male.setCoverColor(sf::Color(20, 85, 30, 200));
            }
            // Female
            {
                Female.create(550, 398, 70, 30, RegularFont, 16, "Female");
                Female.setFillColor(sf::Color(25, 89, 34, 255));
                Female.setTextColor(sf::Color::White);
                Female.setCoverColor(sf::Color(20, 85, 30, 200));
            }
        }
        // Date of Birth
        {
            DOB.setString("Date of Birth");
            DOB.setPosition(300, 500);
            DOB.setFillColor(sf::Color::Black);
            DOB.setFont(RegularFont);
            DOB.setCharacterSize(20);

            // Day
            {
                Subtitle[4].setString("Day:");
                Subtitle[4].setPosition(350, 555);

                Cell[4].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                Cell[4].setPosition(450, 550);
                Cell[4].setLimit(2);
                Cell[4].setNumber();
            }
            // Month
            {
                Subtitle[5].setString("Month:");
                Subtitle[5].setPosition(350, 625);

                Cell[5].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                Cell[5].setPosition(450, 620);
                Cell[5].setLimit(2);
                Cell[5].setNumber();
            }
            // Year
            {
                Subtitle[6].setString("Year:");
                Subtitle[6].setPosition(350, 695);

                Cell[6].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                Cell[6].setPosition(450, 690);
                Cell[6].setLimit(4);
                Cell[6].setNumber();
            }
        }
    }

    // Setup for all cells

    for (int i = 0; i < numCell; i++)
    {
        if (i != 3)
        {
            Cell[i].setCaret();
            Cell[i].setTyping();
            Cell[i].setOpacity();
        }
        Cell[i].setFont(RegularFont);
        Cell[i].setFillColor(BackgroundColor);
        Cell[i].setTextColor();
        Cell[i].setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    }

    // Fail type 1 : Empty cell

    Fail1.setFont(RegularFont);
    Fail1.setCharacterSize(20);
    Fail1.setFillColor(sf::Color(168, 30, 20, 255));
    Fail1.setString("Failed: Cells can not be empty!");
    Fail1.setPosition(400, 780);

    // Fail type 2 : Invalid Date type

    Fail2.setFont(RegularFont);
    Fail2.setCharacterSize(20);
    Fail2.setFillColor(sf::Color(168, 30, 20, 255));
    Fail2.setString("Failed: Invalid Date!");
    Fail2.setPosition(400, 780);

    // Fail type 3 : Staff member existed

    Fail3.setFont(RegularFont);
    Fail3.setCharacterSize(20);
    Fail3.setFillColor(sf::Color(168, 30, 20, 255));
    Fail3.setString("Failed: Staff member existed!");
    Fail3.setPosition(400, 780);

    // Success

    Success.setFont(RegularFont);
    Success.setCharacterSize(20);
    Success.setFillColor(sf::Color(144, 212, 58, 255));
    Success.setString("Add Staff member successfully!");
    Success.setPosition(400, 780);

    // Confirm Button

    Confirm.create(650, 850, 150, 50, BoldFont, 24, "Confirm");
    Confirm.setFillColor(sf::Color(25, 89, 34, 255));
    Confirm.setTextColor(sf::Color::White);
    Confirm.setCoverColor(sf::Color(20, 85, 30, 200));

    // First Draw

    FirstDraw();

    // Setup

    fail = Clear;
}

// Draw /////////////////////////////////////////////////////////////////////////////////////////////////////

void AddStaffMember::drawTexture()
{
    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(DOB);
    for (int i = 0; i < numCell; i++)
    {
        Texture.draw(Subtitle[i]);
        Texture.draw(Cell[i]);
    }
    if (fail == 0)
        Texture.draw(Success);
    if (fail == empty)
        Texture.draw(Fail1);
    if (fail == invalid)
        Texture.draw(Fail2);
    if (fail == existed)
        Texture.draw(Fail3);
    Texture.display();
}

void AddStaffMember::FirstDraw()
{
    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(DOB);
    for (int i = 0; i < numCell; i++)
    {
        Texture.draw(Subtitle[i]);
        Cell[i].drawTexture();
        Texture.draw(Cell[i]);
    }
    Male.drawTexture();
    Texture.draw(Male);
    Female.drawTexture();
    Texture.draw(Female);
    Confirm.drawTexture();
    Texture.draw(Confirm);
    Texture.display();
}

void AddStaffMember::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc ///////////////////////////////////////////////////////////////////////////////////////////

void AddStaffMember::processEvent(sf::Event event)
{
    for (int i = 0; i < numCell; i++)
    {
        if (Cell[i].checkEvent(event))
            Texture.draw(Cell[i]);
    }
    Texture.draw(Male);
    Texture.draw(Female);
    Texture.draw(Confirm);
    if (Male.isPressed(event))
    {
        Cell[3].setText("Male");
        Cell[3].drawTexture();
        Texture.draw(Cell[3]);
    }
    if (Female.isPressed(event))
    {
        Cell[3].setText("Female");
        Cell[3].drawTexture();
        Texture.draw(Cell[3]);
    }
    if (Confirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
    {
        fail = 0;
        bool check = 1;
        for (int i = 0; i < numCell; i++)
            check &= (bool)(Cell[i].getText().getSize());
        Date Tmp(std::stoi(std::string(Cell[6].getText())),
                 std::stoi(std::string(Cell[5].getText())),
                 std::stoi(std::string(Cell[4].getText())));
        if (!check)
            fail = empty;
        else if (!Tmp.isValidDate())
            fail = invalid;
        else if (!Backend::StaffMember::createStaffMember(Cell[0].getText()))
            fail = existed;
        else
        {
            auto Staff = Backend::g_staffMembers.back();
            Staff.setDateOfBirth(Tmp);
            Staff.setFirstName(Cell[1].getText());
            Staff.setLastName(Cell[2].getText());
            Staff.setGender(Cell[3].getText());
        }
        drawTexture();
    }
}

bool AddStaffMember::mouseOn(const sf::Vector2i &MousePos)
{
    bool check = 0;
    for (int i = 0; i < numCell; i++)
        check |= Cell[i].mouseOn(MousePos);
    return check;
}

void AddStaffMember::setMouseCursor(const sf::Vector2i &MousePos)
{
    sf::Cursor cursor;
    if (mouseOn(MousePos))
    {
        cursor.loadFromSystem(sf::Cursor::Text);
        window.setMouseCursor(cursor);
    }
}

void AddStaffMember::clearLine()
{
    fail = Clear;
    for (int i = 0; i < numCell; i++)
    {
        Cell[i].erase();
        Cell[i].drawTexture();
    }
    drawTexture();
}

// Destructor //////////////////////////////////////////////////////////////////////////

AddStaffMember::~AddStaffMember()
{
    delete[] Cell;
    delete[] Subtitle;
}