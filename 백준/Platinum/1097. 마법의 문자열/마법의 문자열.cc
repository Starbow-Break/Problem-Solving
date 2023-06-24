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
#define MAX_L 500'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

vector<vector<int>> pers;

vector<int> temp;
bool used[8] = {false, };
void getPermutation(int N, int step = 0) {
    if(step == N) {
        pers.push_back(temp);
        return;
    }
    
    for(int i = 0; i < N; i++) {
        if(!used[i]) {
            used[i] = true;
            temp.push_back(i);
            getPermutation(N, step+1);
            temp.erase(temp.end()-1);
            used[i] = false;
        }
    }
}

vector<int> getFail(string &s) {
    vector<int> fail;
    fail.push_back(0);
    
    for(int i = 1, j = 0; i < s.length(); i++) {
        while(j > 0 && s[i] != s[j]) j = fail[j-1];
        if(s[i] == s[j]) j++;
        fail.push_back(j);
    }
    
    return fail;
}

int kmp(string &s, string &t) {
    vector<int> fail = getFail(t);
    int ret = 0;
    
    for(int i = 0, j = 0; i < s.length()-1; i++) {
        while(j > 0 && s[i] != t[j]) j = fail[j-1];
        if(s[i] == t[j]) j++;
        if(j == t.length()) {
            ret++; j = fail[j-1];
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<string> words;
    
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        words.push_back(s);
    }
    
    getPermutation(N);
    
    int ans = 0, K;
    cin >> K;
    for(auto &per: pers) {
        string s = "";
        for(auto &i: per)
        s += words[i];
        string ss = s+s;
        int cnt = kmp(ss, s);
        ans += (cnt == K);
    }
    
    cout << ans;
    
    return 0;
}