// AbstractBaseClass.cpp : 
#include <iostream>
using namespace std;

class Vehicle
{
    int speed;//скорость
public:
    virtual void move() = 0;//чисто виртуальный метод.
    //Именно этот метод и делает класс абстрактным.
};
class GroundVehicle : private Vehicle {};//Абстрактный класс без реализации
class Car :public GroundVehicle
{
public:
    void move()
    {
        cout << " Машина едет на 4-х колесах" << endl;
    }
};
class Bike :public GroundVehicle
{
public:
    void move()
    {
        cout << " Мотоцикл едет на 2-х колесах" << endl;
    }
};
class WaterVehicle:public Vehicle {};
class Boat:WaterVehicle{};
class Speedboat :public Boat
{
public:
    void move()
    {
        cout << " Катер без паруса" << endl;
    }
};
class Yacht :public Boat
{
public:
    void move()
    {
        cout << " Яхта с парусами" << endl;
    }
};

class AirVehicle:Vehicle{};
class Airplane :AirVehicle
{
public:
    void move()
    {
        cout << " У самолета два крыла" << endl;
    }
};
class  Vertalet:AirVehicle
{
public:
    void move()
    {
    cout << " У вертолета большой пропеллер" << endl;
    
    }
};


int main()
{
    setlocale(LC_ALL, "");
    //Vehicle v;//Abstract
    //GroundVehicle gv;// Abstract
    Car bmw;
    bmw.move();
    Bike harley_devidson;
    harley_devidson.move();
    Speedboat passenger_boat;
    passenger_boat.move();
    Yacht category_d;
    category_d.move();
    Airplane airobus;
    airobus.move();
    Vertalet the_acula;
    the_acula.move();



}

