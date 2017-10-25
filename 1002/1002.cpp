// Description
// 二哥在自己的后花园里种了一些花生，也快到了收获的时候了。这片花生地是一个长度为L、宽度为W的矩形，每个单位面积上花生产量都是独立的。他想知道，对于某个指定的区域大小，在这么大的矩形区域内，花生的产量最大会是多少。
//
// Input Format
// 第1行有2个整数，长度L和宽度W。
// 第2行至第L+1行，每行有W个整数，分别表示对应的单位面积上的花生产量A（ 0≤A<100≤A<10 ）。
// 第L+2行有2个整数，分别是指定的区域大小的长度a和宽度b。
#include <iostream>
using namespace std;

int main() {
  int l, w;
  cin >> l >> w;
  // int **area = new int*[l];
  int area[1001][1001];
  for (int i = 0; i < l; i++) {
    // area[i] = new int[w];
    for (int j = 0; j < w; j++) {
      cin >> area[i][j];
      // cout << area[i][j];
      // cout << "\n Data " << i << ' ' << j << "Complete" << endl;
    }
    // cout << "\n Line" << i << "Complete" << endl;
  }
  int a, b;
  int cnt, res = 0;
  cin >> a >> b;
  // cout << a << b << endl;

  for (int si = 0; si < l - a + 1; si++) {
    for (int sj = 0; sj < w - b + 1; sj++) {
      cnt = 0;
      for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
          cnt += area[si + i][sj + j];
        }
      }
      // cout << "si" << si << "\tsj" << sj << "\tcnt" << cnt << endl;
      if (res < cnt) {
        res = cnt;
      }
    }
  }
  cout << res;
  // for (int i = 0; i < l; i++) {
    // delete [] area[i];
  // }
  // delete [] area;
  return 0;
}

// Output Format
// 输出一个整数m，表示在指定大小的区域内，花生最大产量为m。
//
// Sample Input
/*
4 5
1 2 3 4 5
6 7 8 0 0
0 9 2 2 3
3 0 0 0 1
3 3
*/
// Sample Output
// 38
// 样例解释
// 左上角：38 = (1+2+3) + (6+7+8) + (0+9+2)
//
// 数据范围
// 对于30%的数据： 1≤L,W≤1001≤L,W≤100；
// 对于100%的数据： 1≤L,W≤10001≤L,W≤1000。
// 全部区域大小满足：1≤a≤L，1≤b≤W1≤a≤L，1≤b≤W 。

// int main(int argc, char const *argv[]) {
//   int l, w;
//   cin >> l >> w;
//   int **area = new int*[l];
//   for (int i = 0; i < l; i++) {
//     area[i] = new int[w];
//     for (int j = 0; j < w; j++) {
//       cin >> area[i][j];
//     }
//   }
//   int a, b;
//   int cnt, res = 0;
//   cin >> a >> b;
//   for (int si = 0; si < l - a; si++) {
//     for (int sj = 0; sj < w - b; sj++) {
//       cnt = 0;
//       for (int i = si; i < a; i++) {
//         for (int j = sj; j < b; j++) {
//           cnt += area[i][j];
//         }
//       }
//       if (res < cnt) {
//         res = cnt;
//       }
//     }
//   }
//   cout << res;
//   for (int i = 0; i < l; i++) {
//     delete [] area[i];
//   }
//   delete [] area;
//   return 0;
// }
