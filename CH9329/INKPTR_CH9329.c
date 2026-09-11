#include "INKPTR_CH9329.h"

INKPTR_CH9329_Operation_TypeDef INKPTR_CH9329_Operation = {0};
uint8_t INKPTR_CH9329_SerialCmd[14] = {0};

void INKPTR_CH9329_LoadCmd_Keyboard(void)
{
    uint8_t i, m;
    const uint8_t DataHead[5] = {0x57, 0xab, 0x00, 0x02, 0x08};
    
    for(i = 0 ; i < 5 ; i++)    {INKPTR_CH9329_SerialCmd[i] = DataHead[i];}
    INKPTR_CH9329_SerialCmd[5]  = INKPTR_CH9329_Operation.Ctrl_or_Mouse_Key;
    INKPTR_CH9329_SerialCmd[6]  = 0x00;
    for(i = 0 ; i < 6 ; i++)
    {
        m = 1;
        if((INKPTR_CH9329_Operation.Key[i] >= 0x21) && (INKPTR_CH9329_Operation.Key[i] <= 0x24))    {INKPTR_CH9329_SerialCmd[i+7] = INKPTR_CH9329_Operation.Key[i] + 7;     m = 0;}
        if((INKPTR_CH9329_Operation.Key[i] >= 'A') && (INKPTR_CH9329_Operation.Key[i] <= 'Z'))      {INKPTR_CH9329_SerialCmd[i+7] = INKPTR_CH9329_Operation.Key[i] - 0x3d;  m = 0;}
        if((INKPTR_CH9329_Operation.Key[i] >= '1') && (INKPTR_CH9329_Operation.Key[i] <= '9'))      {INKPTR_CH9329_SerialCmd[i+7] = INKPTR_CH9329_Operation.Key[i] - 0x13;  m = 0;}
        if(INKPTR_CH9329_Operation.Key[i] > 0x60)                                                   {INKPTR_CH9329_SerialCmd[i+7] = INKPTR_CH9329_Operation.Key[i] - 0x28;  m = 0;}
        if(m)
        {
            switch(INKPTR_CH9329_Operation.Key[i])
            {
                case '0':   {INKPTR_CH9329_SerialCmd[i+7] = 0x27;   break;}
                case ' ':   {INKPTR_CH9329_SerialCmd[i+7] = 0x2c;   break;}
                case '-':   {INKPTR_CH9329_SerialCmd[i+7] = 0x2d;   break;}
                case '=':   {INKPTR_CH9329_SerialCmd[i+7] = 0x2e;   break;}
                case '[':   {INKPTR_CH9329_SerialCmd[i+7] = 0x2f;   break;}
                case ']':   {INKPTR_CH9329_SerialCmd[i+7] = 0x30;   break;}
                case '\\':  {INKPTR_CH9329_SerialCmd[i+7] = 0x31;   break;}
                case ';':   {INKPTR_CH9329_SerialCmd[i+7] = 0x33;   break;}
                case '\'':  {INKPTR_CH9329_SerialCmd[i+7] = 0x34;   break;}
                case '`':   {INKPTR_CH9329_SerialCmd[i+7] = 0x35;   break;}
                case ',':   {INKPTR_CH9329_SerialCmd[i+7] = 0x36;   break;}
                case '.':   {INKPTR_CH9329_SerialCmd[i+7] = 0x37;   break;}
                case '/':   {INKPTR_CH9329_SerialCmd[i+7] = 0x38;   break;}
                default:    {INKPTR_CH9329_SerialCmd[i+7] = 0x00;}
            }
        }
    }
    INKPTR_CH9329_SerialCmd[13] = INKPTR_CH9329_SerialCmd[5] + 0x0c;
    for(i = 0 ; i < 6 ; i++)    {INKPTR_CH9329_SerialCmd[13] += INKPTR_CH9329_SerialCmd[i+7];}
}

void INKPTR_CH9329_LoadCmd_MouseRel(void)
{
    uint8_t i;
    const uint8_t DataHead[6] = {0x57, 0xab, 0x00, 0x05, 0x05, 0x01};

    for(i = 0 ; i < 6 ; i++)    {INKPTR_CH9329_SerialCmd[i] = DataHead[i];}

    INKPTR_CH9329_SerialCmd[6]  = INKPTR_CH9329_Operation.Ctrl_or_Mouse_Key;
    INKPTR_CH9329_SerialCmd[7]  = (uint8_t)INKPTR_CH9329_Operation.MouseRel_X;
    INKPTR_CH9329_SerialCmd[8]  = (uint8_t)INKPTR_CH9329_Operation.MouseRel_Y;
    INKPTR_CH9329_SerialCmd[9]  = (uint8_t)INKPTR_CH9329_Operation.MouseWheel;

    INKPTR_CH9329_SerialCmd[10] = 0x0d;
    for(i = 0 ; i < 4 ; i++)    {INKPTR_CH9329_SerialCmd[10] += INKPTR_CH9329_SerialCmd[i+6];}
}

void INKPTR_CH9329_LoadCmd_MouseAbs(void)
{
    uint8_t i;
    const uint8_t DataHead[6] = {0x57, 0xab, 0x00, 0x04, 0x07, 0x02};
    uint16_t Temp_X, Temp_Y;

    for(i = 0 ; i < 6 ; i++)    {INKPTR_CH9329_SerialCmd[i] = DataHead[i];}

    INKPTR_CH9329_SerialCmd[6]  = INKPTR_CH9329_Operation.Ctrl_or_Mouse_Key;
    Temp_X = (uint16_t)((uint32_t)4096 * INKPTR_CH9329_Operation.MouseAbs_X / INKPTR_CH9329_ScreenResolution_X);    if(Temp_X > 4095) {Temp_X = 4095;}
    Temp_Y = (uint16_t)((uint32_t)4096 * INKPTR_CH9329_Operation.MouseAbs_Y / INKPTR_CH9329_ScreenResolution_Y);    if(Temp_Y > 4095) {Temp_Y = 4095;}
    INKPTR_CH9329_SerialCmd[7]  = (uint8_t)Temp_X;
    INKPTR_CH9329_SerialCmd[8]  = (uint8_t)(Temp_X>>8);
    INKPTR_CH9329_SerialCmd[9]  = (uint8_t)Temp_Y;
    INKPTR_CH9329_SerialCmd[10] = (uint8_t)(Temp_Y>>8);
    INKPTR_CH9329_SerialCmd[11] = (uint8_t)INKPTR_CH9329_Operation.MouseWheel;

    INKPTR_CH9329_SerialCmd[12] = 0x0f;
    for(i = 0 ; i < 6 ; i++)    {INKPTR_CH9329_SerialCmd[12] += INKPTR_CH9329_SerialCmd[i+6];}
}

void INKPTR_CH9329_ClearOperation(void)
{
    uint8_t i;
    INKPTR_CH9329_Operation.Ctrl_or_Mouse_Key   = 0x00;
    for(i = 0 ; i < 6 ; i++)    {INKPTR_CH9329_Operation.Key[i] = 0x00;}
    INKPTR_CH9329_Operation.MouseWheel          = 0x00;
    INKPTR_CH9329_Operation.MouseRel_X          = 0x00;
    INKPTR_CH9329_Operation.MouseRel_Y          = 0x00;
    INKPTR_CH9329_Operation.MouseAbs_X          = 0x00;
    INKPTR_CH9329_Operation.MouseAbs_Y          = 0x00;
}