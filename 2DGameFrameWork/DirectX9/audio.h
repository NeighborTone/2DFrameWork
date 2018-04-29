#pragma once
#include <XAudio2.h>
#include "wav.h"

class SoundSource
{
private:


public:
	SoundSource();
	SoundSource(SoundSource&);
	~SoundSource();
	bool Load(const char* path);
	void PlayBGM(int loopNum = XAUDIO2_LOOP_INFINITE, float gain = 1.0f, float pitch = 1.0f);
	void PlaySE(float gain = 1.0f, float pitch = 1.0f);
	//一時停止
	void Stop();
	void Destroy();
	//ソースヴォイス(ここに音源が格納される
	IXAudio2SourceVoice* pSource;
	//wavデータ格納用
	WAV					  wav;
};

//サウンド管理部。シングルトン・
class SoundSystem 
{
private:
		//インターフェース
		static IXAudio2* pXAudio2;
		//マスターヴォイス
		static IXAudio2MasteringVoice* pMaster;

		SoundSystem();
		SoundSystem(const SoundSystem&) = delete;	//コピー禁止
public:
	~SoundSystem();
	
	static SoundSystem* GetSystem();
	//サウンドシステムの初期化、一度だけ作ればよい
	bool Create();
	//ソースボイスの登録
	//ソースボイスは明示的に開放しない限りアプリケーション終了時まで残り続ける
	bool AddSource(SoundSource& source);
	void DestroySystem(SoundSource& source);
};

