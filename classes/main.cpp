#include <iostream>
#include <string>

using namespace std;


class Box {
    // public can be accessed everywhere within program's scope
    public:
        double length;
        double breadth;
        double height;
        
        double GetLength(void);
        double GetBreadth(void);
        double GetHeight(void);

        double GetVolume(void) {
            return length * breadth * height;
        }

    // private can only be accessed within parent class
    private:
        int _number;
        string _name;

    // protected can be access by derived classes
    protected:
        double width;

};

// class function defined outside the class, using scope resolution operator ::
double Box::GetLength(void) {
    return length;
};

double Box::GetBreadth(void) {
    return breadth;
};

double Box:: GetHeight(void) {
    return height;
};

// create a derived class
class SmallBox : public Box {
    public:
        void SetSmallLength(double length);
        double GetSmallLength(void);
};

// member functions of a child class
double SmallBox::GetSmallLength(void) {
    return length;
};

void SmallBox::SetSmallLength(double length1) {
    length = length1;
};


int main() {

    Box box1;
    Box box2;
    SmallBox box3;

    double volume = 0.0;

    box1.height = 5.0;
    box1.length = 6.0;
    box1.breadth = 7.0;

    box2.height = 10.0;
    box2.length = 12.0;
    box2.breadth = 13.0;

    cout << "Box1 Height: " << box1.GetHeight() << 
            " | Breadth: " << box1.GetBreadth() << 
            " | Length: " << box1.GetLength() << endl;
    volume = box1.GetVolume();
    cout << "Volume of Box 1: " << volume << endl;

    cout << "Box2 Height: " << box2.GetHeight() << 
            " | Breadth: " << box2.GetBreadth() << 
            " | Length: " << box2.GetLength() << endl;
    volume = box2.GetVolume();
    cout << "Volume of Box 2: " << volume << endl;

    box3.SetSmallLength(5.0);
    cout << "Length of a Small Box 3: " << box3.GetSmallLength() << endl;

    return 0;
}