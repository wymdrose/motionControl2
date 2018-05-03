
#pragma once
#include <QMessageBox>

#include "DMCLib/LTDMC.h"
#include "APSLib/APS168.h"

#ifdef _M_X64
#pragma comment(lib, "DMCLib/LTDMCx64.lib")
#pragma comment(lib, "APSLib/APS168x64.lib")
#endif

#ifdef _M_IX86  
#pragma comment(lib, "DMCLib/LTDMCx86.lib")
#pragma comment(lib, "APSLib/APS168x86.lib") 
#endif // _M_IX86




namespace _MOTIONCLASS
{
	enum MOTION_CARD_TYPE
	{
		DMC5000,
		PCI7856
	};

	enum MOVE_TYPE
	{
		SingleAxisPositionMove,
		SingleAxisSpeedMove

	};

	struct DMC5000InitialPara
	{
		WORD  CardNun;				//定义卡数
		WORD  CardIdList[8];		//定义卡号数组
		DWORD CardTypeList[8];		//定义各卡类型
	};

	struct DMC5000HomePara
	{
		WORD CardNo = 0;	WORD axis = 0;
		WORD outmode = 0;

		double Min_Vel = 0;		double Max_Vel = 0;
		double Tacc = 0;		double Tdec = 0;
		double stop_vel = 200;

		WORD home_dir = 0;
		double vel_mode = 0;
		WORD mode = 0;
		WORD EZ_count = 0;
	};

	struct DMC5000MovePara
	{
		WORD CardNo; WORD axis; double Min_Vel; double Max_Vel; double Tacc; double Tdec; double stop_vel;
		WORD s_mode; double s_para;

		bool bLogic;	//direction
		long nPulse;
		MOVE_TYPE moveType = SingleAxisPositionMove;
	};

	struct PCI7856InitialPara
	{
		I32 boardID_InBits = 0; // Return board ID in bit format. [北ID肚,ノBitΑボ]
		I32 mode = 0;	// Initail mode [﹍て家Α]
		I32 cardName = 0; 
	};

class MOTIONLib
{
public:
	MOTIONLib(){};
	~MOTIONLib(){};

	virtual bool initial() =0;
	virtual bool home() = 0;
	virtual void emgStop() = 0;
	virtual void move() = 0;

public:
	DMC5000InitialPara mInitialPara;

private:
	
};



class DMC5000Lib : public MOTIONLib
{
public:
	DMC5000Lib()
	{
		mHomePara.home_dir = 1;               //初始化回零方向为正方向
		           
		mHomePara.Min_Vel = 500;			//初始化起始速度
		mHomePara.Max_Vel = 10000;
		mHomePara.Tacc = 1;
	}
	~DMC5000Lib()
	{

	}


	bool initial()
	{
		auto a = dmc_board_init();

		if (a <= 0)   //控制卡的初始化操作
		{
			return false;
		}

		dmc_get_CardInfList(&mInitialPara.CardNun, mInitialPara.CardTypeList, mInitialPara.CardIdList);    //获取正在使用的卡号

		return true;
	}

	//
	void setHomePara(WORD CardNo, WORD axis,
		double Min_Vel, double Max_Vel,
		double Tacc, double Tdec,

		WORD home_dir,
		double vel_mode,
		WORD mode,

		double stop_vel = 500, WORD EZ_count = 0)
	{
		mHomePara.CardNo = CardNo;	 mHomePara.axis = axis;
		mHomePara.Min_Vel = Min_Vel; mHomePara.Max_Vel = Max_Vel;
		mHomePara.Tacc = Tacc;		 mHomePara.Tdec = Tdec;
	}

	bool home()
	{
		dmc_set_pulse_outmode(mHomePara.CardNo, mHomePara.axis, 0);  //设置脉冲输出模式
		dmc_set_profile(mHomePara.CardNo, mHomePara.axis, mHomePara.Min_Vel, mHomePara.Max_Vel, mHomePara.Tacc, mHomePara.Tdec, 200);//设置速度曲线
		dmc_set_homemode(mHomePara.CardNo, mHomePara.axis, mHomePara.home_dir, mHomePara.vel_mode, mHomePara.mode, mHomePara.EZ_count = 1);//设置回零方式
		dmc_home_move(mHomePara.CardNo, mHomePara.axis);//回零动作
		while (dmc_check_done(mHomePara.CardNo, mHomePara.axis) == 0)      //判断当前轴状态
		{
			QApplication::processEvents();
		}

		return true;
	}

