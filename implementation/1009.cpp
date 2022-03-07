// 분산처리

#include <iostream>

using namespace std;

int T, a, b;

int squared_last_num(int squared_num) {
    int result = 1;
    while (squared_num--) {
        result = (result * a) % 10;
    }

    return result;
}

void print_last_data() {
    if (a % 10 == 0) {
        cout << 10 << '\n';
        return;
    }

    int cycle_num = 1, next_num = (a * a) % 10;

    while (next_num != a % 10) {
        cycle_num += 1;
        next_num = (next_num * a) % 10;
    }

    if (cycle_num == 1) {
        cout << a % 10 << '\n';
    }
    else {
        int temp = b % cycle_num;

        if (temp == 0) {
            temp = cycle_num;
        }

        cout << squared_last_num(temp) << '\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    
    while (T--) {
        cin >> a >> b;

        print_last_data();
    }
}
