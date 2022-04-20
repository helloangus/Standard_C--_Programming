#ifndef _MANAGER_
#define _MANAGER_

#include <iostream>
using namespace std;

#include "abstractWorker.h"
#include <string>

// 经理类
class Manager : public AbstractWorker
{
    public:
        // 构造函数
        Manager(int id, string name, int depId);

        virtual void showInfo();
        virtual string getDepName();
};


#endif