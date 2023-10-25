#include <SetStudentWindow.hpp>
#include <FrontendGlobal.hpp>
#include <BackendGlobal.hpp>

SetStudentWindow::SetStudentWindow()
{
}

void SetStudentWindow::create()
{
    // Background

    Texture.create(window.getSize().x, window.getSize().y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(window.getSize()));
    Background.setFillColor(BackgroundColor);

    // Title

    Title.setString("Student");
    Title.setFillColor(sf::Color::Black);
    Title.setFont(LightFont);
    Title.setCharacterSize(40);
    Title.setStyle(sf::Text::Bold);
    Title.setPosition(100, 100);

    // Add

    Add.create(150, 150, 300, 75, BoldFont, 30, "Add");
    Add.setFillColor(sf::Color(9, 66, 55, 255));
    Add.setTextColor(sf::Color::White);
    Add.setCoverColor(sf::Color(30, 100, 70, 200));

    // Load from file

    FromFile.create(150, 250, 300, 75, RegularFont, 30, "Load from file");
    FromFile.setFillColor(sf::Color(60, 60, 60, 255));
    FromFile.setTextColor(sf::Color::White);
    FromFile.setCoverColor(sf::Color(55, 55, 55, 200));

    Tutorial.setString("(Press this button to load info from all <Classname>.csv");
    Tutorial.setFillColor(sf::Color(16, 63, 145, 255));
    Tutorial.setFont(LightFont);
    Tutorial.setCharacterSize(20);
    Tutorial.setStyle(sf::Text::Bold);
    Tutorial.setPosition(150, 350);

    // Remove

    Remove.create(500, 150, 300, 75, BoldFont, 30, "Remove");
    Remove.setFillColor(sf::Color(9, 66, 55, 255));
    Remove.setTextColor(sf::Color::White);
    Remove.setCoverColor(sf::Color(30, 100, 70, 200));

    // Fail : Add File fail

    FailFile.setFont(RegularFont);
    FailFile.setCharacterSize(20);
    FailFile.setFillColor(sf::Color(168, 30, 20, 255));
    FailFile.setString("Load info from file failed!");
    FailFile.setPosition(150, 400);

    // Success

    FileAdd.setFont(RegularFont);
    FileAdd.setCharacterSize(20);
    FileAdd.setFillColor(sf::Color(144, 212, 58, 255));
    FileAdd.setString("Load info successfully!");
    FileAdd.setPosition(150, 400);

    // Add title

    AddTitle.setString("Add student");
    AddTitle.setFillColor(sf::Color::Black);
    AddTitle.setFont(LightFont);
    AddTitle.setCharacterSize(40);
    AddTitle.setStyle(sf::Text::Bold);
    AddTitle.setPosition(100, 100);

    // Remove title

    RemoveTitle.setString("Remove student");
    RemoveTitle.setFillColor(sf::Color::Black);
    RemoveTitle.setFont(LightFont);
    RemoveTitle.setCharacterSize(40);
    RemoveTitle.setStyle(sf::Text::Bold);
    RemoveTitle.setPosition(100, 100);

    // Class name

    InputClass.setString("Class name: ");
    InputClass.setFillColor(sf::Color::Black);
    InputClass.setFont(LightFont);
    InputClass.setCharacterSize(18);
    InputClass.setStyle(sf::Text::Bold);
    InputClass.setPosition(200, 200);

    ClassName.create(0, 0, 250, 50, 18, sf::Vector2f(8, 25));
    ClassName.setCaret();
    ClassName.setTyping();
    ClassName.setOpacity();
    ClassName.setFont(RegularFont);
    ClassName.setFillColor(BackgroundColor);
    ClassName.setTextColor();
    ClassName.setOutlineColor(sf::Color(25, 89, 34, 255), sf::Color::Cyan);
    ClassName.setPosition(300, 195);

    ClassConfirm.create(500, 195, 150, 50, RegularFont, 18, "Confirm");
    ClassConfirm.setFillColor(sf::Color(60, 60, 60, 255));
    ClassConfirm.setTextColor(sf::Color::White);
    ClassConfirm.setCoverColor(sf::Color(55, 55, 55, 200));

    // Button class

    ClassList.create(5, 5, 180, 50, 30, 30, RegularFont, 18);
    ClassList.setPosition(200, 300);
    ClassList.setFillColor(sf::Color(25, 89, 34, 255));
    ClassList.setTextColor(sf::Color::White);
    ClassList.setCoverColor(sf::Color(50, 120, 60, 255));

    // Pages

    pages.create();
    pages.setPosition(550 + ClassList.getPosition().x, ClassList.getPosition().y + ClassList.getHeight() + 30);

    // Function window

    Class.setString("");
    Class.setFillColor(sf::Color::Black);
    Class.setFont(LightFont);
    Class.setCharacterSize(40);
    Class.setStyle(sf::Text::Bold);
    Class.setPosition(100, 100);

    // Infomation cells

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
        // Student ID
        {
            Subtitle[0].setString("Student ID:");
            Subtitle[0].setPosition(300, 200);

            Cell[0].create(0, 0, 350, 50, 18, sf::Vector2f(8, 25));
            Cell[0].setPosition(300, 235);
            Cell[0].setNumber();
        }
        // Social ID
        {
            Subtitle[1].setString("Social ID:");
            Subtitle[1].setPosition(700, 200);

            Cell[1].create(0, 0, 500, 50, 18, sf::Vector2f(8, 25));
            Cell[1].setPosition(700, 235);
            Cell[1].setNumber();
        }
        // First Name
        {
            Subtitle[2].setString("First name:");
            Subtitle[2].setPosition(300, 300);

            Cell[2].create(0, 0, 500, 50, 18, sf::Vector2f(8, 25));
            Cell[2].setPosition(300, 335);
        }
        // Last Name
        {
            Subtitle[3].setString("Last name:");
            Subtitle[3].setPosition(900, 300);

            Cell[3].create(0, 0, 250, 50, 18, sf::Vector2f(8, 25));
            Cell[3].setPosition(900, 335);
        }
        // Gender
        {
            Subtitle[4].setString("Gender:");
            Subtitle[4].setPosition(300, 400);

            Cell[4].create(0, 0, 100, 50, 18, sf::Vector2f(8, 25));
            Cell[4].setPosition(300, 435);

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
                Subtitle[5].setString("Day:");
                Subtitle[5].setPosition(350, 555);

                Cell[5].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                Cell[5].setPosition(450, 550);
                Cell[5].setLimit(2);
                Cell[5].setNumber();
            }
            // Month
            {
                Subtitle[6].setString("Month:");
                Subtitle[6].setPosition(350, 625);

                Cell[6].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                Cell[6].setPosition(450, 620);
                Cell[6].setLimit(2);
                Cell[6].setNumber();
            }
            // Year
            {
                Subtitle[7].setString("Year:");
                Subtitle[7].setPosition(350, 695);

                Cell[7].create(0, 0, 100, 40, 18, sf::Vector2f(8, 20));
                Cell[7].setPosition(450, 690);
                Cell[7].setLimit(4);
                Cell[7].setNumber();
            }
        }
    }

    // Setup for all cells

    for (int i = 0; i < numCell; i++)
    {
        if (i != 4)
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

    // Add
    {
        // Fail : Empty cell

        EmptyFail.setFont(RegularFont);
        EmptyFail.setCharacterSize(20);
        EmptyFail.setFillColor(sf::Color(168, 30, 20, 255));
        EmptyFail.setString("Failed: Cells can not be empty!");
        EmptyFail.setPosition(400, 780);

        // Fail : Invalid Date type

        DateFail.setFont(RegularFont);
        DateFail.setCharacterSize(20);
        DateFail.setFillColor(sf::Color(168, 30, 20, 255));
        DateFail.setString("Failed: Invalid Date!");
        DateFail.setPosition(400, 780);

        // Fail : Existed Student

        ExistFail.setFont(RegularFont);
        ExistFail.setCharacterSize(20);
        ExistFail.setFillColor(sf::Color(168, 30, 20, 255));
        ExistFail.setString("Failed: Student existed!");
        ExistFail.setPosition(400, 780);

        // Success

        ManualAdd.setFont(RegularFont);
        ManualAdd.setCharacterSize(20);
        ManualAdd.setFillColor(sf::Color(144, 212, 58, 255));
        ManualAdd.setString("Add Student successfully!");
        ManualAdd.setPosition(400, 780);

        // Confirm Button

        StudentConfirm.create(650, 850, 150, 50, BoldFont, 24, "Confirm");
        StudentConfirm.setFillColor(sf::Color(25, 89, 34, 255));
        StudentConfirm.setTextColor(sf::Color::White);
        StudentConfirm.setCoverColor(sf::Color(20, 85, 30, 200));
    }

    // Remove
    {
        // Fail : Empty cell

        RemoveEmptyFail.setFont(RegularFont);
        RemoveEmptyFail.setCharacterSize(20);
        RemoveEmptyFail.setFillColor(sf::Color(168, 30, 20, 255));
        RemoveEmptyFail.setString("Failed: Student ID can not be empty!");
        RemoveEmptyFail.setPosition(300, 310);

        // Fail : Not found student

        RemoveFoundFail.setFont(RegularFont);
        RemoveFoundFail.setCharacterSize(20);
        RemoveFoundFail.setFillColor(sf::Color(168, 30, 20, 255));
        RemoveFoundFail.setString("Failed: Not found student!");
        RemoveFoundFail.setPosition(300, 310);

        // Success

        RemoveSuccess.setFont(RegularFont);
        RemoveSuccess.setCharacterSize(20);
        RemoveSuccess.setFillColor(sf::Color(144, 212, 58, 255));
        RemoveSuccess.setString("Add Student successfully!");
        RemoveSuccess.setPosition(300, 310);

        // Confirm Button

        RemoveConfirm.create(375, 340, 150, 50, BoldFont, 24, "Confirm");
        RemoveConfirm.setFillColor(sf::Color(25, 89, 34, 255));
        RemoveConfirm.setTextColor(sf::Color::White);
        RemoveConfirm.setCoverColor(sf::Color(20, 85, 30, 200));
    }

    // Pre-draw

    Prepare();

    // Setup

    fail = Clear;
    NumPage = 0;
    TotalPage = 0;
    type = 0;
}

