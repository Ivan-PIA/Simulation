#include "simulation.h"

int main(){
    
    srand(time(NULL));
    int i,j,objt,x,y, chek=0, count_obj, count_mov, id, scale, choice, mov;
     cout << "\nВведите масштаб : ";
    cin >> scale;
    cout << "\nВведите количество объектов: ";
    cin >> count_obj;
    cout << "\nВведите количество движений: ";
    cin >> count_mov;



    Object *stek = new Object[count_obj]; //выделение памяти для массива
     
     for(i=0;i<count_obj;i++){
         stek[i].memoryInit(count_mov);
    }

    setting_id(count_obj,stek);
   
    setting_coord(count_obj, scale, stek);
    

    cout << "\n---------------------------- " <<endl; 
    system("pause");

    choice_method(1,stek,count_obj,scale,count_mov);

    for(mov=0; mov < count_mov; mov++){
		  paint(scale,mov, count_obj, stek);
    }

    interface_distance(stek,count_obj,scale,count_mov);
	
    delete[] stek;

}