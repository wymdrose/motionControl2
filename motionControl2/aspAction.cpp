#include "aspAction.h"
#include "motionLib.h"
#include <qDebug>

aspAction::aspAction(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	
	connect(ui.pushButtonInitial, &QPushButton::clicked, [this](){
	
		//APS_close();

		I32 ret;			
		I32 boardID_InBits = 0; 
		I32 mode = 0 | (1 << 6);	
		I32 cardId = 0;	
		I32 ver = 0;
		I32 cardName = 0; 

		ret = APS_initial(&boardID_InBits, mode);
		qDebug() << QString("APS_initial() ret: %1").arg(ret);

		APS_get_card_name(cardId, &cardName);
		qDebug() << QString("cardName: %1").arg(cardName);

		if (cardName != 5) //5:PCI-7856
		{
			qDebug() << "PCI-7856 not found.";
			return;
		}

		ver = APS_version();
		qDebug() << QString("APS_version() ver: %1").arg(ver);

		if (ver < 100721) //If library version not match. 
		{ 
			return;
		}
	});



}

aspAction::~aspAction()
{

}



/*

	//¡­Initial card 
	I32 Dimension = 2; 
	I32 Master_Axis_ID = 1; //Master axis 
	I32 Axis_ID_Array[4] = {1, 2}; //Axis ID 1 is master axis. 
	I32 Position_Array [4] = {1000, 2000}; //(Unit: pulse) 


	//¦¤X = 1000 pulse 
	//¦¤Y = 2000 pulse 
	I32 Max_Linear_Speed = 1000;  //(Unit: pulse/ second)

	I32 Ret;
	APS_set_axis_param(Master_Axis_ID, PRA_CURVE, 0);//Set T-curve 
	APS_set_axis_param(Master_Axis_ID, PRA_ACC, 10000);// 
	Set acceleration APS_set_axis_param(Master_Axis_ID, PRA_DEC, 10000);// Set deceleration

	¡­ 
	Ret = APS_absolute_linear_move ( Dimension, Axis_ID_Array, Position_Array, Max_Linear_Speed ); 
	¡­














*/

