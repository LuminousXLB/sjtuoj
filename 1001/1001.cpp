#include <iostream>

using namespace std;

int main()
{
  int shengao, dengzi, total;
  cin >> shengao >> dengzi >> total;
  int height = shengao + dengzi;
  // cout << "Height" << height << endl;
  int apple, cnt = 0;
  for (int i = 0; i < total; i++)
  {
    cin >> apple;
    // cout << apple << '\t';
    if (apple <= height)
    {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
