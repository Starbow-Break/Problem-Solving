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
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct query {
    int q, num;
};

int N, Q, k;
vector<query> queries;
list<int> scheduler;
bool rev = false;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> Q >> k;
    while(Q--) {
        int q; cin >> q;
        if(!q) {
            int num; cin >> num;
            queries.push_back({q, num});
        }
        else queries.push_back({q, -1});
    }
    
    int t;
    for(t = queries.size()-1; t >= 0; t--) {
        if(queries[t].q == 1) break;
    }
    
    for(int i = 0; i <= t; i++) {
        if(queries[i].q == 0) {
            scheduler.push_back(queries[i].num);
        }
    }
    
    scheduler.sort();
    
    for(int i = t+1; i < queries.size(); i++) {
        if(queries[i].q == 2) {
            rev = !rev;
        }
        else {
            if(rev) scheduler.push_back(queries[i].num);
            else scheduler.push_front(queries[i].num);
        }
    }
    
    if(rev) {
        auto iter = scheduler.end();
        while(k--) { iter--; }
        cout << *iter;
    }
    else {
        auto iter = scheduler.begin(); k--;
        while(k--) { iter++; }
        cout << *iter;
    }

    return 0;
}