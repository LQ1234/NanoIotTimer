#include "src/timerTimeoutInterval.h"

using TimerTimeout::TimeoutInterval;
using TimerTimeout::setTimeout;
using TimerTimeout::setInterval;

int ledPin = 13;
bool ledState=0;

char msg[256];

int test1_counts[6];
char test1_str[]="test1: hello 0";

#define CONCAT(a, b) a ## b

#define MAKE_TEST_1_FUNC(idx) \
void CONCAT(test1_,idx) (TimeoutInterval* tt){ \
	test1_str[13]='0'+test1_counts[idx]; \
	test1_str[4]='0'+idx; \
	strcpy(msg,test1_str); \
	test1_counts[idx]++; \
	if(test1_counts[idx]<10) setTimeout(CONCAT(test1_,idx),100); \
}

MAKE_TEST_1_FUNC(0)
MAKE_TEST_1_FUNC(1)
MAKE_TEST_1_FUNC(2)
MAKE_TEST_1_FUNC(3)
MAKE_TEST_1_FUNC(4)
MAKE_TEST_1_FUNC(5)

void test0_0(TimeoutInterval* tt){
	strcpy(msg,"test0_0: hello");
}
void test0_1(TimeoutInterval* tt){
	strcpy(msg,"test0_1: hello");
}
TimeoutInterval* test0_0_ti;
TimeoutInterval* test0_1_ti;

void setup(){
	SerialUSB.begin(9600);
	while (!SerialUSB.available());

	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin,ledState);

	TimerTimeout::begin();

	setTimeout([](TimeoutInterval* tt){
		test0_0_ti=setInterval(test0_0,310);
		test0_1_ti=setInterval(test0_1,300);
		strcpy(msg,"Test 0:");

		setTimeout([](TimeoutInterval* tt){
			test0_1_ti->clear();
			test0_0_ti->clear();

			strcpy(msg,"Clearing test 0 intervals...");

		},2500);
	},10);

	setTimeout([](TimeoutInterval* tt){
		strcpy(msg,"Test 1: ");

		char is_used[]="f f f f f f";
		for(int i=0;i<6;i++){
			if(TimerTimeout::timeoutIntervals[i]->isr) is_used[i*2]='t';
		}
		strcpy(msg+8,is_used);

		setTimeout(test1_0,0);
		setTimeout(test1_1,1);
		setTimeout(test1_2,2);
		setTimeout(test1_3,3);
		setTimeout(test1_4,4);
		setTimeout(test1_5,5);
	},3000);
}

void loop(){
	if(msg[0]){
		SerialUSB.println(msg);
		memset(msg, 0, 256);
	}
}
