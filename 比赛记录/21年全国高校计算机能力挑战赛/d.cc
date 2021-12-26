#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
using namespace std;
void ac();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef DDEBUG
        FILE *fp = freopen("./a.in", "r", stdin);       //测试用例所在路径
    #endif

    ac();

    #ifdef DDEBUG
        fclose(fp);
    #endif
}

void ac(){
    unordered_map<string, vector<string>> s;
    map<string, vector<string>> c;
    int N; cin >> N;
    N *= 2;
    string a, b, x, y;
    char t;
    for (int i = 0; i < N; ++ i){
        cin >> a >> t >> b >> x >> y;
        if (t == 'S'){
            s[a] = vector<string>{b, x, y};
        }else if (t == 'C'){
            c[b] = vector<string>{a, x, y};
        }
    }

    // for (auto it = c.begin(); it != c.end(); ++ it){
    //     cout << it->first << " " ;
    //     for (int i = 0; i < it->second.size(); ++ i){
    //        cout  << it->second[i] << " ";
    //     }
    //     cout << endl;
    // }
    for (auto p: c){
        long long xx = stoll(p.second[1]), yy = stoll(p.second[2]);
        long long u = stoll(s[p.second[0]][1]), v = stoll(s[p.second[0]][2]);

        double dis = sqrt((xx - u) * (xx - u) + (yy - v) * (yy - v));
        dis = (long long)((dis * 100) + 0.5) / 100.0;
        printf("%s %s %.2lf\n", p.first.c_str(), s[p.second[0]][0].c_str(), dis);
    }
}