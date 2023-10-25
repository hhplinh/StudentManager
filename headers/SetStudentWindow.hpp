#pragma once
#include <TextBox.hpp>
#include <ButtonTable.hpp>
#include <Layer.hpp>
#include <Page.hpp>
#include <Class.hpp>

class SetStudentWindow : public sf::Drawable
{
public:
    // Constructor

    SetStudentWindow();
    void create();

    // Draw

    void Prepare();
    void FirstDraw();
    void drawTexture(const Layer &layer);

    // Misc

    void processEvent(sf::Event event, Layer &layer);
    bool mouseOn(const sf::Vector2i &MousePos, const Layer &layer);
    void clearLine();
    void resetFail();

    // Destructor

    ~SetStudentWindow();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    Button Add;
    Button Remove;
    Button RemoveConfirm;
    Button FromFile;
    Button ClassConfirm;
    sf::RectangleShape Background;
    sf::RenderTexture Texture;
    TextBox ClassName;
    ButtonTable ClassList;
    Page pages;
    sf::Text Title, AddTitle, RemoveTitle, *Temp,
        RemoveEmptyFail, RemoveFoundFail, RemoveSuccess,
        InputClass, Class, FoundFail, EmptyClassFail,
        FileAdd, FailFile, Tutorial,
        ManualAdd, EmptyFail, DateFail, ExistFail, DOB;
    Iterator <Backend::Class> CurClass;
    sf::Text *Subtitle;
    TextBox *Cell;
    Button Male, Female;
    Button StudentConfirm;
    int NumPage, TotalPage;
    int fail, type;
    const int numCell = 8,
              add = 1, remove = 2,
              notFoundStd = 10, emptyremove = 11,
              EmptyClass = 1, notFound = 2,
              AddFileFail = 3,
              empty = 4, date = 5, existed = 6,
              Clear = INT_MAX,
              MAX_CELL = 25;
    const Layer Std = Layer(1, 50),
                LStd = Layer(2, 50),
                AStdM = Layer(3, 50),
                RStd = Layer(2, 100);
};