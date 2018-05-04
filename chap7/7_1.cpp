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

enum Suit {
	CLUB = 0,
	DIAMOND = 1,
	HEART = 2,
	SPADE = 3,
};

class Deck {
	private:
	vector<Card> cards;

	public:
	void setDeckofCards(vector<Card> deckOfCars)
	{
		/* ... */
	}

	void shuffle()
	{
		/* ... */
	}
};

class Card {
	private:
	int faceValue;
	Suit suit;

	public:
	Card(int c, Suit s)
	{
		faceValue = c;
		suit = s;
	}

	int value()
	{
		return faceValue;
	}

	Suit suit()
	{
		return suit;
	}
};

class Hand
{
	protected:
	vector<Card> cards;

	public:
	void addCard(Card card)
	{
		cards.append(card);
	}
};


int main()
{
    return 0;
}
