#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <conio.h>
#include <time.h>
using namespace std;

#define N 1000

typedef struct Object
{
    int x;
    int y;
    int key;
    int **memory;

}object;




void randomazer(int sum_move, int sum_obj, int scale, object *mass_obj){
    int move;
    int cur = rand()%5;
    for(move=0; move < sum_move; move++){
        if (cur == 0){
            mass_obj->x=mass_obj->x;
            mass_obj->y=mass_obj->y;
        }
        else if (cur == 1 & mass_obj->y+scale>0)
            mass_obj->y+=scale;
        
        else if (cur == 2 & mass_obj->y-scale<1000)
            mass_obj->y-=scale;

        else if (cur == 3 & mass_obj->x+scale<1000)
            mass_obj->x+=scale;
            
        else if (cur == 4 & mass_obj->x-scale>0) 
            mass_obj->x-=scale;  

        mass_obj->memory[move][0]=mass_obj->x;
        mass_obj->memory[move][1]=mass_obj->y;
    
    } 
}




int main(){

    srand(time(NULL));

int i,j,mov,scale, sum_obj, sum_move, obj;

object *mass_obj;


cout << "Enter scale: ";
cin >> scale;

cout << "\nEnter amount object: ";
cin >> sum_obj;

cout << "\nEnter amount move: ";
cin >> sum_move;


mass_obj = (object*)malloc(sum_obj*sizeof(object)); 

randomazer(sum_move, sum_obj, scale, mass_obj);


int look = 0; 
//PAINT
cout << "sfjhkf" ;
for (mov = 0; mov < sum_move; mov++){

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
     system("cls");
    
    for(i = 0; i < N/scale; i++){
        for(j = 0; N < N/scale; j++){
            for(obj=0; obj < N/1000; obj++){
                if(i == mass_obj->x/scale && j == mass_obj->y/scale){
                    
                    cout << "@ ";
                }
                if(i != mass_obj->x/scale || j != mass_obj->y/scale){
                    cout << "* ";
                }
            }
        }
        cout << "\n";
    }
    cout << "\n";
}




}