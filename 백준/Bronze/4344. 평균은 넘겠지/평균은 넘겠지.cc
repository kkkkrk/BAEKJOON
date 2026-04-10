#include <stdio.h>
#include <stdlib.h>
int main() {
   int num=0;
   int* grade = (int*)calloc(1001, sizeof(int));
   float* average = (float*)calloc(1001, sizeof(float));
   scanf("%d", &num);
   for (int i = 0; i < num; i++) {
      int k = 0;
      int count = 0;
      int sum=0;
      int person=0;
      int temp;
      do {
         if (k == 0) {
            scanf("%d", &count);
            temp = count;
            k++;
         }
         else {
            scanf("%d", &grade[k - 1]);
            k++;
         }
         count--; 
      } while (count >= 0);
      for (int j = 0; j<temp; j++) {
         sum += grade[j];
      }
      float aVerage=((float)sum / (float)temp);
      for(int p=0;p<temp;p++){
      if(aVerage<grade[p]){
         person++;
         }
      }
      average[i] = ((float)person/(float)temp*100);
   }
   
   for (int i = 0; i < num; i++) {
      printf("%.3f%%\n", average[i]);
   }
   return 0;
}