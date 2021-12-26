#include <iostream>
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
	// int n; cin >> n;
    int l, r, k;     cin >> l >> r >> k;
    int ans = 0;
    for (int i = l / k + 3; i <= r; i += k){
        string s = to_string(i);
        int m = 0, n = s.length() - 1;
        bool ok = true;
        while (m < n){
            if (s[m] != s[n]){
                ok = false;
                break;
            }
            ++m;
            --n;

        }
        ans += ok;
    }
    cout << ans << endl;
}