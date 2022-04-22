#include "workerManage.h"


WorkerManage :: WorkerManage()
{
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);

    // 文件不存在的情况
    if(!ifs.is_open())
    {
        cout << "首次使用，数据存储文件不存在" << endl;
        this->m_FileIsEmpty = true;
        this->m_EmpNum = 0;
        this->m_EmpListHead = new EmpNode;
        this->m_EmpListHead->m_Emp = NULL;
        this->m_EmpListHead->next = NULL;
        ifs.close();
        return;
    }
    
    // 文件为空的情况
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "数据存储文件已被清空" << endl;
        this->m_FileIsEmpty = true;
        this->m_EmpNum = 0;
        this->m_EmpListHead = new EmpNode;
        this->m_EmpListHead->m_Emp = NULL;
        this->m_EmpListHead->next = NULL;
        ifs.close();
        return;
    }

    // 文件中有数据
    this->read();
    cout << "现有职工数为： " << this->getEmpNum() << endl;


}

WorkerManage :: ~WorkerManage()
{
    this->release();
}

void WorkerManage :: showMenu()
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
                this->addEmp();
                break;
            // 2、显示所有职工
            case 2:
                this->showEmp();
                break;
            // 3、删除指定职工
            case 3:
                this->deleteEmp();
                break;
            // 4、修改职工信息
            case 4:
                this->modEmp();
                break;
            // 5、查找职工信息
            case 5:
                this->findEmp();
                break;
            // 6、按编号排序
            case 6:
                this->sortEmp();
                break;
            // 7、清空所有职工信息
            case 7:
                this->cleanEmp();
                break;
            
            default:
                cout << "输入错误，请重新输入" << endl;
                break;
        }
        cout << endl;
    }
}


int WorkerManage :: getEmpNum()
{
    return this->m_EmpNum;
}


void WorkerManage :: showEmp()
{
    cout << endl;
    if(this->m_FileIsEmpty)
    {
        cout << "记录为空" << endl;
    }
    else
    {
        cout << "现有全部职工如下：" << endl;
        EmpNode *p = this->m_EmpListHead;
        while (p->next != NULL)
        {
            p->next->m_Emp->showInfo();
            p = p->next;
        }
    }
}


void WorkerManage :: modEmpNode(EmpNode * p)
{
    int id;
    string name;
    int depId;
    
    while (true)
    {
        cout << "请输入职工编号：" << endl;
        cin >> id;
        if (this->empFind(id) == INVALID_ID)
        {
            cout << "职工编号不合法，请重新输入" << endl;
            // 考虑cin的内容若为字符型，无法存入id，则需要重置缓冲区
            cin.clear();
            cin.ignore();
        }
        else if(this->empFind(id) == VALID_ID)
        {
            cout << "职工编号已存在，请重新输入" << endl;
            cin.clear();
            cin.ignore();
        }
        else if(this->empFind(id) == EMPTY_ID)
        {
            break;
        }
    }

    cout << "请输入职工姓名：" << endl;
    cin >> name;

    while (true)
    {
        cout << "请输入职工岗位：" << endl;
        cout << "1、普通员工" << endl;
        cout << "2、经理" << endl;
        cout << "3、老板" << endl;

        cin >> depId;
        if (depId == 1 || depId == 2 || depId == 3)
        {
            break;
        }
        else
        {
            cout << "输入岗位不合法，请重新输入" <<endl;
            cin.clear();
            cin.ignore();
        }
    }
    
    switch (depId)
    {
    case 1:
        p->m_Emp = new Employee(id, name, depId);
        break;
    case 2:
        p->m_Emp = new Manager(id, name, depId);
        break;
    case 3:
        p->m_Emp = new Boss(id, name, depId);
        break;

    default:
        break;
    }
}

void WorkerManage :: addEmp()
{
    cout << endl;
    cout << "输入需要增加的职工数量：" << endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum <= 0)
    {
        cout << "输入数量有误" << endl;
    }
    else
    {
        for (size_t i = 0; i < addNum; i++)
        {
            cout << "录入第 " << i+1 << " 个新职工信息" << endl;
            EmpNode* p = new EmpNode;
            this->modEmpNode(p);
            // 用头插法接入链表
            p->next = this->m_EmpListHead->next;
            this->m_EmpListHead->next = p;
        }
        this->m_EmpNum += addNum;
        this->m_FileIsEmpty = false;
        // 写入文件
        this->save();
        cout << "成功添加 " << addNum << " 个新职工" << endl;
    }
}

