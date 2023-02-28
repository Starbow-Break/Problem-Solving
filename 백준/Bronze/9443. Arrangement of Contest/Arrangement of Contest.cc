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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    bool arr[26] = {false, };
    
    int N; cin >> N;
    while(N--) {
        string s; cin >> s;
        arr[s[0]-'A'] = true;
    }
    
    for(int i = 0; i <= 26; i++) {
        if(i == 26 || !arr[i]) {cout << i; break;}
    }
    
    return 0;
}