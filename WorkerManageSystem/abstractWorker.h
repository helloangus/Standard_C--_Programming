#ifndef _WORKER_
#define _WORKER_

#include <iostream>
using namespace std;
#include <string>

// 抽象职工类
class AbstractWorker
{
    public:
        // 构造函数
        AbstractWorker(int id, string name, int depId);

        virtual void showInfo() = 0;
        virtual string getDepName() = 0;

        int getId();
        string getName();
        int getDepId();

    private:
        // 职工编号
        int m_Id;
        // 职工姓名
        string m_Name;
        // 职工岗位
        int m_DepId;
};


#endif