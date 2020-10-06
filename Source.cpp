////////lab 6 Teplyakov Iliay
#include<iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int i, j, n, m;
	//������� ������
	cout << "����� ����� ���������: ";
	cin >> n;
	cout << "����� ����� �����������: ";
	cin >> m;
	m += 1;
	float **matrix = new float *[n];
	for (i = 0; i < n; i++)
		matrix[i] = new float[m];

	//��������������

	for (i = 0; i < n; i++)

		for (j = 0; j < m; j++)
		{
			cout << "������� " << "[" << i + 1 << " , " << j + 1 << "]: ";

			cin >> matrix[i][j];
		}

	//������� ������
	cout << "matrix: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	//����� ������
	//������ ���, ���������� � ������������������ ����
	float  tamp;
	float *xx = new float[m];

	int k;

	for (i = 0; i < n; i++)
	{
		tamp = matrix[i][i];
		for (j = n; j >= i; j--)
			matrix[i][j] /= tamp;
		for (j = i + 1; j < n; j++)
		{
			tamp = matrix[j][i];
			for (k = n; k >= i; k--)
				matrix[j][k] -= tamp * matrix[i][k];
		}
	}
	/*�������� ���*/
	xx[n - 1] = matrix[n - 1][n];
	for (i = n - 2; i >= 0; i--)
	{
		xx[i] = matrix[i][n];
		for (j = i + 1; j < n; j++) xx[i] -= matrix[i][j] * xx[j];
	}

	//������� �������
	for (i = 0; i < n; i++)
		cout << xx[i] << " ";
	cout << endl;

	delete[] matrix;

	return 0;
}