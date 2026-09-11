#ifndef INKPTR_CH9329_H
#define INKPTR_CH9329_H

// Screen resolution
#define INKPTR_CH9329_ScreenResolution_X    2560
#define INKPTR_CH9329_ScreenResolution_Y    1440

typedef struct
{
    uint8_t     Ctrl_or_Mouse_Key;
    uint8_t     Key[6];
    int8_t      MouseWheel;
    int8_t      MouseRel_X;
    int8_t      MouseRel_Y;
    uint16_t    MouseAbs_X;
    uint16_t    MouseAbs_Y;
} INKPTR_CH9329_Operation_TypeDef;
extern INKPTR_CH9329_Operation_TypeDef INKPTR_CH9329_Operation;
extern uint8_t INKPTR_CH9329_SerialCmd[14];

typedef enum
{
	INKPTR_CH9329_Ctrl_L = 0x01, INKPTR_CH9329_Shift_L = 0x02, INKPTR_CH9329_Alt_L = 0x04, INKPTR_CH9329_Win_L = 0x08,
	INKPTR_CH9329_Ctrl_R = 0x10, INKPTR_CH9329_Shift_R = 0x20, INKPTR_CH9329_Alt_R = 0x40, INKPTR_CH9329_Win_R = 0x80,
} INKPTR_CH9329_CtrlKey;
typedef enum
{
	INKPTR_CH9329_Enter = 0x21,
	INKPTR_CH9329_Esc,     INKPTR_CH9329_BackSpace,   INKPTR_CH9329_Tab,
	INKPTR_CH9329_CapsLock = 0x61,
	INKPTR_CH9329_F1,      INKPTR_CH9329_F2,      INKPTR_CH9329_F3,      INKPTR_CH9329_F4,      INKPTR_CH9329_F5,      INKPTR_CH9329_F6,
	INKPTR_CH9329_F7,      INKPTR_CH9329_F8,      INKPTR_CH9329_F9,      INKPTR_CH9329_F10,     INKPTR_CH9329_F11,     INKPTR_CH9329_F12,
	INKPTR_CH9329_PrtSc,   INKPTR_CH9329_ScrLk,   INKPTR_CH9329_Pause,
	INKPTR_CH9329_Ins,     INKPTR_CH9329_Home,    INKPTR_CH9329_PgUp,    INKPTR_CH9329_Del,     INKPTR_CH9329_End,     INKPTR_CH9329_PgDn,
	INKPTR_CH9329_Right,   INKPTR_CH9329_Left,    INKPTR_CH9329_Down,    INKPTR_CH9329_Up,
	INKPTR_CH9329_NumLock, INKPTR_CH9329_NumDiv,  INKPTR_CH9329_NumMul,  INKPTR_CH9329_NumSub,  INKPTR_CH9329_NumAdd,  INKPTR_CH9329_NumEnter,
	INKPTR_CH9329_Num1,    INKPTR_CH9329_Num2,    INKPTR_CH9329_Num3,    INKPTR_CH9329_Num4,    INKPTR_CH9329_Num5,
	INKPTR_CH9329_Num6,    INKPTR_CH9329_Num7,    INKPTR_CH9329_Num8,    INKPTR_CH9329_Num9,    INKPTR_CH9329_Num0,
	INKPTR_CH9329_NumDel,
} INKPTR_CH9329_OtherKey;
typedef enum {INKPTR_CH9329_Mouse_Left = 0x01,   INKPTR_CH9329_Mouse_Right = 0x02,  INKPTR_CH9329_Mouse_Middle = 0x04} INKPTR_CH9329_MouseKey;
typedef enum {INKPTR_CH9329_CmdLen_Keyboard = 14, INKPTR_CH9329_CmdLen_MouseRel = 11, INKPTR_CH9329_CmdLen_MouseAbs = 13} INKPTR_CH9329_CmdLen;

void    INKPTR_CH9329_LoadCmd_Keyboard(void);
void    INKPTR_CH9329_LoadCmd_MouseRel(void);
void    INKPTR_CH9329_LoadCmd_MouseAbs(void);
void    INKPTR_CH9329_ClearOperation(void);

#endif