#pragma once
#include <XAudio2.h>
#include "wav.h"

class SoundSource
{
private:

	bool Submit(int loopNum = XAUDIO2_LOOP_INFINITE);
public:
	SoundSource();
	SoundSource(SoundSource&);
	~SoundSource();
	bool Load(const char* path);
	void PlayBGM(int loopNum = XAUDIO2_LOOP_INFINITE);
	void PlaySE();
	//一時停止
	void Stop();
	void Destroy();
	//ソースヴォイス(ここに音源が格納される
	IXAudio2SourceVoice* pSource;
	//wavデータ
	WAV					  wav;
};

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
	bool Create();
	bool AddSource(SoundSource& source);
	void DestroySystem(SoundSource& source);
};

