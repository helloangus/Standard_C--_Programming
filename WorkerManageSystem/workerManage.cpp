#include "workerManage.h"


WorkerManage:: WorkerManage(/* args */)
{
}

WorkerManage:: ~WorkerManage()
{
}

void WorkerManage:: showMenu()
{
    // 循环执行
    while(true)
    {   
        cout << "********************" << endl;
        cout << "*欢迎使用职工管理系统*" << endl;
        cout << "** 0.退出管理系统 ***" << endl;
        cout << "** 1.增加职工信息 ***" << endl;
        cout << "** 2.显示所有职工 ***" << endl;
        cout << "** 3.删除指定职工 ***" << endl;
        cout << "** 4.修改职工信息 ***" << endl;
        cout << "** 5.查找职工信息 ***" << endl;
        cout << "** 6.按照编号排序 ***" << endl;
        cout << "** 7.清空所有信息 ***" << endl;
        cout << "********************" << endl;

        cout << "请输入您的选择：" << endl;

        int input = 0;
        cin >> input;
        // 管理系统实现功能：
        switch (input)
        {
            // 0、退出管理程序
            case 0: 
                cout << "退出系统，欢迎下次使用" << endl;
                return;
            // 1、增加职工信息
            case 1:
                break;
            // 2、显示所有职工
            case 2:
                break;
            // 3、删除指定职工
            case 3:
                break;
            // 4、修改职工信息
            case 4:
                break;
            // 5、查找职工信息
            case 5:
                break;
            // 6、按编号排序
            case 6:
                break;
            // 7、清空所有职工信息
            case 7:
                break;
            
            default:
                cout << "输入错误，请重新输入" << endl;
                break;
        }
    }
}