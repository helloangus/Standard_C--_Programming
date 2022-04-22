#include "employee.h"

Employee :: Employee(int id, string name, int depId) : AbstractWorker(id, name, depId)
{
    if (depId != 1)
    {
        throw "Wrong Department ID!";
        return;
    }
}

void Employee :: showInfo()
{
    cout << "员工编号：" << this->getId() << "\t";
    cout << "员工姓名：" << this->getName() << "\t";
    cout << "岗位名称：" << this->getDepName() << "\t";
    cout << "岗位职责：完成经理交给的任务" << endl;
}

string Employee :: getDepName()
{
    return "员工";
}