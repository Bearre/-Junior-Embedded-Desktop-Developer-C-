#include<iostream>


class Coords
{
    double x = 0;
    double y = 0;
    double z = 0;
    
    public:
        Coords();
        Coords(double a, double b, double c): x(a), y(b), z(c) {}
        Coords& operator+=(Coords c2)
        {
            x = c2.get_x();
            y = c2.get_y();
            z = c2.get_z();
            return *this;
        }
        
        double get_x() noexcept { return x; }
        double get_y() noexcept { return y; }
        double get_z() noexcept { return z; }
};

void GO(Coords& start, int x, int y, int z)
{
    start = Coords(start.get_x() + x, start.get_y() + y, start.get_z() + z);
}


int main()
{
    Coords start(10, 20, 0);
    GO(start, 10, 20, 30);
    GO(start, 40, -20, 20);
    GO(start, -10, -20, -10);
    std::cout<<'('<<start.get_x()<<';'<<start.get_y()<<';'<<start.get_z()<<')'<<'\n';
    return 0;
}
