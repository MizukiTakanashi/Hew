#pragma once
//=====================================
//�e�̃p�^�[��D
//����ҁF����đ�
//������F1/25
//=====================================
#include "BulletPattern.h"

class BulletPattern;
class  BulletPatternD :public BulletPattern
{
public:
	BulletPatternD();
	virtual ~BulletPatternD();
	virtual void Update(Boss* pBoss)override;
private:

};

