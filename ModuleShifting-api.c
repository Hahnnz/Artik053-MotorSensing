#include <stdio.h>
#include <apps/shell/tash.h>
#include <fcntl.h>
#include <tinyara/gpio.h>

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

void ModuleInitializing_Horizontal(){	//모듈 초기화 함
	printf("Module Initializing..\n");
	int GPIO_NUM = 37;	//가로의  첫 모듈 번호
	while(true){ //가로의 첫 모듈번호 부터 끝 번호까지 신호 입력
		if(GPIO_NUM==42) break;
		gpio_write(GPIO_NUM, 1);
		GPIO_NUM++;
	}
	GPIO_NUM=51; // 세로의 첫 모듈 번호
	while(true){ //세로의 첫 모듈번호 부터 끝 번호까지 신호 입력
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
	if (WorH=="width") GPIO_NUM = ModuleNum+36; //가로 GPIO Number 설정
	else if (WorH=="height") GPIO_NUM = ModuleNum+50; //세로 GPIO Number 설정

	if(Mode == "On"){ //모듈 작동
		gpio_write(GPIO_NUM, 1);
		if (LorR=="left") gpio_write(54, 1); //왼쪽 모듈 움직임설정
		else if (LorR=="right") gpio_write(55, 1); // 오른쪽 모듈 움직임 설정
	}
	else if (Mode == "Off"){ //모듈 끄기
		gpio_write(GPIO_NUM, 0);
		if (LorR=="left") gpio_write(54, 0);  //왼쪽 모듈 움직임설정
		else if (LorR=="right") gpio_write(55, 0);  //왼쪽 모듈 움직임설정
	}
	else if (Mode == "SuperOff" && WorH=="none" && LorR=="none"){  // 모듈 전체 끄기 함수
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

void Module_Test(){
	int i=0;
	ModuleInitializing_Horizontal();
	up_mdelay(100);
	ModuleShifting_Horizontal(1,"SuperOff","none","none");
	up_mdelay(100);
	while(true){
		if(i==9) break;
		else if(i<6){
			ModuleShifting_Horizontal(i,"On","width","left");
			up_mdelay(100);
			ModuleShifting_Horizontal(i,"Off","width","left");
			up_mdelay(100);
			ModuleShifting_Horizontal(i,"On","width","right");
			up_mdelay(100);
			ModuleShifting_Horizontal(i,"Off","width","right");
			up_mdelay(100);
			i++;
		}
		else if(i>5){
			int j=i-5;
			ModuleShifting_Horizontal(j,"On","height","left");
			up_mdelay(1000);
			ModuleShifting_Horizontal(j,"Off","height","left");
			up_mdelay(1000);
			ModuleShifting_Horizontal(j,"On","height","right");
			up_mdelay(1000);
			ModuleShifting_Horizontal(j,"Off","height","right");
			up_mdelay(100);
			i++;
		}
	}
	ModuleShifting_Horizontal(0,"SuperOff","none","none");
	up_mdelay(500);
	ModuleInitializing_Horizontal();
}

