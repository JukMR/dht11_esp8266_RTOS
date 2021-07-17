/*
 * ESPDataLogger.c
 *
 *  Created on: May 26, 2020
 *      Author: controllerstech
 */

#include "UartRingbuffer.h"
#include "ESPDataLogger.h"
#include "stdio.h"
#include "string.h"

extern UART_HandleTypeDef huart1;

#define wifi_uart &huart1


void bufclr (char *buf)
{
	int len = strlen (buf);
	for (int i=0; i<len; i++) buf[i] = '\0';
}


//void ESP_Init (char *SSID, char *PASSWD)
//{
//	char data[80];
//
//	Ringbuf_init();
//
//	Uart_sendstring("AT+RST\r\n");
//	HAL_Delay(1000);
//
//	Uart_flush();
//
//	/********* AT **********/
//	Uart_sendstring("AT\r\n");
//	while(!(Wait_for("OK\r\n")));
//
//	Uart_flush();
//
//
//	/********* AT+CWMODE=1 **********/
//	Uart_sendstring("AT+CWMODE=1\r\n");
//	while (!(Wait_for("OK\r\n")));
//
//	Uart_flush();
//
//
//	/********* AT+CWJAP="SSID","PASSWD" **********/
//	sprintf (data, "AT+CWJAP=\"%s\",\"%s\"\r\n", SSID, PASSWD);
//	Uart_sendstring(data);
//	while (!(Wait_for("GOT IP\r\n")));
//
//	Uart_flush();
//
//	/********* AT+CIPMUX=0 **********/
//	Uart_sendstring("AT+CIPMUX=0\r\n");
//	while (!(Wait_for("OK\r\n")));
//
//	Uart_flush();
//
//}

void ESP_Send_Data (char *APIkey, int Field_num, uint16_t value)
{
	char local_buf[100] = {0};
	char local_buf2[30] = {0};

	char Link_ID;
	while (!(Get_after("+IPD,", 1, &Link_ID, wifi_uart)));
	Link_ID -= 48;

	Uart_sendstring("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n", wifi_uart);
	while (!(Wait_for("OK\r\n", wifi_uart)));

	sprintf (local_buf, "GET /update?api_key=%s&field%d=%u\r\n", APIkey, Field_num, value);
	int len = strlen (local_buf);

	sprintf (local_buf2, "AT+CIPSEND=%d,%d\r\n", Link_ID, len);
	Uart_sendstring(local_buf2, wifi_uart);
	while (!(Wait_for(">", wifi_uart)));

	Uart_sendstring (local_buf, wifi_uart);
	while (!(Wait_for("SEND OK\r\n", wifi_uart)));

	while (!(Wait_for("CLOSED", wifi_uart)));

	bufclr(local_buf);
	bufclr(local_buf2);

	Ringbuf_init();

}

void ESP_Send_Multi (char *APIkey, int numberoffileds, float value[])
{
	char local_buf[500] = {0};
	char local_buf2[30] = {0};
	char field_buf[200] = {0};

//	char Link_ID;
//	while (!(Get_after("+IPD,", 1, &Link_ID, wifi_uart)));
//	Link_ID -= 48;

	Uart_sendstring("AT+CIPSTART=2,\"TCP\",\"184.106.153.149\",80\r\n", wifi_uart);
	while (!(Wait_for("OK\r\n", wifi_uart)));

	sprintf (local_buf, "GET /update?api_key=%s", APIkey);
	for (int i=0; i<numberoffileds; i++)
	{
		sprintf(field_buf, "&field%d=%f",i+1, value[i]);
		strcat (local_buf, field_buf);
	}

	strcat(local_buf, "\r\n");
	int len = strlen (local_buf);

	sprintf (local_buf2, "AT+CIPSEND=2,%d\r\n", len);
	Uart_sendstring(local_buf2, wifi_uart);
	while (!(Wait_for(">", wifi_uart)));

	Uart_sendstring (local_buf, wifi_uart);
	while (!(Wait_for("SEND OK\r\n", wifi_uart)));

	while (!(Wait_for("CLOSED", wifi_uart)));

	bufclr(local_buf);
	bufclr(local_buf2);

	Ringbuf_init();

}
