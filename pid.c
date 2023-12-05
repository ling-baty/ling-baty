/***************************************
This file is for PID control.
****************************************/

#include <stdio.h>

struct _pid
{
	float SetSpeed;
	float ActSpeed;
	float err;
	float err_last;
	float Kp, Ki, Kd;
	float voltage;
	float integral;
} pid;

void init_PID(void)
{
	printf("init_PID start.\n");
	pid.SetSpeed = 0.0;
	pid.ActSpeed = 0.0;
	pid.err = 0.0;
	pid.err_last = 0.0;
	pid.Ki = 0.2;
	pid.Ki = 0.015;
	pid.Kd = 0.2;
	pid.voltage = 0.0;
	pid.integral = 0.0;
	printf("init_PID end.\n");
}

float control_PID(float speed)
{
	pid.SetSpeed = speed;
	pid.err = pid.SetSpeed - pid.ActSpeed;
	pid.integral += pid.err;
	pid.ActSpeed = pid.Kp*pid.err + pid.Ki*pid.integral + pid.Kd*(pid.err - pid.err_last);
	pid.err_last = pid.err;
	pid.voltage = pid.ActSpeed*1.0;
	return pid.voltage;
}

int main(void)
{
	int count = 0;
	float speed1 = 200.0, actspeed;
	init_PID();
	
	while (count < 1500)
	{
		actspeed = control_PID(speed1);	
		printf("count = %d, actspeed = %f\n", count, actspeed);
		count ++;
	} 
	return 0;
}