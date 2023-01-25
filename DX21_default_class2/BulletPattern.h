#pragma once
//=====================================
//�e�̃p�^�[����{
//����ҁF����đ�
//������F1/25
//=====================================
class Boss;

class BulletPattern
{
public:
	virtual ~BulletPattern() {}
	virtual void Update(Boss* pBoss) = 0;
};

class BulletPatternNull :public BulletPattern
{
	virtual void Update(Boss* pBoss)override {}
};