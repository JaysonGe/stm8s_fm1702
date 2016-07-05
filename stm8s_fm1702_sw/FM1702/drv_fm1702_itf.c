#include "iostm8s105k6.h"
#include "drv_fm1702_itf.h"
#include "drive_spi.h"

void drv_fm1702ItfGpioInit(void)
{
	drv_spiInit();
}

void drv_fm1702ItfClearReset(void)
{
	PC_ODR_ODR2 = 0;
}

void drv_fm1702ItfSetReset(void)
{
	PC_ODR_ODR2 = 1;
}

void drv_fm1702ItfClearCs(void)
{
	PC_ODR_ODR4 = 0;
}

void drv_fm1702ItfSetCs(void)
{
	PC_ODR_ODR4 = 1;
}

//=======================================================
//	���ƣ�	drv_fm1702ItfReadByte
//	���ܣ�	SPI��ȡ����
//	���:
//		addr:	Ҫ��ȡ��FM1702SL�ڵļĴ�����ַ[0x01~0x3f]
//	����:
//	˵����Ϊ������ٶȣ��Ե�ַ����Ч�Բ������
//========================================================
UINT8 drv_fm1702ItfReadByte(UINT8 addr)
{
    UINT8 rdata;
    
    drv_fm1702ItfClearCs();
	
    addr <<= 1;
    addr |= 0x80;
	
	drv_spiReadWriteByte(addr);
	rdata = drv_spiReadWriteByte(0x00);
	
    drv_fm1702ItfSetCs();
    
    return (rdata);
}

void drv_fm1702ItfRead(UINT8 addr, UINT8* dat, UINT8 len)
{
	if(len == 0)
	{
		return;
	}
	
    drv_fm1702ItfClearCs();
	
    addr <<= 1;
    addr |= 0x80;
	
	drv_spiReadWriteByte(addr);
	
	while(len--)
	{
		*dat++ = drv_spiReadWriteByte(addr);
	}
	
	drv_fm1702ItfSetCs();
}


//=======================================================
//	���ƣ�drv_fm1702ItfWriteOneByte
//	���ܣ�SPIд�����
//	���:	addr:	Ҫд��FM1702SL�ڵļĴ�����ַ[0x01~0x3f]
//          wData ��  	Ҫд�������
//	����:
//	˵����Ϊ������ٶȣ��Ե�ַ����Ч�Բ������
//========================================================
void drv_fm1702ItfWriteByte(UINT8 addr, UINT8 byte)
{
    drv_fm1702ItfClearCs();
	
    addr <<= 1;
    addr &= 0x7E;

	drv_spiReadWriteByte(addr);
	
	drv_spiReadWriteByte(byte);
	
    drv_fm1702ItfSetCs();
}

void drv_fm1702ItfWrite(UINT8 addr, UINT8* dat, UINT8 len)
{
	if(len == 0)
	{
		return ;
	}
	
    drv_fm1702ItfClearCs();
	
    addr <<= 1;
    addr &= 0x7E;

	drv_spiReadWriteByte(addr);
	
	while(len--)
	{
		drv_spiReadWriteByte(*dat++);
	}
	
    drv_fm1702ItfSetCs();
}
