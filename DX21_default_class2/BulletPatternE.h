#pragma once
//=====================================
//�e�̃p�^�[��E
//����ҁF����đ�
//������F1/25
//=====================================
#include "BulletPattern.h"

class BulletPattern;
class  BulletPatternE :public BulletPattern
{
public:
	BulletPatternE();
	virtual ~BulletPatternE();
	virtual void Update(Boss* pBoss)override;
private:

};

