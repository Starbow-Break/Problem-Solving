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

pii operator+ (pii a, pii b) {
    return {a.fi+b.fi, a.se+b.se};
}

//앨범
struct Album {
    string name;
    Album *parent; // 상위 앨범
    map<string, Album> child_album; // 자식 앨범, 키 값이 앨범의 이름
    set<string> pictures; //사진들
    
    Album(string album_name) {
        name = album_name;
        parent = NULL;
    }
    
    pii search() {
        pii ret = {1, pictures.size()};
        
        for(auto t = child_album.begin(); t != child_album.end(); t++) {
            ret = ret + t->se.search();
        }
        
        return ret;
    }
};

//프로그램
struct Program {
    Album *root; //루트 앨범
    Album *cursor; // 현재 앨범
    
    Program() {
        root = new Album("album");
        cursor = root;
    }
    
    //앨범 생성
    void make_album(string album_name) {
        //동일 이름을 가진 앨범이 있는지 확인
        auto t = cursor->child_album.find(album_name);
        
        //있으면 메시지 출력 후 종료
        if(t != cursor->child_album.end()) {
            cout << "duplicated album name" << '\n';
            return;
        }
        
        //없으면 생성
        pair<map<string, Album>::iterator, bool> ret 
            = cursor->child_album.insert({album_name, Album(album_name)});
        Album &ca = ret.fi->se;
        ca.parent = cursor;
    }
    
    //앨범 삭제
    pii remove_album(string s) {
        auto t = cursor->child_album.find(s);
        if(t == cursor->child_album.end()) return {0, 0};
        pii ret = t->se.search(); // 전체 앨범 수 계산
        cursor->child_album.erase(t); //앨범 삭제
        return ret;
    }
    
    //앨범 삭제
    pii remove_album(int v) {
        //없으면 {0, 0} 반환
        if(cursor->child_album.empty()) return {0, 0};
         
        pii ret = {0, 0};
        
        switch(v) {
            //사전순으로 가장 빠른 앨범 반환
            case -1:
                ret = remove_album(cursor->child_album.begin()->fi);
                break;
            //현재 앨범에 속해있는 모든 앨범 삭제
            case 0:
                while(!cursor->child_album.empty()) {
                    ret = ret + remove_album(cursor->child_album.begin()->fi);
                }
                break;
            //사전순으로 가장 늦은 앨범 삭제
            case 1:
                ret = remove_album(cursor->child_album.rbegin()->fi);
        }
        
        return ret;
    }
    
    //사진 삽입
    void insert_picture(string picture_name) {
        auto t = cursor->pictures.find(picture_name);
        if(t != cursor->pictures.end()) {
            cout << "duplicated photo name" << '\n';
            return;
        }
        cursor->pictures.insert(picture_name);
    }
    
    //사진 삭제
    int delete_picture(string s) {
        auto t = cursor->pictures.find(s);
        if(t == cursor->pictures.end()) return 0;
        cursor->pictures.erase(t);
        return 1;
    }
    
    //사진 삭제
    int delete_picture(int v) {
        if(cursor->pictures.empty()) return 0;
        
        int ret = 0;
        
        switch(v) {
            //사전순으로 가장 빠른 앨범 반환
            case -1:
                ret = delete_picture(*cursor->pictures.begin());
                break;
            //현재 앨범에 속해있는 모든 앨범 삭제
            case 0:
                ret = cursor->pictures.size();
                cursor->pictures.erase(cursor->pictures.begin(), cursor->pictures.end());
                break;
            //사전순으로 가장 늦은 앨범 삭제
            case 1:
                ret = delete_picture(*cursor->pictures.rbegin());
        }
        
        return ret;
    }
    
    //앨범 이동
    string change_album(string s) {
        string ret = "";
        
        //부모로 이동
        if(s == "..") {
            if(cursor->parent != NULL) {
                cursor = cursor->parent;
            }
        }
        //루트로 이동
        else if(s == "/") {
            cursor = root;
        }
        //속해 있는 앨범 중 s로 이동
        else {
            auto t = cursor->child_album.find(s);
            if(t != cursor->child_album.end()) {
                cursor = &(t->se);
            }
        }
        
        return cursor->name;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    Program p = Program();
    int N; cin >> N;
    while(N--) {
        string s, t; cin >> s >> t;
        if(s == "mkalb") {
            p.make_album(t);
        }
        if(s == "rmalb") {
            pii result;
            if(t[0] == '-' || ('0' <= t[0] && t[0] <= '9')) {
                result = p.remove_album(stoi(t));
            }
            else result = p.remove_album(t);
            cout << result.fi << ' ' << result.se << '\n';
        }
        if(s == "insert") {
            p.insert_picture(t);
        }
        if(s == "delete") {
            int result;
            if(t[0] == '-' || ('0' <= t[0] && t[0] <= '9')) {
                result = p.delete_picture(stoi(t));
            }
            else result = p.delete_picture(t);
            cout << result << '\n';
        }
        if(s == "ca") {
            string result = p.change_album(t);
            cout << result << '\n';
        }
    }
    
    return 0;
}