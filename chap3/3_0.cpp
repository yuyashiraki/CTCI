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
class MyStack
{
    private:
    class StackNode {
        private:
        T data;
        StackNode *next;

        public:
        StackNode(T data)
        {
            this->data = data;
        }
    };
    StackNode *top;

    public:
    T pop()
    {
        if (this->top == NULL) throw "Exception: Stack empty";
        T item = this->top->data;
        delete this->top;
        this->top = this->top->next;
        return item;
    }

    void push(T item)
    {
        StackNode *t = new StackNode(item);
        t->next = top;
        top = t;
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
};

template <typename T>
class MyQueue {
    private:
    class QueueNode {
        private:
        T data;
        QueueNode *next;

        public:
        QueueNode(T data)
        {
            this->data = data;
        }
    };
    QueueNode *first;
    QueueNode *last;

    public:
    void add(T item)
    {
        QueueNode *t = new QueueNode(item);
        if (this->last != NULL) {
            this->last = t;
        }
        this->last = t;
        if (this->first == NULL) {
            this->first = this->last;
        }
    }

    T remove()
    {
        if (this->first == NULL) throw "Exception: Queue empty";
        T data = this->first->data;
        delete this->first;
        this->first = this->first->next;
        if (this->first == NULL) {
            this->last = NULL;
        }
        return data;
    }

    T peek()
    {
        if (this->first == NULL) throw "Exception: Queue empty";
        return this->first->data;
    }

    bool ieEmpty()
    {
        return this->first == NULL;
    }
};


int main()
{

    return 0;
}
