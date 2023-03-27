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

//------------------Aho-Corasick------------------
class Trie {
    private:
    Trie* child[26]; //자식노드
    Trie* failure; //실패 노자식노드
    bool isEnd; //문자열의 끝을 표시
    bool isRoot; //트라이의 루트노드임을 표시
    
    //문자열 하나를 트라이에 추가
    void insert(string s, int idx = 0) {
        if(idx == s.length()) {
            isEnd = true; return;
        }
        
        if(child[s[idx]-'a'] == NULL) {
            child[s[idx]-'a'] = new Trie();
        }
        
        child[s[idx]-'a']->insert(s, idx+1);
    }
    
    //각 노드의 실패시 이동할 노드 구하기
    void getFailure() {
        queue<Trie*> q; q.push(this);
        
        while(!q.empty()) {
            Trie* cur = q.front(); q.pop();
            
            for(int i = 0; i < 26; i++) {
                if(cur->child[i] == NULL) continue;
                
                if(cur->isRoot) cur->child[i]->failure = cur;
                else {
                    Trie* fail = cur->failure;
                    while(!(fail->isRoot) && fail->child[i] == NULL) {
                        fail = fail->failure;
                    }
                    
                    if(fail->child[i] != NULL) {
                        fail = fail->child[i];
                    }
                    
                    cur->child[i]->failure = fail;
                    
                    if(fail->isEnd)
                        cur->child[i]->isEnd = true;
                }
                
                q.push(cur->child[i]);
            }
        }
    }
    
    public:
    //생성자
    Trie(bool isRoot = false) {
        for(int i = 0; i < 26; i++) child[i] = NULL;
        failure = NULL; isEnd = false;
        this->isRoot = isRoot;
    }
    
    //트라이 빌드하기
    void build(vector<string> strSet) {
        //모든 문자열을 트라이에 추가
        for(auto &s: strSet) {
            insert(s);
        }
        
        getFailure(); //실패노드 구하기
    }
    
    bool check(string s) {
        Trie* cur = this;
        
        bool ret = false;
        for(int i = 0; i < s.length() && !ret; i++) {
            while(!(cur->isRoot) && cur->child[s[i]-'a'] == NULL)
                cur = cur->failure;
  
            if(cur->child[s[i]-'a'] != NULL)
                cur = cur->child[s[i]-'a'];
            
            if(cur->isEnd) ret = true;
        }
        
        return ret;
    }
};
//------------------Aho-Corasick------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    Trie tr = Trie(true);
    vector<string> S, Q;
    
    int N; cin >> N;
    while(N--) {
        string s; cin >> s;
        S.push_back(s);
    }
    
    int M; cin >> M;
    while(M--) {
        string s; cin >> s;
        Q.push_back(s);
    }
    
    tr.build(S);
    
    for(auto &q: Q) {
        cout << (tr.check(q) ? "YES" : "NO") << '\n';
    }

    return 0;
}