void WorkerManage :: save()
{
    // 创建文件输出流
    ofstream ofs;
    ofs.open(FILE_NAME, ios :: out);

    // 将内存中的m_EmpList保存到文件中
    EmpNode *p = this->m_EmpListHead;
    while (p->next != NULL)
    {
        ofs << p->next->m_Emp->getId() << " "
            << p->next->m_Emp->getName() << " "
            << p->next->m_Emp->getDepId() << endl;
        p = p->next;
    }
    ofs.close();
}

void WorkerManage :: read()
{
    // 创建文件输入流
    ifstream ifs;
    ifs.open(FILE_NAME, ios :: in);


    // 读取文件中的内容到m_EmpList中
    // 要保证接入链表的顺序和文件中的数据顺序一致，这里采用尾插法读取
    int id;
    string name;
    int depId;
    int empCount = 0;

    this->m_EmpListHead = new EmpNode;
    this->m_EmpListHead->m_Emp = NULL;
    this->m_EmpListHead->next = NULL;
    EmpNode * p = this->m_EmpListHead;  // 尾指针
    while(ifs >> id && ifs >> name && ifs >> depId)
    {
        EmpNode *q = new EmpNode;
        q->next = NULL;
        switch (depId)
        {
        case 1:
            q->m_Emp = new Employee(id, name, depId);
            break;
        case 2:
            q->m_Emp = new Manager(id, name, depId);
            break;
        case 3:
            q->m_Emp = new Boss(id, name, depId);
            break;

        default:
            break;
        }
        p->next = q;
        p = p->next;
        empCount++;
    }
    this->m_EmpNum = empCount;
    this->m_FileIsEmpty = false;

    // 关闭文件
    ifs.close();
}


void WorkerManage :: release()
{
    EmpNode *q = this->m_EmpListHead->next;
    while(q != NULL)
    {
        this->m_EmpListHead->next = q->next;
        delete q;
        q = this->m_EmpListHead->next;
    }
    this->m_EmpNum = 0;
}


int WorkerManage :: empFind(int id)
{
    if(id <= 0)
    {
        return INVALID_ID;
    }
    else
    {
        EmpNode *p = this->m_EmpListHead;
        while (p->next != NULL)
        {
            if(p->next->m_Emp != NULL && p->next->m_Emp->getId() == id)
            {
                return VALID_ID;
            }
            p = p->next;
        }
        return EMPTY_ID;
    }
}


// 重载根据ID返回职工节点的前一个节点
int WorkerManage :: empFind(int id, EmpNode **S_pre)
{
    if(id <= 0)
    {
        *S_pre = NULL;
        return INVALID_ID;
    }
    else
    {
        EmpNode *p = this->m_EmpListHead;
        while (p->next != NULL)
        {
            if(p->next->m_Emp != NULL && p->next->m_Emp->getId() == id)
            {
                *S_pre = p;
                return VALID_ID;
            }
            p = p->next;
        }
        *S_pre = NULL;
        return EMPTY_ID;
    }
}

// 重载根据名字返回职工节点的前一个节点
int WorkerManage :: empFind(string name, EmpNode **S_pre)
{
    EmpNode *p = this->m_EmpListHead;
    while (p->next != NULL)
    {
        if(p->next->m_Emp != NULL && p->next->m_Emp->getName() == name)
        {
            *S_pre = p;
            return VALID_ID;
        }
        p = p->next;
    }
    *S_pre = NULL;
    return EMPTY_ID;
}

