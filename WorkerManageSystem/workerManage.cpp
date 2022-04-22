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


int WorkerManage :: getEmpNum()
{
    return this->m_EmpNum;
}


void WorkerManage :: showEmp()
{
    cout << "现有全部职工如下：" << endl;
    EmpNode *p = this->m_EmpListHead;
    while (p->next != NULL)
    {
        cout << "职工编号：" << p->next->m_Emp->getId() << "\t"
        << "职工姓名：" << p->next->m_Emp->getName() << "\t"
        << "职工岗位：" << p->next->m_Emp->getDepName() << endl;
        p = p->next;
    }
}


void WorkerManage :: addEmp()
{
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
            int id;
            string name;
            int depId;
            
            while (true)
            {
                cout << "请输入第 " << i+1 << " 个新职工编号：" << endl;
                cin >> id;
                if (this->idFind(id) == INVALID_ID)
                {
                    cout << "职工编号不合法，请重新输入" << endl;
                    // 考虑cin的内容若为字符型，无法存入id，则需要重置缓冲区
                    cin.clear();
                    cin.ignore();
                }
                else if(this->idFind(id) == VALID_ID)
                {
                    cout << "职工编号已存在，请重新输入" << endl;
                    cin.clear();
                    cin.ignore();
                }
                else if(this->idFind(id) == EMPTY_ID)
                {
                    break;
                }
            }

            cout << "请输入第 " << i+1 << " 个新职工姓名：" << endl;
            cin >> name;

            while (true)
            {
                cout << "请输入第 " << i+1 << " 个新职工岗位：" << endl;
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
            
            EmpNode *p = new EmpNode;
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


int WorkerManage :: idFind(int id)
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
            if(p->next->m_Emp->getId() == id)
            {
                return VALID_ID;
            }
            p = p->next;
        }
        return EMPTY_ID;
    }
}


// 重载根据ID返回职工节点
int WorkerManage :: idFind(int id, EmpNode *q)
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
            if(p->m_Emp->getId() == id)
            {
                q = p;
                return VALID_ID;
            }
            p = p->next;
        }
        return EMPTY_ID;
    }
}