#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

class Book {
private:
    const int id;
    std::string title;
    std::string* authors;
    int authorCount;
    int pages;

	// Method to be used to copy authors from one array to another
    void copyAuthors(const std::string* src, int count) {
    }

public:
    // Default Constructor
	// Inits the title to "Unknown", authors to nullptr, authorCount to 0, pages to 0 and id to 0
    Book()
    {}

    // Parameterized Constructor
	// Don't do shallow copy of authors
    Book(int id, const std::string& title, const std::string* authors, int authorCount, int pages){

    }

    // Copy Constructor
    Book(const Book& other){
    }

    // Destructor
    ~Book() {

    }

    // Assignment Operator
	Book& operator=(const Book& other) {
		return *this;
    }

    int getPages() const {
        return 0;
    }

    // Check if a name is an author of the book
    bool isAuthor(const std::string& name) const {
        return false;
    }

    // Returns the position of an author in the list, or -1 if not found
    int getAuthorPosition(const std::string& name) const {
        return -100;
    }

    // Display details at the console
    void display() {

    }

};

//Sample operators

//    Book b2 = b1 + 50;  // Add pages
//    b2.display();
//
//    Book b3 = 100 + b1; // Add pages with int on the left
//    b3.display();
//
//    b1 += 20;           // Increase pages
//    b1.display();
//
//    std::cout << "Has no authors? " << (!b1 ? "Yes" : "No") << "\n";
//
//    std::cout << "Title as string: " << std::string(b1) << "\n";
//
//    std::cout << "First author: " << b1[0] << "\n";
//
//    ++b1;               // Increment pages
//    b1.display();
//
//    b1--;               // Decrement pages
//    b1.display();
//
//    std::cout << "Are b1 and b2 equal? " << (b1 == b2 ? "Yes" : "No") << "\n";
//    std::cout << "Is b1 greater than b2? " << (b1 > b2 ? "Yes" : "No") << "\n";
//
//    std::string title = (string)b1;   //cast to string
//    std::cout << "Title: " << title << std::endl;
// 
//    // Input a new book
//    Book b4;
//    std::cin >> b4;
//    std::cout << "You entered:\n" << b4;
// 
//      //Function operator to Return the number of pages
//    std::cout << "Pages: " << b() << std::endl;
//
//      //Function operator to Return an author's name based on a given index
//    std::cout << "First author: " << b(0) << std::endl;
