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
class StackWithMin
{
    private:
    class StackNode {
        public:
        T data;
        StackNode *next;
        T min;

        StackNode(T data)
        {
            this->data = data;
        }
    };
    StackNode *top = NULL;

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
        if (t->next) t->min = min(t->next->min, item);
        else t->min = item;
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

    T minimum()
    {
        if (top == NULL) throw "Exception: Stack empty";
        return top->min;
    }
};


int main()
{
    StackWithMin<int> stack;
    stack.push(5);
    stack.push(3);
    stack.push(10);
    stack.push(2);
    cout << stack.minimum() << endl;;
    stack.pop();
    cout << stack.minimum() << endl;;
    stack.pop();
    cout << stack.minimum() << endl;;
    stack.pop();
    cout << stack.minimum() << endl;;
    stack.pop();
    return 0;
}
