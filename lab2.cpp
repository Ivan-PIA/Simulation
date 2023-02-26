#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <conio.h>
using namespace std;

struct c
{

    int x;
    int y;
};


int main(){

int i,j,k,c,N;


printf("Введите размер поля: ");

scanf("%d",&N);
char map[N][N];
//printf("Введите начальное положение ");



int look= 0, o=0, p=1 ;



    
for ( c=0; c<3;c++)    {
    p++;
    o++;

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    system("cls");
    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            look=0;
            for(k=0; k<1; k++){
                if(i==o & j == p){
                    look = 1 ; 
                     printf("0");
                }
                else look = 0;
                
                if (look == 0){
                    
                    printf("*");

                }
           
            }

        }
        printf("\n");
    }
    printf("\n");

}


}