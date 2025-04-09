#pragma once
class DemoApp;
class action;
class colVec;
class gold;
class fish;
class bullet
{
public:
	bullet();
	bullet(DemoApp * app, action * scene, colVec  * colObj, sprite * bt, sprite * wang,  int hurt =1, float speed=8);
	~bullet();
	void changeType(string type);//�ı���ʾ״̬
	void moveForword();//��ǰ�ƶ�
	int frameFun(vector<fish *>*fishArr);//ÿһ֡����
	void isTest(vector<fish *>*fishArr);
	void bullet::createGold(fish * fs);
	void bullet::setX(float x);
	void bullet::setY(float y);
	bool bullet::inScreen();
	utils::useSpSt st1;//�ӵ��ṹһ
	utils::useSpSt st2;//��ṹ��
public:
	string bulletType = "bt";//�ӵ���ǰ��ʾ״̬
	sprite * view;//��ͼ����
	sprite * bt;//��̨����
	sprite * wang; //������
	int hurt = 0;
	int w_time = 20;
	float speed = 0;
	float angle = 0;
	void (*removeScene)(bullet * b);
	sprite * scInfo;
private:
	DemoApp * app;//��Ϸapp
	action * scene;//��Ϸ����
	colVec * colObj;//��Ϸ��ײ����
};

