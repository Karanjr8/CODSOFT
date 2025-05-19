#include <iostream>
#include <limits>
using namespace std;

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
void clearInputBuffer();

int main()
{
    double currentResult, newNumber;
    int choice;
    bool continueCalc = true;

    cout<<"***** Calculator Program *****"<<endl;

    cout<<"Enter the first number: ";
    while(!(cin>> currentResult))
    {
        cout<<"Invalid input. Please enter a numeric value: ";
        clearInputBuffer();
    }
    while(continueCalc)
    {
        cout<<"Enter the next number: ";
        while(!(cin>>newNumber))
        {
            cout<<"Invalid input. Please enter a number value: ";
            clearInputBuffer();
        }
        cout<<"\nChoose an option to perform with the current result (" << currentResult << "):\n";
        cout<<"1. Addition (+)\n";
        cout<<"2. Subtraction (-)\n";
        cout<<"3. Multiplication (*)\n";
        cout<<"4. Division (/)\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice (1-5): ";

        cin>>choice;

        cout<<fixed;
        cout.precision(2);

        switch(choice)
        {
            case 1:
            currentResult = add(currentResult, newNumber);
            cout<<"Updated Result: " << currentResult << endl;
            break;
            case 2:
            currentResult = subtract(currentResult, newNumber);
                cout << "Updated Result: " << currentResult << endl;
                break;
            case 3:
                currentResult = multiply(currentResult, newNumber);
                cout << "Updated Result: " << currentResult << endl;
                break;
            case 4:
                if (newNumber == 0) {
                    cout << "Error: Division by zero is not allowed." << endl;
                } else {
                    currentResult = divide(currentResult, newNumber);
                    cout << "Updated Result: " << currentResult << endl;
                }
                break;
            case 5:
                continueCalc = false;
                cout << "\nExiting calculator. Final Result: " << currentResult << endl;
                break;
            default:
            cout<<"Invalid choice. Please enter a number between 1 and 5.";
        }
    }
    return 0;
}
double add(double a, double b) {
    return a + b;
}
double subtract(double a, double b) {
    return a - b;
}
double multiply(double a, double b) {
    return a * b;
}
double divide(double a, double b) {
    return a / b;
}
void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
