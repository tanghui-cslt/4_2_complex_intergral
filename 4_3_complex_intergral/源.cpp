#include <iostream>
using namespace std;

void scanf_data(double temp_a[]);
double integral_f(double temp_a[]);

int main()
{

	double temp_a[2] = { 0,0 };		//区间的上下界
	
	scanf_data(temp_a);

	integral_f(temp_a);

	getchar();
	getchar();
}

double integral_f(double temp_a[])
{
	double piecewise = 1000;			//分段个数
	double len = temp_a[1] - temp_a[0];	//区间的长度
	double sum = 0;						//积分的结果
	double piece_len = len / piecewise;	//每个小段的长度

	double x = temp_a[0];				//梯形的上底的x
	double x_1 = temp_a[0];				//梯形的下底的x
	double fx = 0;						//梯形的上底
	double fx_1 = 1.0/(1+x_1*x_1);		//梯形的下底
	for (int i = 1; i <= piecewise; i++)
	{
		x = x_1;
		x_1 = i * piece_len + temp_a[0];
		//cout << x << " " << x_1 << endl;
		fx = fx_1;
		fx_1 = 1.0/(1+x*x);
		sum += 0.5*piece_len*(fx+fx_1);
	}
	cout << "\n\n************结果为*********\n";
	cout << sum << endl;
	return sum;
}
void scanf_data(double temp_a[])
{
	cout << "********请输入积分上下界:**********\n";
	
	for (size_t i = 0; i < 2; i++)
	{
		cin >> temp_a[i];
		
	}
}
