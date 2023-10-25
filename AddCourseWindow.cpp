#include <AddCourseWindow.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>

AddCourseWindow::AddCourseWindow()
{
}

void AddCourseWindow::create()
{
    // Background

    Texture.create(LeftWindowWidth, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(Texture.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("Add course");
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
        // Semester
        {
            Smt.setFillColor(sf::Color::Black);
            Smt.setFont(RegularFont);
            Smt.setCharacterSize(20);
            Smt.setString("Semester:");
            Smt.setPosition(300, 200);

            Semester.create(400, 195, 30, 30, RegularFont, 18, "");
            Semester.setTextColor(sf::Color::Black);
        }

        // School year
        {
            ScY.setFillColor(sf::Color::Black);
            ScY.setFont(RegularFont);
            ScY.setCharacterSize(20);
            ScY.setString("School year:");
            ScY.setPosition(550, 200);

            SchoolYear.create(660, 195, 150, 50, RegularFont, 18, "");
            SchoolYear.setTextColor(sf::Color::Black);
        }

        // Course ID
        {
            Subtitle[0].setString("Course ID:");
            Subtitle[0].setPosition(300, 270);

            Cell[0].create(0, 0, 350, 50, 18, sf::Vector2f(8, 25));
            Cell[0].setPosition(300, 305);
        }

        // Course Name
        {
            Subtitle[1].setString("Course name:");
            Subtitle[1].setPosition(300, 400);

            Cell[1].create(0, 0, 800, 50, 18, sf::Vector2f(8, 25));
            Cell[1].setPosition(300, 435);
        }

        // Class Name
        {
            Subtitle[2].setString("Class name:");
            Subtitle[2].setPosition(300, 500);

            Cell[2].create(0, 0, 250, 50, 18, sf::Vector2f(8, 25));
            Cell[2].setPosition(300, 535);
        }

        // Teacher Name
        {
            Subtitle[3].setString("Teacher name:");
            Subtitle[3].setPosition(650, 500);

            Cell[3].create(0, 0, 750, 50, 18, sf::Vector2f(8, 25));
            Cell[3].setPosition(650, 535);
        }

        // Number of Credits
        {
            Subtitle[4].setString("No. Credits:");
            Subtitle[4].setPosition(300, 600);

            Cell[4].create(0, 0, 50, 50, 18, sf::Vector2f(8, 25));
            Cell[4].setPosition(400, 590);
            Cell[4].setNumber();
            Cell[4].setLimit(2);
        }

        // Number of Students
        {
            Subtitle[5].setString("No. Students:");
            Subtitle[5].setPosition(550, 600);

            Cell[5].create(0, 0, 50, 50, 18, sf::Vector2f(8, 25));
            Cell[5].setPosition(670, 590);
            Cell[5].setNumber();
            Cell[5].setLimit(2);
            Cell[5].setText("50");
        }

        // Day of Week
        {
            Subtitle[6].setString("Day of week:");
            Subtitle[6].setPosition(300, 700);

            Cell[6].create(0, 0, 60, 30, 18, sf::Vector2f(8, 25));
            Cell[6].setPosition(450, 698);

            // Button
            {
                sf::String *Tmp;
                Tmp = new sf::String[numDoW];
                Tmp[0] = "MON";
                Tmp[1] = "TUE";
                Tmp[2] = "WED";
                Tmp[3] = "THU";
                Tmp[4] = "FRI";
                Tmp[5] = "SAT";
                DoW = new Button[numDoW];
                for (int i = 0; i < numDoW; i++)
                {
                    DoW[i].create(550 + 90 * i, 698, 60, 30, RegularFont, 16, Tmp[i]);
                    DoW[i].setFillColor(sf::Color(25, 89, 34, 255));
                    DoW[i].setTextColor(sf::Color::White);
                    DoW[i].setCoverColor(sf::Color(20, 85, 30, 200));
                }
                delete[] Tmp;
            }
        }

        // Session
        {
            Subtitle[7].setString("Day of week:");
            Subtitle[7].setPosition(300, 770);

            Cell[7].create(0, 0, 30, 30, 18, sf::Vector2f(8, 25));
            Cell[7].setPosition(450, 768);

            // Button
            {
                sf::String *Tmp;
                Tmp = new sf::String[numSes];
                Tmp[0] = "S1";
                Tmp[1] = "S2";
                Tmp[2] = "S3";
                Tmp[3] = "S4";
                Session = new Button[numSes];
                for (int i = 0; i < numSes; i++)
                {
                    Session[i].create(550 + 60 * i, 768, 30, 30, RegularFont, 16, Tmp[i]);
                    Session[i].setFillColor(sf::Color(25, 89, 34, 255));
                    Session[i].setTextColor(sf::Color::White);
                    Session[i].setCoverColor(sf::Color(20, 85, 30, 200));
                }
                delete[] Tmp;
            }
        }
    }

    // Setup for all cells

    for (int i = 0; i < numCell; i++)
    {
        if (i < 6)
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

    // Fail : Empty cell

    EmptyFail.setFont(RegularFont);
    EmptyFail.setCharacterSize(20);
    EmptyFail.setFillColor(sf::Color(168, 30, 20, 255));
    EmptyFail.setString("Failed: Cells can not be empty!");
    EmptyFail.setPosition(400, 800);

    // Fail : Class not found

    ClassFail.setFont(RegularFont);
    ClassFail.setCharacterSize(20);
    ClassFail.setFillColor(sf::Color(168, 30, 20, 255));
    ClassFail.setString("Failed: Class not found!");
    ClassFail.setPosition(400, 800);

    // Fail : Course existed

    ExistFail.setFont(RegularFont);
    ExistFail.setCharacterSize(20);
    ExistFail.setFillColor(sf::Color(168, 30, 20, 255));
    ExistFail.setString("Failed: Course existed!");
    ExistFail.setPosition(400, 800);

    // Success

    Success.setFont(RegularFont);
    Success.setCharacterSize(20);
    Success.setFillColor(sf::Color(168, 30, 20, 255));
    Success.setString("Add course successfully!");
    Success.setPosition(400, 800);

    // Confirm Button

    Confirm.create(700, 850, 150, 50, BoldFont, 24, "Confirm");
    Confirm.setFillColor(sf::Color(25, 89, 34, 255));
    Confirm.setTextColor(sf::Color::White);
    Confirm.setCoverColor(sf::Color(20, 85, 30, 200));

    // Pre-draw

    Prepare();

    // Setup

    fail = Clear;
}

// Draw //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AddCourseWindow::Prepare()
{
    Semester.drawTexture();
    SchoolYear.drawTexture();
    for (int i = 0; i < numCell; i++)
        Cell[i].drawTexture();
    for (int i = 0; i < numDoW; i++)
        DoW[i].drawTexture();
    for (int i = 0; i < numSes; i++)
        Session[i].drawTexture();
    Confirm.drawTexture();

    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(Smt);
    Texture.draw(Semester);
    Texture.draw(ScY);
    Texture.draw(SchoolYear);
    for (int i = 0; i < numCell; i++)
    {
        Texture.draw(Subtitle[i]);
        Texture.draw(Cell[i]);
    }
    for (int i = 0; i < numDoW; i++)
        Texture.draw(DoW[i]);
    for (int i = 0; i < numSes; i++)
        Texture.draw(Session[i]);
    Texture.draw(Confirm);
    Texture.display();
}

void AddCourseWindow::FirstDraw()
{
    Semester.setText(std::to_string(Backend::activeSemester->getID()));
    Semester.setTextPos();
    Semester.drawTexture();
    int Start = Backend::activeSemester->schoolYear()->getStartYear();
    int End = Start + 1;
    SchoolYear.setText(std::to_string(Start) + '-' + std::to_string(End));
    SchoolYear.setTextPos();
    SchoolYear.drawTexture();
    Texture.draw(Semester);
    Texture.draw(SchoolYear);
    Texture.display();
}

void AddCourseWindow::drawTexture()
{
    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(Smt);
    Texture.draw(Semester);
    Texture.draw(ScY);
    Texture.draw(SchoolYear);
    for (int i = 0; i < numCell; i++)
    {
        Texture.draw(Subtitle[i]);
        Texture.draw(Cell[i]);
    }
    for (int i = 0; i < numDoW; i++)
        Texture.draw(DoW[i]);
    for (int i = 0; i < numSes; i++)
        Texture.draw(Session[i]);
    if (fail == empty)
        Texture.draw(EmptyFail);
    if (fail == ClassNotFound)
        Texture.draw(ClassFail);
    if (fail == existed)
        Texture.draw(ExistFail);
    if (!fail)
        Texture.draw(Success);
    Texture.draw(Confirm);
    Texture.display();
}

void AddCourseWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc ////////////////////////////////////////////////////////////////////////////////////////////

void AddCourseWindow::processEvent(sf::Event event)
{
    for (int i = 0; i < numCell; i++)
        if (Cell[i].checkEvent(event))
            Texture.draw(Cell[i]);
    for (int i = 0; i < numDoW; i++)
    {
        Texture.draw(DoW[i]);
        if (DoW[i].isPressed(event))
        {
            Cell[6].setText(DoW[i].getText());
            Cell[6].drawTexture();
            Texture.draw(Cell[6]);
        }
    }
    for (int i = 0; i < numSes; i++)
    {
        Texture.draw(Session[i]);
        if (Session[i].isPressed(event))
        {
            Cell[7].setText(Session[i].getText());
            Cell[7].drawTexture();
            Texture.draw(Cell[7]);
        }
    }
    Texture.draw(Confirm);
    if (Confirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
    {
        fail = 0;
        bool check = 1;
        for (int i = 0; i < numCell; i++)
            check &= (bool)(Cell[i].getText().getSize());
        if (!check)
            fail = empty;
        if (!fail)
        {
        }
        drawTexture();
    }
}

bool AddCourseWindow::mouseOn(const sf::Vector2i &MousePos, const Layer &layer)
{
    if (layer == ACrs)
    {
        bool check = 0;
        for (int i = 0; i < 6; i++)
            check |= Cell[i].mouseOn(MousePos);
        return check;
    }
    return false;
}

void AddCourseWindow::clearLine()
{
    for (int i = 0; i < numCell; i++)
        Cell[i].erase();
    fail = Clear;
}

// Destructor ////////////////////////////////////////////////////////////////////////////////////////////

AddCourseWindow::~AddCourseWindow()
{
    delete[] Cell;
    delete[] DoW;
    delete[] Session;
}