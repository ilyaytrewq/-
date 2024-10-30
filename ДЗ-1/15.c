#include <stdio.h>

int CrossProduct(int x1, int y1, int x2, int y2) { return x1 * y2 - x2 * y1; }

int sgn(int x) {
  if (x == 0) return 0;
  return (x < 0 ? -1 : 1);
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  int x1, y1, x2, y2;
  int pos = 0, neg = 0;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  int xf = x1, xs = x2, yf = y1, ys = y2;
  for (int i = 2; i < n; ++i) {
    int x3, y3;
    scanf("%d %d", &x3, &y3);
    int cur = sgn(CrossProduct(x1 - x2, y1 - y2, x3 - x2, y3 - y2));
    if (cur == 1) {
      pos++;
    } else if (cur == -1) {
      neg++;
    }
    if (i == n - 1) {
      int s = sgn(CrossProduct(x2 - x3, y2 - y3, xf - x3, yf - y3));
      if (s == 1) {
        pos++;
      } else if (s == -1) {
        neg++;
      }
    }
    x1 = x2;
    y1 = y2;
    x2 = x3;
    y2 = y3;
  }
  int s = sgn(CrossProduct(x2 - xf, y2 - yf, xs - xf, ys - yf));
  if (s == 1) {
    pos++;
  } else if (s == -1) {
    neg++;
  }
  if (pos > 0 && neg > 0) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }
  return 0;
}
