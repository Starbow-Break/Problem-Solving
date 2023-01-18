#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

bool visited[7][7] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<string> knight;
    
    string s;
    while(cin >> s) { knight.push_back(s); }
    knight.push_back(knight[0]);
    
    bool ans = true; int r = -1, c = -1;
    for(auto &s: knight) {
        int rr = s[1]-'0'; int cc = s[0]-'A'+1;
        
        if(r == -1 && c == -1) { r = rr; c = cc; }
        else {
            if(visited[rr][cc]) {
                ans = false; break; 
            }
            
            visited[rr][cc] = true;
            
            int dr = abs(r-rr); int dc = abs(c-cc);
            if(!((dr == 2 && dc == 1) || (dr == 1 && dc == 2))) {
                ans = false; break;
            }
            
            r = rr; c = cc;
        }
    }
    
    cout << (ans ? "Valid" : "Invalid");

    return 0;
}