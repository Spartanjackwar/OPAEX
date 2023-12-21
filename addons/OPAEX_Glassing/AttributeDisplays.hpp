class Rsc_OPAEX_AttributeNumberFromXSlider: RscControlsGroup
{
	idc = 2300;
	x = 0.3 * GUI_GRID_W;
	y = 1.5 * GUI_GRID_H;
	w = 30 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
	class Controls
	{
		class AttributeSlider: RscXSliderH
		{
			idc = 1900;
			x = 10 * GUI_GRID_W;
			y = 0 * GUI_GRID_H;
			w = 20 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			
			sliderRange[] = {0, 1000};
			sliderStep = 1;
			colorText[] = {1, 1, 1, 1};
		};
		class AttributeName: RscText
		{
			idc = 1001;
			text = "Attribute name:";
			x = 0 * GUI_GRID_W;
			y = 0 * GUI_GRID_H;
			w = 10 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
		};
	};
};

class Rsc_OPAEX_AttributeNumberFromXListBox: RscControlsGroup
{
	idc = 2300;
	x = 0.3 * GUI_GRID_W;
	y = 1.5 * GUI_GRID_H;
	w = 30 * GUI_GRID_W;
	h = 1 * GUI_GRID_H;
	class Controls
	{
		class AttributeBox: RscXListBox
		{
			idc = 1900;
			x = 10 * GUI_GRID_W;
			y = 0 * GUI_GRID_H;
			w = 20 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			class Items
			{
				class Item0
				{
					text = "Default Item";
					picture = "";
					color[] = {0, 0, 0, 1};
					colorPicture[] = {1, 1, 1, 1};
					data = "0";
					value = 0;
					default = 1;
				};
				class Item1: Item0
				{
					text = "Non-Default Item";
					default = 0;
					
					data = "1";
					value = 1;
				};
			};
		};
		class AttributeName: RscText
		{
			idc = 1001;
			text = "Attribute name:"; //--- ToDo: Localize;
			x = 0 * GUI_GRID_W;
			y = 0 * GUI_GRID_H;
			w = 10 * GUI_GRID_W;
			h = 1 * GUI_GRID_H;
			colorText[] = {1, 1, 1, 1};
		};
	};
};
