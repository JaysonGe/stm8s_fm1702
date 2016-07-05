/****************************************************************************
* �ļ�����LCMDRV.H
* ���ܣ�12864ͼ��Һ��ģ����������
*       ����ZLG/GUI�û�ͼ�ν��档
*
*  ���ߣ����ܱ�
*  ���ڣ�2005/3/7
****************************************************************************/
#ifndef  LCMDRV_H
#define  LCMDRV_H


/* ������ɫ��������(���������ݽṹ) */
#define  TCOLOR	  UINT8 		//�����޸ģ�ԭ����	UINT8 

/* ����LCM�������� */
#define  GUI_LCM_XMAX		128				//�����޸�			/* ����Һ��x��������� */
#define  GUI_LCM_YMAX		64				//�����޸�			/* ����Һ��y��������� */


void  GUI_Initialize(void);
void  GUI_FillSCR(TCOLOR dat);
void  GUI_ClearSCR(void);
void  GUI_Point(UINT16 x, UINT8 y, TCOLOR color);
UINT8  GUI_ReadPoint(UINT16 x, UINT8 y, TCOLOR *ret);
void  GUI_HLine(UINT16 x0, UINT8 y0, UINT16 x1, TCOLOR color);
void  GUI_RLine(UINT16 x0, UINT8 y0, UINT8 y1, TCOLOR color);
void  GUI_Exec(void);

/****************************************************************************
* ���ƣ�GUI_CmpColor()
* ���ܣ��ж���ɫֵ�Ƿ�һ�¡�
* ��ڲ�����color1		��ɫֵ1
*		   color2		��ɫֵ2
* ���ڲ���������1��ʾ��ͬ������0��ʾ����ͬ��
* ˵����������ɫ����TCOLOR�����ǽṹ���ͣ�������Ҫ�û���д�ȽϺ�����
****************************************************************************/
#define  GUI_CmpColor(color1, color2)	( (color1&0x01) == (color2&0x01) )

/****************************************************************************
* ���ƣ�GUI_CopyColor()
* ���ܣ���ɫֵ���ơ�
* ��ڲ�����color1		Ŀ����ɫ����
*		   color2		Դ��ɫ����
* ���ڲ�������
* ˵����������ɫ����TCOLOR�����ǽṹ���ͣ�������Ҫ�û���д���ƺ�����
****************************************************************************/
#define  GUI_CopyColor(color1, color2) 	*color1 = color2



#endif
