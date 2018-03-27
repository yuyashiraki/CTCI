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
class FixedMultiStack {
    private:
    int numberOfStacks = 3;
    int stackCapacity;
    T *values;
    int *sizes;

    public:
    FixedMultiStack(int stackSize)
    {
        stackCapacity = stackSize;
        values = new T[stackSize * numberOfStacks];
        sizes = new int[numberOfStacks];
    }

    void push(int stackNum, T value)
    {
        if (isFull(stackNum)) {
            throw "Exception: Stack is Full";
        }
        sizes[stackNum]++;
        values[indexOfTop(stackNum)] = value;
    }

    T pop(int stackNum)
    {
        if (isEmpty(stackNum)) {
            throw "Exception: Stack is Empty";
        }
        int topIndex = indexOfTop(stackNum);
        T value = values[topIndex];
        values[topIndex] = 0;
        sizes[stackNum]--;
        return value;
    }

    bool isEmpty(int stackNum)
    {
        return sizes[stackNum] == 0;
    }

    bool isFull(int stackNum)
    {
        return sizes[stackNum] == stackCapacity;
    }

    private:
    int indexOfTop(int stackNum)
    {
        int offset = stackNum * stackCapacity;
        int size = sizes[stackNum];
        return offset + size - 1;
    }
};


int main()
{
    FixedMultiStack<char> stack(5);
    stack.push(0, 'H');
    stack.push(0, 'I');
    stack.push(0, '!');
    cout << stack.pop(0);
    cout << stack.pop(0);
    cout << stack.pop(0);
    return 0;
}
