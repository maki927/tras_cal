#pragma once

//+++++++++++++++++クラスの役割++++++++++++++++++++++++
//
//要素の型がfloatの行列を扱える
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
class MATRIX_float
{
public:

	//========================================
	//  行列の表示
	//========================================
	void DispMatrix();

	//========================================
	//  要素すべてを1にする
	//========================================
	void AllOne();

	//========================================
	//  行列内の指定された要素にアクセスできる
	//-------------引数について---------------
	//  m...行数
	//  n...列数
	//========================================
	float& Data(unsigned int m, unsigned int n);
	float& Data(unsigned int num);

	//========================================
	//  メンバ変数を得る
	//========================================
	int GetRow() { return row; }
	int GetColumn() { return column; }

	//========================================
	//  ガウスジョルダンのはじき出し法で解を求める
	//-------------引数について---------------
	// A_matrix...右辺の行列
	//-------------戻り値---------------------
	// MATRIX_float...解となる行列
	//========================================
	MATRIX_float gauss_j(MATRIX_float A_matrix);


	//***************コントラスタ、デストラクタ*****************
	MATRIX_float(unsigned int n, unsigned int m);
	MATRIX_float(const MATRIX_float& obj);
	~MATRIX_float() { delete[] matrix; }
	//**********************************************************


	//*****************演算子のオーバーロード*******************
	MATRIX_float operator+(MATRIX_float obj); //行列の足し算
	MATRIX_float operator-(MATRIX_float obj); //行列の引き算
	MATRIX_float operator*(MATRIX_float obj); //行列の掛け算

	//実装しなくていいかも
	//MATRIX_float& operator=(const MATRIX_float& obj);


private:
	
	float* matrix; //行列
	unsigned int row; //行数
	unsigned int column; //列数
};

