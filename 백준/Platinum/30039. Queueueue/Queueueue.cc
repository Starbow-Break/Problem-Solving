#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define push_back pb
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

//Queueueue의 노드
struct Node {
    int value;
    Node* hprev; //가로 Queue 기준 이전 노드
    Node* hnext; //가로 Queue 기준 다음 노드
    Node* vprev; //세로 Queue 기준 이전 노드
    Node* vnext; //세로 Queue 기준 다음 노드
    
    Node(int v) {
        value = v;
        hprev = hnext = vprev = vnext = NULL;
    }
};

//Queueueue
struct Queueueue {
    Node* hf; // 가로 Queue 기준 front
    Node* hb; // 가로 Queue 기준 back
    Node* vf; // 세로 Queue 기준 front
    Node* vb; // 세로 Queue 기준 back
    Node* m; // 공유 노드
    
    int hsz; // 가로 Queue에 들어있는 원소의 갯수
    int vsz; // 세로 Queue에 들어있는 원소의 갯수
    
    Queueueue() {
        hf = hb = vf = vb = m = NULL;
        vsz = hsz = 0;
    }
    
    // 가로 Queue 뒤에 정수 x를 삽입
    void hpush(int x) {
        if(hf == NULL) { //비어있는 상태면
            hf = new Node(x);
            m = vf = vb = hb = hf;
            hsz++; vsz++;
        }
        else { //이미 원소가 있으면
            hb->hnext = new Node(x);
            hb->hnext->hprev = hb;
            hb = hb->hnext;
            hsz++;
            
            //공유 원소가 변해야 한다면
            if((hsz+1)/2 > hsz/2) {
                if(m->vnext != NULL) {
                    m->vnext->vprev = m->hnext;
                    m->hnext->vnext = m->vnext;
                }
                else {
                    vb = vb->hnext;
                }
                
                if(m->vprev != NULL) {
                    m->vprev->vnext = m->hnext;
                    m->hnext->vprev = m->vprev;
                }
                else {
                    vf = vf->hnext;
                }
                
                m->vprev = m->vnext = NULL;
                m = m->hnext;
            }
        }
    }
    
    // 가로 Queue의 맨 앞의 요소 삭제 후 해당 요소 반환, 없으면 -1
    int hpop() {
        if(hf == NULL) return -1; //원소가 없으면 -1 반환
        
        int ret = hf->value;
        if(hsz == 1) { // 가로 Queue에 원소가 하나밖에 없는 경우
            if(vsz == 1) { // Queueueue에 원소가 하나 있는 경우
                hsz--; vsz--;
                delete hf;
                m = hf = hb = vf = vb = NULL;
            }
            else if(vsz == 2) {
                m = vf = vb = hf = hb = hf->vnext;
                delete hf->vprev;
                hf->vprev = NULL;
                vsz--;
            }
            else { // Queueueue에 원소가 두개 이상 있는 경우
                Node *p = hf;
                hf->vnext->vprev = hf->vprev;
                hf->vprev->vnext = hf->vnext;
                
                if((vsz+1)/2 == vsz/2) {
                    m = hf = hb = hf->vnext;
                }
                else {
                    m = hf = hb = hf->vprev;
                }
                
                p->vnext = p->vprev = NULL;
                delete p;
                
                vsz--;
            }
        }
        else { // 두개 이상 있는 경우
            if((hsz+1)/2 == hsz/2) { // 중간 요소의 위치가 유지되어야 하는 경우
                if(m->vnext != NULL) {
                    m->vnext->vprev = m->hnext;
                    m->hnext->vnext = m->vnext;
                }
                else {
                    vb = vb->hnext;
                }
                
                if(m->vprev != NULL) {
                    m->vprev->vnext = m->hnext;
                    m->hnext->vprev = m->vprev;
                }
                else {
                    vf = vf->hnext;
                }
                
                m->vprev = m->vnext = NULL;
                m = m->hnext;
            }
            
            hf = hf->hnext;
            delete hf->hprev;
            hf->hprev = NULL;
            hsz--;
        }
        
        return ret;
    }
    
    // 가로 Queue의 맨 앞의 요소 반환
    int hfront() {
        if(hf == NULL) return -1;
        return hf->value;
    }
    
    // 가로 Queue의 맨 뒤의 요소 반환
    int hback() {
        if(hb == NULL) return -1;
        return hb->value;
    }
    
    // 가로 Queue에 들어있는 요소의 갯수
    int hsize() {
        return hsz;
    }
    
    // 세로 Queue 뒤에 정수 x를 삽입
    void vpush(int x) {
        if(vf == NULL) { //비어있는 상태면
            vf = new Node(x);
            m = hf = hb = vb = vf;
            hsz++; vsz++;
        }
        else { //이미 원소가 있으면
            vb->vnext = new Node(x);
            vb->vnext->vprev = vb;
            vb = vb->vnext;
            vsz++;
            
            //공유 원소가 변해야 한다면
            if((vsz+1)/2 > vsz/2) {
                if(m->hnext != NULL) {
                    m->hnext->hprev = m->vnext;
                    m->vnext->hnext = m->hnext;
                }
                else {
                    hb = hb->vnext;
                }
                
                if(m->hprev != NULL) {
                    m->hprev->hnext = m->vnext;
                    m->vnext->hprev = m->hprev;
                }
                else {
                    hf = hf->vnext;
                }
                
                m->hprev = m->hnext = NULL;
                m = m->vnext;
            }
        }
    }
    
