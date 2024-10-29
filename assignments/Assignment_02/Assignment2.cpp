#pragma once

#include <iostream>
#include <string>
#include <string.h>

class Book {
private:
    std::string title;
    char author[50];
    int year;
    float* reviews;      // Dynamic array for review scores (from 1 to 5; accepts floating point values like 2.3)
    int reviewCount;     // Number of reviews

public:
    // Default constructor
    Book() {
        //init title with ""
        //init author with "No author"
        //init year with 0
        //init reviews with null pointer
        //init reviews count with 0
    }

    // Parameterized constructor
    // Init Book attributes with received values. 
    // Init reviews and reviewCount with null pointer and 0
    Book(const std::string& title, const std::string& author, int year) {

    }

    // Parameterized constructor
    // Init Book attributes with received values. 
    Book(const std::string& title, const std::string& author, int year, float* reviews, int reviewCount) {

    }

    // Getter methods
    std::string getTitle() {
        return "";
    }
    char* getAuthor() {
        return nullptr;
    }

    int getYear() {
        return 0;
    }

    // Returns a copy of the reviews array
    float* getReviews() {
        return nullptr;
    }

    int getNoReviews() {
        return 0;
    }

    // Setter methods
    void setTitle(std::string title) {

    }
    void setAuthor(const char* author) {

    }
    void setYear(int year) {

    }

    // Deep copy for array
    void setReviews(const float* newReviews, int size) {
        // Implement deep copy of `newReviews` into `reviews`

    }

    // Add a review to the reviews array
    void addReview(float score) {

    }

    // Display book details
    void display() {
    }

    // Average value of all reviews
    float getAverageReviewsValue() {
        return 0;
    }

    // The minium value of all reviews 
    float getMinimumReviewValue() {
        return 0;
    }

    // Number of reviews with minium value
    int getMinimumReviewCount() {
        return 0;
    }
};


int main(){
	return 0;
}