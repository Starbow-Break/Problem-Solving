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

string s;
vector<int> vec;
int ans;

bool checkLower(char a) {
    return ('a' <= a && a <= 'z');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> s;
    int cnt = 0; bool isLower = true;
    for(int i = 0; i < s.length(); i++) {
        if(checkLower(s[i])) {
            if(isLower) cnt++;
            else {
                vec.push_back(cnt); cnt = 1; isLower = true;
            }
        }
        else {
            if(isLower) {
                vec.push_back(cnt); cnt = 1; isLower = false;
            }
            else cnt++;
        }
    }
    vec.push_back(cnt);
    
    ans = s.length(); int idx = 0;
    while(idx < vec.size()-1) {
        if(vec[idx+1] == 1) { ans++; idx += 2; }
        else { ans++; idx++; }
    }
    
    cout << ans;

    return 0;
}