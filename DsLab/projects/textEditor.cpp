#include <iostream>
#include <string>

class Node {
public:
    char text;
    Node* next;

    Node() : text(), next(nullptr) {}
    Node(char data) : text(data), next(nullptr) {}
    Node(char data, Node* next) : text(data), next(next) {}
};

class TextEditor {
public:
    Node* cursor;
    Node* head;
    int count;

    TextEditor() : cursor(nullptr), head(nullptr), count(0) {}

    ~TextEditor() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addText(const std::string& text) {
        for (char c : text) {
            Node* newNode = new Node(c, nullptr);
            if (cursor == nullptr) {
                head = cursor = newNode;
            } else {
                newNode->next = cursor->next;
                cursor->next = newNode;
            }
            cursor = newNode;
            count++;
        }
    }

    int deleteText(int k) {
        int countDeleted = 0;
        while (cursor != nullptr && countDeleted < k) {
            Node* temp = cursor->next;
            if (temp != nullptr) {
                cursor->next = temp->next;
                delete temp;
                countDeleted++;
            } else {
                break; // No more characters to delete.
            }
        }
        if (cursor == nullptr) {
            return 0;
        }
        return countDeleted;
    }

    std::string cursorLeft(int k) {
        std::string deletedText;
        for (int i = 0; i < k && cursor != nullptr; i++) {
            Node* temp = cursor->next;
            if (temp != nullptr) {
                cursor->next = temp->next;
                deletedText += temp->text;
                delete temp;
            }
        }
        return deletedText;
    }

    std::string cursorRight(int k) {
        std::string movedText;
        for (int i = 0; i < k && cursor != nullptr; i++) {
            Node* temp = cursor->next;
            if (temp != nullptr) {
                cursor->next = temp->next;
                movedText += temp->text;
                temp->next = nullptr;
                if (cursor->next == nullptr) {
                    cursor->next = temp;
                } else {
                    temp->next = cursor->next->next;
                    cursor->next->next = temp;
                }
            }
        }
        return movedText;
    }

    std::string getText() {
        std::string text;
        Node* temp = head;
        while (temp != nullptr) {
            text += temp->text;
            temp = temp->next;
        }
        return text;
    }
};

#include <iostream>
#include <string>

// ... (the Node and TextEditor classes go here)

int main() {
    TextEditor textEditor;

    while (true) {
        std::cout << "Text Editor Menu:\n";
        std::cout << "1. Add Text\n";
        std::cout << "2. Delete Text\n";
        std::cout << "3. Move Cursor Left\n";
        std::cout << "4. Move Cursor Right\n";
        std::cout << "5. Get Current Text\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string input;
                std::cout << "Enter text to add: ";
                std::cin.ignore(); // Consume the newline character
                std::getline(std::cin, input);
                textEditor.addText(input);
                break;
            }
            case 2: {
                int k;
                std::cout << "Enter the number of characters to delete: ";
                std::cin >> k;
                int deletedCount = textEditor.deleteText(k);
                std::cout << "Deleted " << deletedCount << " character(s)\n";
                break;
            }
            case 3: {
                int k;
                std::cout << "Enter the number of positions to move left: ";
                std::cin >> k;
                std::string deletedText = textEditor.cursorLeft(k);
                std::cout << "Moved left: " << deletedText << "\n";
                break;
            }
            case 4: {
                int k;
                std::cout << "Enter the number of positions to move right: ";
                std::cin >> k;
                std::string movedText = textEditor.cursorRight(k);
                std::cout << "Moved right: " << movedText << "\n";
                break;
            }
            case 5: {
                std::string currentText = textEditor.getText();
                std::cout << "Current Text: " << currentText << "\n";
                break;
            }
            case 6: {
                std::cout << "Exiting the Text Editor.\n";
                return 0; // Exit the program
            }
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    }

    return 0;
}

