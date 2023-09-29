#include <iostream>
using namespace std;
int main()
{
    double num1 = 0;
    double num2 = 0;
    char operation;

    cout << "Simple Calculator Program" << endl;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    double result;

    if (operation == '+')
    {
        result = num1 + num2;
    }
    else if (operation == '-')
    {
        result = num1 - num2;
    }
    else if (operation == '*')
    {
        result = num1 * num2;
    }
    else if (operation == '/')
    {
        if (num2 != 0)
        {
            result = num1 / num2;
        }
        else
        {
            cout << "Error! Division by zero is not allowed." << endl;
            return 1;
        }
    }
    else
    {
        cout << "Invalid operation! Please enter +, -, *, or /." << endl;
        return 1;
    }

    cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << endl;

    return 0;
}
