#pragma once
#include"ATOMIC_INFO.h"
#include"ARRAYMAG.h"

//========================================
//  ���ʋz���W�����v�Z
//-------------�����ɂ���---------------
//  atomic_info...���q�̏��
//  final_Energy...�v�Z�p�̃G�l���M�[
//  final_E_n...�f�[�^��
//========================================
void cal_massmu(ATOMIC_INFO* atomic_info, int final_E_n, float* final_Energy);

//========================================
//  ���z���W���̌v�Z
//-------------�����ɂ���---------------
//  atomic_info...���q�̏��
//  atom_num...���q��
//  t...����
//  den...���x
//------------�߂�l�ɂ���--------------
//  ARRAYMAG...���z���W��
//========================================
ARRAYMAG cal_MU(ATOMIC_INFO* atomic_info, int atom_num, float t, float den);

//========================================
//  ���ߗ��̌v�Z
//-------------�����ɂ���---------------
//  mutot...���z���W��
//------------�߂�l�ɂ���--------------
//  ARRAYMAG...���ߗ�
//========================================
ARRAYMAG cal_trans(ARRAYMAG mutot);