#include <iostream>
#include "drink.h"
using namespace std;


// 构造函数
AbstractMakeDrink :: AbstractMakeDrink()
{
	cout << "抽象饮品制作类构造函数" << endl;
}

// 析构函数
AbstractMakeDrink :: ~AbstractMakeDrink()
{ 
	cout << "抽象饮品制作类析构函数" << endl;
}

// 拷贝构造函数
AbstractMakeDrink :: AbstractMakeDrink(const AbstractMakeDrink &d)
{
	cout << "抽象饮品制作类拷贝构造函数" << endl;
}


// 确定制作流程
void AbstractMakeDrink :: makeDrink()
{
	boil();
	brew();
	pour();
	putSomething();
}



// 重写纯虚函数
void makeCoffee :: boil()
{
	cout << "煮纯净水" << endl;
}

void makeCoffee :: brew()
{
	cout << "冲泡咖啡" << endl;
}

void makeCoffee :: pour()
{
	cout << "咖啡倒入杯中" << endl;
}

void makeCoffee :: putSomething()
{
	cout << "加入牛奶" << endl;
}


void makeTea :: boil()
{
	cout << "煮白开水" << endl;
}

void makeTea :: brew()
{
	cout << "冲泡茶叶" << endl;
}

void makeTea :: pour()
{
	cout << "茶水倒入杯中" << endl;
}

void makeTea :: putSomething()
{
	cout << "加入枸杞" << endl;
}

