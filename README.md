# Simulation

## Задачи : 
- движение объекта в консоли
- для реализации использовать class Object, class Coordinates.

## Object 

- поле  ```shCoordinates cord``` - хранит текущие координаты через class Coordinates
- поле ```shint Id``` - хранит id объекта 
- поле ```shCoordinates *memory``` - хранить все координаты

## Coordinates

- поле ```shint _x``` - координата Х
- поле ```shint _y``` - координата Y 


## Windows vs Linux

- программы на данный момент настроена на среду Windows, для Linux требуется изменить одну строчку кода:

Файл simulation.cpp

```sh
162: system("cls");
```
Изменить на:

```sh
162: system("clear");
```

## Компиляция программы

```sh
g++ main.cpp simulation.cpp -o pro
./pro
```

## Работа программы 

Интерфейс:

[![Build Status](https://github.com/Ivan-PIA/Simulation/blob/main/1-path.png)]


Вывод движущихся объектов и нахождения расстояния между ними:

[![Build Status](https://github.com/Ivan-PIA/Simulation/blob/main/2-path.png)]


