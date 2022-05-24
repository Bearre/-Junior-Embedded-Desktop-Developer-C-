#include<iostream>
#include <math.h>


class Point
{
    int x = 0;
    int y = 0;
    
    public:
        Point() = default;
        Point(int a, int b): x(a), y(b) {}
        
        void set_coord(int a, int b)
        {
            x = a;
            y = b;
        }
        int get_x() { return x; }
        int get_y() { return y; }
};


class Manipulator
{
    double radius;
    Point position;

    public:
    Manipulator(double x, double y, double r)
    {
        radius = r;
        position.set_coord(x,y);
    }
	
    double get_x() { return position.get_x(); }
    double get_y() { return position.get_y(); }
    double get_radius() { return radius; }
};


double distance_between(Manipulator &a, Point &b)
{
    return std::pow(std::pow(b.get_x() - a.get_x(), 2) + std::pow(b.get_y() - a.get_y(), 2),0.5);
}


void what_manupulator_to_use(Manipulator manipulator1, Manipulator manipulator2, Point target)
{
    if((distance_between(manipulator1, target) < distance_between(manipulator2, target)) && distance_between(manipulator1, target) <= manipulator1.get_radius())
    {
        std::cout<<"manipulator_1"<<'\n';
    } 
    else if((distance_between(manipulator1, target) > distance_between(manipulator2, target)) && distance_between(manipulator2, target) <= manipulator2.get_radius()) 
    {
        std::cout<<"manipulator_2"<<'\n';
    } else {
        std::cout<<"Out of range"<<'\n';
    }
}


int main()
{
    // Manipulators
    Manipulator m1(1,3, 3);
    Manipulator m2(1,2, 3);
    
    // Target
    Point target(3,5);
    what_manupulator_to_use(m1,m2,target);
	
    return 0;
}
