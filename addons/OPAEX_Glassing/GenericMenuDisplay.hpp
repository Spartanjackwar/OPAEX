#define GUI_GRID_X	(0)
#define GUI_GRID_Y	(0)
#define GUI_GRID_W	(0.025)
#define GUI_GRID_H	(0.04)
#define GUI_GRID_WAbs	(1)
#define GUI_GRID_HAbs	(1)
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT START (by LCpl. Spartanjackwar, v1.063, #Cilety)
////////////////////////////////////////////////////////

class RscDisplay_OPAEX_GenericMenuDisplay: RscControlsGroup
{
	idc = 1234;
	x = 3.5 * GUI_GRID_W + GUI_GRID_X;
	y = 8 * GUI_GRID_H + GUI_GRID_Y;
	w = 33 * GUI_GRID_W;
	h = 9.5 * GUI_GRID_H;
	class ControlsBackground {
		class Background: RscText
		{
			idc = 30001;

			x = 0.3 * GUI_GRID_W;
			y = 1.5 * GUI_GRID_H;
			w = 32.4 * GUI_GRID_W;
			h = 10 * GUI_GRID_H; //6.5 * GUI_GRID_H;
			colorBackground[] = {0,0,0,0.7};
		};
	};
	class Controls {
		class Content: RscControlsGroup
		{
			idc = 30003;

			x = 0.3 * GUI_GRID_W;
			y = 1.5 * GUI_GRID_H;
			w = 32.4 * GUI_GRID_W;
			h = 10 * GUI_GRID_H; //6.5 * GUI_GRID_H;
			class Controls
			{
			};
		};
		class Title: RscText
		{
			idc = 30002;

			text = "EDIT %1"; //--- ToDo: Localize;
			x = 0.3 * GUI_GRID_W;
			y = 0.4 * GUI_GRID_H;
			w = 32.4 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
		};
		class ButtonOK: RscButtonMenuOK
		{
			x = 26.7 * GUI_GRID_W;
			y = 11.6 * GUI_GRID_H; //8.1 * GUI_GRID_H;
			w = 6 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
		};
		class ButtonCustom: RscButtonMenu
		{
			idc = 30004;

			x = 20.58 * GUI_GRID_W;
			y = 11.6 * GUI_GRID_H; //8.1 * GUI_GRID_H;
			w = 6 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
		};
		class ButtonCancel: RscButtonMenuCancel
		{
			x = 0.3 * GUI_GRID_W;
			y = 11.6 * GUI_GRID_H; //8.1 * GUI_GRID_H;
			w = 6 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
		};
	};
};

////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////