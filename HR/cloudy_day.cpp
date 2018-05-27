#include <bits/stdc++.h>
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
#include <tuple>
#include <map>
#include <string>
#include <iterator>


using namespace std;

#define MAX_END 10000000000

vector<string> split_string(string);

// Complete the maximumPeople function below.
long maximumPeople(vector<long> p, vector<long> x, vector<long> y, vector<long> r) {
    // Return the maximum number of people that will be in a sunny town after removing exactly one cloud.
    // p = [populations in each town]
    // x = [location of each town]
    // y = [location of clouds]
    // r = [range of clouds]
    set<tuple<long long, long long, long long> > bin_tree;  // bin_tree[(location, population)]
    long long total_pop = 0;
    for (int idx = 0; idx < x.size(); idx++) {
        bin_tree.insert(make_tuple(x[idx], p[idx], idx));
        total_pop += p[idx];
    }
    for (int idy = 0; idy < y.size(); idy++) {
        bin_tree.insert(make_tuple(y[idy] - r[idy], -1, idy));
        bin_tree.insert(make_tuple(y[idy] + r[idy], MAX_END, idy));
    }

    set<long long> clouds;
    map<long long, long long> single_cover_pop;
    long long sunny_pop = 0, dark_pop = 0, num_clouds = 0, max_single_cover = 0;
    for (auto itr = bin_tree.begin(); itr != bin_tree.end(); ++itr) {
        long long pop = get<1>(*itr), idc = get<2>(*itr);
        if (-1 == pop) {
            clouds.insert(idc);
            single_cover_pop[idc] = 0;
            num_clouds++;
            continue;
        }
        if (MAX_END == pop) {
            clouds.erase(idc);
            max_single_cover = max(max_single_cover, single_cover_pop[idc]);
            num_clouds--;
            continue;
        }
        if (0 == num_clouds) {
            sunny_pop += pop;
            continue;
        }
        if (1 == num_clouds) {
            single_cover_pop[(long long)*clouds.begin()] += pop;
        }
        dark_pop += pop;
    }
    assert((total_pop - dark_pop + max_single_cover) == (sunny_pop + max_single_cover));
    return sunny_pop + max_single_cover;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<long> p(n);

    for (int i = 0; i < n; i++) {
        long p_item = stol(p_temp[i]);

        p[i] = p_item;
    }

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split_string(x_temp_temp);

    vector<long> x(n);

    for (int i = 0; i < n; i++) {
        long x_item = stol(x_temp[i]);

        x[i] = x_item;
    }

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string y_temp_temp;
    getline(cin, y_temp_temp);

    vector<string> y_temp = split_string(y_temp_temp);

    vector<long> y(m);

    for (int i = 0; i < m; i++) {
        long y_item = stol(y_temp[i]);

        y[i] = y_item;
    }

    string r_temp_temp;
    getline(cin, r_temp_temp);

    vector<string> r_temp = split_string(r_temp_temp);

    vector<long> r(m);

    for (int i = 0; i < m; i++) {
        long r_item = stol(r_temp[i]);

        r[i] = r_item;
    }

    long result = maximumPeople(p, x, y, r);

    fout << result << "\n";
    cout << result << endl;

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

