#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int n, k;
vector<int> card;
vector<vector<int>> per;

bool visited[10] = {false, };
vector<int> temp;
void getPermutation(int n, int k, int step = 0) {
    if(step == k) {
        per.push_back(temp);
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            temp.push_back(i);
            getPermutation(n, k, step+1);
            temp.erase(temp.end()-1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int v; cin >> v;
        card.push_back(v);
    }
    
    getPermutation(n, k);
    
    map<int, int> mp;
    for(auto &p: per) {
        int v = 0;
        for(int i = 0; i < k; i++) {
            if(card[p[i]] < 10) {
                v *= 10;
                v += card[p[i]];
            }
            else {
                v *= 100;
                v += card[p[i]];
            }
        }
        
        mp.insert({v, 0});
    }
    
    cout << mp.size();

    return 0;
}