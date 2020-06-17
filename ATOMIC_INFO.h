#pragma once

//+++++++++++++++++�N���X�̖���++++++++++++++++++++++++
//
//�f�[�^�x�[�X����f�[�^��ǂݍ���
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
class ATOMIC_INFO
{
public:	
	//========================================
	//  ����\������
	//========================================
	void Disp_info();
	void Disp_photo();
	void Disp_scatter();
	void Disp_edgelist();

	//========================================
	//  �N���X���������ł���
	//-------------�����ɂ���---------------
	//  atomname...���q��
	//  num...�g����
	//========================================
	void Input_Name_Rate(char* atomname, int num);

	//========================================
	//  ���ʋz���W�����C���v�b�g
	//-------------�����ɂ���---------------
	//  data...���ʋz���W���̔z��|�C���^
	//  num...�f�[�^��
	//========================================
	void Mass_muIn(float* data, int num);


	//========================================
	//  �����o�ϐ��𓾂�
	//========================================
	char* GetName() { return name; }
	int GetRate() { return rate; };
	int GetNumber() { return number; }
	float GetWeight() { return weight; }

	float GetPhotoene(int num) { return photoene[num]; }
	float* GetPhotoene() { return photoene;}
	float GetPhoto(int num) { return photo[num]; }
	float* GetPhoto() { return photo; }
	int GetPhoto_num() { return photo_num; }

	float GetScene(int num) { return scene[num]; }
	float* GetScene() { return scene; }
	float GetCoh(int num) { return coh[num]; }
	float* GetCoh() { return coh; }
	float GetIncoh(int num) { return  incoh[num]; }
	float* GetIncoh() { return incoh; }
	int GetSc_num() { return sc_num; }

	float* GetEdgelist() { return edgelist; }
	float GetEdge(int num) { return edgelist[num]; }
	int GetEdgenum() { return edge_num; };

	float* GetMass_mu() { return mass_mu; }
	float GetMass_mu(int num) { return mass_mu[num]; }
	int GetMu_num() { return mu_num; }
	void dispMassmu();


	//========================================
	//  �������̊J��
	//========================================
	~ATOMIC_INFO();

private:
	char name[3]; //���q��
	int rate; //�g����
	int number; //���q�ԍ�
	float weight; //���q��


	float* photoene; //photo�ɑ΂���G�l���M�[
	float* photo; //�z����
	int photo_num; //�f�[�^��

	float* scene; //coh,incoh�ɑ΂���G�l���M�[
	float* coh; //�e���U����
	float* incoh; //��e���U����
	int sc_num; //�f�[�^��

	float* edgelist; //�z���[���X�g
	int edge_num; // �f�[�^��
	
	float* mass_mu; //���ʋz���W��
	int mu_num; //�f�[�^��


	//========================================
	//  �f�[�^�x�[�X����f�[�^��ǂݍ���
	//  Input_Name_Rate�ɌĂяo�����
	//========================================
	void search_atnw();
	void input_photo();
	void input_scatter();
	void make_edgelist();
};

