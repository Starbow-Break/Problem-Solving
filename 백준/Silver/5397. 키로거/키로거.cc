#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <list>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

list<char> password;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        password.clear();
        auto cursor = password.begin();
        
        string s; cin >> s;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '<') {
                if(cursor != password.begin()) cursor--;
            }
            else if(s[i] == '>') {
                if(cursor != password.end()) cursor++;
            }
            else if(s[i] == '-') {
                if(cursor != password.begin()) cursor = password.erase(--cursor);
            }
            else {
                cursor = password.insert(cursor, s[i]); cursor++;
            }
        }
        
        for(auto &c: password) { cout << c; }
        cout << '\n';
    }

    return 0;
}