#ifndef DRINK
#define DRINK


// 定义抽象饮品制作类
class AbstractMakeDrink
{
	public:
		// 构造函数
		AbstractMakeDrink();

		// 析构函数
		~AbstractMakeDrink();

		// 拷贝构造函数
		AbstractMakeDrink(const AbstractMakeDrink &d);


	public:
		// 纯虚函数
		virtual void boil() = 0;
		virtual void brew() = 0;
		virtual void pour() = 0;
		virtual void putSomething() = 0;

		// 确定制作流程
		void makeDrink();

};

class makeCoffee : public AbstractMakeDrink
{
    public: 
        // 重写纯虚函数
        void boil();
        void brew();
        void pour();
        void putSomething();
};
// 定义冲茶叶类，公共继承抽象饮品制作类
class makeTea : public AbstractMakeDrink
{
    public: 
        // 重写纯虚函数
        void boil();
        void brew();
        void pour();
        void putSomething();
};

#endif