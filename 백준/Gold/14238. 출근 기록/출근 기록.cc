#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MAX 100000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int cnt[3] = {0, };
vector<char> ans(51);
string d = "CBA";

bool visited[51][51][51][3][3] = {false, };

bool solve(int step = 0, int b = 0, int c = 0) {
    if(visited[cnt[0]][cnt[1]][cnt[2]][b][c]) return false;
    
    visited[cnt[0]][cnt[1]][cnt[2]][b][c] = true;
    
    if(!cnt[0] && !cnt[1] && !cnt[2]) return true;
    
    for(int i = 0; i < 3; i++) {
        char cur = d[i];
        
        if(!cnt[cur-'A']) continue;
        
        if(cur == 'A') {
            ans[step] = 'A'; cnt[cur-'A']--;
            if(solve(step+1, max(0, b-1), max(0, c-1))) return true;
            cnt[cur-'A']++;
        }
        else if(cur == 'B') {
            if(b) continue;
            
            ans[step] = 'B'; cnt[cur-'A']--;
            if(solve(step+1, 1, max(0, c-1))) return true;
            cnt[cur-'A']++;
        }
        else {
            if(c) continue;
            
            ans[step] = 'C'; cnt[cur-'A']--;
            if(solve(step+1, max(0, b-1), 2)) return true;
            cnt[cur-'A']++;
        }
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    for(int i = 0; i < s.length(); i++) {
        cnt[s[i]-'A']++; 
    }
    
    if(solve()) {
        for(auto &a: ans) { cout << a; }
    }
    else cout << -1;

    return 0;
}
