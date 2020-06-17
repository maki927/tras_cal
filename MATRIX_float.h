#pragma once

//+++++++++++++++++�N���X�̖���++++++++++++++++++++++++
//
//�v�f�̌^��float�̍s���������
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
class MATRIX_float
{
public:

	//========================================
	//  �s��̕\��
	//========================================
	void DispMatrix();

	//========================================
	//  �v�f���ׂĂ�1�ɂ���
	//========================================
	void AllOne();

	//========================================
	//  �s����̎w�肳�ꂽ�v�f�ɃA�N�Z�X�ł���
	//-------------�����ɂ���---------------
	//  m...�s��
	//  n...��
	//========================================
	float& Data(unsigned int m, unsigned int n);
	float& Data(unsigned int num);

	//========================================
	//  �����o�ϐ��𓾂�
	//========================================
	int GetRow() { return row; }
	int GetColumn() { return column; }

	//========================================
	//  �K�E�X�W�����_���̂͂����o���@�ŉ������߂�
	//-------------�����ɂ���---------------
	// A_matrix...�E�ӂ̍s��
	//-------------�߂�l---------------------
	// MATRIX_float...���ƂȂ�s��
	//========================================
	MATRIX_float gauss_j(MATRIX_float A_matrix);


	//***************�R���g���X�^�A�f�X�g���N�^*****************
	MATRIX_float(unsigned int n, unsigned int m);
	MATRIX_float(const MATRIX_float& obj);
	~MATRIX_float() { delete[] matrix; }
	//**********************************************************


	//*****************���Z�q�̃I�[�o�[���[�h*******************
	MATRIX_float operator+(MATRIX_float obj); //�s��̑����Z
	MATRIX_float operator-(MATRIX_float obj); //�s��̈����Z
	MATRIX_float operator*(MATRIX_float obj); //�s��̊|���Z

	//�������Ȃ��Ă�������
	//MATRIX_float& operator=(const MATRIX_float& obj);


private:
	
	float* matrix; //�s��
	unsigned int row; //�s��
	unsigned int column; //��
};

