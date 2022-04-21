#include "employee.h"

Employee :: Employee(int id, string name, int depId) : AbstractWorker(id, name, depId)
{
    if (depId != 1)
    {
        throw "Wrong Department ID!";
        return;
    }
    
    cout << "子类调用父类构造函数" << endl;
}

void Employee :: showInfo()
{
    cout << "员工编号：" << this->getId() << "\t";
    cout << "员工姓名：" << this->getName() << "\t";
    cout << "部门编号：" << this->getDepName() << "\t";
    cout << "岗位职责：完成经理交给的任务" << endl;
}

string Employee :: getDepName()
{
    return "员工";
}