#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"

using dim::DoublyLinkedList;

// ============================================================
// 1. Тест для push_back и get_size
// ============================================================

TEST(DoublyLinkedListTest, PushBackAndGetSize) {
    DoublyLinkedList<int> list;
    EXPECT_EQ(list.get_size(), 0);
    
    list.push_back(10);
    EXPECT_EQ(list.get_size(), 1);
    
    list.push_back(20);
    list.push_back(30);
    EXPECT_EQ(list.get_size(), 3);
}

// ============================================================
// 2. Тест для has_item
// ============================================================

TEST(DoublyLinkedListTest, HasItem) {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    EXPECT_TRUE(list.has_item(10));
    EXPECT_TRUE(list.has_item(20));
    EXPECT_TRUE(list.has_item(30));
    EXPECT_FALSE(list.has_item(100));
}

// ============================================================
// 3. Тест для remove_first (удаление из начала)
// ============================================================

TEST(DoublyLinkedListTest, RemoveFirstFromBeginning) {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    EXPECT_TRUE(list.remove_first(10));
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_FALSE(list.has_item(10));
    EXPECT_TRUE(list.has_item(20));
}

// ============================================================
// 4. Тест для remove_first (удаление из середины)
// ============================================================

TEST(DoublyLinkedListTest, RemoveFirstFromMiddle) {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    EXPECT_TRUE(list.remove_first(20));
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_FALSE(list.has_item(20));
    EXPECT_TRUE(list.has_item(10));
    EXPECT_TRUE(list.has_item(30));
}

// ============================================================
// 5. Тест для remove_first (удаление из конца)
// ============================================================

TEST(DoublyLinkedListTest, RemoveFirstFromEnd) {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    EXPECT_TRUE(list.remove_first(30));
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_FALSE(list.has_item(30));
    EXPECT_TRUE(list.has_item(10));
}

// ============================================================
// 6. Тест для remove_first (удаление единственного элемента)
// ============================================================

TEST(DoublyLinkedListTest, RemoveFirstSingleElement) {
    DoublyLinkedList<int> list;
    list.push_back(10);
    
    EXPECT_TRUE(list.remove_first(10));
    EXPECT_EQ(list.get_size(), 0);
    EXPECT_FALSE(list.has_item(10));
}

// ============================================================
// 7. Тест для remove_first (элемент не найден)
// ============================================================

TEST(DoublyLinkedListTest, RemoveFirstNotFound) {
    DoublyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    
    EXPECT_FALSE(list.remove_first(100));
    EXPECT_EQ(list.get_size(), 2);
}

// ============================================================
// 8. Тест для print (просто проверяем, что не падает)
// ============================================================

TEST(DoublyLinkedListTest, PrintDoesNotCrash) {
    DoublyLinkedList<int> list;
    EXPECT_NO_THROW(list.print());
    
    list.push_back(10);
    list.push_back(20);
    EXPECT_NO_THROW(list.print());
}
