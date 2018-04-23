#pragma once
#include <XAudio2.h>
#include "wav.h"

class Audio
{
private:
	//�C���^�[�t�F�[�X
	static IXAudio2* pAudio;
	//�}�X�^�[���H�C�X
	static IXAudio2MasteringVoice* pMaster;

	//�\�[�X���H�C�X(�����ɉ������i�[�����
	IXAudio2SourceVoice* pSource;
	//wav�t�H�[�}�b�g�\����
	WAVEFORMATEX          wavFmt;
	//wav�f�[�^
	WAV					  wav;

	Audio();
	Audio(const Audio& audio);
	

	//�I��
	void Exit();
	//���y�f�[�^���L���[�ɑ��M
	bool Submit();
	//XAudio2 �C���^�[�t�F�[�X
	bool CreateXAudio2();	
	//�}�X�^�[���H�C�X�̍쐬
	bool CreateMaster();	
	//�\�[�X���H�C�X�̍쐬
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