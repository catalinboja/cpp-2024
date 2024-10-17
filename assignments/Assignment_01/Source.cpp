#include <iostream>
#include <string.h>

//Read requirements from the pdf document
//Implement and test required methods


struct Book {
	char title[100];
	char author[100];
	int year;
	int pages;
};

void initializeBook(Book* b, const char* title, const char* author, int year, int pages)
{

}

//bonus
//rewrite initializeBook with references
void initializeBookWithReference(Book& b, const char* title, const char* author, int year, int pages)
{

}

void displayBooks(const Book books[], int size) {

}

Book* addBook(Book* books, int& size, const Book& newBook) {
	return nullptr;
}

Book* searchByTitle(Book* books, int size, const char* title) {
	return nullptr;
}

void cleanup(Book*& books) {

}

void sortByYear(Book* books, int size) {

}

int main() {
	return 0;
}