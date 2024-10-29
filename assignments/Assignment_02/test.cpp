#include "pch.h"
#include "Assignment.h"


// Test suite for Book class
class BookTest : public ::testing::Test {
protected:
    // This will run before each test
    void SetUp() override {
        // Initialize test data or objects if needed
    }

    // This will run after each test
    void TearDown() override {
        // Clean up any resources if necessary
    }
};

// Test default constructor
TEST_F(BookTest, DefaultConstructor) {
    Book book;
    EXPECT_EQ(book.getTitle(), "");
    EXPECT_STREQ(book.getAuthor(), "No author");
    EXPECT_EQ(book.getYear(), 0);
    EXPECT_EQ(book.getReviews(), nullptr); // Assuming getReviews returns nullptr for no reviews
}

// Test parameterized constructor
TEST_F(BookTest, ParameterizedConstructor) {
    Book book("Test Title", "Test Author", 2023);
    EXPECT_EQ(book.getTitle(), "Test Title");
    EXPECT_STREQ(book.getAuthor(), "Test Author");
    EXPECT_EQ(book.getYear(), 2023);
}

// Test setTitle method
TEST_F(BookTest, SetTitle) {
    Book book;
    book.setTitle("New Title");
    EXPECT_EQ(book.getTitle(), "New Title");
}

// Test setAuthor method
// Test that the initial name is correctly set
TEST_F(BookTest, DefaulAuthorValue) {
    Book book;
    const char* defaultName = "Default Book Name";
    book.setAuthor(defaultName); // Assuming there's a setter for the name
    EXPECT_STREQ(book.getAuthor(), defaultName);
}

// Test that the name is set correctly
TEST_F(BookTest, SetAuthor) {
    Book book;
    const char* newName = "New Book Title";
    book.setAuthor(newName); // Set a new name using a setter

    // Check if the name was set correctly
    EXPECT_STREQ(book.getAuthor(), newName); // Compares C-style strings
}

// Test that the name is not exceeding buffer size
TEST_F(BookTest, SetAuthorBoundaryCheck) {
    Book book;
    const char* longName = "This is a very long name that exceeds the buffer limit of fifty characters in length";
    book.setAuthor(longName); // Set a long name that might exceed the buffer

    // Verify that the name was truncated or handled within bounds
    EXPECT_LT(strlen(book.getAuthor()), 50); // Check length to be under 50
}


// Test setYear method
TEST_F(BookTest, SetYear) {
    Book book;
    book.setYear(2025);
    EXPECT_EQ(book.getYear(), 2025);
}

// Test setReviews method with deep copy
TEST_F(BookTest, SetReviews) {
    Book book;
    float reviews[] = { 3.0, 4.5 };
    book.setReviews(reviews, 2);

    float* retrievedReviews = book.getReviews();
    ASSERT_NE(retrievedReviews, nullptr);
    EXPECT_EQ(retrievedReviews[0], 3.0);
    EXPECT_EQ(retrievedReviews[1], 4.5);

    delete[] retrievedReviews; // Clean up copied array
}

// Test getReviews returns a copy of reviews
TEST_F(BookTest, GetReviewsReturnsCopy) {
    Book book;
    float reviews[] = { 4.2, 3.8 };
    book.setReviews(reviews, 2);

    float* reviewsCopy1 = book.getReviews();
    float* reviewsCopy2 = book.getReviews();

    ASSERT_NE(reviewsCopy1, reviewsCopy2); // Ensure different memory addresses
    EXPECT_EQ(reviewsCopy1[0], 4.2);
    EXPECT_EQ(reviewsCopy1[1], 3.8);

    delete[] reviewsCopy1;
    delete[] reviewsCopy2;
}

// Test addReview method
TEST_F(BookTest, AddReview) {
    Book book;
    book.addReview(4.5);
    book.addReview(3.5);

    float* reviews = book.getReviews();
    ASSERT_NE(reviews, nullptr);
    EXPECT_EQ(reviews[0], 4.5);
    EXPECT_EQ(reviews[1], 3.5);

    delete[] reviews; // Clean up copied array
}

// Test getAverageReviewsValue
TEST_F(BookTest, GetAverageReviewsValue) {
    Book book;
    float reviews[] = { 4.0, 3.0, 5.0, 2.0 };
    book.setReviews(reviews, 4);  // Assuming setReviews exists

    // Expected average: (4.0 + 3.0 + 5.0 + 2.0) / 4 = 3.5
    EXPECT_FLOAT_EQ(book.getAverageReviewsValue(), 3.5);
}

// Test getMinimumReviewValue
TEST_F(BookTest, GetMinimumReviewValue) {
    Book book;
    float reviews[] = { 4.0, 3.0, 5.0, 2.0 };
    book.setReviews(reviews, 4);  // Assuming setReviews exists

    // Expected minimum review value: 2.0
    EXPECT_FLOAT_EQ(book.getMinimumReviewValue(), 2.0);
}

// Test getMinimumReviewCount
TEST_F(BookTest, GetMinimumReviewCount) {
    Book book;
    float reviews[] = { 4.0, 2.0, 2.0, 5.0, 2.0 };
    book.setReviews(reviews, 5);  // Assuming setReviews exists

    // Expected count of minimum values: 3 occurrences of 2.0
    EXPECT_EQ(book.getMinimumReviewCount(), 3);
}
