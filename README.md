# Win32Lab5
В данной лабораторной реализован будильник, который берет значение из файла l5.txt (изначально в файле 0), два потока "одновременно"
изменяют значение на единицу.
Через каждый период будильник берет значение из файла и Beep() столько раз, сколько в данный момент времени было записано в файле. 
Способ синхронизации потоков - mutex. В лобораторной я использовал C++11 : #include <mutex>, но также можно реализовать через <windwos.h>
(WaitForSingleObject).
Данная лабораторная - последняя. Но при желани  факультативно будет и 6-я.
