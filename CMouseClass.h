#ifndef __CMouseClass_h__
#define __CMouseClass_h__

#include <Windows.h>
#include <thread>
#include <random>

class CMouseClass {


public:

	//�R���X�g���N�^
	CMouseClass();
	//�f�X�g���N�^
	~CMouseClass();

	void Movement(int, int)const throw();
	void AutoMovement(bool)const throw();
	void Thread(bool)const throw();

private:


};


#endif