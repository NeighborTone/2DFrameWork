#pragma once
#include <XAudio2.h>
#include "wav.h"

class Audio
{
private:
	//インターフェース
	static IXAudio2* pAudio;
	//マスターヴォイス
	static IXAudio2MasteringVoice* pMaster;

	//ソースヴォイス(ここに音源が格納される
	IXAudio2SourceVoice* pSource;
	//wavフォーマット構造体
	WAVEFORMATEX          wavFmt;
	//wavデータ
	WAV					  wav;

	Audio();
	Audio(const Audio& audio);
	

	//終了
	void Exit();
	//音楽データをキューに送信
	bool Submit();
	//XAudio2 インターフェース
	bool CreateXAudio2();	
	//マスターヴォイスの作成
	bool CreateMaster();	
	//ソースヴォイスの作成
	bool CreateSorce();		

public:
	~Audio();

	static Audio* GetInst();

	bool LoadWav(const std::string &path);
	bool Load();
	void Play();
	void Stop();
	void Pause();

	void SetGain(float gain);
	float GetGain()const;

};