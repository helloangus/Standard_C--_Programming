#include <iostream>
using namespace std;

// 定义抽象饮品制作类
class AbstractMakeDrink
{
	public:
		// 构造函数
		AbstractMakeDrink()
		{
			cout << "抽象饮品制作类构造函数" << endl;
		}

		// 析构函数
		~AbstractMakeDrink()
		{ 
			cout << "抽象饮品制作类析构函数" << endl;
		}

		// 拷贝构造函数
		AbstractMakeDrink(const AbstractMakeDrink &d)
		{
			cout << "抽象饮品制作类拷贝构造函数" << endl;
		}


	public:
		// 纯虚函数
		virtual void boil() = 0;
		virtual void brew() = 0;
		virtual void pour() = 0;
		virtual void putSomething() = 0;

		// 确定制作流程
		void makeDrink()
		{
			boil();
			brew();
			pour();
			putSomething();
		}

};


// 定义冲咖啡类，公共继承抽象饮品制作类
class makeCoffee : public AbstractMakeDrink
{
	// 重写纯虚函数
	void boil()
	{
		cout << "煮纯净水" << endl;
	}

	void brew()
	{
		cout << "冲泡咖啡" << endl;
	}

	void pour()
	{
		cout << "咖啡倒入杯中" << endl;
	}

	void putSomething()
	{
		cout << "加入牛奶" << endl;
	}
};

// 定义冲茶叶类，公共继承抽象饮品制作类
class makeTea : public AbstractMakeDrink
{
	// 重写纯虚函数
	void boil()
	{
		cout << "煮白开水" << endl;
	}

	void brew()
	{
		cout << "冲泡茶叶" << endl;
	}

	void pour()
	{
		cout << "茶水倒入杯中" << endl;
	}

	void putSomething()
	{
		cout << "加入枸杞" << endl;
	}
};

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


// 定义主函数
int main()
{
	test01();

	return 0;
}