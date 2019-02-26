#include <stdio.h>
int arr[10];
int main() {
   int i, n, cnt;
   scanf("%d", &n);

   do{
      arr[n % 10]++;
      n /= 10;
   }while (n);
   cnt = (arr[9] + arr[6] + 1) / 2;
   for (i = 0; i < 9; i++) {
      if (i != 9 && i != 6) {
         if (arr[i] > cnt) {
            cnt = arr[i];
         }
      }
   }
   printf("%d", cnt);
   return 0;
}
