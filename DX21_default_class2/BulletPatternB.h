#pragma once
//=====================================
//�e�̃p�^�[��B
//����ҁF����đ�
//������F1/25
//=====================================
#include "BulletPattern.h"

class BulletPattern;
class  BulletPatternB :public BulletPattern
{
public:
	BulletPatternB();
	virtual ~BulletPatternB();
	virtual void Update(Boss* pBoss)override;
private:

};