void WorkerManage :: deleteEmp()
{
    cout << endl;
    if(this->m_FileIsEmpty)
    {
        cout << "记录为空" << endl;
    }
    else
    {
        cout << "请输入需要删除的职工编号：" << endl;
        int id;
        cin >> id;
        // 创建节点二级指针
        EmpNode *pre = NULL;
        EmpNode **S_pre = &pre;
        // 调用可以返回节点的empFind函数
        // 若找到，则删除*pre->next节点
        if( empFind(id, S_pre) == VALID_ID)
        {
            EmpNode *q = pre->next;
            pre->next = q->next;
            delete q;
            this->save();
            cout << "删除成功" << endl;
            return;
        }
        // 否则给出提示
        else
        {
            cout << "输入职工编号不合法，或对应职工不存在" << endl;
            return;
        }
    }
}


void WorkerManage :: modEmp()
{
    cout << endl;
    if(this->m_FileIsEmpty)
    {
        cout << "记录为空" << endl;
    }
    else
    {
        // 提示输入要修改的职工id
        cout << "请输入需要修改的职工编号： " << endl;
        // 接收职工id
        int id;
        cin >> id;
        // 创建一级指针
        EmpNode *pre = NULL;
        // 创建二级指针并指向对应一级指针
        EmpNode **S_pre = &pre;
        // 调用通过职工id返回对应职工节点的前一个节点的empFind函数
        if(empFind(id, S_pre) == VALID_ID)
        {
            // 把节点原来的信息释放掉
            delete pre->next->m_Emp;
            pre->next->m_Emp = NULL;
            // 传入对应的职工节点，调用modEmpNode函数修改节点信息
            cout << "请输入新的职工信息：" << endl;
            this->modEmpNode(pre->next);
            // 提示修改成功
            cout << "修改成功" << endl;
            // 保存到文件
            this->save();
            return;
        }
        // 若没找到，给出提示
        else
        {
            cout << "输入职工编号不合法，或对应职工不存在" << endl;
            return;
        }
    }
}


void WorkerManage :: findEmp()
{
    cout << endl;
    if(this->m_FileIsEmpty)
    {
        cout << "记录为空" << endl;
    }
    else
    {
        // 提示通过职工编号查找还是通过姓名查找
        cout << "请选择查找方式：" << endl;
        cout << "1、通过职工编号查找" << endl;
        cout << "2、通过职工姓名查找" << endl;
        // 创建对应一级、二级指针
        EmpNode *pre = NULL;
        EmpNode **S_pre = &pre;
        // 若通过编号查找
        int choice;
        cin >> choice;
        if(choice == 1)
        {
            cout << "请输入职工编号：" << endl;
            int id;
            cin >> id;
            // 调用对应重载empFind
            if(empFind(id, S_pre) == VALID_ID)
            {
                // 显示职工信息
                pre->next->m_Emp->showInfo();
                return;
            }
            else
            {
                cout << "输入职工编号非法，或对应职工不存在" << endl;
                return;
            }
            
        }
        // 若通过姓名查找
        else if(choice == 2)
        {
            cout << "请输入职工姓名：" << endl;
            string name;
            cin >> name;
            // 调用对应重载empFind
            if(empFind(name, S_pre) == VALID_ID)
            {
                // 显示职工信息
                pre->next->m_Emp->showInfo();
                return;
            }
            else
            {
                cout << "对应职工不存在" << endl;
                return;
            }
            return;
        }
        else
        {
            cout << "查找方式错误" << endl;
            return;
        }
    }
}

void WorkerManage :: sortEmp()
{
    cout << endl;
    if(this->m_FileIsEmpty)
    {
        cout << "记录为空" << endl;
    }
    else
    {
        // TODO
    }
}

void WorkerManage :: cleanEmp()
{
    cout << endl;
    // 提示确认是否清空
    cout << "是否确认清空全部记录？" << endl;
    cout << "1、确认清空" << endl;
    cout << "2、取消操作" << endl;
    int choice;
    cin >> choice;
    // 若确认
    if(choice == 1)
    {
        // 以覆盖方式重新创建文件并关闭
        ofstream ofs;
        ofs.open(FILE_NAME, ios::trunc);
        ofs.close();
        // 释放链表空间
        this->release();
        // m_FileIsEmpty为真
        this->m_FileIsEmpty = true;
        // 给出成功提示
        cout << "清空成功" << endl;
        return;
    }
    else
    {
        // 否则给出提示
        cout << "取消操作" << endl;
        return;
    }
}
