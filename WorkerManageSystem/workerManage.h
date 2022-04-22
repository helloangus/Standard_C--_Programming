#ifndef _WORKERMANAGE_
#define _WORKERMANAGE_

#include <iostream>
using namespace std;

#include "abstractWorker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILE_NAME "empFile.txt"
#define INVALID_ID -1
#define EMPTY_ID 0
#define VALID_ID 1

typedef struct EmpNode
{
    AbstractWorker * m_Emp;
    struct EmpNode * next;
}EmpNode;


class WorkerManage
{
    private:
        bool m_FileIsEmpty;
        int m_EmpNum;
        EmpNode * m_EmpListHead;

    public:
        WorkerManage();
        ~WorkerManage();

        void showMenu();
        void addEmp();
        void showEmp();
        void deleteEmp();
        void modEmp();
        void findEmp();
        void sortEmp();
        void cleanEmp();

        void save();
        void read();
        void release(); // 释放创建的堆区链表节点

        int getEmpNum();
        void modEmpNode(EmpNode *p);
        int empFind(int id);  // 根据输入职工ID查找链表，返回ID存在状态，可根据需要通过修改来返回找到的节点指针
        int empFind(int id, EmpNode **S_pre);   // 重载函数，根据输入职工ID查找链表，通过修改返回找到节点的前一个节点指针
        int empFind(string name, EmpNode **S_pre); // 重载函数，根据输入职工的名字查找链表，通过修改返回找到节点的前一个节点指针
};



#endif