#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Converter{
    public:
    int BinaryToDecimal(int bin){
    int dec=0;
    int i=0;
    while(bin!=0){
        dec+=(bin%10)*pow(2,i);
        bin/=10;
        i++;
    }
    return dec;
    }

    int OctaltoDecimal(int oct){
        int dec=0;
        int i=0;
        while(oct!=0){
            dec+=(oct%10)*pow(8,i);
            oct/=10;
            i++;
        }
        return dec;
    }

    int HextoDecimal(int hex) {
    int dec = 0;
    int base = 1; // Represents 16^0
    while (hex != 0) {
        int digit = hex % 10;
        dec += digit * base;
        hex /= 10;
        base *= 16; // Move to the next power of 16
    }
    return dec;
}

    vector <int> toOctal(int dec){
        vector <int> oct;
        while(dec!=0){
            oct.emplace_back(dec%8);
            dec/=8;
        }std::reverse(oct.begin(), oct.end());

        return oct; 
    }

    vector <int> toBinary(int dec){
        vector <int> bin;
        while(dec!=0){
            bin.emplace_back(dec%2);
            dec/=2;
        }
        std::reverse(bin.begin(), bin.end()); 
        return bin;
    }

    vector<int> toHex(int dec) {
    vector<int> hex;
    while (dec != 0) {
        int r = dec % 16;
        if (r >= 10 && r <= 15) {
            hex.emplace_back(r - 10);  // Adjust for 'A' to 'F'
        } else {
            hex.emplace_back(r);
        }
        dec /= 16;
    }
    std::reverse(hex.begin(), hex.end());

    return hex;
}

        
};



int main()
{
    cout<<"Enter the type of conversion you want with the specific character(case sensetive) \n a. Binary to Octal \n b. Octal to Binary \n c. Binary to Hexadecimal \n d. Hexadecimal to Binary \n e. Octal to Hexadecimal \n f. Hexadecimal to Octal \n";
    
    char x;
    cin >> x;

    cout << "Enter the Number:";
    string input; // Read the input as a string
    cin >> input;

    int n = stoi(input, nullptr, 0); // Convert the input string to an integer
    int a;
    vector<int> result;
    Converter operation;
    switch (x){
        case 'a':{a=operation.BinaryToDecimal(n);
                 result=operation.toOctal(a);}
        break;
        case 'b':{a=operation.OctaltoDecimal(n);
                 result=operation.toBinary(a);}
        break;
        case 'c':{a=operation.BinaryToDecimal(n);
                 result=operation.toHex(a);}
        break;
        case 'd':{a=operation.HextoDecimal(n);
                 result=operation.toBinary(a);}
        break;
        case 'e':{a=operation.OctaltoDecimal(n);
                 result=operation.toHex(a);}
        break;
        case 'f':{a=operation.HextoDecimal(n);
                 result=operation.toOctal(a);}
        break;
        default:cout<<"!!!Operation not Identified(try again with letters from a-f)!!!";
    }cout<<endl<<"Result:";
    for(auto i:result){
        
            cout << i;
        }  return 0;
    }
    
   
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// #include <cmath>

// class Converter {
// public:
//     int BinaryToDecimal(int bin) {
//         int dec = 0;
//         int i = 0;
//         while (bin != 0) {
//             dec += (bin % 10) * pow(2, i);
//             bin /= 10;
//             i++;
//         }
//         return dec;
//     }

//     int OctaltoDecimal(int oct) {
//         int dec = 0;
//         int i = 0;
//         while (oct != 0) {
//             dec += (oct % 10) * pow(8, i);
//             oct /= 10;
//             i++;
//         }
//         return dec;
//     }

//     int HextoDecimal(int hex) {
//         int dec = 0;
//         int base = 1;
// while (hex != 0) {
//     char digitChar = hex % 10;
//     int digit = 0;

//     if (digitChar >= '0' && digitChar <= '9') {
//         digit = digitChar - '0';
//     } else if (digitChar >= 'A' && digitChar <= 'F') {
//         digit = 10 + (digitChar - 'A');
//     } else if (digitChar >= 'a' && digitChar <= 'f') {
//         digit = 10 + (digitChar - 'a');
//     }

//     dec += digit * base;
//     hex /= 10;
//     base *= 16;
// }

//         return dec;
//     }

//     std::vector<int> toOctal(int dec) {
//         std::vector<int> oct;
//         while (dec != 0) {
//             oct.emplace_back(dec % 8);
//             dec /= 8;
//         }
//         std::reverse(oct.begin(), oct.end());
//         return oct;
//     }

//     std::vector<int> toBinary(int dec) {
//         std::vector<int> bin;
//         while (dec != 0) {
//             bin.emplace_back(dec % 2);
//             dec /= 2;
//         }
//         std::reverse(bin.begin(), bin.end());
//         return bin;
//     }

//     std::vector<int> toHex(int dec) {
//         std::vector<int> hex;
//         while (dec != 0) {
//             int r = dec % 16;
//             if (r >= 10 && r <= 15) {
//                 hex.emplace_back(r - 10);
//             } else {
//                 hex.emplace_back(r);
//             }
//             dec /= 16;
//         }
//         std::reverse(hex.begin(), hex.end());
//         return hex;
//     }
// };

// int main() {
//     std::cout << "Enter the type of conversion you want with the specific character (case sensitive):" << std::endl
//               << "a. Binary to Octal" << std::endl
//               << "b. Octal to Binary" << std::endl
//               << "c. Binary to Hexadecimal" << std::endl
//               << "d. Hexadecimal to Binary" << std::endl
//               << "e. Octal to Hexadecimal" << std::endl
//               << "f. Hexadecimal to Octal" << std::endl;

//     char choice;
//     std::cin >> choice;

//     int number;
//     std::cout << "Enter the Number:";
//     std::cin >> number;

//     Converter operation;
//     std::vector<int> result;

//     switch (choice) {
//         case 'a':
//             result = operation.toOctal(operation.BinaryToDecimal(number));
//             break;
//         case 'b':
//             result = operation.toBinary(operation.OctaltoDecimal(number));
//             break;
//         case 'c':
//             result = operation.toHex(operation.BinaryToDecimal(number));
//             break;
//         case 'd':
//             result = operation.toBinary(operation.HextoDecimal(number));
//             break;
//         case 'e':
//             result = operation.toHex(operation.OctaltoDecimal(number));
//             break;
//         case 'f':
//             result = operation.toOctal(operation.HextoDecimal(number));
//             break;
//         default:
//             std::cout << "!!!Operation not Identified (try again with letters from a-f)!!!" << std::endl;
//             return 1;
//     }

//     std::cout << "Result:";
//     for (auto i : result) {
//         if (i < 10) {
//             std::cout << i;
//         } else {
//             std::cout << static_cast<char>('A' + i - 10);
//         }
//     }

//     return 0;
// }
