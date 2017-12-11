/****************************************************************************
 *
 * Copyright 2017 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/

#include <stdio.h>
#include <apps/shell/tash.h>
#include <fcntl.h>
#include <tinyara/gpio.h>
int GPIO[10];
static void show_usage(FAR const char *program)
{
	printf("USAGE:\n");
	printf(" %s led        : gpio led on/off test\n", program);
	printf(" %s ledpwm     : pwm led on/off test\n", program);
	printf(" %s ledst      : gpio starter board led test\n", program);
	printf(" %s uart       : uart loopback test\n", program);
	printf(" %s gpio       : gpio loopback test\n", program);
	printf(" %s button     : gpio button interrupt test\n", program);
	printf(" %s pwm        : pwm buzzer test\n", program);
	printf(" %s tcs34725   : i2c rgb sensor(tcs34725) test\n", program);
	printf(" %s mpu9250    : i2c 9-axis motion tracking sensor(MPU9250) test\n", program);
	printf(" %s k6ds3      : spi 6-axis acceler sensor(K6DS3) test\n", program);
	printf(" %s lis3lv02qd : spi 3-axis acceler sensor(LIS3LV02QD) test\n", program);
	printf(" %s adctest    : adc print all channel value\n", program);
	printf(" %s ModuleWork_Horizontal    :  Move Module stick up or down\n", program);
}

#ifdef CONFIG_BUILD_KERNEL
int main(int argc, FAR char *argv[])
#else
int sensorbd_main(int argc, FAR char *argv[])
#endif
{
	int ret = 0;

	switch (argc) {
	case 2:
		if (strcmp(argv[1], "led") == 0) {
			ledonoff_main(argc, argv);
		} else if (strcmp(argv[1], "ledpwm") == 0) {
			ledpwm_main(argc, argv);
		} else if (strcmp(argv[1], "ledst") == 0) {
			starterled_main(argc, argv);
		} else if (strcmp(argv[1], "uart") == 0) {
			uartloopback_main(argc, argv);
		} else if (strcmp(argv[1], "gpio") == 0) {
			gpioloopback_main(argc, argv);
		} else if (strcmp(argv[1], "button") == 0) {
			switch_main(argc, argv);
		} else if (strcmp(argv[1], "pwm") == 0) {
			pwmbuzzer_main(argc, argv);
		} else if (strcmp(argv[1], "tcs34725") == 0) {
			tcs34725_main(argc, argv);
		} else if (strcmp(argv[1], "mpu9250") == 0) {
			mpu9250_main(argc, argv);
		} else if (strcmp(argv[1], "k6ds3") == 0) {
			k6ds3_main(argc, argv);
		} else if (strcmp(argv[1], "lis3lv02qd") == 0) {
			lis3lv02qd_main(argc, argv);
		} else if (strcmp(argv[1], "adctest") == 0) {
			adctest_main(argc, argv);
		} else if (strcmp(argv[1], "ModuleWork_Horizontal") == 0) {
			ModuleShifting_Horizontal(1, "Off");
		} else {
			show_usage(argv[0]);
		}
		break;

	default:
		show_usage(argv[0]);
		break;
	}

	return ret;
}
static void gpio_write(int port, int value)
{
	char str[4];
	static char devpath[16];
	snprintf(devpath, 16, "/dev/gpio%d", port);
	int fd = open(devpath, O_RDWR);
	ioctl(fd, GPIOIOC_SET_DIRECTION, GPIO_DIRECTION_OUT);
	write(fd, str, snprintf(str, 4, "%d", value != 0) + 1);
	close(fd);
}

void ModuleInitializing_Horizontal(){
	printf("Module Initializing..\n");
	int GPIO_NUM = 37;
	while(true){
		if(GPIO_NUM==42) break;
		gpio_write(GPIO_NUM, 128);
		GPIO_NUM++;
	}
	GPIO_NUM=51;
	while(true){
		if(GPIO_NUM==54) break;
		gpio_write(GPIO_NUM, 1);
		GPIO_NUM++;
	}
	printf("Done\n");
}

void ModuleShifting_Horizontal(int ModuleNum,char Mode[],char WorH[], char LorR[])
//WorH : "width" "height" "none"
//LorR : "left":54 "right":55 "Off" "All"
{
	int a=0;
	int GPIO_NUM=0;
	if (WorH=="width") GPIO_NUM = ModuleNum+36;
	else if (WorH=="height") GPIO_NUM = ModuleNum+50;

	if(Mode == "On"){
		gpio_write(GPIO_NUM, 128);
		if (LorR=="left") gpio_write(54, 128);
		else if (LorR=="right") gpio_write(55, 128);
	}
	else if (Mode == "Off"){
		gpio_write(GPIO_NUM, 0);
		if (LorR=="left") gpio_write(54, 0);
		else if (LorR=="right") gpio_write(55, 0);
	}
	else if (Mode == "SuperOff" && WorH=="none" && LorR=="none"){
		printf("Super Power Off\n");
		gpio_write(54,0);	//Left
		gpio_write(55,0);	//Right
		while(true){
			if(a==9) break;
			else if(a<6){
				gpio_write(GPIO_NUM+37+a, 0);
				a++;
			}
			else if(a>5){
				int b=a-5;
				gpio_write(GPIO_NUM+50+b, 0);
				a++;
			}
		}
	}
}

int main(int argc, FAR char *argv[]){
	int i=0;
	tash_cmd_install("sensorbd", sensorbd_main, TASH_EXECMD_SYNC);

	ModuleInitializing_Horizontal();
	up_mdelay(500);
	ModuleShifting_Horizontal(1,"SuperOff","none","none");
	up_mdelay(500);
	while(true){
		if(i==9) break;
		else if(i<6){
			ModuleShifting_Horizontal(i,"On","width","left");
			up_mdelay(250);
			ModuleShifting_Horizontal(i,"Off","width","left");
			up_mdelay(250);
			ModuleShifting_Horizontal(i,"On","width","right");
			up_mdelay(250);
			ModuleShifting_Horizontal(i,"Off","width","right");
			up_mdelay(250);
			i++;
		}
		else if(i>5){
			int j=i-5;
			ModuleShifting_Horizontal(j,"On","height","left");
			up_mdelay(250);
			ModuleShifting_Horizontal(j,"Off","height","left");
			up_mdelay(250);
			ModuleShifting_Horizontal(j,"On","height","right");
			up_mdelay(250);
			ModuleShifting_Horizontal(j,"Off","height","right");
			up_mdelay(250);
			i++;
		}
	}
	ModuleShifting_Horizontal(0,"SuperOff","none","none");
	up_mdelay(500);
	ModuleInitializing_Horizontal();

	return 0;
}
// Pin Info
// Width : 1-1 / 2-4 / 3-2 / 4-3 / 5-5
// height : 1-51 / 2-52 / 3-53
