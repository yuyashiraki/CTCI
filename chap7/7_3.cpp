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

class CD
{
	private:
	string name;
	vector<Song *> songs;
	vector<Artist *> artists;
};

class Song
{
	private:
	CD *cd;
	vector<Artist *> artists;
};

class Artist
{
	private:
	vector<Song *> songs;
	vector<CD *> cds;
};

class Playlist
{
	private:
	vector<Song *> songs;
};

class Jukebox
{
	private:
	queue<Song *> songPlayQueue;
	vector<CD *> cds;
	vector<Song *> songs;
	map<string, Artist *> artists;
};

int main()
{
    return 0;
}
