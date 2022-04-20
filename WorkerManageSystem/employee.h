#ifndef _EMPLOYEE_
#define _EMPLOYEE_

#include <iostream>
using namespace std;

#include "abstractWorker.h"
#include <string>

// 普通员工类
class Employee : public AbstractWorker
{
    public:
        // 构造函数
        Employee(int id, string name, int depId);

        virtual void showInfo();
        virtual string getDepName();
};

#endif