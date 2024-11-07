#include "pch.h"
#include "Assignment.h"

// Test default constructor
TEST(BookTest, DefaultConstructor) {
    Book b;
    EXPECT_EQ(b.getTitle(), nullptr);
    EXPECT_EQ(b.getNumLibraries(), 0);
}

// Test parameterized constructor
TEST(BookTest, ParameterizedConstructor) {
    int copies[] = { 3, 5, 2 };
    Book b("C++ Programming", 3, copies);
    EXPECT_STREQ(b.getTitle(), "C++ Programming");
    EXPECT_EQ(b.getNumLibraries(), 3);
    EXPECT_EQ(b.getCopiesPerLibrary()[0], 3);
    EXPECT_EQ(b.getCopiesPerLibrary()[1], 5);
    EXPECT_EQ(b.getCopiesPerLibrary()[2], 2);
}

// Test getters and setters
TEST(BookTest, GettersSetters) {
    int copies[] = { 4, 6 };
    Book b;
    b.setTitle("New Book");
    b.setCopiesPerLibrary(2, copies);
    EXPECT_STREQ(b.getTitle(), "New Book");
    EXPECT_EQ(b.getNumLibraries(), 2);
    EXPECT_EQ(b.getCopiesPerLibrary()[0], 4);
    EXPECT_EQ(b.getCopiesPerLibrary()[1], 6);
}

// Test getTotalCopies
TEST(BookTest, GetTotalCopies) {
    int copies[] = { 4, 6, 8 };
    Book b("Test Book", 3, copies);
    EXPECT_EQ(b.getTotalCopies(), 18);
}

// Test hasAtLeastCopies
TEST(BookTest, HasAtLeastCopies) {
    int copies[] = { 4, 6, 8 };
    Book b("Test Book", 3, copies);
    EXPECT_TRUE(b.hasAtLeastCopies(1, 5));
    EXPECT_FALSE(b.hasAtLeastCopies(2, 10));
}

// Test copy constructor
TEST(BookTest, CopyConstructor) {
    int copies[] = { 3, 5 };
    Book b1("Original", 2, copies);
    Book b2(b1);
    EXPECT_STREQ(b2.getTitle(), "Original");
    EXPECT_EQ(b2.getNumLibraries(), 2);
    EXPECT_EQ(b2.getCopiesPerLibrary()[0], 3);
    EXPECT_EQ(b2.getCopiesPerLibrary()[1], 5);
}

// Test assignment operator
TEST(BookTest, AssignmentOperator) {
    int copies1[] = { 2, 4 };
    int copies2[] = { 6, 8 };
    Book b1("Book 1", 2, copies1);
    Book b2("Book 2", 2, copies2);
    b2 = b1;
    EXPECT_STREQ(b2.getTitle(), "Book 1");
    EXPECT_EQ(b2.getNumLibraries(), 2);
    EXPECT_EQ(b2.getCopiesPerLibrary()[0], 2);
    EXPECT_EQ(b2.getCopiesPerLibrary()[1], 4);
}

// Test addCopies
TEST(BookTest, AddCopies) {
    int copies[] = { 3, 5 };
    Book b("Test Book", 2, copies);

    // Add a new value
    b.addCopies(7);
    EXPECT_EQ(b.getNumLibraries(), 3);
    EXPECT_EQ(b.getCopiesPerLibrary()[2], 7);

    // Add another value
    b.addCopies(9);
    EXPECT_EQ(b.getNumLibraries(), 4);
    EXPECT_EQ(b.getCopiesPerLibrary()[3], 9);
}

// Test removeCopiesAtIndex
TEST(BookTest, RemoveCopiesAtIndex) {
    int copies[] = { 3, 5, 7 };
    Book b("Test Book", 3, copies);

    // Remove the value at index 1
    b.removeCopiesAtIndex(1);
    EXPECT_EQ(b.getNumLibraries(), 2);
    EXPECT_EQ(b.getCopiesPerLibrary()[0], 3);
    EXPECT_EQ(b.getCopiesPerLibrary()[1], 7);

    // Remove the value at index 0
    b.removeCopiesAtIndex(0);
    EXPECT_EQ(b.getNumLibraries(), 1);
    EXPECT_EQ(b.getCopiesPerLibrary()[0], 7);

    // Remove the last remaining value
    b.removeCopiesAtIndex(0);
    EXPECT_EQ(b.getNumLibraries(), 0);
}

// Test removeCopiesAtIndex with invalid index
TEST(BookTest, RemoveCopiesAtIndexInvalid) {
    int copies[] = { 3, 5 };
    Book b("Test Book", 2, copies);

    // Expect an exception when index is out of range
    EXPECT_THROW(b.removeCopiesAtIndex(-1), std::out_of_range);
    EXPECT_THROW(b.removeCopiesAtIndex(2), std::out_of_range);
}

TEST(BookTest, AddCopiesInvalidValue) {
    int copies[] = { 3, 5 };
    Book b("Test Book", 2, copies);

    // Test with zero
    EXPECT_THROW(b.addCopies(0), std::invalid_argument);

    // Test with a negative value
    EXPECT_THROW(b.addCopies(-5), std::invalid_argument);

    // Ensure the original data remains unchanged
    EXPECT_EQ(b.getNumLibraries(), 2);
    EXPECT_EQ(b.getCopiesPerLibrary()[0], 3);
    EXPECT_EQ(b.getCopiesPerLibrary()[1], 5);
}
