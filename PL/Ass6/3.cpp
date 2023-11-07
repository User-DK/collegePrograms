#include <iostream>
#include <stdexcept>
#include <climits>  // Include this for INT16_MAX

using namespace std;

template <class X>X min(X a[], int b)  
{
    X min1 = INT16_MAX;
    for (int i = 0; i < b; i++) {
        if (min1 > a[i]) {
            min1 = a[i];
        }
    }
    return min1;
}

int main() {
    int a[5] = {6, 8, 3, 1, 9};
    float b[5] = {1.3, 1.5, 0.5, 0.200, 2.5};

    cout << "\nMin in the array {6, 8, 3, 1, 9} is: " << min(a, 5);
    cout << "\n\nMin in the array {1.3, 1.5, 0.5, 0.200, 2.5} is: " << min(b, 5);

    return 0;
}
