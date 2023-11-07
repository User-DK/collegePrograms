#include <iostream>
#include <queue>

using namespace std;

class Stack {
  queue < int > q;
public:
  void Push(int x) {
    int s = q.size();
    q.push(x);
    for (int i = 0; i < s; i++) {
      q.push(q.front());
      q.pop();
    }
  }
  int Pop() {
    int n = q.front();
    q.pop();
    return n;
  }
  int Top() {
    return q.front();
  }
  int Size() {
    return q.size();
  }
};

int main() {
  Stack stack;

  int choice;
  int value;
  do {
    cout << "\nStack Operations Menu:\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Top\n";
    cout << "4. Size\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter a value to push: ";
      cin >> value;
      stack.Push(value);
      cout << "Value " << value << " pushed onto the stack.\n";
      break;
    case 2:
      if (stack.Size() > 0) {
        cout << "Popped value: " << stack.Pop() << endl;
      } else {
        cout << "Stack is empty. Cannot pop.\n";
      }
      break;
    case 3:
      if (stack.Size() > 0) {
        cout << "Top value: " << stack.Top() << endl;
      } else {
        cout << "Stack is empty. No top value.\n";
      }
      break;
    case 4:
      cout << "Stack size: " << stack.Size() << endl;
      break;
    case 5:
      cout << "Exiting program.\n";
      break;
    default:
      cout << "Invalid choice. Please try again.\n";
    }
  } while (choice != 5);

  return 0;
}
