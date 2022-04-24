#include <iostream>
#include <cassert>
#include "deque.cpp"
#include "deque.h"

using namespace std;

bool testDoesDequeConstructInRightState () 
{
    deque<int> d;
    return d.isEmpty();
}

bool testDoesDequePushFront ()
{
    deque<int> d;
    d.push_front(5);
    return !d.isEmpty();
}

bool testDoesDequePushBack ()
{
    deque<int> d;
    d.push_back(5);
    return !d.isEmpty();
}

bool testDoesDequeAccessFrontCorrectly ()
{
    deque<int> d;
    d.push_front(5);
    d.push_front(7);
    return d.front() == 7;
}

bool testDoesDequeAccessBackCorrectly ()
{
    deque<int> d;
    d.push_front(5);
    d.push_front(7);
    return d.back() == 5;
}

bool testDoesDequeModifyFrontValueCorrectly ()
{
    deque<int> d;
    d.push_back(7);
    d.front() = 10;
    return d.front() == 10;
}

bool testDoesDequeModifyBackValueCorrectly ()
{
    deque<int> d;
    d.push_front(7);
    d.back() = 10;
    return d.back() == 10;
}

bool testDoesDequePopFrontCorrectlyNotEmpty ()
{
    deque<int> d;
    d.push_front(5);
    d.push_back(7);
    d.pop_front();
    return d.front() == 7 && d.back() == 7;
}

bool testDoesDequePopBackCorrectlyNotEmpty ()
{
    deque<int> d;
    d.push_front(5);
    d.push_back(7);
    d.pop_back();
    return d.back() == 5 && d.front() == 5;
}

bool testDoesDequePopFrontCorrectlyEmpty ()
{
    deque<int> d;
    d.push_front(5);
    d.pop_front();
    return d.isEmpty();
}

bool testDoesDequePopBackCorrectlyEmpty ()
{
    deque<int> d;
    d.push_front(5);
    d.pop_back();
    return d.isEmpty();
}
int main() {
    assert(testDoesDequeConstructInRightState());
    assert(testDoesDequePushFront());
    assert(testDoesDequePushBack());
    assert(testDoesDequeAccessFrontCorrectly());
    assert(testDoesDequeAccessBackCorrectly());
    assert(testDoesDequeModifyFrontValueCorrectly());
    assert(testDoesDequeModifyBackValueCorrectly());
    assert(testDoesDequePopFrontCorrectlyNotEmpty());
    assert(testDoesDequePopBackCorrectlyNotEmpty());
    assert(testDoesDequePopBackCorrectlyEmpty());
    assert(testDoesDequePopFrontCorrectlyEmpty());
    deque<int> errors;
    errors.pop_back();
    errors.pop_front();
}