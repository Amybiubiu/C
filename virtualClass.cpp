#include <iostream>
using namespace std;

class Automobile    //∆˚≥µ¿‡
{
private:
    int power;  //¬Ì¡¶
public:
    Automobile(int power){
        this->power = power;
        cout<<"Automobile constructing..."<<endl;
    }
    void show(){
        cout<<" power:"<<power;
    }
};
class Car: virtual public Automobile    //–°øÕ≥µ¿‡
{
private:
    int seat;
public:
    Car(int power,int seat):Automobile(power){
        this->seat = seat;
        cout<<"car constructor ..."<<endl;
    }
    void show(){
        cout<<"car:";
        Automobile::show();
        cout<<" seat:"<<seat<<endl;
    }
};
class Wagon: virtual public Automobile{
private:
    int load;
public:
    Wagon(int power,int load):Automobile(power){
        this->load = load;
        cout<<"Wagon constructor..."<<endl;
    }
    void show(){
        cout<<"Wagon:";
        Automobile::show();
        cout<<"load: "<<load<<endl;
    }
};
class StationWagon:public Car,public Wagon{
public:
    StationWagon(int Cpower,int Wpower,int seat,int load):Automobile(Cpower),Wagon(Wpower,load),Car(Cpower,seat){
        cout<<"stationWagon constructor..."<<endl;
    }
    void show(){
        cout<<"StationWagon.."<<endl;
        Car::show();
        Wagon::show();
    }
};
int main(){
    int x;
    cin>>x;
    StationWagon SW(105,108,3,8);
    SW.show();
    return 0;
}
