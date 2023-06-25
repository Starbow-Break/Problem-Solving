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

vector<pair<string, int>> words;
char board[4][5];
bool visited[4][4];
int score[300'000];
bool findWord[300'000];
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    if(a.first.length() != b.first.length())
        return a.first.length() < b.first.length();
    else
        return a.first > b.first;
}

struct Node {
    int isEnd;
    Node* child[26];
    
    Node() {
        isEnd = 0;
        for(int i = 0; i < 26; i++) child[i] = NULL;
    }
    
    void insert(string &s, int num, int idx = 0) {
        if(idx == s.length()) {
            isEnd = num;
            return;
        }
        if(child[s[idx]-'A'] == NULL) {
            child[s[idx]-'A'] = new Node();
        }
        child[s[idx]-'A']->insert(s, num, idx+1);
    }
};

class Trie {
    private:
    Node* root;
    
    public:
    Trie() {
        root = new Node();
    }
    
    //문자열 추가
    void insert(string &s, int num) {
        root->insert(s, num);
    }
    
    //루트 노드 반환
    Node* getRoot() {
        return root;
    }
};

void init() {
    fill(findWord, findWord+300'000, false);
}

void dfs(Node *p, int r, int c) {
    char ch = board[r][c];
    if(p->child[ch-'A'] == NULL) return;
    
    visited[r][c] = true;
    p = p->child[ch-'A'];
    if(p->isEnd) findWord[p->isEnd] = true;
    
    for(int i = 0; i < 8; i++) {
        if(0 <= r+dr[i] && r+dr[i] < 4 && 0 <= c+dc[i] && c+dc[i] < 4) {
            if(!visited[r+dr[i]][c+dc[i]]) dfs(p, r+dr[i], c+dc[i]);
        }
    }
    
    visited[r][c] = false;
}

void progress(Trie *tr, int r, int c) {
    for(int i = 0; i < 4; i++) fill(visited[i], visited[i]+4, false);
    Node *p = tr->getRoot();
    dfs(p, r, c);
}

int calcScore(string &word) {
    switch(word.length()) {
        case 1:
        case 2: return 0;
        case 3:
        case 4: return 1;
        case 5: return 2;
        case 6: return 3;
        case 7: return 5;
        case 8: return 11;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int w; cin >> w;
    Trie* tr = new Trie();
    
    //트라이에 사전에 등재된 단어 전부 담기
    for(int i = 1; i <= w; i++) {
        string word; cin >> word;
        score[i] = calcScore(word);
        words.push_back({word, i});
        tr->insert(word, i);
    }
    
    sort(words.begin(), words.end(), cmp);
    
    int b; cin >> b;
    while(b--) {
        init();
        for(int i = 0; i < 4; i++) cin >> board[i];
        
        //가능한 단어 찾기
        for(int r = 0; r < 4; r++) {
            for(int c = 0; c < 4; c++) {
                progress(tr, r, c);
            }
        }
        
        int totalScore = 0, numWord = 0;
        string longestWord = "";
        
        for(int i = 1; i <= w; i++) {
            numWord += findWord[i];
            totalScore += findWord[i]*score[i];
        }
        
        for(auto &w: words) {
            if(findWord[w.second]) longestWord = w.first;
        }
        
        cout << totalScore << ' ' << longestWord << ' ' << numWord << '\n';
    }

    return 0;
}