// Draw //////////////////////////////////////////////////////////////////////////////////////////////////////////

void SetStudentWindow::Prepare()
{
    Add.drawTexture();
    Remove.drawTexture();
    FromFile.drawTexture();
    ClassName.drawTexture();
    ClassConfirm.drawTexture();
    Male.drawTexture();
    Female.drawTexture();
    for (int i = 0; i < numCell; i++)
        Cell[i].drawTexture();
    StudentConfirm.drawTexture();
    RemoveConfirm.drawTexture();

    Texture.draw(Background);
    Texture.draw(Title);
    Texture.draw(Add);
    Texture.draw(Remove);
    Texture.draw(FromFile);
    Texture.draw(Tutorial);
    Texture.display();
}

void SetStudentWindow::FirstDraw()
{
    Texture.draw(Background);
    if (Temp)
        Texture.draw(*Temp);
    Texture.draw(InputClass);
    Texture.draw(ClassName);
    Texture.draw(ClassConfirm);
    NumPage = 1;
    TotalPage = ((Backend::g_classes.size()) ? (Backend::g_classes.size() / MAX_CELL + (bool)(Backend::g_classes.size() % MAX_CELL)) : 1);
    ClassList.drawTexture(Backend::g_classes, 1);
    pages.setPage(NumPage, TotalPage);
    Texture.draw(ClassList);
    Texture.draw(pages);
}

