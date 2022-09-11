skrienošās rindas programma priekš stm32f401cc 

LED diodes jāpievieno pie GPIOA 1 - 7 un BPIOB 0 - 1. Tiek izmantots ārējais pārtraukums ar iebūvēto pogu uz GPIOA0, lai mainītu skriešanas virezienu

lai nokompilētu kodu vajag : 	GNU make un gcc-arm-none-eabi(https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)

pēc repozitorija lejupielades jāieiet tā Debug mapē un no komandrindas ar komandu "make all" var nokompilēt programmkodu(debug režīmam)

risinājumā iekļāvu CMSIS header failus (galvenokārt, lai tiktu galā ar pārtraukumu)

linker skripts, vektoru tabula un make faili tika ģenerēti automātiski
