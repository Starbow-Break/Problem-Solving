#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORIter(v, vec) for(auto &v: vec)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

bool isAlphabet(char c) {
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

char capitalize(char c) {
    return ('A' <= c && c <= 'Z' ? c : c-'a'+'A');
}

string cipherPart(string part, vector<char>& grid, vector<int>& pos) {
    int pos0 = pos[part[0] - 'A'], pos1 = pos[part[1] - 'A'];
    
    // 행 일치
    if(pos0/5 == pos1/5) {
        pos0 = pos0/5*5+(pos0%5+1)%5;
        pos1 = pos1/5*5+(pos1%5+1)%5;
    }
    else if(pos0%5 == pos1%5) { // 열 일치
        pos0 = (pos0/5+1)%5*5+pos0%5;
        pos1 = (pos1/5+1)%5*5+pos1%5;
    }
    else {
        int new0 = pos0/5*5+pos1%5;
        int new1 = pos1/5*5+pos0%5;
        pos0 = new0, pos1 = new1;
    }
    
    string ret = "XX";
    ret[0] = grid[pos0]; ret[1] = grid[pos1];
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    cin.ignore();
    
    FOR(tc, 1, t+1) {
        string key, plain;
        
        getline(cin, key); getline(cin, plain);
        
        vector<char> grid(25); vector<int> pos(26, -1);
        
        // 그리드 만들기
        int idx = 0;
        FORIter(c, key) {
            if(!isAlphabet(c)) continue;
            
            char cur = (capitalize(c) == 'J' ? 'I' : capitalize(c));
            if(pos[cur-'A'] == -1) {
                pos[cur-'A'] = idx;
                grid[idx] = cur;
                idx++;
            }
        }
        
        FOR(i, 0, 26) {
            if(i == 9) continue;
            if(pos[i] == -1) {
                pos[i] = idx;
                grid[idx] = (char)('A' + i);
                idx++;
            }
        }
        
        // 암호문 만들기기
        string cipher = "";
        string part = ""; bool flag = false;
        char addChar = 'A';
        FORIter(c, plain) {
            if(!isAlphabet(c)) continue;
            
            char cur = (capitalize(c) == 'J' ? 'I' : capitalize(c));
            if(part.length() == 0) { part += cur; }
            else {
                if(part[0] == cur) {
                    if(part[0] == addChar)
                        addChar = (addChar - 'A' + (addChar == 'I' ? 2 : 1)) % 26 + 'A';
                    part += addChar;
                    
                    addChar = (addChar - 'A' + (addChar == 'I' ? 2 : 1)) % 26 + 'A';
                    flag = true;
                }
                else part += cur;
            }
            
            if(part.length() == 2) {
                //cout << part << '\n';
                cipher += cipherPart(part, grid, pos);
                part = "";
                if(flag) {
                    part += capitalize(c);
                    flag = false;
                }
            }
        }
        
        if(part.length() == 1) {
            if(part[0] == addChar)
                addChar = (addChar - 'A' + (addChar == 'I' ? 2 : 1)) % 26 + 'A';
            //cout << part + addChar << '\n';
            cipher += cipherPart(part + addChar, grid, pos);
        }
        
        cout << "Case " << tc << ": " << cipher << '\n';
    }
    
    return 0;
}
