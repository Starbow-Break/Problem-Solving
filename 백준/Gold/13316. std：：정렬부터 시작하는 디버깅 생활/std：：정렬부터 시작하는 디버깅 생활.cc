#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

vector<pii> vec;

int main()
{
    vec.push_back({0, 0});
    vec.push_back({1, 2});
    vec.push_back({1, 3});
    vec.push_back({0, 0});
    vec.push_back({1, 4});
    vec.push_back({1, 5});
    
    cout << vec.size() << '\n';
    
    for(auto &p: vec) {
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}