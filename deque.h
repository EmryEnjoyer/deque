/*
 * -----------------------------------------
 * This file is the interface for a deque   
 * By Justice Roberts                       
 * For CS350V Advanced Data Structures      
 * -----------------------------------------
 */
#ifndef DEQUE_H
#define DEQUE_H
template<typename T>
class deque 
{
    struct link 
    {
        T value;
        link* next;
        link* prev;
        link(T v, link * n, link * p) {
            value = v;
            next = n;
            prev = p;
        }
    };
    link * p_front;
    link * p_back;
public:
    deque() 
    {
        p_front = p_back = nullptr;
    }
    
    /** 
     * is the deque empty?
     * @return true if empty.
     * */
    bool isEmpty();

    /// Push val to the front of the deque  
    void push_front(T val);
    /// Push val to the back of the deque
    void push_back(T val);
    
    /**
     * Access the front element of the deque
     * @return reference to value at front of deque 
     * */
    T & front();
    /**
     * Access the back element of the deque
     * @return reference to the value at back of deque
     * */
    T & back();

    /// Pop the front element of the deque, invalidates reference to front.
    void pop_front(std::string str = __builtin_FUNCTION());
    /// Pop the back element of the deque, invalidates reference to back.
    void pop_back(std::string str = __builtin_FUNCTION());
    ~deque();
};
#endif