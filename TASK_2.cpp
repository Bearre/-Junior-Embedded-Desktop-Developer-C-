#include<iostream>
#include <math.h>
#include <vector>


class Point
{
    double x = 0;
    double y = 0;
    
    public:
        Point() = default;
        Point(double a, double b): x(a), y(b) {}
        
        void set_coord(double a, double b) noexcept
        {
            x = a;
            y = b;
        }
        double get_x() noexcept { return x; }
        double get_y() noexcept { return y; }
};


class Manipulator
{
    double radius = 0;
    Point position = Point(0,0);
    
    public:
    Manipulator() = default;
    Manipulator(Point p, double r)
    {
        radius = r;
        position = p;
    }
    
    double get_x() noexcept { return position.get_x(); }
    double get_y() noexcept { return position.get_y(); }
    double get_radius() noexcept { return radius; }
};


double find_distance_between(Manipulator &a, Point &b)
{
    // Модуль вектора построенного из 2 точек
    return std::pow(std::pow(b.get_x() - a.get_x(), 2) + std::pow(b.get_y() - a.get_y(), 2), 0.5);
}


void find_optimal_way(Manipulator& m1, Manipulator& m2, std::vector<Point>& vec)
{
    for(int i = 0; i < 5; ++i)
    {
        std::cout<<"Iteration:"<<i<<'\n';
        if(find_distance_between(m1, vec[i]) < find_distance_between(m2, vec[i]))
        {
            std::cout<<'('<<vec[i].get_x()<<';'<<vec[i].get_y()<<')'<<' '<<"using"<<' ';
            std::cout<<"Manipulator 1"<<'\n';
        } else {
            std::cout<<'('<<vec[i].get_x()<<' '<<vec[i].get_y()<<')'<<' '<<"using"<<' ';
            std::cout<<"Manipulator 2"<<'\n';
        }
    }
}


int main()
{
    // Manipulators
    Manipulator m1(Point(0,0), 4);
    Manipulator m2(Point(2,1), 3);
	
	// Координаты деталей
    std::vector<Point> vec_test = {Point(1,3), Point(2,1.41), Point(0.2,-7), Point(-5,-1), Point(0,9)};
    find_optimal_way(m1, m2, vec_test);
    return 0;
}
