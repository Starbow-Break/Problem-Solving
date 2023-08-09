#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;


// 트라이
struct Trie {
    //트라이의 노드
    struct Node {
        Node *child[26];
        
        Node() {
            FOR(i, 0, 26) { child[i] = NULL; }
        };
        
        void insert(string &s, int idx = 0) {
            if(idx == s.length()) return;
            
            if(child[s[idx]-'a'] == NULL) {
                child[s[idx]-'a'] = new Node();
            }
            child[s[idx]-'a']->insert(s, idx+1);
        }
        
        string generateNickname(string &s, int idx = 0) {
            if(idx == s.length()) return "";
            
            if(child[s[idx]-'a'] == NULL) {
                string ret = "";
                for(int i = 0; i <= idx; i++) {
                    ret += s[i];
                }
                return ret;
            }
            return child[s[idx]-'a']->generateNickname(s, idx+1);
        }
    };
    
    Node *root;
    
    Trie() {
        root = new Node();
    }
    
    // 문자열 삽입
    void insert(string &s) {
        root->insert(s);
    }
    
    //별칭 생성
    string generateNickname(string s) {
        return root->generateNickname(s);
    };
};

map<string, int> mp;

void printNickname(Trie &tr, string &s) {
    auto t = mp.find(s);
    int cnt = 0;
    if(t == mp.end()) {
        cnt = 1;
        mp.insert({s, 1});
    }
    else {
        t->second++;
        cnt = t->second;
    }
    
    string result = tr.generateNickname(s);
    if(result == "") {
        cout << s;
        if(cnt > 1) cout << cnt;
        cout << '\n';
    }
    else {
        cout << result << '\n';
    }
    
    tr.insert(s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    Trie tr = Trie();
    while(N--) {
        string s; cin >> s;
        printNickname(tr, s);
    }
    
    return 0;
}