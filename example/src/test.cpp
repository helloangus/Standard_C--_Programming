#include "drink.h"
#include <iostream>
using namespace std;


// 定义业务函数
void doWork(AbstractMakeDrink *drink)
{
	// 根据传入的饮品制作类开始制作
	drink->makeDrink();
	// 释放对应空间
	delete drink;
}

// 定义测试函数
void test01()
{
	doWork(new makeCoffee);
	cout << "-----------" << endl;
	doWork(new makeTea);
}