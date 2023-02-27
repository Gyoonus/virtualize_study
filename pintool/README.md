https://github.com/JonathanSalwan/VMProtect-devirtualization

cmd : 
pin custom code : https://github.com/JonathanSalwan/VMProtect-devirtualization/blob/main/pin/source/tools/VMP_Trace/VMP_Trace.cpp
```
$ ./pin/pin -t ./pin/source/tools/VMP_Trace/obj-intel64/VMP_Trace.so -start 4198848 -end 4198895 -- ./vmp_binaries/binaries/sample2.vmp.bin 1 2 &> ./vmp_traces/sample2.vmp.trace
```
```
mr:0x7ffda459d718:8:0x227db4f8
r:0x40200a:0x0:0x7ffda459f571:0x2:0x40200a:0x0:0x0:0x7ffda459d688:0x0:0x0:0x7feee9b80ac0:0x7feee9b8000f:0xad1c3e:0x0:0x0:0x0
i:0x89173e:8:488BB42490000000
```
```
mr:0x7ffda459d718:8:0x227db4f8
메모리READ : [addr]:[length]:[value]
```
```
i:0x89173e:8:488BB42490000000
메모리EXE : [addr]:[length]:[value]
 - 488BB42490000000 : mov    rsi,QWORD PTR [rsp+0x90]
```