void SetStudentWindow::drawTexture(const Layer &layer)
{
    Texture.draw(Background);
    if (layer == Std)
    {
        Texture.draw(Title);
        Texture.draw(Add);
        Texture.draw(Remove);
        Texture.draw(FromFile);
        Texture.draw(Tutorial);
        if (fail == AddFileFail)
            Texture.draw(FailFile);
        if (!fail)
            Texture.draw(FileAdd);
    }
    if (layer == LStd)
    {
        if (Temp)
            Texture.draw(*Temp);
        Texture.draw(InputClass);
        Texture.draw(ClassName);
        Texture.draw(ClassConfirm);
        if (fail == EmptyClass)
            Texture.draw(EmptyClassFail);
        if (fail == notFound)
            Texture.draw(FoundFail);
        Texture.draw(ClassList);
        Texture.draw(pages);
    }
    if (layer == AStdM)
    {
        Texture.draw(Class);
        for (int i = 0; i < numCell; i++)
        {
            Texture.draw(Subtitle[i]);
            Texture.draw(Cell[i]);
        }
        Texture.draw(Male);
        Texture.draw(Female);
        Texture.draw(StudentConfirm);
        if (fail == empty)
            Texture.draw(EmptyFail);
        if (fail == date)
            Texture.draw(DateFail);
        if (fail == existed)
            Texture.draw(ExistFail);
        if (!fail)
            Texture.draw(ManualAdd);
    }
    if (layer == RStd)
    {
        Texture.draw(Class);
        Texture.draw(Subtitle[0]);
        Texture.draw(Cell[0]);
        Texture.draw(RemoveConfirm);
        if (fail == emptyremove)
            Texture.draw(RemoveEmptyFail);
        if (fail == notFoundStd)
            Texture.draw(RemoveFoundFail);
        if (!fail)
            Texture.draw(RemoveSuccess);
    }
    Texture.display();
}

