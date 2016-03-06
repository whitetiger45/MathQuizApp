#ifndef MATHQUIZ_HXX
#define MATHQUIZ_HXX

#include <ctime>
#include <iostream>
#include <string>

#define func(n, a) void show##n(){std::cout << a << "\n";}
func(Title, "\n*************\n* Math Quiz *\n*************")
#undef func
//----------------------------------------------------------------------------------------------------------------
#define func(n, a) void show##n(){std::cout << a << "\n";}
func(Menu, "\nSelect A Quiz Type:\n===================\n1: Addition\n2: Subtraction\n3: Quit")
func(DifficultyMenu, "(Enter 'b' to return to mode select)\n\nSet a difficulty level by entering 1, 2, 3 or 4")
func(NumberOfQuestionsMenu, "(Enter 'm' to return to mode select and 'b' for difficulty select)\n\nHow many questions do you like to attempt (Max is 20):")
#undef func
//----------------------------------------------------------------------------------------------------------------

auto addition = [](signed int x, signed int y) -> signed int {return x + y;};
auto subtraction = [](signed int x, signed int y) -> signed int {return x - y;};

//----------------------------------------------------------------------------------------------------------------
auto lineWrapper = [](std::string lineToWrap, char c){for(signed int i = 0; i < lineToWrap.size(); i++)std::cout << c; std::cout << "\n";};
auto lineWrapperI = [](unsigned int numOfChars, char c){for(signed int i = 0; i < numOfChars ; i++)std::cout << c; std::cout << "\n";};
class Quizzer
{
    public:

            void setXAndY(signed int x, signed int y)
            {
                m_x = x;
                m_y = y;
                m_xStr = std::to_string(x);
                m_yStr = std::to_string(y);
            }
//----------------------------------------------------------------------------------------------------------------
            void setNumberOfQuestionsCounter(signed int val)
            {
                m_numberOfQuizQuestionsCounter = val;
            }
//----------------------------------------------------------------------------------------------------------------
            void decrementNumberOfQuestionsCounter()
            {
                m_numberOfQuizQuestionsCounter--;
            }
//----------------------------------------------------------------------------------------------------------------
            signed int getNumberOfQuestionsCounter() const
            {
                return m_numberOfQuizQuestionsCounter;
            }
//----------------------------------------------------------------------------------------------------------------
            unsigned int getX() const
            {
                return m_x;
            }
//----------------------------------------------------------------------------------------------------------------
            unsigned int getY() const
            {
                return m_y;
            }
//----------------------------------------------------------------------------------------------------------------
            std::string getXStr() const
            {
                return m_xStr;
            }
//----------------------------------------------------------------------------------------------------------------
            std::string getYStr() const
            {
                return m_yStr;
            }
//----------------------------------------------------------------------------------------------------------------
            std::string getProblem(char op) const
            {
                std::string problem = "(Enter 'q' to quit)\n\nSolve: \n\n" + getXStr() + " " + op + " " + getYStr() + " = ";
                return problem;      
            }
//----------------------------------------------------------------------------------------------------------------
    private:

        signed int m_x;
        signed int m_y;
        std::string m_xStr;
        std::string m_yStr;
        signed int m_numberOfZerosToAddX = 0;
        signed int m_numberOfZerosToAddY = 0;
        signed int m_numberOfQuizQuestionsCounter = 0;

};
#endif // MATHQUIZ_HXX
