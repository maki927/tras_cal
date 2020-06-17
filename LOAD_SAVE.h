#pragma once

//+++++++++++++++++�N���X�̖���++++++++++++++++++++++++
//
//�v�Z�������t�@�C������ǂݎ��A�v�Z���ʂ��o�͂���B
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
class LOAD_SAVE {
public:

	//========================================
	//  �v�Z���ʂ��o��
	//-------------�����ɂ���---------------
	//  filename...�t�@�C����
	//  namenum...�t�@�C�����̕�����
	//  Xdata...�����f�[�^
	//  Ydata...�c���f�[�^
	//  num...�f�[�^��
	//========================================
	void DataSave(char* filename, int namenum, float* Xdata, float* Ydata, int num);

	//========================================
	// �v�Z������ǂݎ��
	//========================================
	void DataLoad();

	//========================================
	// �����o�ϐ��̒��g��\��
	//========================================
	void dispinfo();

	//========================================
	// �����o�ϐ��𓾂�
	//========================================
	char* GetFormula() { return formula; }
	float GetDensity() { return density; }
	float GetThickness() { return thickness; }
	float GetMin() { return Energy_min; }
	float GetInter() { return Energy_inter; }
	float GetMax() { return Energy_max; }

private:
	char formula[100]; //���w��
	int formnum; //���w���̕�����
	float density; //�����̖��x[g/cm^3]
	float thickness; //�����̖���[microns]
	float Energy_min; //�v�Z�̈�̃G�l���M�[�̎n�܂�
	float Energy_inter; //�G�l���M�[�Ԋu
	float Energy_max; //�G�l���M�[�̏I���
};




