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

map<int, int> mp;
int arr[500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int K, L; cin >> K >> L;
    for(int i = 1; i <= L; i++) {
        int s; cin >> s;
        auto t = mp.find(s);
        
        if(t == mp.end()) {
            arr[i] = s;
            mp.insert({s, i});
        }
        else {
            arr[t->second] = -1; arr[i] = s;
            t->second = i;
        }
    }
    
    for(int i = 1; i <= L && K > 0; i++) {
        if(arr[i] > -1) {
            printf("%08d\n", arr[i]); K--;
        }
    }

    return 0;
}