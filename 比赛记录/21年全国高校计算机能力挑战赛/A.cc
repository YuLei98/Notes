#include <iostream>
using namespace std;
int main(){
    #ifdef LOCALL
        FILE *fp = freopen("./a.in", "r", stdin);       //测试用例所在路径
    #endif
    int N;cin >>N;
    while (N--){
        int a, b, c;
        char x, y;
        cin >> a >> x >> b >> y >> c;
        if (x == '+'){
            if (y == '+'){
                cout << a + b + c << endl;
            }else if (y == '-'){
                cout << a + b - c << endl;
            }else if (y == '*'){
                cout << a + b * c << endl;
            }
        }else if (x == '-'){
            if (y == '+'){
                cout << a - b + c << endl;
            }else if (y == '-'){
                cout << a - b - c << endl;
            }else if (y == '*'){
                cout << a - b * c << endl;
            }
        }else if (x == '*'){
            if (y == '+'){
                cout << a * b + c << endl;
            }else if (y == '-'){
                cout << a * b - c << endl;
            }else if (y == '*'){
                cout << a * b * c << endl;
            }
        }
    }
    #ifdef LOCALL
        fclose(fp);
    #endif
    return 0;
}