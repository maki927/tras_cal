#pragma once

//+++++++++++++++++クラスの役割++++++++++++++++++++++++
//
//計算条件をファイルから読み取る、計算結果を出力する。
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
class LOAD_SAVE {
public:

	//========================================
	//  計算結果を出力
	//-------------引数について---------------
	//  filename...ファイル名
	//  namenum...ファイル名の文字数
	//  Xdata...横軸データ
	//  Ydata...縦軸データ
	//  num...データ数
	//========================================
	void DataSave(char* filename, int namenum, float* Xdata, float* Ydata, int num);

	//========================================
	// 計算条件を読み取る
	//========================================
	void DataLoad();

	//========================================
	// メンバ変数の中身を表示
	//========================================
	void dispinfo();

	//========================================
	// メンバ変数を得る
	//========================================
	char* GetFormula() { return formula; }
	float GetDensity() { return density; }
	float GetThickness() { return thickness; }
	float GetMin() { return Energy_min; }
	float GetInter() { return Energy_inter; }
	float GetMax() { return Energy_max; }

private:
	char formula[100]; //化学式
	int formnum; //化学式の文字数
	float density; //試料の密度[g/cm^3]
	float thickness; //試料の膜厚[microns]
	float Energy_min; //計算領域のエネルギーの始まり
	float Energy_inter; //エネルギー間隔
	float Energy_max; //エネルギーの終わり
};




