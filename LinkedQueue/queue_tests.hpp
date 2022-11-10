#include"../doctest.h"
#include"LinkedQueue.h"

TEST_CASE("After creating a queue, it is empty") {
    LinkedQueue<int> q;
    CHECK(q.empty());
}
TEST_CASE("After adding an item to a queue, it is not empty") {
    LinkedQueue<int> q;
    q.enqueue(42);
    CHECK_FALSE(q.empty());
}

TEST_CASE("Attempting to look in or out of an empty queue item throws an exception") {
    LinkedQueue<int> q;
    CHECK_THROWS(q.head());
    CHECK_THROWS(q.dequeue());
}

TEST_CASE("When sequentially adding elements to the queue, the first added is excluded" ) {
    LinkedQueue<int> q;
    for(int i = 1; i <= 10; i++)
        q.enqueue(i);
    CHECK_EQ(q.head(), 1);
    CHECK_EQ(q.dequeue(), 1);
    CHECK_NE(q.head(), 1);
}

TEST_CASE("When sequentially adding items to the queue, they are removed in the same order and then the queue remains empty" ) {
    LinkedQueue<int> q;
    for(int i = 1; i <= 10; i++)
        q.enqueue(i);
    CHECK_FALSE(q.empty());
    for(int i = 1; i <= 10; i++)
        CHECK_EQ(q.dequeue(), i);
    CHECK(q.empty());

    for(int i = 11; i <= 20; i++)
        q.enqueue(i);
    CHECK_FALSE(q.empty());
    for(int i = 11; i <= 20; i++)
        CHECK_EQ(q.dequeue(), i);
    CHECK(q.empty());
}

TEST_CASE("Repeated addition and exclusion of items" ) {
    LinkedQueue<int> q;
    for(int j = 0; j < 100; j++) {
        for(int i = 1; i <= 10; i++)
            q.enqueue(i);
        CHECK_FALSE(q.empty());
        for(int i = 1; i <= 10; i++)
            CHECK_EQ(q.dequeue(), i);
        CHECK(q.empty());
    }
}


TEST_CASE("Конструкторът за копиране не споделя памет" ) {
    LinkedQueue<int> q1;
    for(int i = 1; i <= 10; i++)
        q1.enqueue(i);
    LinkedQueue<int> q2 = q1;
//    std::clog << s2.pop() << std::endl;
    q2.enqueue(20);
    for(int i = 1; i <= 10; i++) {
        CHECK(! q1.empty());
        CHECK_EQ(q1.dequeue(), i);
    }
    CHECK(q1.empty());
}

TEST_CASE("Копиране на празна опашка" ) {
    LinkedQueue<int> q1;
    LinkedQueue<int> q2 = q1;
    CHECK(q2.empty());
}