#include<iostream>
using namespace std;


const float PI = 3.14;
struct Circle{
    float centerX;
    float centerY;
    float radius;
    
    float calculateArea(Circle c){
       float area = PI * (c.radius * c.radius);
        
        return area;
    }
    void growCircle(Circle &c, float growthFactor){
        c.radius = c.radius * growthFactor;
    }
    void translateCircle(Circle &c, float x, float y) {
        c.centerX = c.centerX + x;
        c.centerY = c.centerY + y;
    }
};
int main(){
    Circle c;
    cout<<"Enter centre X: ";
    cin >> c.centerX;
    cout << "Enter Canter Y: ";
    cin>> c.centerY;
    cout<<" Enter radius: ";
    cin>>c.radius;
    
    if(c.radius <= 0){
        cout << "Invalid! Radius must be greater than 0."<< endl;
        return 1;
    }
    
    cout << "\n--- Original Circle ---" << endl;
    cout << "Center : (" << c.centerX << ", " << c.centerY << ")" << endl;
    cout << "Radius : " << c.radius << endl;
    cout << "Area   : " << c.calculateArea(c) << endl;

//Calculate Area
    cout << "\n--- After calculateArea ---" << endl;
    cout << "Area   : " << c.calculateArea(c) << endl;

//Grow Circle
    float growthFactor;
    cout << "\nEnter growth factor: ";
    cin >> growthFactor;
    c.growCircle(c, growthFactor);
    cout << "--- After growCircle ---" << endl;
    cout << "New Radius : " << c.radius << endl;
    cout << "New Area   : " << c.calculateArea(c) << endl;

//Translate Circle
    float x, y;
    cout << "\nEnter X offset: ";
    cin >> x;
    cout << "Enter Y offset: ";
    cin >> y;
    c.translateCircle(c, x, y);
    cout << "--- After translateCircle ---" << endl;
    cout << "New Center : (" << c.centerX << ", " << c.centerY << ")" << endl;

    return 0;
}
