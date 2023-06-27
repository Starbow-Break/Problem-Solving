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

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

bool check1(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'h';
}

bool check(string word) {
    for(int i = 0; i < word.length(); i++) {
        if(word[i] == '\'') {
            if(i == 1 && word.length() >= 3) {
                if(word[i-1] == 'c') return check1(word[i+1]);
                if(word[i-1] == 'j') return check1(word[i+1]);
                if(word[i-1] == 'n') return check1(word[i+1]);
                if(word[i-1] == 'm') return check1(word[i+1]);
                if(word[i-1] == 't') return check1(word[i+1]);
                if(word[i-1] == 's') return check1(word[i+1]);
                if(word[i-1] == 'l') return check1(word[i+1]);
                if(word[i-1] == 'd') return check1(word[i+1]);
            }
            if(i == 2 && word.length() >= 4) {
                if(word[i-2] == 'q' && word[i-1] == 'u') return check1(word[i+1]);
            }
        }
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    getline(cin, s);
    vector<string> words;
    
    string w = "";
    for(auto &c: s) {
        if(c == ' ' || c == '-') {
            words.push_back(w);
            w = "";
        }
        else w += c;
    }
    words.push_back(w);
    
    int ans = words.size();
    
    for(auto &word: words) {
        ans += check(word);
    }
    
    cout << ans;
    
    return 0;
}