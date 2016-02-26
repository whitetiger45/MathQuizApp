#ifndef MATHQUIZ_HXX
#define MATHQUIZ_HXX

#include <ctime>
#include <iostream>
#include <string>

#define func(n, a) void show##n(){std::cout << a << "\n";}
func(Title, "\n* Math Quiz *")
#undef func

#define func(n, a) void show##n(){std::cout << a << "\n";}
func(Menu, "\nSelect A Quiz Type:\n=========\n1: Addition\n2: Subtraction\n3: Quit")
func(DifficultyMenu, "\nSet a difficulty level by entering 1, 2, 3 or 4 (Enter 'b' to return to mode select)")
#undef func

auto lineWrapper = [](std::string lineToWrap, char c){for(signed int i = 0; i < lineToWrap.size(); i++)std::cout << c; std::cout << "\n";};

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

            unsigned int getX() const
            {
                return m_x;
            }

            unsigned int getY() const
            {
                return m_y;
            }

            std::string getXStr() const
            {
                return m_xStr;
            }

            std::string getYStr() const
            {
                return m_yStr;
            }

            std::string getProblem(char op) const
            {
                    std::string problem = "*(Enter 'q' to quit)*\nSolve: \n\n" + getXStr() + " " + op + " " + getYStr() + " = ";
                    return problem;      
            }


    private:

        signed int m_x;
        signed int m_y;
        std::string m_xStr;
        std::string m_yStr;
        signed int m_numberOfZerosToAddX = 0;
        signed int m_numberOfZerosToAddY = 0;

};
#endif // MATHQUIZ_HXX