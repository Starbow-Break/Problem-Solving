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

bool _left[500'001][100] = {false, }, _right[500'001][100] = {false, };

//실패함수 구하기
vector<int> getFail(string s) {
    vector<int> fail(s.length());
    
    fail[0] = 0;
    
    for(int i = 1; i < s.length(); i++) {
        int j = fail[i-1];
        while(j > 0 && s[j] != s[i]) j = fail[j-1];
        
        if(s[j] == s[i]) j++;
        fail[i] = j;
    }
    
    return fail;
}

void kmp(string &s, string &t, int idx) {
    vector<int> fail = getFail(t);
    
    for(int i = 0, j = 0; i < s.length(); i++) {
        while(j > 0 && t[j] != s[i]) j = fail[j-1];
        
        if(t[j] == s[i]) j++;
        
        if(j == t.length()) {
            _left[i-j+1][idx] = true;
            _right[i][idx] = true; 
            j = fail[j-1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<string> strSet;
    
    for(int i = 0; i < N; i++) {
        int L; string s;
        cin >> L >> s;
        strSet.push_back(s);
    }
    
    int lenS; string S; cin >> lenS >> S;
    
    for(int i = 0; i < N; i++) kmp(S, strSet[i], i);
    
    int ans = 1'000'000;
    
    int i = 0, j = -1;
    int cnt[100] = {0, }; int _cnt = 0;
    while(j < lenS) {
        if(_cnt < N) {
            j++;
            
            for(int k = 0; k < N; k++) {
                if(_right[j][k]) {
                    if(cnt[k] == 0) _cnt++;
                    cnt[k]++;
                }
            }
        }
        else {
            ans = min(ans, j-i+1);
            
            for(int k = 0; k < N; k++) {
                if(_left[i][k]) {
                    cnt[k]--;
                    if(cnt[k] == 0) _cnt--;
                }
            }
            
            i++;
        }
    }
    
    cout << ans;

    return 0;
}