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

	double x = temp_a[0];
	double x_1 = temp_a[0];
	double x_2 = temp_a[0];
	double fx = 0;
	double fx_1 = 0;
	double fx_2 = 1.0 / (1 + x_2*x_2);

	for (int i = 0; i < piecewise; i = i + 2)
	{
		x = x_2;
		x_1 = (i+1) * piece_len + temp_a[0];;
		x_2 = (i+2) * piece_len + temp_a[0];
		//cout << x << " " << x_1 << endl;
		fx = fx_2;
		fx_1 = 1.0 / (1 + x_1*x_1);
		fx_2 = 1.0 / (1 + x_2*x_2);

		sum += 2*piece_len /6.0 * (fx+4*fx_1 +fx_2);
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
