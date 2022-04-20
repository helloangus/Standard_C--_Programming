#ifndef _BOSS_
#define _BOSS_

#include <iostream>
using namespace std;

#include "abstractWorker.h"
#include <string>


// 老板类
class Boss : public AbstractWorker
{
    public:
        // 构造函数
        Boss(int id, string name, int depId);

        virtual void showInfo();
        virtual string getDepName();
};

#endif