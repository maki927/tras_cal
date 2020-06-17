#pragma once

//+++++++++++++++++クラスの役割++++++++++++++++++++++++
//
//データベースからデータを読み込む
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++
class ATOMIC_INFO
{
public:	
	//========================================
	//  情報を表示する
	//========================================
	void Disp_info();
	void Disp_photo();
	void Disp_scatter();
	void Disp_edgelist();

	//========================================
	//  クラスを初期化できる
	//-------------引数について---------------
	//  atomname...原子名
	//  num...組成比
	//========================================
	void Input_Name_Rate(char* atomname, int num);

	//========================================
	//  質量吸収係数をインプット
	//-------------引数について---------------
	//  data...質量吸収係数の配列ポインタ
	//  num...データ数
	//========================================
	void Mass_muIn(float* data, int num);


	//========================================
	//  メンバ変数を得る
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
	//  メモリの開放
	//========================================
	~ATOMIC_INFO();

private:
	char name[3]; //原子名
	int rate; //組成比
	int number; //原子番号
	float weight; //原子量


	float* photoene; //photoに対するエネルギー
	float* photo; //吸収項
	int photo_num; //データ数

	float* scene; //coh,incohに対するエネルギー
	float* coh; //弾性散乱項
	float* incoh; //非弾性散乱項
	int sc_num; //データ数

	float* edgelist; //吸収端リスト
	int edge_num; // データ数
	
	float* mass_mu; //質量吸収係数
	int mu_num; //データ数


	//========================================
	//  データベースからデータを読み込む
	//  Input_Name_Rateに呼び出される
	//========================================
	void search_atnw();
	void input_photo();
	void input_scatter();
	void make_edgelist();
};

