#ifndef HANDCONTROL_H
#define HANDCONTROL_H

#include <QDialog>
#include "ui_handControl.h"
#include "motionLib.h"

class handControl : public QDialog
{
	Q_OBJECT

public:
	handControl(QWidget *parent = 0);
	~handControl();


public:
	WORD  My_CardNum;			//定义卡数
	WORD  My_CardList[8];		//定义卡号数组
	DWORD My_CardTypeList[8];   //定义各卡类型

	long	m_nUposition;
	long	m_nXposition;
	long	m_nYposition;
	long	m_nZposition;
	int		m_nLowspeed;
	int		m_nPositive;
	int		m_nXaixs;
	int     m_nStatus;
	double	m_nSPara;
	double	m_nAcc;
	double	m_nDec;
	double	m_nSpeedmax;
	int		m_nHome;
	WORD m_Card = 0;
	double	m_NowSpe;
	double	m_nSpeedmin;

private:
	_MOTIONCLASS::DMC5000Lib mDMC5000Lib;
	_MOTIONCLASS::PCI7856Lib* mpPCI7856Lib = new _MOTIONCLASS::PCI7856Lib();

	_MOTIONCLASS::MOTIONLib *mpMOTIONLib;
	_MOTIONCLASS::MOTION_CARD_TYPE mCardType = _MOTIONCLASS::MOTION_CARD_TYPE::DMC5000;
	Ui::handControl ui;
};

#endif // HANDCONTROL_H
