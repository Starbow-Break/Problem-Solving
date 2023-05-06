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
typedef __int128_t int128;

const ll mod = 10'000'000'000'000;

ll fibonacci(ll n, ll mod) {
    if(n == 0) return 0;
    
    int128 arr[2][2] = {1, 0, 0, 1};
    int128 w[2][2] = {1, 1, 1, 0};
    int128 temp[2][2];
    while(n > 0) {
        if(n%2) {
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    temp[i][j] = (arr[i][0]*w[0][j]+arr[i][1]*w[1][j])%mod;
                }
            }
            
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    arr[i][j] = temp[i][j];
                }
            }
        }
        
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                temp[i][j] = (w[i][0]*w[0][j]+w[i][1]*w[1][j])%mod;
            }
        }
            
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                w[i][j] = temp[i][j];
            }
        }
        
        n /= 2;
    }
    
    return arr[0][1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
    
    vector<ll> indexVec; int f[1500];
    ll cur = 1'000;
    
    f[0] = 0; f[1] = 1;
    for(int i = 2; i < 1500; i++) {
        f[i] = (f[i-1]+f[i-2])%cur;
    }
    for(int i = 1; i < 1500; i++) {
        if(f[i] == n%cur) indexVec.push_back(i);
    }
    
    do {
        cur *= 10;
        vector<ll> temp;
        
        sort(indexVec.begin(), indexVec.end());
        
        for(int i = 0; i < indexVec.size(); i++) {
            for(int j = 0; j < 10; j++) {
                if(fibonacci(cur*15/100*j+indexVec[i], cur) == n%cur) {
                    temp.push_back(cur*15/100*j+indexVec[i]);
                }
            }
        }
        
        indexVec = temp;
    } while(cur < mod);
    
    sort(indexVec.begin(), indexVec.end());
    
    cout << (indexVec.empty() ? -1 : indexVec[0]);

    return 0;
}