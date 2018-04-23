#include <reg52.h>
#define PINLV     	11059200UL			 		//ʹ��11.0592M����
#define BAUD_9600   9600UL		     			//�����ʶ���Ϊ9600
/***************************************************
*								���ڳ�ʼ���Ӻ���
*				T1�����ڷ�ʽ2��������9600���������ж�
****************************************************/
void UART_INIT(void)				//���ڳ�ʼ��
{
//	EA=0; 					//��ʱ�ر��ж�
	TMOD=0x20;    	//��ʱ��1������ģʽ2���Զ���װģʽ
	SCON=0x50;     //���ڹ�����ģʽ1
	TH1=256-PINLV/(BAUD_9600*12*16);  //���㶨ʱ����װֵ
	TL1=256-PINLV/(BAUD_9600*12*16);
	PCON|=0x80;    //���ڲ����ʼӱ�
	TR1=1;        	//������ʱ��1

}

/***************************************************
*								���ڷ����ֽ��Ӻ���
*				���ν�����HELLO[]�е�Ԫ�ط��͸�����
****************************************************/
void uart_send_byte(unsigned char i)
{
		SBUF = i;	//���뷢�ͻ���Ĵ���
		while(TI == 0);		//�жϷ����Ƿ����
		TI = 0;						//����жϱ�־
}