#include "../include/define.h"
#include "personStruct.h"

// 初始化通讯录
AddressBooks* initAddressBooks();
// 添加联系人
void addPerson(AddressBooks* addressBooks);
// 显示联系人
void showPerson(AddressBooks* addressBooks);
// 删除联系人
void deletePerson(AddressBooks* addressBooks);
// 查找联系人
void findPerson(AddressBooks* addressBooks);
// 修改联系人
void modifyPerson(AddressBooks* addressBooks);
// 清空联系人
void clearPerson(AddressBooks* addressBooks);