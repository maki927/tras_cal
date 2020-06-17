#include "SPLINE.h"
#include "MATRIX_float.h"
#include "ARRAYMAG.h"
#include <iostream>

using namespace std;

MATRIX_float make_hdata(float* xdata, int num) {

	MATRIX_float hdata(1, num - 1);

	for (unsigned int i = 0; i < num - 1; i++) {
		hdata.Data(i + 1) = xdata[i + 1] - xdata[i];
	}

	return hdata;
}


MATRIX_float make_hmatrix(MATRIX_float hdata) {

	MATRIX_float hmatrix(hdata.GetColumn() - 1, hdata.GetColumn() - 1);

	for (unsigned int i = 1; i <= hmatrix.GetRow(); i++) {
		hmatrix.Data(i, i) = 2 * (hdata.Data(i) + hdata.Data(i + 1));
	}
	for (unsigned int i = 1; i <= hmatrix.GetRow() - 1; i++) {
		hmatrix.Data(i, i + 1) = hdata.Data(i + 1);
		hmatrix.Data(i + 1, i) = hdata.Data(i + 1);
	}

	return hmatrix;
}


MATRIX_float make_vdata(MATRIX_float hdata, float* ydata) {

	MATRIX_float vdata(hdata.GetColumn() - 1, 1);

	for (unsigned int i = 1; i <= vdata.GetColumn(); i++) {
		vdata.Data(i) = 6 * (((ydata[i + 1] - ydata[i]) / hdata.Data(i + 1)) - ((ydata[i] - ydata[i - 1]) / hdata.Data(i)));
	}

	return vdata;
}


ARRAYMAG spline(float* xdata, float* ydata, int xdatanum, float* x_spl, int xsplnum) {

	MATRIX_float hdata = make_hdata(xdata, xdatanum);

	MATRIX_float hmatrix = make_hmatrix(hdata);

	MATRIX_float vdata = make_vdata(hdata, ydata);

	MATRIX_float udata = hmatrix.gauss_j(vdata);

	int para_num = xdatanum - 1;
	float* ui = new float[xdatanum];
	float* ai = new float[para_num];
	float* bi = new float[para_num];
	float* ci = new float[para_num];
	float* di = new float[para_num];

	ui[0] = 0;
	for (unsigned int i = 1; i <= udata.GetRow(); i++) {
		ui[i] = udata.Data(i);
	}
	ui[udata.GetRow() + 1] = 0;

	for (unsigned int i = 0; i < para_num; i++) {
		ai[i] = (ui[i + 1] - ui[i]) / (6 * (xdata[i + 1] - xdata[i]));
		bi[i] = ui[i] / 2;
		ci[i] = ((ydata[i + 1] - ydata[i]) / (xdata[i + 1] - xdata[i]))
			- ((xdata[i + 1] - xdata[i]) * (2 * ui[i] + ui[i + 1])) / 6;
		di[i] = ydata[i];
	}

	float* y_spl = new float[xsplnum];
	int j = 0;
	for (unsigned int i = 0; i < xsplnum; i++) {
		if (j < para_num - 1) {
			for (;;) {
				if (xdata[j] <= x_spl[i] && x_spl[i] < xdata[j + 1] || xdata[xdatanum - 1] <= x_spl[i] || xdata[0] > x_spl[i]) {
					break;
				}
				j++;
			}
		}
		y_spl[i] = ai[j] * pow((x_spl[i] - xdata[j]), 3.0)
			+ bi[j] * pow((x_spl[i] - xdata[j]), 2.0)
			+ ci[j] * pow((x_spl[i] - xdata[j]), 1.0)
			+ di[j];
	}

	ARRAYMAG tmp;
	tmp.ArrayIn(y_spl, xsplnum);

	delete[] ai; delete[] bi; delete[] ci; delete[] di; delete[] ui; delete[] y_spl;

	return tmp;
}
