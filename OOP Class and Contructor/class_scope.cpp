#include<iostream>
using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;
    
    public:
        
        //Constructors
        Rectangle(){length = breadth = 1;}
        Rectangle(int l, int b);

        //Facilitators - Manipulate data
        int area();
        int perimeter();

        //Accessors - Getter functions
        int getLength(){ return length;}
        int getBreadth(){ return breadth;}

        //Mutators - Setter functions
        void setLength(int l) {length = l;}
        void setBreadth(int b) {breadth = b;}


        //Destructor
        ~Rectangle();

};

Rectangle::Rectangle(int l, int b){
    length = l;
    breadth = b;
}

int Rectangle::area(){
    return length*breadth;
}

int Rectangle::perimeter(){
    return 2*(length+breadth);
}

Rectangle::~Rectangle(){
    cout<<"Destructor"<<endl;
}

int main(){
    Rectangle r(10,5);

    cout<<"Area: "<<r.area()<<endl;
    cout<<"Perimeter: "<<r.perimeter()<<endl;

    r.setLength(20);

    cout<<"Updated Length: "<<r.getLength()<<endl;
}
