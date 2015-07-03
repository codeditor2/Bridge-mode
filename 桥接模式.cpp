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
        cout << "��װWindow����ϵͳ\n" << endl;
    }
};

class LinuxOS : public OS
{
public:
    void NameOS()
    {
        cout <<  "��װLinux����ϵͳ\n" << endl;
    }
};

class UnixOS : public OS
{
public:
    void NameOS()
    {
        cout << "��װUnix����ϵͳ\n" << endl;
    }
};

class Computer
{
public:
    Computer(OS *osptr) : m_osPtr(osptr) {}

    virtual void InstallOs() = 0;
    
protected:
    OS *m_osPtr;
};

class DellComputer : public Computer
{
public:
    DellComputer(OS *osptr) : Computer(osptr) {}

    void InstallOs()
    {
        cout << "Dell Computer" << endl;
        m_osPtr->NameOS();
    }
};

class LenovoComputer : public Computer
{
public:
    LenovoComputer(OS *osptr) : Computer(osptr){}
    
    void InstallOs()
    {
        cout << "Lenovo Computer" << endl;
        m_osPtr->NameOS();
    }
};

int main()
{
    DellComputer * DellPtr1 = new DellComputer(new WindowOS);
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
