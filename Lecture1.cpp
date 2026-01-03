// Jb multiple DSA ke concept ke around hm ek application ko build krte h, that is System Design
// Abstraction hides any un necessary details and only shows the necessary ones

#include<iostream>
#include<string>

using namespace std;

// Yeh sirf ek interface h
// Yeh ek abstract class h
class Car {
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual ~Car() {} 
};

class sportsCar : public Car {
private:
    string brand;
    string model;
    int curSpeed;
    int curGear;
    bool isEngineOn;
public:
    sportsCar(string a, string b){
        this -> brand = a;
        this -> model = b;
        isEngineOn = false;
        curGear = 0;
        curSpeed = 0;
        return;
    }

    string getModel(){
        return model;
    }
    string getBrand(){
        return brand;
    }

    int getCurSpeed(){
        return curSpeed;
    }

    void setCurSpeed(int val){
        this -> curSpeed = val;
    }

    void startEngine() {
        if(isEngineOn){
            cout << "Car is already on" << endl;
            return;
        }
        this -> isEngineOn = true;
        cout << "Car is now on" << endl;
    }

    void shiftGear(int gear) {
        this -> curGear = gear;
        cout << "New gear now is -> " << curGear << endl; 
    }
};

int main() {

    // yeh nhi chlega, kyuki interfaces classes ka usually kaam hota h ki vo bs as a way rhe communicate krne ka
    // aur neeche ki implementation details chod de
    // Car* c = new sportsCar("Renault", "Triber");

    // yeh chl jaega
    sportsCar* c = new sportsCar("Renault", "Triber");
    cout << "Name: " << c -> getModel() << endl;
    cout << "Brand: " << c -> getBrand() << endl; 
    c -> startEngine();
    c -> startEngine();

    int currentSpeed = c -> getCurSpeed();
    cout << "CurrentSpeed is : " << currentSpeed << endl;
    return 0;
}