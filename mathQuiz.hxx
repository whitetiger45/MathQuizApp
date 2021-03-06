#ifndef MATHQUIZ_HXX
#define MATHQUIZ_HXX

#include <ctime>
#include <iostream>
#include <cstdlib>  
#include <string>

#define func(n, a) void show##n(){std::cout << a << "\n";}
func(Title, "\n*************\n* Math Quiz *\n*************")
#undef func

//----------------------------------------------------------------------------------------------------------------

#define func(n, a) void show##n(){std::cout << a << "\n";}
func(Menu, "\nSelect A Quiz Type:\n===================\n1: Addition\n2: Subtraction\n3: Combo\n4: Quit")
func(DifficultyMenu, "(Enter 'b' to return to actual quiz mode menu and 'm' to return to mode menu select)\n\nSet a difficulty level by entering 1, 2, 3, 4 or 5 for randomized questioning)")
func(NumberOfQuestionsMenu, "(Enter 'm' to return to mode select and 'b' for difficulty select)\n\nHow many questions do you like to attempt (Max is 20):")
func(TimedModeMenu, "(Enter 'm' to return to mode select, 'd' for difficulty select and 'b' to set the number of questions again)\n\nWould you like to enable timed mode (y/n): ")
func(ActualQuizModeMenu, "(Enter 'b' to return to the mode menu)\n\nWould you like to enable actual quiz mode (y/n): ")
#undef func

//----------------------------------------------------------------------------------------------------------------

auto addition = [](signed int x, signed int y) -> signed int {return x + y;};
auto subtraction = [](signed int x, signed int y) -> signed int {return x - y;};

//----------------------------------------------------------------------------------------------------------------

auto lineWrapper = [](std::string lineToWrap, char c){for(unsigned int i = 0; i < lineToWrap.size(); i++)std::cout << c; std::cout << "\n";};
auto lineWrapperI = [](unsigned int numOfChars, char c){for(unsigned int i = 0; i < numOfChars ; i++)std::cout << c; std::cout << "\n";};

//----------------------------------------------------------------------------------------------------------------

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
        void setNumberOfQuestionsCounter(unsigned int val)
        {
            m_numberOfQuizQuestionsCounter = val;
            m_numberOfQuizQuestionsTotal = val;
        }
//----------------------------------------------------------------------------------------------------------------
        void decrementNumberOfQuestionsCounter()
        {
            m_numberOfQuizQuestionsCounter--;
        }
//----------------------------------------------------------------------------------------------------------------
        unsigned int getNumberOfQuestionsCounter() const
        {
            return m_numberOfQuizQuestionsCounter;
        }
