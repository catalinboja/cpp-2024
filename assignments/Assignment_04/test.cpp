#include "pch.h"
#include "Assignment.h"


//
//USE the tests only after you have implemented all the methods in the class, including the required operators and methods
//


TEST(BookTest, DefaultConstructor) {
    Book b;
    EXPECT_EQ(static_cast<std::string>(b), "Unknown");
    EXPECT_EQ(!b, true); // No authors
    EXPECT_THROW(b[0], std::out_of_range); // Accessing authors should fail
}

TEST(BookTest, ParameterizedConstructor) {
    std::string authors[] = { "Author A", "Author B" };
    Book b(1,"Test Book", authors, 2, 300);

    EXPECT_EQ(static_cast<std::string>(b), "Test Book");
    EXPECT_EQ(b[0], "Author A");
    EXPECT_EQ(b[1], "Author B");
    EXPECT_EQ(!b, false);
}

TEST(BookTest, CopyConstructor) {
    std::string authors[] = { "Author A", "Author B" };
    Book b1(1,"Original Book", authors, 2, 300);
    Book b2 = b1;

    EXPECT_EQ(static_cast<std::string>(b2), "Original Book");
    EXPECT_EQ(b2[0], "Author A");
    EXPECT_EQ(b2[1], "Author B");
    EXPECT_NE(&b1[0], &b2[0]); // Ensure deep copy
}

TEST(BookTest, AssignmentOperator) {
    std::string authors[] = { "Author A", "Author B" };
    Book b1(1,"Original Book", authors, 2, 300);
    Book b2;

    b2 = b1;

    EXPECT_EQ(static_cast<std::string>(b2), "Original Book");
    EXPECT_EQ(b2[0], "Author A");
    EXPECT_EQ(b2[1], "Author B");
    EXPECT_NE(&b1[0], &b2[0]); // Ensure deep copy
}

TEST(BookTest, AdditionOperator) {
    std::string authors[] = { "Author A", "Author B" };
    Book b(1,"Test Book", authors, 2, 300);

    Book b2 = b + 50;
    EXPECT_EQ(static_cast<std::string>(b2), "Test Book");
    EXPECT_EQ(b2[0], "Author A");
    EXPECT_EQ(b2[1], "Author B");
    EXPECT_EQ(!b2, false);
    EXPECT_EQ(b2.getPages(), 350);
}

TEST(BookTest, AdditionOperatorWithIntOnLeft) {
    std::string authors[] = { "Author A", "Author B" };
    Book b("Test Book", authors, 2, 300);

    Book b2 = 50 + b;
    EXPECT_EQ(static_cast<std::string>(b2), "Test Book");
    EXPECT_EQ(b2.getPages(), 350);
}

TEST(BookTest, EqualityOperator) {
    std::string authors1[] = { "Author A", "Author B" };
    Book b1("Test Book", authors1, 2, 300);

    std::string authors2[] = { "Author A", "Author B" };
    Book b2("Test Book", authors2, 2, 300);

    EXPECT_EQ(b1 == b2, true);

    Book b3("Different Book", authors1, 2, 300);
    EXPECT_EQ(b1 == b3, false);
}

TEST(BookTest, GreaterThanOperator) {
    std::string authors[] = { "Author A", "Author B" };
    Book b1("Book A", authors, 2, 400);
    Book b2("Book B", authors, 2, 300);

    EXPECT_EQ(b1 > b2, true);
    EXPECT_EQ(b2 > b1, false);
}

TEST(BookTest, StreamOperators) {
    Book b;
    std::istringstream input("Test Book\n2\nAuthor A\nAuthor B\n350\n");
    input >> b;

    EXPECT_EQ(static_cast<std::string>(b), "Test Book");
    EXPECT_EQ(b[0], "Author A");
    EXPECT_EQ(b[1], "Author B");
    EXPECT_EQ(b.getPages(), 350);

    std::ostringstream output;
    output << b;
    EXPECT_TRUE(output.str().find("Test Book") != std::string::npos);
    EXPECT_TRUE(output.str().find("Author A") != std::string::npos);
    EXPECT_TRUE(output.str().find("Author B") != std::string::npos);
    EXPECT_TRUE(output.str().find("350") != std::string::npos);
}

TEST(BookTest, FunctionOperator) {
    std::string authors[] = { "Author A", "Author B" };
    Book b(1,"Test Book", authors, 2, 300);

    // Test returning pages
    EXPECT_EQ(b(), 300);

    // Test returning an author's name
    EXPECT_EQ(b(0), "Author A");
    EXPECT_EQ(b(1), "Author B");

    // Test out-of-range access
    EXPECT_THROW(b(2), std::out_of_range);
}

TEST(BookTest, IsAuthorMethod) {
    std::string authors[] = { "Author A", "Author B" };
    Book b(1,"Test Book", authors, 2, 300);

    // Test with an existing author
    EXPECT_EQ(b.isAuthor("Author A"), true);

    // Test with a non-existing author
    EXPECT_EQ(b.isAuthor("Author C"), false);

    // Test with an empty string
    EXPECT_EQ(b.isAuthor(""), false);
}

TEST(BookTest, GetAuthorPositionMethod) {
    std::string authors[] = { "Author A", "Author B", "Author C" };
    Book b(1,"Test Book", authors, 3, 300);

    // Test with an existing author
    EXPECT_EQ(b.getAuthorPosition("Author A"), 0);
    EXPECT_EQ(b.getAuthorPosition("Author C"), 2);

    // Test with a non-existing author
    EXPECT_EQ(b.getAuthorPosition("Author X"), -1);

    // Test with an empty string
    EXPECT_EQ(b.getAuthorPosition(""), -1);
}