// #include <iostream>
// #include <iomanip>
// #include <string>
// #include <vector>

// using namespace std;

// class Item {
// public:
//     string name;
//     int code;
//     double cost;

//     Item() : name(""), code(0), cost(0.0) {}

//     Item(string n, int c, double co) : name(n), code(c), cost(co) {}
// };

// int main() {
//     vector<Item> items;

//     while (true) {
//         string name;
//         int code;
//         double cost;

//         cout << "Enter item name (or 'quit' to exit): ";
//         cin >> name;

//         if (name == "quit") {
//             break;
//         }

//         cout << "Enter item code: ";
//         cin >> code;

//         cout << "Enter item cost: ";
//         cin >> cost;

//         Item newItem(name, code, cost);
//         items.push_back(newItem);
//     }
//     cout<<endl;
//     // Display the table header
//     cout << left << setw(20) << "NAME" << setw(20) << "CODE" << setw(20) << "COST" << endl;

//     // Display the items
//     for (const Item& item : items) {
//         cout << left << setw(20) << item.name << setw(20) << item.code << fixed << setprecision(2) << right << setw(20) << item.cost << endl;
//     }

//     return 0;
// }
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Item {
public:
    string name;
    int code;
    double cost;

    Item() : name(""), code(0), cost(0.0) {}

    Item(string n, int c, double co) : name(n), code(c), cost(co) {}
};

int main() {
    vector<Item> items;

    while (true) {
        string name;
        int code;
        double cost;

        cout << "Enter item name (or 'quit' to exit): ";
        cin >> name;

        if (name == "quit") {
            break;
        }

        cout << "Enter item code: ";
        cin >> code;

        cout << "Enter item cost: ";
        cin >> cost;

        Item newItem(name, code, cost);
        items.push_back(newItem);
    }

    // Display the table header
    cout << left << setw(20) << "NAME" << setw(20) << "CODE" << setw(20) << "COST" << endl;

    // Display the items
    for (const Item& item : items) {
        cout << left << setw(20) << item.name << setw(20) << item.code << fixed << setprecision(2) << right << setw(20) << item.cost << endl;
    }

    return 0;
}
