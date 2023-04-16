#include "simulation.h"


Coordinates::Coordinates(int x, int y){
            _x = x;
            _y = y;
        }
Coordinates::Coordinates(){
		_x = 0;
		_y = 0;
        }
void Coordinates::Set_Cord(int x, int y){
        _x = x;
        _y = y;
}
int Coordinates::GetX(){ 
    return _x;
}
int Coordinates:: GetY(){
    return _y;
    }
       


Object::Object(int id, int x, int y){
        Id = id;
        cord.Set_Cord(x,y);
}
Object::Object(){
        Id = 0;
        cord.Set_Cord(0,0);
}
void Object::memoryInit(int count_mov){
    memory = new Coordinates[count_mov];
}
int Object::memoryGet_X(int n){
    return memory[n].GetX();
}

int Object::memoryGet_Y(int n){
    return memory[n].GetY();
}
int Object::getId(){
    return Id;
}

void Object::setId(int id){
    Id = id;
}

void Object::setCord(int x, int y, int i){
    cord.Set_Cord(x,y);
    memory[i].Set_Cord(x,y);
}
int Object::GetX(){ 
    return cord.GetX();
}
int Object::GetY(){
    return cord.GetY();
}

void Object::move(int direct, int scale, int mov){
    if(direct == 0){ //На месте
        cord.Set_Cord(cord.GetX(), cord.GetY());
    }
    if(direct == 1){ //Вверх
        cord.Set_Cord(cord.GetX(), cord.GetY()+scale);
    }
    if(direct == 2){//Влево
        cord.Set_Cord(cord.GetX()-scale, cord.GetY());
    }
    if(direct == 3){//Вправо
        cord.Set_Cord(cord.GetX()+scale, cord.GetY());
    }
    if(direct == 4){//Вниз
        cord.Set_Cord(cord.GetX(), cord.GetY()-scale);
    }
    memory[mov] = cord;                                
}
int Object::lengthWay(int count_mov, int slace){
    return count_mov * slace;
}
        
       


void rando(Object *stek, int count_obj, int count_mov, int scale){ //рандомное перемещение
    int direct, i, obj;
    for(obj=0;obj<count_obj;obj++){
        for(i=1;i<count_mov;i++){
            direct = rand()%5;
            if(direct == 0){ //На месте
             stek[obj].move(0, scale, i);
            }
            if(direct == 1 && stek[obj].GetY()+ scale < SIZE/scale){
                stek[obj].move(1, scale, i);
            }
            if(direct == 2 && stek[obj].GetX() - scale > 0){
                stek[obj].move(2, scale, i);
            }
            if(direct == 3 && stek[obj].GetX() + scale < SIZE/scale){
                stek[obj].move(3, scale, i);
            }
             if(direct == 4 && stek[obj].GetY()- scale > 0){
                stek[obj].move(4, scale, i);
            }
            else stek[obj].move(0, scale, i);
        }
    }
}


int find(int id1, int id2, Object *stek, int count_obj, int count_mov, int scale){//найти расстояние
	int i, j,rast, a,b,d, x1,y1, x2,y2, way1,way2;
	
    for(i=0;i<count_obj;i++){
        if(id1 == stek[i].getId()){ 
			x1=stek[i].GetX();
			y1=stek[i].GetY();
			way1 = stek[i].lengthWay(count_mov, scale);
		}
        if(id2 == stek[i].getId()){
			x2=stek[i].GetX();
			y2=stek[i].GetY();
			way2 = stek[i].lengthWay(count_mov, scale);
		}
	}

    cout << "\nКоординаты 1 точки " << x1<<", "<< y1<<"";
	cout << "\nКоординаты 2 точки " << x2<<", "<< y2<<"";
	cout << "\nПройденное расстояние 1 точки: " <<way1<<"метров"<<endl;
	cout << "\nПройденное расстояние 2 точки:" <<way2<<"метров"<<endl;
	rast=sqrt(pow((x2-x1),2)+ pow((y2-y1),2));
	return rast;
}

void paint_2 (int count_obj, int mov, int scale, Object  *stek, int i, int j){
    int chek=0,objt;
        for(objt=0; objt < count_obj; objt++){
            if(i==((stek[objt].memoryGet_Y(mov))/scale) && j == ((stek[objt].memoryGet_X(mov))/scale)){ 
                cout << " "<< objt+1;
                chek=1;
            }
            else if ((i!=((stek[objt].memoryGet_Y(mov))/scale) || j != ((stek[objt].memoryGet_X(mov))/scale)) && (chek == 0)) {
                chek=0;
                if (i==0 || j==0 || i==SIZE/scale-1 || j==SIZE/scale-1){
                    chek=2;
                
            }
           
            }
        }

        if(chek==0) 
            cout << "  "; 
        if(chek==2)
            cout<< " +";
}

void paint (int scale, int mov, int count_obj, Object *stek ){
    	sleep(1); 
        system("cls");
        for(int i=0;i<(SIZE/scale);i++){
            for(int j=0;j<(SIZE/scale);j++){
		        paint_2(count_obj,mov,scale,stek,i,j); 
	    }
         cout <<"\n";
    	}
}


int  setting_id(int count_obj, Object *stek){
    //cout << count_obj;
    int id=0,chek;
    for(int i=0; i<count_obj; i++){
        id++;
        cout << "\nID объекта № " << i+1 << ": " << id;  
        chek = 0;
        for(int j=0; j < count_obj; j++){
             if(id == stek[j].getId())
             chek=1;
        }
        if(chek==0)
            stek[i].setId(id);
        else{
                i--;
        }
    }
    return 0;
}

int setting_coord(int count_obj, int scale, Object *stek){
    int chek;
    for(int i=0;i<count_obj;i++){
        int x = (rand()%(SIZE/scale))*scale;
        int y = (rand()%(SIZE/scale))*scale;
        for(int j=0;j<count_obj;j++){
            if(x!=stek[j].GetX() && y!=stek[j].GetY()){
                chek=1;
            }
            else{
                chek=0;
                continue;
            }
        }
        if(chek==1){
            stek[i].setCord(x,y,0); 
        }
        else i--;
    }
    return 0;
}

void interface_distance (Object *stek, int count_obj, int scale, int count_mov) {
    int choice = 0;

    int id_1,id_2, rasst;
	while(choice!=2){
        cout<< "\n\nРасстояние между точками?1-начало 2-конец : ";
		cin >> choice;
		if(choice == 1){
            cout << ("\nID 1точки: ");
			cin >> id_1;
			cout << ("\nID 2точки: ");
			cin >> id_2;
			rasst=find(id_1,id_2,stek,count_obj, count_mov,scale);
            cout << "\n\nРасстояние между точками равно: " << rasst << "метров" << endl;
		}
        else if(choice == 2) {
            cout << "\nПрограмма завершена";
            break;
        }
		else cout << "\nERROR\n";
	}
}

void choice_method(int choice, Object *stek, int count_obj, int scale, int count_mov){
    
    switch (choice)
    {
    case 1:
        rando(stek,count_obj, count_mov, scale);
        break;
    case 2:
        /////
    default:
        break;
    }
        

}
         