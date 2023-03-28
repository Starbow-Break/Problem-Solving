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

int arr[26] = {0, -1, 1, -1, -1, -1, 2, -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1};

//------------------Aho-Corasick------------------
class TrieNode {
    private:
    TrieNode* child[4];
    TrieNode* failure;
    bool isRoot, isEnd;
    
    public:
    TrieNode(bool isRoot = false) {
        for(int i = 0; i < 4; i++) child[i] = NULL;
        failure = NULL; isEnd = false;
        this->isRoot = isRoot;
    }
    
    void insert(string s, int l, int r, int step = 0) {
        if(step == s.length()) {
            isEnd = true; return;
        }
        
        int idx;
        if(l <= step && step <= r) idx = (l+r)-step;
        else idx = step;
        
        int t = arr[s[idx]-'A'];
        
        if(child[t] == NULL) {
            child[t] = new TrieNode();
        }
        
        child[t]->insert(s, l, r, step+1);
    }
    
    void setFailure() {
        queue<TrieNode*> q; q.push(this);
        
        while(!q.empty()) {
            TrieNode* cur = q.front(); q.pop();
            
            for(int i = 0; i < 4; i++) {
                TrieNode* next = cur->child[i];
                
                if(next == NULL) continue;
                
                if(cur->isRoot) next->failure = cur;
                else {
                    TrieNode* fail = cur->failure;
                    
                    while(!(fail->isRoot) && fail->child[i] == NULL)
                        fail = fail->failure;
                        
                    if(fail->child[i] != NULL) fail = fail->child[i];
                    
                    next->failure = fail;
                    
                    if(fail->isEnd) next->isEnd = true;
                }
                    
                q.push(next);
            }
        }
    }
    
    int count(string s) {
        int ret = 0;
        
        TrieNode* cur = this;
        for(int i = 0; i < s.length(); i++) {
            int t = arr[s[i]-'A'];
            while(!(cur->isRoot) && cur->child[t] == NULL)
                cur = cur->failure;
    
            if(cur->child[t] != NULL) cur = cur->child[t];
            
            ret += (cur->isEnd);
        }
        
        return ret;
    }
    
    void clear() {
        for(int i = 0; i < 4; i++) {
            if(child[i] != NULL) {
                child[i]->clear();
            }
            
            delete child[i];
            child[i] = NULL;
        }
    }
};

class Trie {
    private:
    TrieNode root;
    
    void insert(string s, int l, int r) {
        root.insert(s, l, r);
    }
    
    void setFailure() {
        root.setFailure();
    }
    
    public:
    Trie() {
        root = TrieNode(true);
    }
    
    void build(string marker, int M) {
        insert(marker, -1, -1);
        for(int i = 0; i < M; i++) {
            for(int j = i+1; j < M; j++) {
                insert(marker, i, j);
            }
        }

        setFailure();
    }
    
    int solve(string s) {
        return root.count(s);
    }
    
    void clear() {
        root.clear();
    }
};
//------------------Aho-Corasick------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    Trie tr = Trie();
    while(T--) {
        tr.clear();
        
        int N, M; cin >> N >> M;
        string s, marker; cin >> s >> marker;
        
        tr.build(marker, M);
        
        cout << tr.solve(s) << '\n';
    }

    return 0;
}