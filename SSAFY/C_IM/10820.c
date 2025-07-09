#include <stdio.h>
#include <string.h>

int main() {
  char s[101];
  int a1, a2, a3, a4;
  int size;
  while (gets(s) != '\0') {
    size = strlen(s);
    a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    for (int b= 0; b < size; b++) {
      if (s[b] == 32) a4++;
      if (s[b] >= 47 && s[b] <= 58) a3++;
      if (s[b] >= 65 && s[b] <= 90) a2++;
      if (s[b] >= 97 && s[b] <= 122) a1++;
    }
    printf("%d %d %d %d\n", a1, a2, a3, a4);
  }
}