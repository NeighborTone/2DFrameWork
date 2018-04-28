#pragma once
#include <XAudio2.h>
#include "wav.h"

class SoundSource
{
private:

	bool Submit();
public:
	SoundSource();
	~SoundSource();
	bool Load(const char* path);
	void Play();
	void Stop();
	//ソースヴォイス(ここに音源が格納される
	IXAudio2SourceVoice* pSource;
	//wavデータ
	WAV					  wav;
	IXAudio2SourceVoice* GetSource() { return pSource; }
	WAV GetWav() { return wav; }
};

class SoundSystem
{
private:
		//インターフェース
		static IXAudio2* pXAudio2;
		//マスターヴォイス
		static IXAudio2MasteringVoice* pMaster;

		SoundSystem();
		
public:
	~SoundSystem();
	
	static SoundSystem* GetSystem();
	bool Create();
	bool AddSource(SoundSource& source);
	void DeleteSystem(SoundSource& source);
};

