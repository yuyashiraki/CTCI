/* This code is not compilable. */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <string>
#include <iterator>
using namespace std;

template <typename T>
class Stack
{
    private:
    class StackNode {
        private:
        T data;

        public:
        StackNode *next = NULL;
        StackNode(T data)
        {
            this->data = data;
        }
    };
    StackNode *top = NULL;
    int capacity;

    public:
    int size = 0;

    Stack(int capacity)
    {
        this->capacity = capacity;
    }

    T pop()
    {
        if (top == NULL) throw "Exception: Stack empty";
        T item = top->data;
        delete top;
        top = top->next;
        size--;
        return item;
    }

    void push(T item)
    {
        StackNode *t = new StackNode(item);
        t->next = top;
        top = t;
        size++;
    }

    T peek()
    {
        if (this->top == NULL) throw "Exception: Stack empty";
        return this->top->data;
    }

    bool isEmpty()
    {
        return this->top == NULL;
    }

    bool isFull()
    {
        return size == capacity;
    }
};


template <typename T>
class SetOfStacks
{
    private:
    list<Stack<T> > stacks;
    int capacity;

    public:
    SetOfStacks(int capacity)
    {
        this->capacity = capacity;
    }

    void push(T v)
    {
        Stack<T> *last = (Stack<T> *) getLastStack();
        if (last != NULL && !last->isFull()) {
            last->push(v);
        } else {
            Stack<T> *stack = new Stack<T>(capacity);
            stack->push(v);
            stacks.push_back(stack);
        }
    }
    
    T pop()
    {
        Stack<T> *last = (Stack<T> *) getLastStack();
        if (last == NULL) throw "Exception: Stack Empty";
        T v = last->pop();
        if (last->size == 0) stacks.erase(last);
        return v;
    }

    T popAt(int index)
    {
        return leftShift(index, true);
    }


    T leftShift(int index, bool removeTop)
    {
        /* iterate until it reaches last stack */
        Stack *stack = stacks.get(index);
        T removed_item;
        if (removeTop) removed_item = stack->pop();
        else removed_item = stack->removeBottom();
        if (stack.isEmpty()) {
            stacks.remove(index);
        } else if (stacks.size() > index + 1) {
            T v = leftShift(index + 1);
            stack.push(v);
        }
        return removed_item;
    }


    Stack<T> *getLastStack()
    {
        if (stacks.empty()) return NULL;
        return --stacks.end();
    }
};


int main()
{
    SetOfStacks<int> stacks = SetOfStacks<int>(1);
    stacks.push(1);
    cout << stacks.pop() << endl;
    return 0;
}
