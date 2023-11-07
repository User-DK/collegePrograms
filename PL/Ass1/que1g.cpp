// Menu driven CPP Program to perform below operations
// a. Binary to Octal
// b. Octal to Binary
// c. Binary to Hexadecimal
// d. Hexadecimal to Binary
// e. Octal to Hexadecimal
// f. Hexadecimal to Octal

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

// Function to convert binary to octal
int binaryToOctal(long long binary)
{
    int octal = 0, decimal = 0, i = 0;
    // Converting binary to decimal
    while (binary != 0)
    {
        decimal += (binary % 10) * pow(2, i);
        i++;
        binary /= 10;
    }
    i = 1;
    // Converting decimal to octal
    while (decimal != 0)
    {
        octal += (decimal % 8) * i;
        decimal /= 8;
        i *= 10;
    }
    return octal;
}

// Function to convert octal to binary
long long octalToBinary(int octal)
{
    int decimal = 0, i = 0;
    long long binary = 0;
    // Converting octal to decimal
    while (octal != 0)
    {
        decimal += (octal % 10) * pow(8, i);
        i++;
        octal /= 10;
    }
    i = 1;
    // Converting decimal to binary
    while (decimal != 0)
    {
        binary += (decimal % 2) * i;
        decimal /= 2;
        i *= 10;
    }
    return binary;
}

// Function to convert binary to hexadecimal
string binaryToHexadecimal(long long binary)
{
    int decimal = 0, i = 0, rem;
    string hexadecimal = "";
    // Converting binary to decimal
    while (binary != 0)
    {
        decimal += (binary % 10) * pow(2, i);
        i++;
        binary /= 10;
    }
    
    // Converting decimal to hexadecimal
    while (decimal != 0)
    {
        rem = decimal % 16;
        if (rem < 10)
            hexadecimal += rem + '0';
        else
            hexadecimal += rem - 10 + 'A';
        decimal /= 16;
    }
    
    // Reversing the string
    reverse(hexadecimal.begin(), hexadecimal.end());
    
    return hexadecimal;
}

// Function to convert hexadecimal to binary
long long hexadecimalToBinary(string hexadecimal)
{
    int decimal = 0, i = 0, rem;
    long long binary = 0;
    
    // Converting hexadecimal to decimal
    for (int j = hexadecimal.length() -1; j >=0; j--)
    {
        if (hexadecimal[j] >= 'A' && hexadecimal[j] <= 'F')
            rem = hexadecimal[j] - 'A' + 10;
        else if (hexadecimal[j] >= 'a' && hexadecimal[j] <= 'f')
            rem = hexadecimal[j] - 'a' + 10;
        else if (hexadecimal[j] >= '0' && hexadecimal[j] <= '9')
            rem = hexadecimal[j] - '0';
        
        decimal += rem * pow(16, i);
        i++;
        
    }
    
     i = 1;
     // Converting decimal to binary
     while (decimal != 0)
     {
         binary += (decimal % 2) * i;
         decimal /=2;
         i *=10;
     }
     
     return binary;

}

// Function to convert octal to hexadecimal
string octalToHexadecimal(int octal)
{
   // First convert octal to binary and then binary to hexadecimal 
   long long binary = octalToBinary(octal);
   string hexadecimal = binaryToHexadecimal(binary);
   return hexadecimal; 
}

// Function to convert hexadecimal to octal
int hexadecimalToOctal(string hexadecimal)
{
   // First convert hexadecimal to binary and then binary to octal 
   long long binary = hexadecimalToBinary(hexadecimal);
   int octal = binaryToOctal(binary);
   return octal; 
}

int main()
{
   char choice; 
   long long bin;
      int oct;
   string hex;
   do
   {
      cout << "Choose an option from the menu:\n";
      cout << "a. Binary to Octal\n";
      cout << "b. Octal to Binary\n";
      cout << "c. Binary to Hexadecimal\n";
      cout << "d. Hexadecimal to Binary\n";
      cout << "e. Octal to Hexadecimal\n";
      cout << "f. Hexadecimal to Octal\n";
      cout << "q. Quit\n";
      cin >> choice;
      
      switch(choice)
      {
         case 'a':
            cout << "Enter a binary number: ";
            cin >> bin;
            cout << "Octal equivalent: " << binaryToOctal(bin) << "\n";
            break;
         case 'b':
            cout << "Enter an octal number: ";
            cin >> oct;
            cout << "Binary equivalent: " << octalToBinary(oct) << "\n";
            break;
         case 'c':
            cout << "Enter a binary number: ";
            cin >> bin;
            cout << "Hexadecimal equivalent: " << binaryToHexadecimal(bin) << "\n";
            break;
         case 'd':
            cout << "Enter a hexadecimal number: ";
            cin >> hex;
            cout << "Binary equivalent: " << hexadecimalToBinary(hex) << "\n";
            break;
         case 'e':
            cout << "Enter an octal number: ";
            cin >> oct;
            cout << "Hexadecimal equivalent: " << octalToHexadecimal(oct) << "\n";
            break;
         case 'f':
            cout << "Enter a hexadecimal number: ";
            cin >> hex;
            cout << "Octal equivalent: " << hexadecimalToOctal(hex) << "\n";
            break;
         case 'q':
            cout << "Thank you for using Bing. Have a nice day!\n";
            break;
         default:
            cout << "Invalid choice. Please try again.\n";
      }
   } while (choice != 'q');
   
   return 0;
}
