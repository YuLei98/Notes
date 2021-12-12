#include <iostream>
#include <vector>
using namespace std;
int main(){
    #ifdef LOCALL
        FILE *fp = freopen("./a.in", "r", stdin);       //测试用例所在路径
    #endif
    
    //题目：将s中出现的第三个s1替换成s2

    int k; 
    string s1, s2, s;
    cin >> k >> s1 >> s2;
    getchar();                     //吸收第一行行尾的换行符
    getline(cin, s);
    int n = s.size(), m = s1.size();
    vector<int> next(m);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && s1[i] != s1[j]) {
            j = next[j - 1];
        }
        if (s1[i] == s1[j]) {
            j++;
        }
        next[i] = j;
    }

    int findcnt = 0, ansidx = -1;
    for (int _ = 0; _ < n;){     //起始位置
        int idx = -1;
        for (int i = _, j = 0; i < n; ++ i){
            while (j > 0 && s[i] != s1[j]){
                j = next[j - 1];
            }
            if (s[i] == s1[j]){
                j++;
            }
            if (j == m){
                idx = i - m + 1;
                break;
            }
        }
        if (idx == -1){
            break;
        }
        _ = idx + 1;
        if (++findcnt == k){
            ansidx = idx;
            break;
        }
    }
    if (findcnt != k){
        cout << "F" << endl;
    }else{
        cout << s.substr(0, ansidx) + s2 + s.substr(ansidx + m) << endl;
    }

    #ifdef LOCALL
        fclose(fp);
    #endif
    return 0;
}