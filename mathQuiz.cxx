#include "mathQuiz.hxx"

using namespace std;

auto addition = [](signed int x, signed int y) -> signed int {return x + y;};
auto subtraction = [](signed int x, signed int y) -> signed int {return x - y;};


int main()
{

    showTitle();
//------------------------------------------------------------------
    modeMenu:

    string userModeChoice_str;
    signed int userModeChoice_si;
    showMenu();
    cout << "\nUser: "; cin >> userModeChoice_str;
    if( userModeChoice_str.length() > 1 || !isdigit(userModeChoice_str[0])
        || stoi(userModeChoice_str) > 3 || stoi(userModeChoice_str) < 1 )
    {
        cout << "\n***You did not enter a valid option!***\n";
        goto modeMenu;
    }
    else
        userModeChoice_si = stoi(userModeChoice_str);

//------------------------------------------------------------------
    difficultyMenu:

    string userDifficultyChoice_str;
    signed int userDifficultyChoice_si;

    showDifficultyMenu();
    cout << "User: ";cin >> userDifficultyChoice_str;

    if( userDifficultyChoice_str.length() > 1 || !isdigit(userDifficultyChoice_str[0])
        || stoi(userDifficultyChoice_str) > 4 || stoi(userDifficultyChoice_str) < 1 )
    {
        if(userDifficultyChoice_str == "b" || userDifficultyChoice_str == "B" )
        {
            goto modeMenu;
        }
        else
        {
            cout << "\n***You did not enter a valid option!***\n";
            goto difficultyMenu;
        }
    }
    else
        userDifficultyChoice_si = stoi(userDifficultyChoice_str);
//------------------------------------------------------------------
    Quizzer quizApp;

    getQuestion:
    srand(time(NULL));

    // quizApp.setXAndY(rand() % 9999, rand() % 9999);
    switch(userDifficultyChoice_si)
    {
        case 1:
            quizApp.setXAndY(rand() % 9, rand() % 9);
            break;
        case 2:
            quizApp.setXAndY(rand() % 99, rand() % 99);
            break;
        case 3:
            quizApp.setXAndY(rand() % 999, rand() % 999);
            break;
        case 4:
            quizApp.setXAndY(rand() % 9999, rand() % 9999);
            break;
    }
//------------------------------------------------------------------
    switch (userModeChoice_si)
    {
        case 1:
        {
            caseOneStart:

            signed int userResponse_si;
            string userResponse_str;

            lineWrapper(quizApp.getProblem('+'), '-');
            std:: cout << quizApp.getProblem('+') <<  "\n\nUser: ";
            cin >> userResponse_str;

            for(auto c : userResponse_str)
            {
                if(!(isdigit(c)))
                {
                    if(c == 'q' || c == 'Q')
                        goto quit;
                    else
                    {
                        cout << "\nInvalid entry!\n";
                        goto caseOneStart;
                    }
                }
            }
            
            userResponse_si = stoi(userResponse_str);

            if(userResponse_si == addition(quizApp.getX(), quizApp.getY()))
            {
                cout << "\nCorrect!\n";
                goto getQuestion;
            }
            else
            {
                cout << "\nIncorrect...the correct answer is: " <<  addition(quizApp.getX(), quizApp.getY()) << "\n\nGame Over\n\n";
                break;
            }
        }
//------------------------------------------------------------------
        case 2:
        {
            caseTwoStart:

            signed int userResponse_si;
            string userResponse_str;

            lineWrapper(quizApp.getProblem('-'), '-');
            std:: cout << quizApp.getProblem('-') << "\n\nUser: ";
            cin >> userResponse_str;
            
            for(auto c : userResponse_str)
            {
                if(!(isdigit(c)))
                {
                    if(c == 'q' || c == 'Q')
                        goto quit;
                    else
                    {
                        cout << "\nInvalid entry!\n";
                        goto caseTwoStart;
                    }
                }
            }
            
            userResponse_si = stoi(userResponse_str);
            
            if(userResponse_si == subtraction(quizApp.getX(), quizApp.getY()))
            {
                cout << "\nCorrect!\n";
                goto getQuestion;
            }
            else
            {
                cout << "\nIncorrect...the correct answer is: " <<  subtraction(quizApp.getX(), quizApp.getY()) << "\n\nGame Over\n\n";
                break;
            }
        }
//------------------------------------------------------------------
        case 3:
            EXIT_SUCCESS;
    }

    quit:
    return 0;
}