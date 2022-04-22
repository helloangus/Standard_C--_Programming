#include "employee.h"
#include "manager.h"
#include "boss.h"

// 三种职工类的创建测试
int test()
{
    try
    {
        Employee *epe = new Employee(2, "angus", 1);    
        epe->showInfo();
        epe->getDepName();
        delete epe;
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }

    try
    {
        Manager *mag = new Manager(3, "angus", 2);    
        mag->showInfo();
        mag->getDepName();
        delete mag;
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }

    try
    {
        Boss *boss = new Boss(4, "angus", 3);    
        boss->showInfo();
        boss->getDepName();
        delete boss;
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }
    
    return 0;
}