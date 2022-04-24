#include "deque.h"
#include <iostream>
template <typename T>
bool deque<T>::isEmpty() 
{
    return p_front == nullptr && p_back == nullptr;
}

template <typename T>
void deque<T>::push_front(T val) 
{
    link * insert = new link(val,nullptr,nullptr);
    if(p_front == nullptr) 
    {
        p_front = insert;
        p_back = insert;
    } 
    else 
    {
        p_front->prev = insert;
        insert->next = p_front;
        p_front = insert;
    }
}
template <typename T>
void deque<T>::push_back(T val) 
{
    link * insert = new link(val,nullptr,nullptr);
    if(p_back == nullptr) 
    {
        p_back = insert;
        p_front = insert;
    }
    else 
    {
        p_back->next = insert;
        insert->prev = p_back;
        p_back = insert;
    }
}

template <typename T>
T & deque<T>::front() 
{
    return p_front->value;
}
template <typename T>
T & deque<T>::back()
{
    return p_back->value;
}

template<typename T>
void deque<T>::pop_front(std::string str)
{
    if(p_front == nullptr) 
    {
        std::cerr << "Error: Attempted access of front when queue is empty by " + str + "()," << std::endl;
        return;
    }
    if(p_front->next == nullptr) 
    {
        delete p_front;
        p_back = p_front = nullptr;
    } 
    else 
    {
        auto temp = p_front->next;
        delete p_front;
        p_front = temp;
        p_front->prev = nullptr;
    }
}
template<typename T>
void deque<T>::pop_back(std::string str)
{
    if(p_back == nullptr) 
    {
        std::cerr << "Error: Attempted access of back when queue is empty by " + str + "()." << std::endl;
        return;
    }
    if(p_back->prev == nullptr) 
    {
        delete p_back;
        p_front = p_back = nullptr;
    } else 
    {
        auto temp = p_back->prev;
        delete p_back;
        p_back = temp;
        p_back->next = nullptr;
    }
}

template<typename T>
deque<T>::~deque() 
{
    while(!isEmpty()) 
    {
        pop_back();
    }
}