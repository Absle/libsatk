#include "ecs/Ecs.hpp"

#include <iostream>
#include <vector>

struct pos
{
    int x;
    int y;
};

class move
{
    public:
    move() : dx(0), dy(0) {} 
    move(int _dx, int _dy) : dx(_dx), dy(_dy) {}
    int dx;
    int dy;

    int do_something();
};
int move::do_something()
{
    return 5;
}

int main()
{
    std::cout << "Starting Ecs.test.cpp..." << '\n';
    Satk::Ecs ecs;
    Satk::uid id0 = ecs.create();
    Satk::uid id1 = ecs.create();
    ecs.add<pos>(id0); 
    pos &p0 = Satk::internal::Component_Manager::Component<pos>::store.at(id0);
    std::cout << p0.x << ", " << p0.y << '\n';
    ecs.add<pos>(id1, 5, 6);
    pos &p1 = Satk::internal::Component_Manager::Component<pos>::store.at(id1);
    std::cout << p1.x << ", " << p1.y << '\n';
    p1.x += 1;
    p1.y += 1;
    std::cout << p1.x << ", " << p1.y << '\n';
    pos &p1a = Satk::internal::Component_Manager::Component<pos>::store.at(id1);
    std::cout << p1a.x << ", " << p1a.y << '\n';

    ecs.add<move>(id1, 4, 3);
    move &m0 = Satk::internal::Component_Manager::Component<move>::store.at(id1);
    std::cout << m0.dx << ", " << m0.dy << '\n';
    std::cout << m0.do_something() << '\n';

    std::cout << Satk::internal::Component_Manager::Component<move>::name << '\n';

    std::vector<int> vec;
    vec.reserve(5);
    std::cout << "test vec size: " << vec.size() << '\n';

    return 0;
}