#include "CMouseClass.h"

CMouseClass::CMouseClass()
{
}

CMouseClass::~CMouseClass()
{

}

void CMouseClass::Movement(int x, int y) const throw()
{
	SetCursorPos(x, y);
}

void CMouseClass::AutoMovement(bool loop) const throw()
{
	std::thread th(&CMouseClass::Thread,this,loop);
	th.join();
}

void CMouseClass::Thread(bool loop)const throw()
{

	POINT pos;

	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand(1, 4);

	GetCursorPos(&pos);
	while (loop) 
	{
		switch (rand(mt))
		{
		case 1:
			this->Movement(pos.x--,pos.y);
			break;
		case 2:
			this->Movement(pos.x++, pos.y);
			break;
		case 3:
			this->Movement(pos.x, pos.y--);
			break;
		case 4:
			this->Movement(pos.x, pos.y++);
			break;
		}

		Sleep(100);
	}
	
}

