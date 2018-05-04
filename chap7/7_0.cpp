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

/*
 * Singleton Class:
 * 	A class has only one instance and ensures access to the instance through the application.
 */
class Restaurant
{
	private:
	static Restaurant *_instance = NULL;

	protected:
	Restaurant() 
	{
		/* ... */
	}

	public:
	Restaurant getInstance()
	{
		if (NULL == _instance) {
			_instance = new Restraurant();
		}
		return _instance;
	}
};

/*
 *	Factory Method:
 *		A class offers an interface for creating an instance of a class.
 */
class CardGame
{
	public:
	static CardGame createCardGame(GameType type)
	{
		if (type == GameType.Poker) {
			return new PokerGame();
		} else if (type == GameType.BlackJack) {
			return new BlackJackGame();
		}
		return NULL;
	}
}

int main()
{
    return 0;
}
