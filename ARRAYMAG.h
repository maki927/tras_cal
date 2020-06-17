#pragma once
#include<vector>

//+++++++++++++++++�N���X�̖���++++++++++++++++++++++++
//
//�z������̃N���X�ɓ���邱�ƂŁA�l�X�ȑ��삪�ł���B
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++

class ARRAYMAG
{
public:
	//**********************�����o�֐�**************************

	//========================================
	//  �z���ǂݍ���
	//-------------�����ɂ���---------------
	//  p...�z��̃|�C���^
	//  num...�z��̗v�f��
	//========================================
	void ArrayIn(float* p, int num);

	//========================================
	//  �z��̗v�f�����ׂ�0�ɂ���
	//  �v�f�����ׂ�0�̔z��𐶐�
	//-------------�����ɂ���---------------
	//  num...�z��̗v�f��
	//========================================
	void Array0(int num);
	void Array0();

	//========================================
	//  �z��A�v�f��t��������
	//-------------�����ɂ���---------------
	//  data...�v�f
	//  p...�z��̃|�C���^
	//  num...�z��̗v�f��
	//========================================
	void ArrayAdd(float data); //�z��̌��ɕt������
	void ArrayAdd(float* p, int num); //�z��̌��ɕt������
	void ArrayAddf(float data); //�z��̑O�ɕt������

	//========================================
	//  �z��̗v�f�����������ɕ��ׂ�
	//========================================
	void sort_min_max();

	//========================================
	//  �z��̗v�f�����������ɕ��ׁA�������l���폜����
	//========================================
	void ecn_del();

	//========================================
	//  �l�����Ԋu�̔z��𐶐�
	//-------------�����ɂ���---------------
	//  min...�z��̍ŏ��l
	//  inter...���l�̊Ԋu
	//  max...�z��̍ő�l
	//========================================
	void GenArray(float min, float inter, float max);

	//========================================
	//  �w�肵���v�f���폜
	//-------------�����ɂ���---------------
	//  num...�v�f�̂���ꏊ
	//========================================
	void DeleteData(int num);

	//========================================
	//  �z���\��
	//========================================
	void DispArray();

	//========================================
	//  �w�肵���͈͓��̗v�f�̒��o
	//-------------�����ɂ���---------------
	//  min...�ŏ��l
	//  max...�ő�l
	//  v...�I�[�o�[���[�h�p�̕ϐ�
	//------------�߂�l�ɂ���--------------
	//  int...�v�f�Ȃ��̎�1�A�v�f������ꍇ0
	//  ARRAYMAG...���o�����z����������N���X
	//========================================
	int pickup(float min, float max);
	ARRAYMAG pickup(float min, float max, int v);

	//========================================
	//  �w�肵���͈͓��̗v�f�ɔ����v�f�̒��o
	//-------------�����ɂ���---------------
	//  min...�ŏ��l
	//  max...�ő�l
	//  obj...���o�Ώ�
	//------------�߂�l�ɂ���--------------
	//  ARRAYMAG...���o���ꂽ�z����������N���X
	//========================================
	ARRAYMAG pickup2(float min, float max, ARRAYMAG obj);

	//========================================
	//  �����o�ϐ��𓾂�
	//========================================
	float* GetArray() { return ARRAY; }
	float GetData(int num);
	int GetNum() { return datanum; }

	//**********************************************************


	//***************�R���g���X�^�A�f�X�g���N�^*****************
	ARRAYMAG();
	ARRAYMAG(float* p, int num);
	ARRAYMAG(const ARRAYMAG& obj);
	~ARRAYMAG() { delete[] ARRAY; return; }
	//**********************************************************


	//*****************���Z�q�̃I�[�o�[���[�h*******************
	ARRAYMAG operator+(ARRAYMAG obj); //�z��̊e�v�f�𑫂�
	ARRAYMAG operator*(float num); //�z��̊e�v�f�ɐ��l��������
	ARRAYMAG operator/(float num); //�z��̊e�v�f�𐔒l�Ŋ���
	ARRAYMAG operator/(ARRAYMAG obj); //�z��̊e�v�f������
	ARRAYMAG operator+=(ARRAYMAG obj); //�z��̊e�v�f�𑫂�
	ARRAYMAG& operator=(const ARRAYMAG& obj); //������Z�q�̃I�[�o�[���[�h

	friend ARRAYMAG operator*(float num, ARRAYMAG obj); //�z��̊e�v�f�ɐ��l��������
	//**********************************************************

private:

	//**************************�����o�ϐ�**********************
	float* ARRAY;
	int datanum;
	//**********************************************************
};
