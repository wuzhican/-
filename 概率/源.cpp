#include<iostream>

long double factorial(long double x, long double y, long double z, int line,bool clear);


int main() {
	using std::cout;
	using std::cin;
	using std::endl;
	long double A, B, x, y, m, n;//AΪ����������BΪȡ������
	//xΪ���������м���������yΪ����
	//mΪ�����е�ѡȡ����nΪ�����е�ѡȡ��
	cout << "��������A:"; cin >> A;
	cout << "ȡ������B:"; cin >> B;
	cout << "���������м�������x:"; cin >> x;
	cout << "������������������y:"; cout<< (y=A-x)<<endl;
	cout << "�����е�ѡȡ��m:"; cin >> m;
	cout << "�����е�ѡȡ��n:"; cout<< (n=B-m)<<endl;

	long double x_, y_, z_;
	x_=factorial(B, m, n, 1,true);
	y_ = factorial(A-B, x-m, y-n, 1,true);
	z_ = factorial(x, y, A, 2,true);
	cout<<"����Ϊ" << x_*y_*z_;
}


long double factorial(long double x, long double y, long double z, int line,bool clear) {
	static  long double num = 1;
	if (clear)num = 1;
	if (line == 1) {//������x��
		if (y == 0) {//�����µ�һ�������Ѿ�����
			if (z == 0)return num;//�����µڶ��������Ѿ�����
			else {//�����µڶ�������δ����
				num *= (x / z);
				return factorial(x - 1, y , z-1, line,false);
			}
		}
		else {//�����µ�һ������δ����
			num *= (x / y);
			return factorial(x - 1, y - 1, z, line, false);
		}
	}
	if (line == 2) {
		if (x == 0) {//�����ϵ�һ�������Ѿ�����
			if (y == 0)return num;//�����ϵڶ��������Ѿ�����
			else {//�����ϵڶ�������δ����
				num *= (y / z);
				return factorial(x , y-1 , z - 1, line, false);
			}
		}
		else {//�����ϵ�һ������δ����
			num *= (x / z);
			return factorial(x - 1, y, z - 1, line, false);
		}
	}
}