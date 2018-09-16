#include<iostream>

long double factorial(long double x, long double y, long double z, int line,bool clear);


int main() {
	using std::cout;
	using std::cin;
	using std::endl;
	long double A, B, x, y, m, n;//A为样本总数，B为取样总数
	//x为样本总数中甲类总数，y为乙类
	//m为甲类中的选取数，n为乙类中的选取数
	cout << "样本总数A:"; cin >> A;
	cout << "取样总数B:"; cin >> B;
	cout << "样本总数中甲类总数x:"; cin >> x;
	cout << "样本总数中乙类总数y:"; cout<< (y=A-x)<<endl;
	cout << "甲类中的选取数m:"; cin >> m;
	cout << "乙类中的选取数n:"; cout<< (n=B-m)<<endl;

	long double x_, y_, z_;
	x_=factorial(B, m, n, 1,true);
	y_ = factorial(A-B, x-m, y-n, 1,true);
	z_ = factorial(x, y, A, 2,true);
	cout<<"概率为" << x_*y_*z_;
}


long double factorial(long double x, long double y, long double z, int line,bool clear) {
	static  long double num = 1;
	if (clear)num = 1;
	if (line == 1) {//除号在x下
		if (y == 0) {//除号下第一个除数已经算完
			if (z == 0)return num;//除号下第二个除数已经算完
			else {//除号下第二个除数未算完
				num *= (x / z);
				return factorial(x - 1, y , z-1, line,false);
			}
		}
		else {//除号下第一个除数未算完
			num *= (x / y);
			return factorial(x - 1, y - 1, z, line, false);
		}
	}
	if (line == 2) {
		if (x == 0) {//除号上第一个除数已经算完
			if (y == 0)return num;//除号上第二个除数已经算完
			else {//除号上第二个除数未算完
				num *= (y / z);
				return factorial(x , y-1 , z - 1, line, false);
			}
		}
		else {//除号上第一个除数未算完
			num *= (x / z);
			return factorial(x - 1, y, z - 1, line, false);
		}
	}
}