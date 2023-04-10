#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "math.h"
#include <unistd.h>
#include <vector>
using namespace std;

#define SIZE 1000

class Coordinates
{
    private:
        int _x;
        int _y;
    public:
        Coordinates(int x, int y);
        Coordinates();
        void Set_Cord(int x, int y);
        int GetX();
        int GetY();
        
};
class Object
{
    private:
        int Id;
        Coordinates cord;
        Coordinates *memory;
    public:
        Object(int id, int x, int y);
	    Object();
        void memoryInit(int count_mov);
        int memoryGet_X(int n);

        int memoryGet_Y(int n);
        int getId();
        void setId(int id);
        void setCord(int x, int y, int i);
        int GetX();
        int GetY();
        void move(int direct, int scale, int mov);
        int lengthWay(int count_mov, int slace);
        
       
};

void rando(Object *stek, int count_obj, int count_mov, int scale);

int find(int id1, int id2, Object *stek, int count_obj, int count_mov, int scale);

void paint_2 (int count_obj, int mov, int scale, Object  *stek, int i, int j);
void paint (int scale, int mov, int count_obj, Object *stek );
int  setting_id(int count_obj, Object *stek);

int setting_coord(int count_obj, int scale, Object *stek);

void interface_distance (Object *stek, int count_obj, int scale, int count_mov);

void choice_method(int choice, Object *stek, int count_obj, int scale, int count_mov);
    
