#include<iostream>
#include<string>
using namespace std;
class CPU
{  public:
	virtual void calculation() = 0;
};
class  video
{public:
	virtual void display() = 0;
};
class  memary
{ public:
	virtual void mem() = 0;
};
class computer
{
public:
	computer(CPU* cpu, video* video, memary* memary)
	{
		m_cpu = cpu;
		m_video = video;
		m_memary = memary;
	}
	void work()
	{
		m_cpu->calculation();
		m_video->display();
		m_memary->mem();
	}
private:

	CPU* m_cpu;
	video* m_video;
	memary* m_memary;
};
class intelcpu:public CPU
{
	virtual void calculation()
	{
		cout << "intelcpu开始计算了";
	}
};
class intelvideo:public video
{
	virtual void display()
	{
		cout << " intelvideo开始显示了";
	}

};
class intelmemary:public memary
{
	virtual void mem()
	{
		cout << " intelmemary开始储存了";
	}
};
class lencpu :public CPU
{
	virtual void calculation()
	{
		cout << "lencpu开始计算了";
	}
};
class lenvideo :public video
{
	virtual void display()
	{
		cout << " lenvideo开始显示了";
	}
};
class lenmemary :public memary
{
	virtual void mem()
	{
		cout << " lenmemary开始储存了";
	}
};
int main()
{
	CPU* m_intelcpu= new intelcpu;
	video* m_intelvideo = new intelvideo;
	memary* m_intelmemary = new intelmemary;
	CPU* m_lencpu = new lencpu;
	video* m_lenvideo = new lenvideo;
	memary* m_lenmemary = new lenmemary;

	computer* computer1=new computer(m_intelcpu, m_intelvideo, m_intelmemary);
	computer* computer2 = new computer(m_lencpu, m_lenvideo, m_intelmemary);

	computer1->work();
	computer2->work();
}