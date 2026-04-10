#include <stdio.h>

int main(){
    int a, b;
    
    //printf("enter 2 num : \n");
    scanf("%d %d", &a, &b);
    
    if(a > b)
    {
        printf(">");
    }
    
    else if(a < b)
    {
        printf("<");
    }
    
    else
    {
        
        printf("==");
    }
    
    return 0;
}