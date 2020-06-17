#pragma once
#include"ATOMIC_INFO.h"

//+++++++++++++++++�N���X�̖���++++++++++++++++++++++++
//
//�v�Z�p�̃G�l���M�[��p�ӂ���
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
class MAKE_ENE
{
public:
	//========================================
	//  ���ׂĂ̌��q�̋z���[���܂Ƃ߂�
	//-------------�����ɂ���---------------
	//  info_heap...ATOMIC_INFO�N���X�̃|�C���^
	//  atom_num...�\�����q��
	//========================================
	void make_alledgelist(ATOMIC_INFO* info_heap, int atom_num);

	//========================================
	//  �v�Z�p�̃G�l���M�[��p�ӂ���
	//-------------�����ɂ���---------------
	//  min...energy�̍ŏ��l
	//  inter...energy�Ԋu
	//  max...energy�̍ő�l
	//========================================
	void make_energy(float min, float inter, float max);

	//========================================
	//  energy�̕\��
	//========================================
	void disp_energy();

	//========================================
	//  �����o�ϐ��𓾂�
	//========================================
	int GetEnenum() { return datanum; }
	float* GetEne() { return energy; }
	float GetEne(int num) { return energy[num]; }

	//***************�R���g���X�^�A�f�X�g���N�^*****************
	MAKE_ENE();
	~MAKE_ENE();
	//**********************************************************
private:
	float* alledgelist; //�\�����q���ׂĂ̋z���[���X�g
	float* energy; //�v�Z�Ɏg���G�l���M�[
	int datanum; //�f�[�^��

	float enemin; //energy�̍ŏ��l
	float enemax; //energy�̍ő�l
};

