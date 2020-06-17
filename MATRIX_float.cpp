#include "MATRIX_float.h"
#include<iostream>

using namespace std;

float& MATRIX_float::Data(unsigned int m, unsigned int n) {

	if (row < m) {
		cout << "You tried to access to out of range\n";
		m = row;
	}
	if (column < n) {
		cout << "You tried to access to out of range\n";
		n = column;
	}

	return matrix[(m - 1) + row * (n - 1)];
}

float& MATRIX_float::Data(unsigned int num) {
	if (row * column < num) {
		cout << "You tried to access to out of range\n";
		num = row * column;
	}

	return matrix[num - 1];
}


void MATRIX_float::DispMatrix() {
	cout << "-----------------------------\n";
	for (unsigned int i = 1; i <= row; i++) {
		for (unsigned int j = 1; j <= column; j++) {
			cout << Data(i, j) << '\t';
		}
		cout << '\n';
	}
	cout << "-----------------------------\n";
}

void MATRIX_float::AllOne() {
	for (unsigned int i = 0; i < row * column; i++) {
		matrix[i] = 1;
	}
}

MATRIX_float MATRIX_float::gauss_j(MATRIX_float A_matrix) {

	MATRIX_float obj = *this;
	MATRIX_float ans(row, 1);

	if (row != A_matrix.GetRow() || row != column) {
		cout << "The calcuration is impossible\n";
		return ans;
	}
	
	unsigned int ipv, i, j, pivot_row;
	float inv_pivot, temp, big;

	for (ipv = 1; ipv <= row; ipv++) {
		
		//---- 入れ替えのための最大値探索 --------------------
		big = 0.0;
		for (i = ipv; i <= row; i++) {
			if (fabs(obj.Data(i, ipv)) > big) {
				big = fabs(obj.Data(i, ipv));
				pivot_row = i;
			}
		}
		if (big == 0.0) {
			cout << "The calculation is failed\n";
			return ans;
		}

		//------------ 行の入れ替え --------------------------
		if (ipv != pivot_row) {
			for (i = 1; i <= row; i++) {
				temp = obj.Data(ipv, i);
				obj.Data(ipv, i) = obj.Data(pivot_row, i);
				obj.Data(pivot_row, i) = temp;
			}
			temp = A_matrix.Data(ipv); 
			A_matrix.Data(ipv) = A_matrix.Data(pivot_row);
			A_matrix.Data(pivot_row) = temp;
		}
		
		//----------------対角化-----------------------------
		inv_pivot = 1.0 / obj.Data(ipv, ipv);

		for (j = 1; j <= row; j++) {
			obj.Data(ipv, j) *= inv_pivot;
		}

		A_matrix.Data(ipv) *= inv_pivot;
		//---------------------------------------------------


		//-------------ピボット列の処理----------------------
		for (i = 1; i <= row; i++) {
			if (i != ipv) {
				temp = obj.Data(i, ipv);
				for (j = 1; j <= row; j++) {
					obj.Data(i, j) -= temp * obj.Data(ipv, j);
				}
				A_matrix.Data(i) -= temp * A_matrix.Data(ipv);
			}
		}
		//---------------------------------------------------
	}

	for (i = 1; i <= row; i++) {
		ans.Data(i) = A_matrix.Data(i);
	}

	return ans;
}



MATRIX_float::MATRIX_float(unsigned int m, unsigned int n) {
	
	matrix = new float[n * m];

	for (int i = 0; i < m * n; i++) {
		matrix[i] = 0;
	}

	row = m;
	column = n;
}

MATRIX_float::MATRIX_float(const MATRIX_float& obj) {
	
	matrix = new float[obj.row * obj.column];
	for (int i = 0; i < obj.row * obj.column; i++) {
		matrix[i] = obj.matrix[i];
	}
	row = obj.row;
	column = obj.column;
	
}



MATRIX_float MATRIX_float::operator+(MATRIX_float obj) {

	if (row != obj.row || column != obj.column) {
		cout << "Matrix calculation is impossible\n";
		MATRIX_float tmp(row, column);
		return tmp;
	}

	MATRIX_float tmp(row, column);

	for (unsigned int i = 1; i <= row; i++) {
		for (unsigned int j = 1; j <= column; j++) {
			tmp.Data(i, j) = Data(i, j) + obj.Data(i, j);
		}
	}

	return tmp;
}

MATRIX_float MATRIX_float::operator-(MATRIX_float obj) {

	if (row != obj.row || column != obj.column) {
		cout << "Matrix calculation is impossible\n";
		MATRIX_float tmp(row, column);
		return tmp;
	}

	MATRIX_float tmp(row, column);

	for (unsigned int i = 1; i <= row; i++) {
		for (unsigned int j = 1; j <= column; j++) {
			tmp.Data(i, j) = Data(i, j) - obj.Data(i, j);
		}
	}

	return tmp;
}

MATRIX_float MATRIX_float::operator*(MATRIX_float obj) {

	if (column != obj.row) {
		cout << "Matrix calculation is impossible\n";
		MATRIX_float tmp(row, obj.column);
		return tmp;
	}

	MATRIX_float tmp(row, obj.column);

	float num = 0;

	for (unsigned int i = 1; i <= row; i++) {
		for (unsigned int j = 1; j <= obj.column; j++) {
			for (unsigned int k = 1; k <= column; k++) {
				num += Data(i, k) * obj.Data(k, j);
			}
			tmp.Data(i, j) = num;
			num = 0;
		}
	}

	return tmp;
}



//実装しなくていいかも

//MATRIX_float& MATRIX_float::operator=(const MATRIX_float& obj) {
//
//	if (this != &obj) {
//		delete[] matrix;
//		matrix = new float[obj.row * obj.column];
//		for (int i = 0; i < obj.row * obj.column; i++) {
//			matrix[i] = obj.matrix[i];
//		}
//		row = obj.row;
//		column = obj.column;
//	}
//	return *this;
//}