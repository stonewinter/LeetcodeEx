#include <iostream>
#include <vector>

using namespace std;

int main(){

}

/*
    solution: ţ�ٷ�
    �����⺯��f(x), ��f(x)=0�Ľ�
    ����ţ�ٷ������߱ƽ�ԭ��, �ɵ� X[n] = X[n-1] - f(X[n-1])/f'(X[n-1])
    �������� x^2 = a �Ľ�, �� x^2 - a = 0 --> f(x) = x^2-a
    �ɵ� X[n] = (X[n-1] + a/X[n-1]) / 2

    Ŀ�����ҵ���ӽ�a��������. ��ô���ǿ���ÿ�ζ��Ƚ� X[n]^2 �� a�Ĵ�С.
    �������˵�� X[n] ̫��, �����ҵ��� X[n] �����ʵ�.
    һ��С��, ˵��֮ǰ�Ǹ� X[n] ������ӽ��Ľ�.
*/
int mySqrt(int a) {
    long r = a;
    while (r*r > a)
        r = (r + a/r) / 2;
    return r;
}



/*
    ����һ��2�ַ�, ˼·��2�ֲ����е�, ���е��ƽ����Ŀ��Ĳ��.
    �������, ˵���е��Сһ��, ��ô�ұ߽���С��, �����е�, ѭ������
    ��֮, ˵����߽�ô�һ��
*/