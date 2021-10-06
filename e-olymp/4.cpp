#include <bits/stdc++.h>
using namespace std;

int main() {
    double x1, x2, y1, y2, r1, r2;
    double safe, cr, fr;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    safe = sqrt((x1 - x2) *(x1-x2) + (y1-y2) * (y1-y2));
    cr = r1+r2;
    fr = abs(r1-r2);
    if (safe == cr) {
        cout << "1";
    }
    else {
        if (safe > cr) {
            cout << "0";
        }
        else {
            if (safe == 0) {
                if (abs(r1-r2) < DBL_EPSILON){
                    cout << "-1";
                } else {
                    cout << "0";
                }
            }
            else {
                if ((0 < safe) && (safe < cr)) {
                    if (fr < safe) {
                        cout << "2";
                    }
                    else {
                        if (fr == safe) {
                            cout << "1";
                        }
                        else {
                            if (fr > safe) {
                                cout << "0";
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}