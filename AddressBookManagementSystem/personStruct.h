#include <string>
#include "../include/define.h"
using namespace std;

// 联系人结构体
struct Person
{
    string Name;
    int Sex;
    int Age;
};

// 通讯录结构体
struct AddressBooks
{
    struct Person personArray[MAX];
    int Size;
};
