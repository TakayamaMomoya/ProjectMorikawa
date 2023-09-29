//=============================================================================
//
// サウンド処理 [sound.h]
// Author : 高山桃也
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CSound
{
public:
	typedef enum
	{
		LABEL_TITLE = 0,				// タイトルBGM
		LABEL_GAME,				        // ゲームBGM
		LABELBREAK_SE,                  // 通常ブロック
		LABELBONUS_SE,                  // ボーナスブロック
		LABELNEEDLE_SE,                 // ニードルに当たった時
		LABELJUMP_SE,                   // ジャンプしたとき
		LABELTRAM_SE,                   // トロッコの音
		LABEL_MAX
	} LABEL;

	typedef enum
	{
		FADESTATE_NONE = 0,	//何もしていない状態
		FADESTATE_IN,	//フェードイン状態
		FADESTATE_OUT,	//フェードアウト状態
		FADESTATE_MAX
	}FADESTATE;

	CSound();	// コンストラクタ
	~CSound();	// デストラクタ

	HRESULT Init(HWND hWnd);
	void Uninit(void);
	void Update(void);

	HRESULT Play(LABEL label);
	void Stop(LABEL label);
	void Stop(void);

	void SetVolume(LABEL label, float fVolume);
	void SetFade(LABEL LabelNow, LABEL LabelNext, float fSpeed);

private:
	typedef struct
	{
		char *pFilename;	// ファイル名
		int nCntLoop;		// ループカウント
	} SOUNDINFO;

	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

	IXAudio2 *m_pXAudio2;								// XAudio2オブジェクトへのインターフェイス
	IXAudio2MasteringVoice *m_pMasteringVoice;			// マスターボイス
	IXAudio2SourceVoice *m_apSourceVoice[LABEL_MAX];	// ソースボイス
	BYTE *m_apDataAudio[LABEL_MAX];					// オーディオデータ
	DWORD m_aSizeAudio[LABEL_MAX];					// オーディオデータサイズ
	FADESTATE m_fadeSound;								// フェード状態
	LABEL m_SoundLabelNow;								// 現在のサウンドラベル
	LABEL m_SoundLabelNext;								// 次のサウンドラベル
	float m_fSpeedFadeSound;									// サウンドがフェードするスピード
	float m_fVolumeSound;										// サウンドのボリューム
	// サウンドの情報
	SOUNDINFO m_aSoundInfo[LABEL_MAX] =
	{
		{ "data/SOUND/BGM/title.wav", -1 },			// タイトル	
		{ "data/SOUND/BGM/game.wav", -1 },			// ゲーム
		{ "data/SE/block_01.wav", 0 },			    // 通常ブロック	
		{ "data/SE/block_02.wav", 0 },			    // ボーナス	
		{ "data/SE/needle.wav", 0 },			    // ニードルに当たった時
		{ "data/SE/jump.wav", 0 },			        // ジャンプしたとき
		{ "data/SE/tram.wav", -1 },			        // トロッコの音
	};
};

#endif