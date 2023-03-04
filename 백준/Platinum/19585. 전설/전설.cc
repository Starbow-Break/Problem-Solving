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
#define MAX_N 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

bool check[2][2001] = {false, };

//--------------------------Trie--------------------------
class Trie {
    bool isEnd; //문자열의 끝을 나타니는 노드인지 표시
    map<char, Trie*> mp;
    
    public:
        Trie() {
            isEnd = false;
        }
        
        //문자열 추가
        void insert(string &s, int step = 0) {
            if(step == s.length()) {
                isEnd = true; return;
            }
            
            auto t = mp.find(s[step]);
            if(t == mp.end()) {
                t = mp.insert({s[step], new Trie()}).first;
            }
            t->second->insert(s, step+1);
        }
        
        //팀명에 속하는 색 or 닉네임 찾기
        void find(string &s, int idx, int step = 0) {
            if(isEnd) check[idx][step] = true;
            
            auto t = mp.find(s[step]);
            if(step == s.length() || t == mp.end()) return;
            t->second->find(s, idx, step+1);
        }
};
//--------------------------Trie--------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    Trie colorTrie = Trie(), nameTrie = Trie();
    
    int N, M; cin >> N >> M;
    //주어진 색 트라이에 추가
    while(N--) {
        string color; cin >> color;
        colorTrie.insert(color);
    }
    //주어진 닉네임을 뒤집은 다음 트라이에 추가
    while(M--) {
        string name; cin >> name;
        reverse(name.begin(), name.end());
        nameTrie.insert(name);
    }
    
    int Q; cin >> Q;
    while(Q--) {
        fill(check[0], check[0]+2001, false);
        fill(check[1], check[1]+2001, false);
        
        string team; cin >> team;
        colorTrie.find(team, 0);
        reverse(team.begin(), team.end());
        nameTrie.find(team, 1);
        
        for(int i = 1; i <= team.length(); i++) {
            if(i == team.length()) {
                cout << "No" << '\n';
            }
            else {
                if(check[0][i] && check[1][team.length()-i]) {
                    cout << "Yes" << '\n'; break;
                }
            }
        }
    }

    return 0;
}