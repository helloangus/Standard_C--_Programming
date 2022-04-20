#include "boss.h"

Boss :: Boss(int id, string name, int depId) : AbstractWorker(id, name, depId)
{
    if (depId != 3)
    {
        throw "Wrong Department ID!";
        return;
    }
    
    cout << "子类调用父类构造函数" << endl;
}

void Boss :: showInfo()
{
    cout << "员工编号：" << getId() << "\t";
    cout << "员工姓名：" << getName() << "\t";
    cout << "部门编号：" << getDepName() << "\t";
    cout << "岗位职责：管理公司所有事务" << endl;
}

string Boss :: getDepName()
{
    return "老板";
}