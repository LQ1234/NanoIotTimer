#pragma once
#include "Arduino.h"

#include "globals.h"
#include "tcWrapperBase.h"
namespace TimerTimeout
{
    struct TimeoutInterval{//wrapper for a TimeoutInterval_TC, not required for interrupt to function
        TC_Wrapper_Base* tc_ref;
        TimeoutInterval(TC_Wrapper_Base* _tc_ref){
            tc_ref=_tc_ref;
        }
        void clear(){
            tc_ref->stop();
        }
        void restartWithTime(int time){
            tc_ref->setValue(time);
            tc_ref->restart();
        }
        int timeTilTrigger(){
            return(tc_ref->getValue());
        }
        void setISR(void (*isr)(TimeoutInterval)){
            tc_ref->isr=isr;
        }
    };
}
