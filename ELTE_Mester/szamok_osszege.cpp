// https://github.com/lezsakdomi/elte-mester-data/blob/master/Sz%C3%A1melm%C3%A9leti%20algoritmusok/Sz%C3%A1mok%20%C3%B6sszege/feladat.pdf
// Two pointers technika

#include <iostream>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  int s[n];
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  for (int i_1 = 0; i_1 < n; ++i_1) {
    int x_rem = x - s[i_1];
    int i_2 = i_1 + 1;
    int i_3 = n - 1;
    while (true) {
      if (i_2 >= i_3) { // Ha átlépték egymást a pointerek akkor nincs találat
        break;
      }
      int sum = s[i_2] + s[i_3];
      if (sum == x_rem) { // Találat
        cout << s[i_1] << " " << s[i_2] << " " << s[i_3] << endl;
        goto finish; // Kiírjuk, megállunk
      }
      if (sum < x_rem) { // Ha túl kevés az összeg bal pointert növeljük
        i_2 += 1;
      } else {
        i_3 -= 1; // Ha túl sok az összeg jobb pointert csökkentjük
      }
    }
  }
  cout << "-1" << endl;
  finish:
    return 0;
}
