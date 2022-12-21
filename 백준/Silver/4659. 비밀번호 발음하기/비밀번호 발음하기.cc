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

bool checkVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool check(string s) {
    bool hasVowel = false;
    bool isVowel = false; int combo = 0;
    for(int i = 0; i < s.length(); i++) {
        if(checkVowel(s[i])) {
            hasVowel = true;
            if(isVowel) combo++;
            else {
                isVowel = true; combo = 1;
            }
        }
        else {
            if(!isVowel) combo++;
            else {
                isVowel = false; combo = 1;
            }
        }
        
        if(combo == 3) return false;
        
        if(i >= 1 && s[i] == s[i-1]) {
            if(s[i] == 'e' || s[i] == 'o') {
                if(i >= 2 && s[i-2] == s[i]) return false;
            }
            else return false;
        }
    }
    
    return hasVowel;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    while(1) {
        cin >> s;
        if(s == "end") break;
        
        cout << "<" << s << "> ";
        cout << (check(s) ? "is acceptable." : "is not acceptable.") << '\n';
    }

    return 0;
}