//----------------------------------------------------------------------------------------------------------------
        unsigned int getNumberOfQuestionsTotal() const
        {
            return m_numberOfQuizQuestionsTotal;
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
        void incrementQuestionNumber()
        {
            m_questionNumber++;
        }
//----------------------------------------------------------------------------------------------------------------
        unsigned int getQuestionNumber() const
        {   
            return m_questionNumber;      
        }
//----------------------------------------------------------------------------------------------------------------
        void resetQuestionNumberCounter()
        {   
            m_questionNumber = 1;      
        }
//----------------------------------------------------------------------------------------------------------------
        std::string getProblem(char op)
        {
            std::string problem = "(Enter 'q' to quit)\n\nSolve: \n\n" + getXStr() + " " + op + " " + getYStr() + " = ";
            return problem;      
        }
//----------------------------------------------------------------------------------------------------------------
        void enableTimedMode()
        {
            m_timedModeEnabled = (m_timedModeEnabled) ? false : true;
        }
//----------------------------------------------------------------------------------------------------------------
        bool timedModeEnabled()
        {
            return m_timedModeEnabled;      
        }
//-----------------------------------------------------------------------------------------------------------------------

        void setDisplayedRulesOnce()
        {
            m_displayedRulesOnce = (m_displayedRulesOnce) ? false : true;
        }
//-----------------------------------------------------------------------------------------------------------------------

        bool alreadyDisplayedRulesOnce()
        {
            return m_displayedRulesOnce;
        }
//-----------------------------------------------------------------------------------------------------------------------
        bool displayTimedModeRule()
        { 
            if(alreadyDisplayedRulesOnce())
                return alreadyDisplayedRulesOnce();

            std::cout << std::endl;
            lineWrapper(std::string("\nAttention: In this mode, you must solve the problem within 5 seconds or the quiz will end\n"), '*');
            std::cout << "\nAttention:\n\nIn this mode, you must solve the problem within 5 seconds or the quiz will end.\n";
            std::cout << "\nThe timer will start once you see 'User:', and it will stop once you have entered your answer.\n\n";
            lineWrapper(std::string("\nAttention: In this mode, you must solve the problem within 5 seconds or the quiz will end\n"), '*');
            setDisplayedRulesOnce();

            return alreadyDisplayedRulesOnce();
        }
//----------------------------------------------------------------------------------------------------------------
        void startTimer()
        {
            time_t m_t = time(0);  
            m_userGuessClock = localtime( & m_t );
            m_clockMinuteBeforeGuess = m_userGuessClock->tm_min;
            m_clockSecondsBeforeGuess = m_userGuessClock->tm_sec;// get time now
        }
//-----------------------------------------------------------------------------------------------------------------------
        unsigned int getSecondsBeforeGuess() const
        {
            return m_clockSecondsBeforeGuess;
        }
//-----------------------------------------------------------------------------------------------------------------------
        unsigned int getMinuteBeforeGuess() const
        {
            return m_clockMinuteBeforeGuess;
        }
//-----------------------------------------------------------------------------------------------------------------------
        void stopTimer()
        {
            time_t m_t = time(0);  
            m_userGuessClock = localtime( & m_t );
            m_clockMinuteAfterGuess = m_userGuessClock->tm_min;
            m_clockSecondsAfterGuess = m_userGuessClock->tm_sec;// get time now
        }
//-----------------------------------------------------------------------------------------------------------------------
        unsigned int getSecondsAfterGuess() const
        {
            return m_clockSecondsAfterGuess;
        }
//-----------------------------------------------------------------------------------------------------------------------
        unsigned int getMinuteAfterGuess() const
        {
            return m_clockMinuteAfterGuess;
        }
//-----------------------------------------------------------------------------------------------------------------------
        unsigned int getDifferenceBetweenGuessClocks() const
        {
            if((getMinuteAfterGuess() - getMinuteBeforeGuess()) == 0) 
            {
                return abs(getSecondsAfterGuess() - getSecondsBeforeGuess());
            }
            else
            {
                signed int numberOfSecondsToMultiplySixtyBy = ( getMinuteAfterGuess() - getMinuteBeforeGuess() );
                return abs( (( getSecondsAfterGuess() + ( numberOfSecondsToMultiplySixtyBy * 60 )) - getSecondsBeforeGuess() ) );
            }
        }
//-----------------------------------------------------------------------------------------------------------------------
        void setAverageTimeDifferenceToGuessTracker() 
        {
            m_averageTimeDifferenceBetweenGuesses += getDifferenceBetweenGuessClocks();
        }
//-----------------------------------------------------------------------------------------------------------------------
        void resetAverageTimeDifferenceToGuessTracker() 
        {
            m_averageTimeDifferenceBetweenGuesses = 0;
        }
//-----------------------------------------------------------------------------------------------------------------------
        unsigned int getAverageTimeDifferenceToGuessTracker() const
        {
            return m_averageTimeDifferenceBetweenGuesses;
        }
//-----------------------------------------------------------------------------------------------------------------------
        double getAverageTimeToGuessTracker() const
        {
            if(m_questionNumber == 0 || getAverageTimeDifferenceToGuessTracker() == 0)
                return getAverageTimeDifferenceToGuessTracker();
            else
                return ((double) getAverageTimeDifferenceToGuessTracker() / (double) (m_questionNumber));
        }
//-----------------------------------------------------------------------------------------------------------------------
        bool userRespondedInTime() const
        {
            if(getDifferenceBetweenGuessClocks() > 5)
            {
                return false;
            }
            else
                return true;
        }
//-----------------------------------------------------------------------------------------------------------------------
        void incrementCorrectAnswerCounter()
        {
            m_numberOfCorrectAnswers++;
        }
//-----------------------------------------------------------------------------------------------------------------------
        void resetCorrectAnswerCounter()
        {
            m_numberOfCorrectAnswers = 0;
        }
//-----------------------------------------------------------------------------------------------------------------------
        unsigned int getNumberOfCorrectAnswers() const
        {
            return m_numberOfCorrectAnswers;
        }
//-----------------------------------------------------------------------------------------------------------------------
        void enableActualQuizMode()
        {
            m_actualQuizModeEnabled = (m_actualQuizModeEnabled) ? false : true;
        }
//-----------------------------------------------------------------------------------------------------------------------
        bool actualQuizModeEnabled()
        {
            return m_actualQuizModeEnabled;
        }
//-----------------------------------------------------------------------------------------------------------------------
        void decrementIncorrectGuessesAllowedCounter()
        {
            m_incorrectGuessesAllowedCounter--;
        }
//-----------------------------------------------------------------------------------------------------------------------
        unsigned int getIncorrectGuessesAllowedCounter() const
        {
           return m_incorrectGuessesAllowedCounter;
        }
//-----------------------------------------------------------------------------------------------------------------------
        void resetIncorrectGuessesAllowedCounter() 
        {
           m_incorrectGuessesAllowedCounter = 1;
        }
//-----------------------------------------------------------------------------------------------------------------------
        void resetAllCountersNonActualQuizMode()
        {
            resetQuestionNumberCounter();
            resetCorrectAnswerCounter();
            resetIncorrectGuessesAllowedCounter();
        }
//-----------------------------------------------------------------------------------------------------------------------
        void resetAllCountersActualQuizMode()
        {
            resetQuestionNumberCounter();
            resetCorrectAnswerCounter();
        }
//-----------------------------------------------------------------------------------------------------------------------
        void correctAnswerHandler()
        {
            decrementNumberOfQuestionsCounter();
            incrementQuestionNumber();
            incrementCorrectAnswerCounter();
        }
//-----------------------------------------------------------------------------------------------------------------------
        void incorrectAnswerHandlerNonActualQuizMode()
        {
            decrementNumberOfQuestionsCounter();
            incrementQuestionNumber();
        }
//-----------------------------------------------------------------------------------------------------------------------

    private:

        signed int m_x;
        signed int m_y;
        std::string m_xStr;
        std::string m_yStr;
        unsigned int m_numberOfQuizQuestionsCounter = 0;
        unsigned int m_numberOfQuizQuestionsTotal = 0;
        bool m_timedModeEnabled = false;
        unsigned int m_questionNumber = 1;

        //timer stuff
        unsigned int m_clockSecondsAfterGuess = 0;
        unsigned int m_clockMinuteAfterGuess = 0;
        unsigned int m_averageTimeDifferenceBetweenGuesses = 0;
        struct tm * m_userGuessClock;
        unsigned int m_clockSecondsBeforeGuess = 0;
        unsigned int m_clockMinuteBeforeGuess = 0;
        bool m_displayedRulesOnce = false;

        unsigned int m_numberOfCorrectAnswers = 0;
        bool m_actualQuizModeEnabled = false;

        unsigned int m_incorrectGuessesAllowedCounter = 1;

};
#endif // MATHQUIZ_HXX
