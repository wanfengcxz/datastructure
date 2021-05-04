#include "gtest/gtest.h"
#include <stack>
#include <unordered_map>

using namespace std;

class stack_test : public ::testing::Test {
protected:
    std::stack<int> teststack;

protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {
        teststack.push(1);
        teststack.push(2);
    }

};

TEST_F(stack_test, demo) {
    ASSERT_EQ(teststack.top(), 2);
}

int add(int a, int b) {
    return a + b;
}

TEST(add, zero) {
    EXPECT_EQ(0, add(0, 0)) << "yes";
}

TEST(add, positive_number) {
    EXPECT_EQ(3, add(1, 2));
}

TEST(add, negative_number) {
    EXPECT_EQ(-3, add(-1, -2));
}

struct Index2 {
    int x, y;

    explicit Index2(int x = 0, int y = 0) : x(x), y(y) {}
};

struct Index2Hash {

    size_t operator()(const Index2 &index) const {
        // hash<int>()(...) 仿函数？
        return hash<int>()(index.x) ^ hash<int>()(index.y);
    }

};

struct Index2Com {

    bool operator()(const Index2 &index1, const Index2 &index2) const {
        return index1.x == index2.x && index1.y == index2.y;
    }
};

class SparseMatrix {
private:
    unordered_map<Index2, int, Index2Hash, Index2Com> map;
    int count;
public:
    SparseMatrix() : count(0) {}

    int at(int x, int y) {
        if (map.count(Index2(x, y)) <= 0) {
            return 0;
        } else {
            return map[Index2(x, y)];
        }
    }

    void insert(int x, int y, int e) {
//        map[Index2(x,y)] = e;
        map.emplace(Index2(x,y), e);
    }

};

int main() {
//    int a = 5,b = 1;
//    std::cout << (b=a) << std::endl;

//    std::stack<int> s;
//    std::cout << s.top() << std::endl;

//    ::testing::InitGoogleTest();
//    return RUN_ALL_TESTS();



    return 0;
}


