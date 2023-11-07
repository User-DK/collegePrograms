#include <iostream>
using namespace std;

class sorting {
public:
    sorting() {
        float sort[5];
        cout << "Enter 5 numbers: ";
        for (int i = 0; i < 5; i++) {
            cin >> sort[i];
        }
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (sort[j] < sort[i]) {
                    float temp = sort[j];
                    sort[j] = sort[i];
                    sort[i] = temp;
                }
            }
        }
        printf("Largest: %.2f\n", sort[4]);
        printf("Second largest: %.2f\n", sort[3]);
        printf("Smallest: %.2f\n", sort[0]);
        printf("Second smallest: %.2f\n", sort[1]);
        printf("Middle: %.2f\n", sort[2]);
    }
};

int main() {
    sorting display;
    return 0;
}
