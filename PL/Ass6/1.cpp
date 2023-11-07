#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    double x, y;
    char operat;
    cout << "\nEnter x: ";
    cin >> x;
    cout << "\nEnter y: ";
    cin >> y;
    cout << "\nSelect the operator:\na. +\nb. -\nc. *\nd. /\n";
    cin >> operat;
    switch (operat)
    {
    case 'a':
    {
        cout << x + y;
    }break;
    case 'b':
    {
        cout << x - y;
    }break;
    case 'c':
    {
        cout << x * y;
    }break;
    default:
    {
        try
        {
            if (y == 0 && operat == 'd')
            {
                throw std::runtime_error("Division by zero is not allowed.");
            }
            else
            {
                throw std::logic_error("No operator Mentioned");
            }
            cout << x / y;
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << "Runtime Error: " << e.what() << std::endl;
        }
        catch (const std::logic_error &e)
        {
            std::cerr << "Logic Error: " << e.what() << std::endl;
        }
    }break;

    }
    return 0;
    }