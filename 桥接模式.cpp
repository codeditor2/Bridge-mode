#include <iostream>
#include <cstdlib>
using namespace std;

class OS
{
public:
    virtual void NameOS() = 0; 
};

class WindowOS : public OS
{
public:
    void NameOS()
    {
        cout << "安装Window操作系统\n" << endl;
    }
};

class LinuxOS : public OS
{
public:
    void NameOS()
    {
        cout <<  "安装Linux操作系统\n" << endl;
    }
};

class UnixOS : public OS
{
public:
    void NameOS()
    {
        cout << "安装Unix操作系统\n" << endl;
    }
};

class Computer
{
public:
    Computer(OS *osptr) : m_osPtr(osptr) {}

    virtual void InstallOs() = 0;
    
protected:
    OS *m_osPtr;	// 包含有一个OS对象的指针，这是关键之一 
};

class DellComputer : public Computer
{
public:
    DellComputer(OS *osptr) : Computer(osptr) {}

    void InstallOs()
    {
        cout << "Dell Computer" << endl;
        m_osPtr->NameOS();	// 使用基类指针调用具体的方法，利用C++多态实现Bridge模式，这是关键之二 
    }
};

class LenovoComputer : public Computer
{
public:
    LenovoComputer(OS *osptr) : Computer(osptr){}
    
    void InstallOs()
    {
        cout << "Lenovo Computer" << endl;
        m_osPtr->NameOS();	// 多态 
    }
};

int main()
{
	// 这是Bridge模式的优势所在  
    DellComputer * DellPtr1 = new DellComputer(new WindowOS);	// 客户端代码中，可以将Computer类和OS类进行任意组合
    DellPtr1->InstallOs();

    DellComputer * DellPtr2 = new DellComputer(new LinuxOS);
    DellPtr2->InstallOs();

    LenovoComputer *LenovoPtr1 = new LenovoComputer(new WindowOS);
    LenovoPtr1->InstallOs();

    LenovoComputer *LenovoPtr2 = new LenovoComputer(new LinuxOS);
    LenovoPtr2->InstallOs();

    system("pause");

    return 0;
}
