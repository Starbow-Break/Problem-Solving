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
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pair<char, char> &p) {
    out << p.first << ' ' << p.second;
    return out;
}

//실패함수 구하기
vector<int> getFail(string &s) {
    vector<int> fail;
    int j = 0;
    fail.push_back(j);
    for(int i = 1; i < s.length(); i++) {
        while(j > 0 && s[j] != s[i]) j = fail[j-1];
        if(s[j] == s[i]) j++;
        fail.push_back(j);
    }
    return fail;
}

bool kmp(string &s, string &t) {
    vector<int> fail = getFail(t);
    for(int i = 1, j = 0; i < s.length()-1; i++) {
        while(j > 0 && s[i] != t[j]) j = fail[j-1];
        if(s[i] == t[j]) j++;
        if(j == t.length()) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    vector<int> fail = getFail(s); //s의 실패함수 구하기
    
    string t = ""; int j = fail[s.length()-1];
    for(int i = 0; i < j; i++) t += s[i];
    
    if(t == "") cout << -1;
    else if(kmp(s, t)) cout << t; //t가 s[1..s.length()-1]의 부분문자열이면 t는 카멜레온 부분문자열이다. 
    else {
        j = fail[j-1];
        if(j) {
            t = "";
            for(int i = 0; i < j; i++) t += s[i];
            cout << t;
        }
        else cout << -1;
    }
    
    return 0;
}