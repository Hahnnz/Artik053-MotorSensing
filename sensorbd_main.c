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
	printf(" %s test        : test Module shifting\n", program);
	printf(" %s init        : initialize Module shifting\n", program);
	printf(" %s alloff      : turn off all of Module power\n", program);
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

int Module_Shifting(int argc, FAR char *argv[]){
	int ret = 0;

	switch (argc) {
	case 2:
		if (strcmp(argv[1], "test") == 0) {
			Module_Test();	//모듈 작동 테스
		}
		if (strcmp(argv[1], "alloff") == 0) {
			ModuleShifting_Horizontal(1,"SuperOff","none","none"); // 모듈 전체 작동 중
		} else if (strcmp(argv[1], "init") == 0) {
			ModuleInitializing_Horizontal(); // 모듈 초기
		} else {
			show_usage(argv[0]); // 이외 다른 명령어 입력시 가능 인자 보여주
		}
		break;

	default:
		show_usage(argv[0]);
		break;
	}

	return ret;
}

int main(int argc, FAR char *argv[]){

	tash_cmd_install("module", Module_Shifting, TASH_EXECMD_SYNC);

	return 0;
}
// Pin Info
// Width : 1-1 / 2-4 / 3-2 / 4-3 / 5-5
// height : 1-51 / 2-52 / 3-53
