#include "mathQuiz.hxx"

using namespace std;

int main()
{
    showTitle();
    Quizzer quizApp;
//---------------------------------------------------------------------------------------------------------------------------------------------
    modeMenu:

    string userModeChoice_str;
    unsigned int userModeChoice_si = 0;

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

    actualQuizModeMenu:
    string userActualQuizModeMenu_str;

    if(userModeChoice_si == 3)
        goto quit;
    else
        lineWrapperI(85, '-');

    showActualQuizModeMenu();
    cout << "\nUser: " ;cin >> userActualQuizModeMenu_str;

    if(userActualQuizModeMenu_str.length() > 1)
    {
        cout << "\n*** Please enter 'y' or 'n' ***\n";
        goto actualQuizModeMenu;
    }
    else if(!(isalpha(userActualQuizModeMenu_str[0])))
    {
        cout << "\n*** You entered an invalid character! ***\n";
        goto actualQuizModeMenu;
    }
    else if(userActualQuizModeMenu_str == "y" || userActualQuizModeMenu_str == "Y")
    {
        if(!quizApp.actualQuizModeEnabled())
            quizApp.enableActualQuizMode();
    }
    else if(userActualQuizModeMenu_str == "n" || userActualQuizModeMenu_str == "N")
    {
        if(quizApp.actualQuizModeEnabled())
            quizApp.enableActualQuizMode();
    }
    else if(userActualQuizModeMenu_str == "b" || userActualQuizModeMenu_str == "B")
    {
        goto modeMenu;
    }
    else
    {
        cout << "*** You entered an invalid character! ***\n";
        goto actualQuizModeMenu;
    }
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
                goto actualQuizModeMenu;
            }
            else if(userDifficultyChoice_str == "m" || userDifficultyChoice_str == "M" )
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

        cout << "Set Number Of Problems To Attempt\n";
        lineWrapper(string("Set Number Of Problems To Attempt\n"), '-');
        showNumberOfQuestionsMenu(); 
        cout << "\nUser: "; cin >> userNumberOfQuestionsResponse_str;

        if(userNumberOfQuestionsResponse_str == "m" || userNumberOfQuestionsResponse_str == "M")
            goto modeMenu;
        else if(userNumberOfQuestionsResponse_str == "b" || userNumberOfQuestionsResponse_str == "B")
            goto difficultyMenu;
        else if(userNumberOfQuestionsResponse_str.length() > 2)
        {
            cout << "\n*** The maximum number of problems you can attempt to solve is 20 ***\n";
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
        {
            lineWrapperI(85, '-');
            goto modeMenu;
        }
        else if(userTimedModeResponse_str == "d" || userTimedModeResponse_str == "D")
        {
            lineWrapperI(85, '-');
            goto difficultyMenu;
        }
        else if(userTimedModeResponse_str == "b" || userTimedModeResponse_str == "B")
        {
            lineWrapperI(85, '-');
            goto numberOfQuestionsMenu;
        }
        else if(userTimedModeResponse_str.length() > 1)
        {
            cout << "\n*** You entered more than one character ***\n";
            lineWrapperI(85, '-');
            goto timedModeMenu;
        }
        else if(!isalpha(userTimedModeResponse_str[0]))
        {
            cout << "\n*** You did not enter a valid character ***\n";
            lineWrapperI(85, '-');
            goto timedModeMenu;
        }
        else if(userTimedModeResponse_str == "y" || userTimedModeResponse_str == "Y")
        {
            if(!quizApp.timedModeEnabled())
            {
                quizApp.enableTimedMode();
                if(!quizApp.alreadyDisplayedRulesOnce())
                {
                    quizApp.displayTimedModeRule();

                    askIfUserIsReadyToBeginQuiz:
                    cout << "\nEnter 's' to start quiz and 'b' to set the number of questions again:\n\nUser: ";
                    string userQuizStartSubMenu_str; cin >> userQuizStartSubMenu_str;
                    cout << std::endl;

                    if(userQuizStartSubMenu_str == "s" || userQuizStartSubMenu_str == "S")
                        goto getQuestion;
                    else if(userQuizStartSubMenu_str == "b" || userQuizStartSubMenu_str == "B")
                    {
                        lineWrapperI(85, '-');
                        goto numberOfQuestionsMenu;
                    }
                    else
                    {
                        cout << "\n*** You did not enter a valid option ***\n";
                        goto askIfUserIsReadyToBeginQuiz;
                    }
                }
            }
        }
        else if(userTimedModeResponse_str == "n" || userTimedModeResponse_str == "N")
        {
            if(quizApp.timedModeEnabled())
            {
                quizApp.enableTimedMode();
            }
        }
//---------------------------------------------------------------------------------------------------------------------------------------------
        getQuestion:

        if((quizApp.getNumberOfQuestionsCounter() == 0 && !quizApp.actualQuizModeEnabled()) 
            || ( quizApp.getIncorrectGuessesAllowedCounter() == 0 && !quizApp.actualQuizModeEnabled()))
        {
            if(quizApp.getNumberOfQuestionsCounter() == 0)
            {
                lineWrapper(string("\nYou have completed the quiz.\n"), '=');
                cout << "\nYou have completed the quiz.\nYour score: " + to_string(quizApp.getNumberOfCorrectAnswers()) + "/" + to_string(quizApp.getNumberOfQuestionsTotal()) + "\n\n";
                lineWrapper(string("\nYou have completed the quiz.\n"), '=');
            }
            else
            {
                lineWrapper(string("\nYou have missed too many questions and the quiz is now over.\n"), '=');
                cout << "\nYou have missed too many questions and the quiz is now over.\nYour score: " + to_string(quizApp.getNumberOfCorrectAnswers()) + "/" + to_string(quizApp.getNumberOfQuestionsTotal()) + "\n\n";
                lineWrapper(string("\nYou have missed too many questions and the quiz is now over.\n"), '=');
            }

            quizApp.resetAllCounters();
            goto modeMenu;
        }
        else if(quizApp.getNumberOfQuestionsCounter() == 0 && quizApp.actualQuizModeEnabled())
        {
            lineWrapper(string("\nYou have completed the quiz.\n"), '=');
            cout << "\nYou have completed the quiz.\nYour score: " + to_string(quizApp.getNumberOfCorrectAnswers()) + "/" + to_string(quizApp.getNumberOfQuestionsTotal()) + "\n\n";
            lineWrapper(string("\nYou have completed the quiz.\n"), '=');
            quizApp.resetQuestionNumberCounter();
            quizApp.resetCorrectAnswerCounter();
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
                
                if(quizApp.timedModeEnabled())
                {
                    if(!quizApp.userRespondedInTime())
                    {
                        cout << endl;
                        
                        if(!quizApp.actualQuizModeEnabled())
                        {
                            lineWrapperI(101, 'x');
                            cout << "\nThe answer was " << addition(quizApp.getX(), quizApp.getY()) << ", but you did not answer the question in time...please try to improve your speed!\n\n";
                            lineWrapperI(101, 'x');
                            quizApp.resetAllCounters();
                            goto modeMenu;
                        }
                        else
                        {
                            lineWrapperI(65, 'x');
                            cout << "\nThe correct answer is: " <<  addition(quizApp.getX(), quizApp.getY()) << ", but you did not answer fast enough.\n\n";
                            lineWrapperI(65, 'x');
                            quizApp.decrementNumberOfQuestionsCounter();
                            quizApp.incrementQuestionNumber();
                            goto getQuestion;
                        }
                    }
                }
                
                userResponse_si = stoi(userResponse_str);

                if(userResponse_si == addition(quizApp.getX(), quizApp.getY()))
                {
                    cout << "\nCorrect!\n";
                    quizApp.decrementNumberOfQuestionsCounter();
                    quizApp.incrementQuestionNumber();
                    quizApp.incrementCorrectAnswerCounter();
                    goto getQuestion;
                }
                else
                {
                    if(!quizApp.actualQuizModeEnabled())
                    {
                        cout << "\nIncorrect...the correct answer is: " <<  addition(quizApp.getX(), quizApp.getY()) << "\n\n";
                        quizApp.decrementIncorrectGuessesAllowedCounter();
                        goto getQuestion;
                    }
                    else
                    {
                        cout << "\nIncorrect...the correct answer is: " <<  addition(quizApp.getX(), quizApp.getY()) << "\n";
                        quizApp.decrementNumberOfQuestionsCounter();
                        quizApp.incrementQuestionNumber();
                        goto getQuestion;
                    }
                }
            }
//---------------------------------------------------------------------------------------------------------------------------------------------
            case 2:
            {
                caseTwoStart:

                signed int userResponse_si;
                string userResponse_str;

                lineWrapper(quizApp.getProblem('-'), '-');
                cout << "Question # " << quizApp.getQuestionNumber() << "\n";
                lineWrapper(string("Question # " + std::to_string(quizApp.getQuestionNumber()) + string(" ")), '-');
                std:: cout << quizApp.getProblem('-');
                
                quizApp.startTimer();    
                            
                cout << "\n\nUser: ";
                cin >> userResponse_str;

                quizApp.stopTimer();
                
                if(quizApp.timedModeEnabled())
                {
                    if(!quizApp.userRespondedInTime())
                    {
                        cout << endl;
                        lineWrapperI(101, 'x');
                        cout << "\nThe answer was " << subtraction(quizApp.getX(), quizApp.getY()) << ", but you did not answer the question in time...please try to improve your speed!\n\n";
                        lineWrapperI(101, 'x');                        
                        quizApp.resetAllCounters();
                        goto modeMenu;
                    }
                }
                
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
                    quizApp.incrementQuestionNumber();
                    quizApp.incrementCorrectAnswerCounter();
                    goto getQuestion;
                }
                else
                {
                    if(!quizApp.actualQuizModeEnabled())
                    {
                        cout << "\nIncorrect...the correct answer is: " <<  subtraction(quizApp.getX(), quizApp.getY()) << "\n\n";
                        quizApp.decrementIncorrectGuessesAllowedCounter();
                        goto getQuestion;
                    }
                    else
                    {
                        cout << "\nIncorrect...the correct answer is: " <<  subtraction(quizApp.getX(), quizApp.getY()) << "\n";
                        quizApp.decrementNumberOfQuestionsCounter();
                        quizApp.incrementQuestionNumber();
                        goto getQuestion;
                    }
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
