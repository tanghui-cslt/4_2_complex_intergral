#include <iostream>
using namespace std;

void scanf_data(double temp_a[]);
double integral_f(double temp_a[]);

int main()
{

	double temp_a[2] = { 0,0 };		//��������½�
	
	scanf_data(temp_a);

	integral_f(temp_a);

	getchar();
	getchar();
}

double integral_f(double temp_a[])
{
	double piecewise = 1000;			//�ֶθ���
	double len = temp_a[1] - temp_a[0];	//����ĳ���
	double sum = 0;						//���ֵĽ��
	double piece_len = len / piecewise;	//ÿ��С�εĳ���

	double x = temp_a[0];				//���ε��ϵ׵�x
	double x_1 = temp_a[0];				//���ε��µ׵�x
	double fx = 0;						//���ε��ϵ�
	double fx_1 = 1.0/(1+x_1*x_1);		//���ε��µ�
	for (int i = 1; i <= piecewise; i++)
	{
		x = x_1;
		x_1 = i * piece_len + temp_a[0];
		//cout << x << " " << x_1 << endl;
		fx = fx_1;
		fx_1 = 1.0/(1+x*x);
		sum += 0.5*piece_len*(fx+fx_1);
	}
	cout << "\n\n************���Ϊ*********\n";
	cout << sum << endl;
	return sum;
}
void scanf_data(double temp_a[])
{
	cout << "********������������½�:**********\n";
	
	for (size_t i = 0; i < 2; i++)
	{
		cin >> temp_a[i];
		
	}
}