    // 세로 Queue의 맨 앞의 요소 삭제 후 해당 요소 반환, 없으면 -1
    int vpop() {
         if(vf == NULL) return -1; //원소가 없으면 -1 반환
        
        int ret = vf->value;
        if(vsz == 1) { // 세로 Queue에 원소가 하나밖에 없는 경우
            if(hsz == 1) { // Queueueue에 원소가 하나 있는 경우
                hsz--; vsz--;
                delete vf;
                m = hf = hb = vf = vb = NULL;
            }
            else if(hsz == 2) {
                m = hf = hb = vf = vb = vf->hnext;
                delete vf->hprev;
                vf->hprev = NULL;
                hsz--;
            }
            else { // Queueueue에 원소가 두개 이상 있는 경우
                Node *p = vf;
                vf->hnext->hprev = vf->hprev;
                vf->hprev->hnext = vf->hnext;
                
                if((hsz+1)/2 == hsz/2) {
                    m = vf = vb = vf->hnext;
                }
                else {
                    m = vf = vb = vf->hprev;
                }
                
                p->hnext = p->hprev = NULL;
                delete p;
                
                hsz--;
            }
        }
        else { // 두개 이상 있는 경우
            if((vsz+1)/2 == vsz/2) { // 중간 요소의 위치가 유지되어야 하는 경우
                if(m->hnext != NULL) {
                    m->hnext->hprev = m->vnext;
                    m->vnext->hnext = m->hnext;
                }
                else {
                    hb = hb->vnext;
                }
                
                if(m->hprev != NULL) {
                    m->hprev->hnext = m->vnext;
                    m->vnext->hprev = m->hprev;
                }
                else {
                    hf = hf->vnext;
                }
                
                m->hprev = m->hnext = NULL;
                m = m->vnext;
            }
            
            vf = vf->vnext;
            delete vf->vprev;
            vf->vprev = NULL;
            vsz--;
        }
        
        return ret;
    }
    
    // 세로 Queue의 맨 앞의 요소 반환
    int vfront() {
        if(vf == NULL) return -1;
        return vf->value;
    }
    
    // 세로 Queue의 맨 뒤의 요소 반환
    int vback() {
        if(vb == NULL) return -1;
        return vb->value;
    }
    
    // 세로 Queue에 들어있는 요소의 갯수
    int vsize() {
        return vsz;
    }
    
    //Queueueue 안에 들어있는 원소의 갯수 반환
    int size() {
        if(!hsz && !vsz) return 0;
        return hsz+vsz-1;
    }
    
    //Queueueue가 비어있으면 1 아니면 0 반환
    int empty() {
        return !hsz && !vsz;
    }
    
    // 공유 원소 반환, 없으면 -1
    int middle() {
        if(m == NULL) return -1;
        return m->value;
    }
    
    // 현재 Queueueue의 정보 표시, 디버깅용
    void printInfo() {
        cout << "horizontal queue: ";
        if(hf == NULL) cout << -1;
        else {
            for(Node* i = hf; i != NULL; i = i->hnext) {
                cout << i->value << ' ';
            }
        }
        cout << '\n';
        
        cout << "vertical queue: ";
        if(vf == NULL) cout << -1;
        else {
            for(Node* i = vf; i != NULL; i = i->vnext) {
                cout << i->value << ' ';
            }
        }
        cout << '\n';
        
        cout << "middle: " << middle() << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    Queueueue q = Queueueue();
    
    int N; cin >> N;
    while(N--) {
        string com; cin >> com;
        if(com == "hpush") {
            int x; cin >> x;
            q.hpush(x);
        }
        if(com == "hpop") {
            cout << q.hpop();
        }
        if(com == "hfront") {
            cout << q.hfront();
        }
        if(com == "hback") {
            cout << q.hback();
        }
        if(com == "hsize") {
            cout << q.hsize();
        }
        if(com == "vpush") {
            int x; cin >> x;
            q.vpush(x);
        }
        if(com == "vpop") {
            cout << q.vpop();
        }
        if(com == "vfront") {
            cout << q.vfront();
        }
        if(com == "vback") {
            cout << q.vback();
        }
        if(com == "vsize") {
            cout << q.vsize();
        }
        if(com == "size") {
            cout << q.size();
        }
        if(com == "empty") {
            cout << q.empty();
        }
        if(com == "middle") {
            cout << q.middle();
        }
        
        if(com != "vpush" && com != "hpush") cout << '\n';
        
        // q.printInfo();
        // cout << "------------------------" << '\n';
    }
    
    return 0;
}