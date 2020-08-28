# NanoIotTimer
JS timeout like timer library for Arduino nano iot

Usage: 
```
TimerTimeout::setTimeout(void (*isr)(TimeoutInterval*), int timeout) //timeout in ms
TimerTimeout::setInterval(void (*isr)(TimeoutInterval*),int interval) //interval in ms
```

Expected test output (from timerTimeoutInterval.ino):
```
Test 0:
test0_1: hello
test0_0: hello
test0_1: hello
test0_0: hello
test0_1: hello
test0_0: hello
test0_1: hello
test0_0: hello
test0_1: hello
test0_0: hello
test0_1: hello
test0_0: hello
test0_1: hello
test0_0: hello
test0_1: hello
test0_0: hello
Clearing test 0 intervals...
Test 1: f f f f f f
test0: hello 0
test1: hello 0
test2: hello 0
test3: hello 0
test4: hello 0
test5: hello 0
test0: hello 1
test1: hello 1
test2: hello 1
test3: hello 1
test4: hello 1
test5: hello 1
test0: hello 2
test1: hello 2
test2: hello 2
test3: hello 2
test4: hello 2
test5: hello 2
test0: hello 3
test1: hello 3
test2: hello 3
test3: hello 3
test4: hello 3
test5: hello 3
test0: hello 4
test1: hello 4
test2: hello 4
test3: hello 4
test4: hello 4
test5: hello 4
test0: hello 5
test1: hello 5
test2: hello 5
test3: hello 5
test4: hello 5
test5: hello 5
test0: hello 6
test1: hello 6
test2: hello 6
test3: hello 6
test4: hello 6
test5: hello 6
test0: hello 7
test1: hello 7
test2: hello 7
test3: hello 7
test4: hello 7
test5: hello 7
test0: hello 8
test1: hello 8
test2: hello 8
test3: hello 8
test4: hello 8
test5: hello 8
test0: hello 9
test1: hello 9
test2: hello 9
test3: hello 9
test4: hello 9
test5: hello 9
```
