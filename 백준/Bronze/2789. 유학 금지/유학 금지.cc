#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s, t = ""; cin >> s;
    string u = "CAMBRIDGE";
    bool check[26] = {false, };
    for(int i = 0; i < u.length(); i++) check[u[i]-'A'] = true;
    
    for(int i = 0; i < s.length(); i++) {
        for(int j = 0; j <= u.length(); j++) {
            if(j == u.length()) t += s[i];
            else {
                if(check[s[i]-'A']) break;
            }
        }
    }
    
    cout << t;
    
    return 0;
}