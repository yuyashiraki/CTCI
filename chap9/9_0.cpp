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

#define ll long long

using namespace std;

// BubbleSort: Avg = Worstcase Time O(n^2) Memory(1)
void bubbleSort(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size() - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                iter_swap(a.begin() + j, a.begin() + j + 1);
            }
        }
    }
}


// SelectionSort: Avg = Worstcase Time O(n^2) Memory O(1)
void selectionSort(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++) {
        int sml_idx = i;
        for (int j = i + 1; j < a.size(); j++) {
            if (a[sml_idx] > a[j]) {
                sml_idx = j;
            }
        }
        iter_swap(a.begin() + i, a.begin() + sml_idx);
    }
}


// MergeSort: Avg = Worstcase O(nlog(n)) Memory O(n) in this case
void mergesort(vector<int> &a, vector<int>& helper, int low, int high);
void merge(vector<int>& a, vector<int>& helper, int low, int middle, int high);
void mergesort(vector<int>& a)
{
    vector<int> helper(a.size());
    mergesort(a, helper, 0, a.size() - 1);
}
void mergesort(vector<int> &a, vector<int>& helper, int low, int high)
{
    if (low < high) {
        int middle = (low + high)/ 2;
        mergesort(a, helper, low, middle);
        mergesort(a, helper, middle + 1, high);
        merge(a, helper, low, middle, high);
    }
}
void merge(vector<int>& a, vector<int>& helper, int low, int middle, int high)
{
    /* copy both halves into a helper array */
    for (int i = low; i <= high; i++) {
        helper[i] = a[i];
    }
    int helperLeft = low, helperRight = middle + 1, current = low;
    // iteratively comapre left half and right half
    while (helperLeft <= middle && helperRight <= high) {
        if (helper[helperLeft] <= helper[helperRight]) {
            a[current++] = helper[helperLeft++];
        } else {
            a[current++] = helper[helperRight++];
        }
    }
    // If left half has remainings, copy them
    // If right half has remainings, it's already there
    for (int i = 0; i <= middle - helperLeft; i++) {
        a[current + i] = helper[helperLeft + i];
    }
}

// QuickSort: Time O(nlog(n)) average, O(n^2) worstcase, Memory O(log(n))
// If index moves one by one from left to right or right to left, it needs O(n^2)
int partition(vector<int>& arr, int left, int right);
void quickSort(vector<int>& arr, int left, int right);
void quickSort(vector<int>& arr)
{
    quickSort(arr, 0, arr.size() - 1);
}
void quickSort(vector<int>& arr, int left, int right)
{
    int index = partition(arr, left, right);
    if (left < index - 1) {
        quickSort(arr, left, index - 1);
    }
    if (index < right) {
        quickSort(arr, index, right);
    }
}
int partition(vector<int>& arr, int left, int right)
{
    int pivot = arr[(left + right) / 2];
    while (left <= right) {
        while (arr[left] < pivot) left++;
        while (arr[right] > pivot) right--;
        if (left <= right) {
            iter_swap(arr.begin() + left, arr.begin() + right);
            left++;
            right--;
        }
    }
    return left;
}


// RadixSort: runtime O(d*(n+b)), n: #elements, d: #digits, b: base number
int getMax(vector<int>& arr);
void countSort(vector<int>& arr, int exp);
void radixSort(vector<int>& arr)
{
    // Get Maximum number
    int m = getMax(arr);
    // exp = 10^i where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}
int getMax(vector<int>& arr)
{
    int mx = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        mx = max(mx, arr[i]);
    }
    return mx;
}
void countSort(vector<int>& arr, int exp)
{
    vector<int> count(10);
    vector<int> output(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i]/exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}


// binary search: time O(log(n))
int binarySearch(vector<int>& arr, int x)
{
    int low = 0, high = arr.size() - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] < x) {
            low = mid + 1;
        } else if (arr[mid] > x) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
int binarySearchRecursive(vector<int>& arr, int x, int low, int high)
{
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] < x) {
        return binarySearchRecursive(arr, x, mid + 1, high);
    } else if (arr[mid] > x) {
        return binarySearchRecursive(arr, x, low, mid - 1);
    } else {
        return mid;
    }
}


int main()
{
    vector<int> a{1,5,7,8,10};
    cout << binarySearch(a, 7) << endl;
    cout << a[0] << a[1] << a[2] << a[3] << a[4] << endl;
    return 0;
}
