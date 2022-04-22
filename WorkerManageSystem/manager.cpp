#include "manager.h"

Manager :: Manager(int id, string name, int depId) : AbstractWorker(id, name, depId)
{
    if (depId != 2)
    {
        throw "Wrong Department ID!";
        return;
    }
}

void Manager :: showInfo()
{
    cout << "员工编号：" << this->getId() << "\t";
    cout << "员工姓名：" << this->getName() << "\t";
    cout << "部门编号：" << this->getDepName() << "\t";
    cout << "岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager :: getDepName()
{
    return "经理";
}