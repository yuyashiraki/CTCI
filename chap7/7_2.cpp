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

#define MAX_EMPLOYEE_LEVEL 3
#define MAX_NAME_LEN 250
#define MAX_TITLE_LEN 250

class CallHandler {
	private:
	/* List of employee
	 * levels[0] = respondents
	 * levels[1] = managers
	 * levels[2] = directors
	 */
	vector<Employee *> levels(MAX_EMPLOYEE_LEVEL);

	/* queues for each call's level */
	vector<queue<Call *> > callQueues(MAX_EMPLOYEE_LEVEL);
	
	public:
	CallHandler()
	{
	}

	/* Gets the first available employee who can handle this call */
	Employee *getHandlerForCall(Call *call)
	{
	}

	/* Routes the call to an available employee, or saves in a queue if no employee is available */
	void dispatchCall(Caller *caller)
	{
		Call *call = new Call(caller);
		dispatchCall(call);
	}

	/* ROutes the call to an available employee, or saves in a queue if no employee is available */
	void dispatchCall(Call *call)
	{
		Employee *emp = getHandlerForCall(call);
		if (emp != NULL) {
			emp->receiveCall(call);
			call.setHandler(emp);
		} else {
			/* Place the call into corresponding call queue according to its rank */
			call->reply("Please wait for free employee to reply")
			callQueues.get(call->getLevel()).push(call);
		}
	}

	bool assignCall(Employee emp)
	{
	}
};

class Call {
	private:
	int level;
	Caller *caller;
	Employee *handler;

	public:
	Call(Caller *c)
	{
		level = 0;
		caller = c;
	}

	void setHandler(Employee *e)
	{
		handler = e;
	}

	void reply(string msg)
	{
	}

	int getLevel() {
		return level;
	}

	void disconnect()
	{
	}
};


class Employee
{
	private:
	char name[MAX_NAME_LEN];
	char title[MAX_TITLE_LEN];
	int age;
};

class Respondent: public Employee
{
};

class Manager: public Employee
{
};

class Director: public Employee
{
};

int main()
{
    return 0;
}
