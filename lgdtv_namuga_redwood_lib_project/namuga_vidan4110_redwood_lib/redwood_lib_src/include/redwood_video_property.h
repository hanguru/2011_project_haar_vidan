#ifndef _REDWOOD_VIDEO_PROPERTY_
#define _REDWOOD_VIDEO_PROPERTY_

#define VIDEO_PROP_CNT		9
typedef enum
{
	PROP_CONTRAST = 0,
	PROP_BRIGHTNESS,
	PROP_SATURATION,
	PROP_SHARPNESS,
	PROP_HUE,
	PROP_GAMMA,
	PROP_WHITE_BALANCE,
	PROP_EXPOSURE,
	PROP_POWER_LINE_FREQ,
} VIDEO_PROP_TYPE;
	
typedef enum
{
	PROP_LEVEL_0 = 0,
	PROP_LEVEL_1,
	PROP_LEVEL_2,
	PROP_LEVEL_3,
	PROP_LEVEL_4,
	PROP_LEVEL_5,
	PROP_LEVEL_6,
	PROP_LEVEL_7,
	PROP_LEVEL_8,
	PROP_LEVEL_9,
	PROP_LEVEL_10,
	PROP_AUTO_ON,
	PROP_AUTO_OFF,
	PROP_DEFAULT,
} VIDEO_PROP_LEVEL;

#endif
