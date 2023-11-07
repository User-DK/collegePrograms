#ifndef BOOK_MANAGEMENT_H
#define BOOK_MANAGEMENT_H

#include <string>

namespace LibrarySystem {
    namespace BookManagement {
        class Book {
            
        };

        void addBook(const Book& book);

        void deleteBook(const Book& book);

        Book searchBook(const std::string& title);

    }
}

#endif 
