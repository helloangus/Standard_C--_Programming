#include <iostream>
#include "ABMS.h"
using namespace std;


// 显示菜单
void showMenu();
// 运行功能主程序
int run(AddressBooks* addressBooks);


int main(){

    AddressBooks* addressBooks = initAddressBooks();
    run(addressBooks);
    delete addressBooks;
    addressBooks = NULL;
    return 0;
}



//菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

//功能主程序
int run(AddressBooks* addressBooks)
{
    int choice = 0;

    while (true)
    {
        showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1: // 添加联系人
            addPerson(addressBooks);
            break;
        case 2: // 显示联系人
            showPerson(addressBooks);
            break;
        case 3: // 删除联系人
            deletePerson(addressBooks);
            break;
        case 4: // 查找联系人
            findPerson(addressBooks);
            break;
        case 5: // 修改联系人
            modifyPerson(addressBooks);
            break;
        case 6: // 清空联系人
            clearPerson(addressBooks);
            break;
        case 0: // 退出通讯录
            cout << "欢迎下次使用" << endl<<endl;
            return 0;
        default:
            cout << "输入错误，请重新输入" << endl;
            break;
        }   // end of switch
    }   // end of while
}