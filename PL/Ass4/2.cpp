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

    // Calculate column widths
    int nameWidth = 20;
    int codeWidth = 20;
    int costWidth = 20;

    // Display the table header
    cout << left << setw(nameWidth) << "NAME" << setw(codeWidth) << "CODE" << setw(costWidth) << "COST" << endl;

    // Display the items
    for (const Item& item : items) {
        cout << left << setw(nameWidth) << item.name << setw(codeWidth) << item.code << fixed << setprecision(2) << right << setw(costWidth) << item.cost << endl;
    }

    return 0;
}
