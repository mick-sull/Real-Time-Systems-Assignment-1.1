#define MESS_SZ 30
struct CommData
{
 char From[3];
 int MessageNumber;
 char Message[MESS_SZ];
 char EndOfMessage;
 int  Temp;
 int  Pressure;
 char  ValveOpen[1];
 int  WaterLevel
 };

#define MESSAGE_SIZE sizeof(struct CommData)