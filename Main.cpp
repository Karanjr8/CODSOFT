#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

void showInstructions()
{
    cout<<" \n=== Number Guessing Game ===\n";
    cout<<" Choose a difficulty level:\n";
    cout<<"1. Easy (1 to 10)\n";
    cout<<"2. Medium (1 to 50)\n";
    cout<<"3. Hard (1 to 100)\n";
    cout<<"Try to guess the number in as few attempts as possible!\n\n";
}
int chooseDifficulty()
{
    int choice;
    while(true)
    {
        cout<<"Enter difficulty level (1-3): ";
        cin>>choice;

        if(cin.fail() || choice < 1 || choice > 3)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid input. Please enter 1, 2, or 3.\n";
        }
        else
        {
            break;
        }
    }
    return choice;
}
int getMaxNumber(int difficulty)
{
    switch(difficulty)
    {
        case 1: return 10;
        case 2: return 50;
        case 3: return 100;
        default: return 100; 
    }
}
int getUserGuess(int min, int max)
{
    int guess;
    while(true)
    {
        cout<<" Enter your guess ("<< min << " - " << max << "): ";
        cin>>guess;

        if(cin.fail() || guess < min || guess > max)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<< "Invalid guess. Please try again.\n";
        }
        else
        {
            break;
        }
}
return guess;
}
void playGame()
{
    int difficulty = chooseDifficulty();
    int maxNumber = getMaxNumber(difficulty);
    int secretNumber = rand() % maxNumber + 1;

    int guess;
    int attempts = 0;

    cout<< "\nI have picked a number between 1 and " << maxNumber << ". Start guessing!\n";

    while(true)
    {
        guess = getUserGuess(1, maxNumber);
        attempts++;
        if(guess < secretNumber)
        {
            cout<<"Too low. Try again.\n";
        }
        else if(guess > secretNumber)
        {
            cout<<"Too high. Try again.\n";
        }
        else
        {
            cout<<"\nCorrect! You guessed the number in "<< attempts << " attempts.\n";
            break;
        }
    }
}
bool askReplay()
{
    char choice;
    while(true)

    {
        cout<<"\nDo you want to play again? (y/n): ";
        cin>>choice;
        if(choice == 'y' || choice == 'Y') return true;
        if(choice == 'n' || choice == 'N') return false;
        cout<<"Invalid input. Please enter 'y' or 'n'.\n"; 
    }
}
int main()
{
    srand(static_cast<unsigned int>(time(0)));

    showInstructions();
    do
    {
        playGame();
    }
    while(askReplay());
    cout<<"\nThanks for playing! Goodbye 👋\n";
    return 0;
}