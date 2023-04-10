# Simulation

## Задачи : 
- движение объекта в консоли
- для реализации использовать class Object, class Coordinates.

## Object 

- поле  <Coordinates cord> - хранит текущие координаты через class Coordinates
- поле <int Id> - хранит id объекта 
- поле <Coordinates *memory> - хранить все координаты

## Coordinates

- поле <int _x> - координата Х
- поле <int _y> - координата Y 


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


