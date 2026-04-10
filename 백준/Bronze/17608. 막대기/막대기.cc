#include <stdio.h>
int stick[100010];

int main()
{
    int N, index = 0;
    for(int i = 1;i < 100009;i++){
        stick[i] = -1;
    }
    stick[0] = 100001;
    
    scanf("%d", &N);
    
    for(int i = 1;i <= N;i++){
        int a;
        scanf("%d", &a);
        if(stick[index] > a){
            stick[index + 1] = a;
            index += 1;
        }
        else{
            while(1){
                stick[index] = -1;
                index -= 1;
                if(stick[index] > a){
                    stick[index + 1] = a;
                    index += 1;
                    break;
                }
            }
        }
        
    }
    
    int result = 0;
    for(int i = 1;i < 100009;i++){
        if(stick[i] == -1){
            break;
        }
        else{
            result += 1;
        }
    }
    printf("%d", result);
    

    return 0;
}
