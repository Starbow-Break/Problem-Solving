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

bool isOver(int n) {
    int sum = 0;
    for(int j = 1; j < n; j++) {
        if(!(n%j)) sum += j;
    }
    
    return sum > n;
}

bool check(int n) {
    for(int j = 1; j < n; j++) {
        if(!(n%j) && isOver(j)) return false;
    }
    
    return isOver(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        cout << (check(n) ? "Good Bye" : "BOJ 2022") << '\n';
    }

    return 0;
}