void SetStudentWindow::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SetStudentWindow::processEvent(sf::Event event, Layer &layer)
{
    if (layer == Std)
    {
        Texture.draw(Add);
        Texture.draw(FromFile);
        Texture.draw(Remove);
        if (FromFile.isPressed(event))
        {
            fail = 0;

            drawTexture(layer);
        }
        if (Add.isPressed(event))
        {
            layer = LStd;
            clearLine();
            type = add;
            Temp = &AddTitle;
            drawTexture(layer);
        }
        if (Remove.isPressed(event))
        {
            layer = LStd;
            clearLine();
            type = remove;
            Temp = &RemoveTitle;
            drawTexture(layer);
        }
    }
    if (layer == LStd)
    {
        Texture.draw(Background);
        if (ClassName.checkEvent(event))
            Texture.draw(ClassName);
        if (ClassList.isPressed(event))
        {
            ClassName.setText(ClassList.getText());
            ClassName.drawTexture();
            Texture.draw(ClassName);
        }
        Texture.draw(ClassList);
        Texture.draw(pages);
        bool Check = 0;
        pages.processEvent(event, NumPage, TotalPage, Check);
        if (Check)
        {
            ClassList.drawTexture(Backend::g_classes, NumPage);
            drawTexture(layer);
        }
        Texture.draw(ClassConfirm);
        if (ClassConfirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            if (ClassName.getText() == "")
                fail = EmptyClass;
            CurClass = Backend::g_classes.find_if(
                [&](const Backend::Class &a) -> bool
                {
                    return a.getID() == ClassName.getText();
                });
            if (fail != empty && CurClass == Backend::g_classes.end())
                fail = notFound;
            else if (!fail)
            {
                Class.setString(ClassName.getText());
                if (type == add)
                    layer = AStdM;
                if (type == remove)
                    layer = RStd;
                clearLine();
            }
            drawTexture(layer);
        }
    }
    if (layer == AStdM)
    {
        for (int i = 0; i < numCell; i++)
            if (Cell[i].checkEvent(event))
                Texture.draw(Cell[i]);
        Texture.draw(StudentConfirm);
        if (StudentConfirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
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
                fail = date;
            else
            {
                
                
            }
            drawTexture(layer);
        }
    }
    if (layer == RStd)
    {
        if (Cell[0].checkEvent(event))
            Texture.draw(Cell[0]);
        Texture.draw(RemoveConfirm);
        if (RemoveConfirm.isPressed(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter))
        {
            fail = 0;
            if (!Cell[0].getText().getSize())
                fail = emptyremove;
        }
    }
}

bool SetStudentWindow::mouseOn(const sf::Vector2i &MousePos, const Layer &layer)
{
    if (layer == LStd)
        return ClassName.mouseOn(MousePos);
    if (layer == AStdM)
    {
        bool check = 0;
        for (int i = 0; i < numCell; i++)
            check |= Cell[i].mouseOn(MousePos);
        return check;
    }
    if (layer == RStd)
        return Cell[0].mouseOn(MousePos);
    return false;
}

void SetStudentWindow::clearLine()
{
    ClassName.erase();
    for (int i = 0; i < numCell; i++)
        Cell[i].erase();
    fail = Clear;
}

void SetStudentWindow::resetFail()
{
    fail = Clear;
}

// Destructor /////////////////////////////////////////////////////////////////////////////////////////////////////////

SetStudentWindow::~SetStudentWindow()
{
    delete[] Subtitle;
    delete[] Cell;
}