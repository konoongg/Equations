#include <stdio.h>
int Del(int x,int free){
    if (x < 0 && free < 0){
        x*= -1;
        free *= -1;
    }
    if(x == 0 && free != 0){
        printf("NaN");
        return 0;
    }
    else if(x == 0 && free == 0){
        printf("Any");
        return 0;
    }
    else if(free%x == 0){
        printf("%d",free/x);
        return 0;
    }
    else{
        int m = x;
        if (m < 0){
            m = m*(-1);
        }
        int f = free;
        if (f < 0){
            f *= (-1);
        }
        if (m > f){
            m = f;
        }
        while(m > 0){
            if(free%m == 0 && x%m ==0){
                free/=m;
                x/=m;
                if (x<0){
                    x*=(-1);
                    free*=(-1);
                }
                printf("%d/%d",free,x);
                return 0;
            }
            m-=1;
        }
        printf("%d/%d",free,x);
        return 0;
        
    }
}
int main() {
    char c;
    int x = 0, free = 0;
    int isR = 0;
    int isX = 0;
    //int isN = 0;
    int ifX = 0;
    int isSign = 1;
    int countNumbers = 0;
    int sign = 0;
    int number = 0;
    int signLate = 0;
    while((c = getchar()) != EOF){
        //printf("%c %d \n",c,countNumbers);
        int sym = (int)c;
        if (sym == 45){
            ++sign;
        }
        //printf("%c %d \n",c,sign);
        if( (sym != 45) && (sym != 32) && (sym != 101) && (sym != 43) && (isSign == 1) ){
            isSign = 2;
        }
        else if ((sym == 45 || sym == 43 || sym == 61 ) && (isSign == 2) && (countNumbers != 0 || isX > 0)){
            if(sym == 45){
                --sign;
                ++signLate;
            }
            
            isSign = 3;
            
        }
        if (sym == 61 && isX == 0 && number ==0){
            sign = 0;
        } 
        //printf("%d %c %d \n",sign,c,isSign);
        if (sym>=48 && sym<=57 ){
            ++countNumbers;
            number*=10;
            number+= (sym-48);
        }
        else if( isSign == 3){
            int k = 1;
            if (sign %2 == 1){
                k = -1;
            }
            if(isX == 1){
                if(isR == 0){
                    x+=(number*k);
                }
                else{
                    x-=(number*k);
                }
            }
            else{
                if(isR == 1){
                    free+=(number*k);
                }
                else{
                    free-=(number*k);
                }
            }
            number = 0;
            isX = 0;
            sign = signLate;
            isSign = 1;
            signLate = 0;
            countNumbers = 0;
        }
        else if(sym == 120 ){
            isX = 1;
            ifX = 1;
            if (countNumbers == 0){
                ++number;
            }
        }
        
        if(sym == 61){
            isR = 1;
        }
               
    }
    // глупый повтор
    int k = 1;
    if (sign %2 == 1){
        k = -1;
    }
    if(isX == 1){
        x-=(number*k);    
    }
    else{
        free+=(number*k);
    }
    if (ifX == 0){
        printf("Not an equation");
        return 0;
    }
    Del(x,free);
    return 0;
}