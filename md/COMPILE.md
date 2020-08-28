## คอมไพล์ C++
การคอมไพล์โปรแกรม ประกอบด้วย 3 อย่าง
1. **Preprocess**
    * [#include](#include)
    * [#define](#define)
    * [#ifndef](#ifndef)
2. **Compiler**
3. **Linker**

## include
* ไลบรารี C++
```cpp
#include <iostream>
```
* ไลบรารี C
```cpp
#include <cstdio>
```
* ฟังก์ชันสร้างเอง
```cpp
#include "mehaeder.h"
```

## define
```cpp
#define MAX 10
#define CALL call()
```

## ifndef
* ป้องกันเรียกใช้(#include)งานซ้ำซ้อน
```cpp
//Haeder Guard
#ifndef ME_H
#define ME_H
//....
#endif
```