	void setMovePara(WORD CardNo, WORD axis, double Min_Vel, double Max_Vel,double Tacc, double Tdec, double stop_vel,
	WORD s_mode, double s_para,
	bool bLogic,
	long nPulse,
	MOVE_TYPE moveType = SingleAxisPositionMove)
	{
		mMovePara.CardNo = CardNo;	mMovePara.axis = axis;
		mMovePara.Min_Vel = Min_Vel; mMovePara.Max_Vel = Max_Vel;
		mMovePara.Tacc = Tacc;		mMovePara.Tdec = Tdec; mMovePara.stop_vel = stop_vel;
		mMovePara.s_mode = s_mode;	mMovePara.s_para = s_para;
		mMovePara.nPulse = nPulse;  mMovePara.bLogic = bLogic;
	}

	void move()
	{
		if (dmc_check_done(mMovePara.CardNo, mMovePara.axis) == 0) //已经在运动中
			return;

		//设定脉冲模式及逻辑方向（此处脉冲模式固定为P+D方向：脉冲+方向）	
		dmc_set_pulse_outmode(mMovePara.CardNo, mMovePara.axis, 0);

		dmc_set_profile(mMovePara.CardNo, mMovePara.axis, mMovePara.Min_Vel, mMovePara.Max_Vel, mMovePara.Tacc, mMovePara.Tdec, 0);
		
		//设定S段时间
		dmc_set_s_profile(mMovePara.CardNo, mMovePara.axis, 0, mMovePara.s_para);
		
		if (SingleAxisPositionMove == mMovePara.moveType)
		{
			//点动(位置模式)
			dmc_pmove(mMovePara.CardNo, mMovePara.axis, mMovePara.nPulse*(mMovePara.bLogic ? 1 : -1), 0);
		}
		else if (SingleAxisSpeedMove == mMovePara.moveType)
		{
			//持续驱动(速度模式)
			dmc_vmove(mMovePara.CardNo, mMovePara.axis, mMovePara.bLogic ? 1 : 0);
		}
		
	}

	void emgStop()
	{
		for (size_t i = 0; i < mInitialPara.CardNun; i++)
		{
			dmc_emg_stop(mInitialPara.CardIdList[i]);
		}	
	}



private:
	DMC5000HomePara mHomePara;
	DMC5000MovePara mMovePara;

};


class PCI7856Lib : public MOTIONLib
{
public:
	PCI7856Lib()
	{
	
	}
	~PCI7856Lib(){}

	bool initial()
	{
		I32 ret;				// Return code. [ㄧΑ肚]
		
		I32 cardId = 0;	// Device ID [北ID]
		I32 ver = 0; // Return APS library version. [眔APSセ絪腹]
		

		/*
		if (mIsInitial())
		{
			APS_close();

			// UI setting (诀ざ砞﹚)
			mSetState(STA_CLOSED);
			return false;
		}
		*/

		// Initial control card.
		ret = APS_initial(&mInitialPara.boardID_InBits, mInitialPara.mode);

//		if (ret != ERR_NoError)
		{
		//	MessageBox("APS initial failed.");
		//	mSetState(STA_CLOSED);
			return false;
		}

		APS_get_card_name(cardId, &mInitialPara.cardName);
		if (mInitialPara.cardName != 5) //5:PCI-7856
		{
		//	MessageBox("PCI-7856 not found.");
		//	mSetState(STA_CLOSED);
			return false;
		}

		// Check APS library version.
		ver = APS_version();
		if (ver < 100721) //If library version not match. 
		{ 
			// Interrupt function does not supported. 
		//	MessageBox("The device does not support DI interrupt functions.");
		//	MessageBox("Device closed.");

			APS_close();

			// UI setting (诀ざ砞﹚)
		//	mSetState(STA_CLOSED);
			return false;
		}

		//mCardId = cardId;

		// UI setting (诀ざ砞﹚)
		//mSetState(STA_INIT);

		return true;
	}

	static void home(I32 Axis_ID)
	{
		 APS_home_move(Axis_ID);
	}

	bool home()
	{
		return true;
	}

	void move()
	{


	}

	void emgStop()
	{

	}


	

private:
	PCI7856InitialPara mInitialPara;
//	static PCI7856Lib mHomePara;
//static PCI7856Lib mMovePara;
};


};//namespace

