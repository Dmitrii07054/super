#include <gtest/gtest.h>

#include "vector.hpp"

using dim::Vector;

// 1. Тест для push_back и get_size

TEST(VectorTest, PushBackAndGetSize) {
    Vector<int> v;
    EXPECT_EQ(v.get_size(), 0);
    
    v.push_back(10);
    EXPECT_EQ(v.get_size(), 1);
    
    v.push_back(20);
    v.push_back(30);
    EXPECT_EQ(v.get_size(), 3);
}

// 2. Тест для has_item

TEST(VectorTest, HasItem) {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    EXPECT_TRUE(v.has_item(10));
    EXPECT_TRUE(v.has_item(20));
    EXPECT_TRUE(v.has_item(30));
    EXPECT_FALSE(v.has_item(100));
}

// 3. Тест для insert (вставка)

TEST(VectorTest, Insert) {
    Vector<int> v;
    v.push_back(10);
    v.push_back(30);
    
    EXPECT_TRUE(v.insert(1, 20));
    EXPECT_EQ(v.get_size(), 3);
    EXPECT_TRUE(v.has_item(20));
    
    EXPECT_TRUE(v.insert(0, 5));
    EXPECT_EQ(v.get_size(), 4);
    EXPECT_TRUE(v.has_item(5));
    
    EXPECT_FALSE(v.insert(10, 99));
}

// 4. Тест для remove_first (удаление из начала)

TEST(VectorTest, RemoveFirstFromBeginning) {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    EXPECT_TRUE(v.remove_first(10));
    EXPECT_EQ(v.get_size(), 2);
    EXPECT_FALSE(v.has_item(10));
    EXPECT_TRUE(v.has_item(20));
}

// 5. Тест для remove_first (удаление из середины)

TEST(VectorTest, RemoveFirstFromMiddle) {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    EXPECT_TRUE(v.remove_first(20));
    EXPECT_EQ(v.get_size(), 2);
    EXPECT_FALSE(v.has_item(20));
    EXPECT_TRUE(v.has_item(10));
    EXPECT_TRUE(v.has_item(30));
}

// 6. Тест для remove_first (удаление из конца)

TEST(VectorTest, RemoveFirstFromEnd) {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    EXPECT_TRUE(v.remove_first(30));
    EXPECT_EQ(v.get_size(), 2);
    EXPECT_FALSE(v.has_item(30));
    EXPECT_TRUE(v.has_item(10));
}

// 7. Тест для remove_first (элемент не найден)

TEST(VectorTest, RemoveFirstNotFound) {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    
    EXPECT_FALSE(v.remove_first(100));
    EXPECT_EQ(v.get_size(), 2);
}

// 8. Тест для print (просто проверяем, что не падает)

TEST(VectorTest, PrintDoesNotCrash) {
    Vector<int> v;
    EXPECT_NO_THROW(v.print());
    
    v.push_back(10);
    v.push_back(20);
    EXPECT_NO_THROW(v.print());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
