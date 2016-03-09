#include "mathQuiz.hxx"

using namespace std;

int main()
{
    showTitle();
    Quizzer quizApp;
//---------------------------------------------------------------------------------------------------------------------------------------------
    modeMenu:

    string userModeChoice_str;
    signed int userModeChoice_si;

    showMenu();
    cout << "\nUser: "; cin >> userModeChoice_str;

    if( userModeChoice_str.length() > 1 || !isdigit(userModeChoice_str[0])
        || stoi(userModeChoice_str) > 3 || stoi(userModeChoice_str) < 1 )
    {
        cout << "\n*** You did not enter a valid option ***\n";
        goto modeMenu;
    }
    else
        userModeChoice_si = stoi(userModeChoice_str);

//---------------------------------------------------------------------------------------------------------------------------------------------
    do
    {
        difficultyMenu:

        string userDifficultyChoice_str;
        signed int userDifficultyChoice_si;

        if(userModeChoice_si == 3)
            break;

        cout << endl; lineWrapperI(85, '-');
        cout << "Difficulty Select\n";
        lineWrapper(string("Difficulty Select\n"), '-');
        showDifficultyMenu();
        cout << "\nUser: ";cin >> userDifficultyChoice_str;
        lineWrapperI(85, '-');

        if( userDifficultyChoice_str.length() > 1 || !isdigit(userDifficultyChoice_str[0])
            || stoi(userDifficultyChoice_str) > 4 || stoi(userDifficultyChoice_str) < 1 )
        {
            if(userDifficultyChoice_str == "b" || userDifficultyChoice_str == "B" )
            {
                goto modeMenu;
            }
            else
            {
                cout << "\n*** You did not enter a valid option ***\n";
                goto difficultyMenu;
            }
        }
        else
            userDifficultyChoice_si = stoi(userDifficultyChoice_str);
//---------------------------------------------------------------------------------------------------------------------------------------------
        numberOfQuestionsMenu:
        string userNumberOfQuestionsResponse_str;

        cout << "Set Quiz Length\n";
        lineWrapper(string("Set Quiz Length\n"), '-');
        showNumberOfQuestionsMenu(); 
        cout << "\nUser: "; cin >> userNumberOfQuestionsResponse_str;

        if(userNumberOfQuestionsResponse_str == "m" || userNumberOfQuestionsResponse_str == "M")
            goto modeMenu;
        else if(userNumberOfQuestionsResponse_str == "b" || userNumberOfQuestionsResponse_str == "B")
            goto difficultyMenu;
        else if(userNumberOfQuestionsResponse_str.length() > 2)
        {
            cout << "\n*** The maximum number of questions in a quiz is 20 ***\n";
            goto numberOfQuestionsMenu;
        }
        
        if(userNumberOfQuestionsResponse_str.length() == 1)
        {
            if(!isdigit(userNumberOfQuestionsResponse_str[0])
                || stoi(userNumberOfQuestionsResponse_str) > 20 
                || stoi(userNumberOfQuestionsResponse_str) < 1 )
            {
                cout << "\n*** You did not enter a valid option ***\n";
                goto numberOfQuestionsMenu;
            }
            else
                quizApp.setNumberOfQuestionsCounter(stoi(userNumberOfQuestionsResponse_str));
        }
        else if(userNumberOfQuestionsResponse_str.length() == 2)
        {
            if(!isdigit(userNumberOfQuestionsResponse_str[0])
                || !isdigit(userNumberOfQuestionsResponse_str[1])
                || stoi(userNumberOfQuestionsResponse_str) > 20 
                || stoi(userNumberOfQuestionsResponse_str) < 1 )
            {
                cout << "\n*** You did not enter a valid option ***\n";
                goto numberOfQuestionsMenu;
            }
            else
                quizApp.setNumberOfQuestionsCounter(stoi(userNumberOfQuestionsResponse_str));
        }
//---------------------------------------------------------------------------------------------------------------------------------------------
        timedModeMenu:
        string userTimedModeResponse_str;

        lineWrapperI(85, '-');
        cout << "Set Timer\n";
        lineWrapper(string("Set Timer\n"), '-');
        showTimedModeMenu(); 
        cout << "\nUser: "; cin >> userTimedModeResponse_str;

        if(userTimedModeResponse_str == "m" || userTimedModeResponse_str == "M")
            goto modeMenu;
        else if(userTimedModeResponse_str == "d" || userTimedModeResponse_str == "D")
            goto difficultyMenu;
        else if(userTimedModeResponse_str == "b" || userTimedModeResponse_str == "B")
            goto numberOfQuestionsMenu;
        else if(userTimedModeResponse_str.length() > 2)
        {
            cout << "\n*** You entered more than one character ***\n";
            goto timedModeMenu;
        }
        else if(!isalpha(userTimedModeResponse_str[0]))
        {
            cout << "\n*** You did not enter a valid character ***\n";
            goto timedModeMenu;
        }
        else if(userTimedModeResponse_str == "y" || userTimedModeResponse_str == "Y")
        {
            if(!quizApp.timedModeEnabled())
            {
                quizApp.enableTimedMode();
            }
        }
//---------------------------------------------------------------------------------------------------------------------------------------------
        getQuestion:

        if(quizApp.getNumberOfQuestionsCounter() == 0)
        {
            cout << "\nYou have answered all the quiz questions correctly...Nice job\n\n";
            lineWrapper(string("\nYou have answered all the quiz questions correctly...Nice job\n\n"), '=');
            goto modeMenu;
        }

        srand(time(NULL));
            
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
//---------------------------------------------------------------------------------------------------------------------------------------------
        switch (userModeChoice_si)
        {
            case 1:
            {
                caseOneStart:

                signed int userResponse_si;
                string userResponse_str;

                lineWrapper(quizApp.getProblem('+'), '-');
                cout << "Question # " << quizApp.getQuestionNumber() << "\n";
                lineWrapper(string("Question # " + std::to_string(quizApp.getQuestionNumber()) + string(" ")), '-');
                std:: cout << quizApp.getProblem('+'); 
                
                quizApp.startTimer();    

                cout << "\n\nUser: ";
                cin >> userResponse_str;

                quizApp.stopTimer();

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
                    quizApp.decrementNumberOfQuestionsCounter();
                    quizApp.incrementQuestionNumber();
                    goto getQuestion;
                }
                else
                {
                    cout << "\nIncorrect...the correct answer is: " <<  addition(quizApp.getX(), quizApp.getY()) << "\n\nGame Over\n\n";
                    goto modeMenu;
                }
            }
//---------------------------------------------------------------------------------------------------------------------------------------------
            case 2:
            {
                caseTwoStart:

                signed int userResponse_si;
                string userResponse_str;

                lineWrapper(quizApp.getProblem('-'), '-');
                std:: cout << quizApp.getProblem('-');
                
                quizApp.startTimer();    
                            
                cout << "\n\nUser: ";
                cin >> userResponse_str;

                quizApp.stopTimer();
                
                for(auto c : userResponse_str)
                {
                    if(!(isdigit(c)))
                    {
                        if(c == 'q' || c == 'Q')
                            goto quit;
                        else if(c == '-')
                            continue;
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
                    quizApp.decrementNumberOfQuestionsCounter();
                    goto getQuestion;
                }
                else
                {
                    cout << "\nIncorrect...the correct answer is: " <<  subtraction(quizApp.getX(), quizApp.getY()) << "\n\nGame Over\n\n";
                    goto modeMenu;
                }
            }
//-------------------------------------------------------------------------------------------------------------------------------------------------
            //this case may not needed
            case 3:
                EXIT_SUCCESS;
        }
    }while(userModeChoice_si != 3 && quizApp.getNumberOfQuestionsCounter() != 0);

    quit:
    return 0;
}
