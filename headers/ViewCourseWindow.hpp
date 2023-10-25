#include <TextBox.hpp>
#include <ButtonTable.hpp>
#include <StudentTable.hpp>
#include <Layer.hpp>
#include <Page.hpp>

class ViewCourseWindow : public sf::Drawable
{
public:
    // Constructor

    ViewCourseWindow();
    void create();

    // Draw

    void Predraw();
    void FirstDraw();
    void drawTexture(const Layer &layer);

    // Misc

    void processEvent(sf::Event event, const Layer &layer);
    bool mouseOn(const sf::Vector2i &MousePos, const Layer &layer);
    void clearLine();

    // Destructor

    ~ViewCourseWindow();

protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

private:
    sf::RectangleShape Background;
    sf::RenderTexture Texture;
    sf::Text Title, CourseInput;
    TextBox CourseName;
    Button CourseConfirm;
    ButtonTable CourseList;
    Page pages;

    sf::Text Course;
    Button Update;
    Button Delete;
    Button AddStudent;
    Button RemoveStudent;
    Button viewStudent;
    Button viewScoreboard;

    // Update Course Information

    sf::Text UpdateTitle, Smt, ScY, *Subtitle, UpdEmptyFail, UpdClassFail, UpdExistFail, UpdSuccess;
    Button Semester;
    Button SchoolYear;
    TextBox *Cell;
    Button Confirm;
    Button *DoW;
    Button *Session;
    const int numCell = 8, numDoW = 6, numSes = 4,
              Updempty = 1, UpdClassNotFound = 2, Updexisted = 3;

    // Delete Course

    sf::Text Caution, DeleteSuccess;

    // Add student

    sf::Text AddTitle;
    sf::Text AddExistFail, AddSuccess;
    const int Addexisted = 4;

    // Remove student

    sf::Text RemoveTitle;
    sf::Text RmvFail, RmvSuccess;
    const int RmvNotFound = 5;

    // Add and remove window

    sf::Text StdTitle;
    TextBox StdID;
    Button StdConfirm;

    // List of students

    sf::Text StdList;
    StudentTable StudentList;

    // Scoreboard

    sf::Text ScbTitle;
    ButtonTable UpdateScb;

    // Update Scoreboard

    sf::Text UpdateScbTitle;
    TextBox *Mark;
    const int numMark = 4, markFail = 6;

    // Common

    int fail;
    const int Clear = INT_MAX;
};