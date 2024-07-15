//SIMPLE CALCULATOR

#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int choice;
    float num1, num2;
    char continueChoice = 'Y'; 
    
    cout<<"+++SIMPLE CALCULATOR+++"<<endl;

    while (continueChoice == 'Y' || continueChoice == 'y') 
    {
        cout << "\nChoose an operation:" << endl;
        cout << "\n1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;

        cin >> choice;

        if (choice >= 1 && choice <= 4) 
        {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
        }

        if (choice == 1) 
        {
            cout << "Addition is: " << num1 + num2 << endl;
        } 
        else if (choice == 2) 
        {
            cout << "Subtraction is: " << num1 - num2 << endl;
        } 
        else if (choice == 3) 
        {
            cout << "Multiplication is: " << num1 * num2 << endl;
        } 
        else if (choice == 4) 
        {
            if (num2 != 0)
                cout << "Division is: " << num1 / num2 << endl;
            else
                cout << "Cannot divide by zero" << endl;
        } 
        else 
        {
            cout << "Invalid choice. Please select a valid operation number." << endl;
        }

        cout << "Do you want to continue? (Yes/No): ";
        cin >> continueChoice;
    }

    cout << "Have a Good day!" << endl;

    return 0;
}

