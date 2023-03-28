#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int in[300'001] = {0, }, out[300'001] = {0, };

//------------------Aho-Corasick------------------
class TrieNode {
    private:
    vector<pair<char, TrieNode*>> child;
    TrieNode* failure;
    bool isRoot; int isEnd;
    
    public:
    TrieNode(bool isRoot = false) {
        failure = NULL; isEnd = 0;
        this->isRoot = isRoot;
    }
    
    void insert(string &s, int idx = 0) {
        if(idx == s.length()) {
            isEnd = s.length(); return;
        }
        
        for(auto &t: child) {
            if(t.first == s[idx])
                return t.second->insert(s, idx+1);
        }
        
        child.push_back({s[idx], new TrieNode()});
        child.back().second->insert(s, idx+1);
    }
    
    void setFailure() {
        queue<TrieNode*> q; q.push(this);
        
        while(!q.empty()) {
            TrieNode* cur = q.front(); q.pop();
            
            for(auto &t: cur->child) {
                char c = t.first;
                TrieNode* next = t.second;
                
                if(cur->isRoot) next->failure = cur;
                else {
                    TrieNode* fail = cur->failure;
                    
                    while(!(fail->isRoot)) {
                        bool check = false;
                        
                        for(auto &f: fail->child) {
                            if(f.first == t.first) {
                                check = true; break;
                            }
                        }
                        
                        if(check) break;
                        
                        fail = fail->failure;
                    }
                    
                    for(auto &f: fail->child) {
                        if(f.first == t.first) {
                            fail = f.second; break;
                        }
                    }
                    
                    next->failure = fail;
                    
                    if(fail->isEnd) next->isEnd = max(next->isEnd, fail->isEnd);
                }
                    
                q.push(next);
            }
        }
    }
    
    void solve(string s) {
        TrieNode* cur = this;
        for(int i = 0; i < s.length(); i++) {
            while(!(cur->isRoot)) {
                bool check = false;
                        
                for(auto &t: cur->child) {
                    if(t.first == s[i]) {
                        check = true; break;
                    }
                }
                
                if(check) break;
                
                cur = cur->failure;
            }
            
            for(auto &t: cur->child) {
                if(t.first == s[i]) {
                    cur = t.second;
                }
            }
            
            if(cur->isEnd) { in[i-(cur->isEnd)+1]++; out[i+1]++; }
        }
    }
};

class Trie {
    private:
    TrieNode root;
    
    void insert(string s) {
        root.insert(s);
    }
    
    void setFailure() {
        root.setFailure();
    }
    
    public:
    Trie() {
        root = TrieNode(true);
    }
    
    void build(vector<string> strSet) {
        for(auto &s: strSet) {
            insert(s);
        }

        setFailure();
    }
    
    void solve(string s) {
        root.solve(s);
    }
};
//------------------Aho-Corasick------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string street; vector<string> tiles;
    int N, M;
    
    cin >> N >> street >> M;
    while(M--) {
        string tile; cin >> tile;
        tiles.push_back(tile);
    }
    
    Trie tr = Trie();
    tr.build(tiles);
    
    tr.solve(street);
    
    int ans = 0; int cnt = 0;
    for(int i = 0; i < N; i++) {
        cnt += in[i]-out[i];
        ans += (cnt == 0);
    }
    
    cout << ans;
    
    return 0;
}