#include "personStruct.h"
#include <iostream>
using namespace std;


AddressBooks* initAddressBooks()
{
    AddressBooks* addressBooks = new AddressBooks;  // malloc对于带string的结构体不友好，需要使用new
    addressBooks->Size = 0;
    return addressBooks;
}

// 添加联系人
void addPerson(AddressBooks* addressBooks)
{
    if(addressBooks->Size == MAX)
    {
        cout << "通讯录已满，无法添加联系人" << endl;
        return;
    }
    else {
        // 输入姓名
        cout << "请输入姓名：";
        cin >> addressBooks->personArray[addressBooks->Size].Name;

        // 输入性别
        cout << "请输入性别(1 -- 男，2 -- 女)：";
        int sex;
        while (true)
        {
            cin >> sex;
            if(sex == 1 || sex == 2)
            {
                addressBooks->personArray[addressBooks->Size].Sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入" << endl;
            }
        }
        
        // 输入年龄
        cout << "请输入年龄：";
        cin >> addressBooks->personArray[addressBooks->Size].Age;

        // 更新联系人数量
        addressBooks->Size++;

        cout << "添加成功" << endl;

            
    }
}

// 显示联系人
void showPerson(AddressBooks* addressBooks)
{
    if(addressBooks->Size == 0)
    {
        cout << "通讯录为空，无法显示联系人" << endl;
        return;
    }
    else
    {
        for(int i = 0; i < addressBooks->Size; i++)
        {
            cout << "姓名：" << addressBooks->personArray[i].Name << "\t";
            cout << "性别：" << (addressBooks->personArray[i].Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << addressBooks->personArray[i].Age << endl;
        }
    }
}

// 删除联系人
int deletePerson(AddressBooks* addressBooks)
{   
    cout << "请输入要删除的联系人姓名：";
    string name;
    cin >> name;
    for (size_t i = 0; i < addressBooks->Size; i++)
    {
        if (addressBooks->personArray[i].Name == name)
        {
            for (size_t j = i; j < addressBooks->Size - 1; j++)
            {
                addressBooks->personArray[j] = addressBooks->personArray[j + 1];
            }
            addressBooks->Size--;
            cout << "删除成功" << endl;
            return 0;
        }
        else
        {
        }
    }
    cout << "删除失败，该联系人不存在" << endl;
    return -1;
}

// 查找联系人
int findPerson(AddressBooks* addressBooks)
{
    cout << "请输入要查找的联系人姓名：";
    string name;
    cin >> name;
    for (size_t i = 0; i < addressBooks->Size; i++)
    {
        if (addressBooks->personArray[i].Name == name)
        {
            cout << "姓名：" << addressBooks->personArray[i].Name << "\t";
            cout << "性别：" << (addressBooks->personArray[i].Sex == 1 ? "男" : "女" ) << "\t";
            cout << "年龄：" << addressBooks->personArray[i].Age << endl;
            return 0;
        }
        else
        {
        }
    }
    cout << "查无此人！" << endl;
    return -1;
}

// 修改联系人
int modifyPerson(AddressBooks* addressBooks)
{
    cout << "请输入要修改的联系人姓名：";
    string name;
    cin >> name;
    for (size_t i = 0; i < addressBooks->Size; i++)
    {
        if (addressBooks->personArray[i].Name == name)
        {
            cout << "请输入新的姓名：";
            cin >> addressBooks->personArray[i].Name;
            
            cout << "请输入新的性别（1 -- 男，2 -- 女）：";
            int sex = 0;
            while (true)
            {
                cin >> sex;
                if (sex == 1 || sex == 2)
                {
                    addressBooks->personArray[i].Sex = sex;
                    break;
                }
                else
                {
                    cout << "输入有误，请重新输入" << endl;
                }
                
            }
            
            cout << "请输入新的年龄：";
            cin >> addressBooks->personArray[i].Age;
            cout << "修改成功" << endl;
            return 0;
        }
        else
        {
        }
    }
    cout << "查无此人" << endl;
    return -1;
}

// 清空联系人
void clearPerson(AddressBooks* addressBooks)
{
    addressBooks->Size = 0;
    cout << "清空成功" << endl;
}