#pragma once
//=====================================
//�e�̃p�^�[��C
//����ҁF����đ�
//������F1/25
//=====================================
#include "BulletPattern.h"

class BulletPattern;
class  BulletPatternC :public BulletPattern
{
public:
	BulletPatternC();
	virtual ~BulletPatternC();
	virtual void Update(Boss* pBoss)override;
private:

};

