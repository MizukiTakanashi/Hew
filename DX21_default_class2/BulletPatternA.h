#pragma once
//=====================================
//�e�̃p�^�[��A
//����ҁF����đ�
//������F1/25
//=====================================
#include "BulletPattern.h"

class BulletPattern;
class  BulletPatternA:public BulletPattern
{
public:
	 BulletPatternA();
	virtual ~ BulletPatternA();
	virtual void Update(Boss* pBoss)override;
private:

};

