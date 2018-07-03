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
#include <pthread.h>
#include <unistd.h>

#define ll long long

using namespace std;

class ThreadTest {
private:
    pthread_t thread_handler;
    pthread_mutex_t mutex;
    int data;
public:
    ThreadTest() {
        data = 0;
    }
    void setData(int i) {
        cout << "wait mutex" << endl;
        pthread_mutex_lock(&(this->mutex));
        data = i;
        pthread_mutex_unlock(&(this->mutex));
        cout << "set Data finished!" << endl;
    }
    int getData() {
        return data;
    }
    static void *executeLauncher(void* args) {
        cout << "executeLauncher" << endl;
        reinterpret_cast<ThreadTest *>(args)->execute();
        return (void*)NULL;
    }
    void threadStart() {
        if ((this->thread_handler) == NULL) {
            cout << "threadStart" << endl;
            pthread_mutex_init(&(this->mutex), NULL);
            pthread_create(
                &(this->thread_handler),
                NULL,
                &ThreadTest::executeLauncher,
                this
            );
        }
    }
    void execute() {
        while(1) {
            pthread_testcancel();
            pthread_mutex_lock(&(this->mutex));
            cout << "execute" << endl;
            cout << "Data = " << (this->getData()) << endl;
            sleep(10);
            pthread_mutex_unlock(&(this->mutex));
            sleep(1);
        }
    }
    ~ThreadTest() {
        cout << "destructor start" << endl;
        pthread_cancel(this->thread_handler);
        pthread_join(this->thread_handler, NULL);
        cout << "destructor end" << endl;
    }
};

int main()
{
    ThreadTest* matrix = new ThreadTest();
    matrix->setData(10);
    matrix->threadStart();
    sleep(1);
    matrix->setData(20);
    sleep(30);
    delete matrix;
    return 0;
}
