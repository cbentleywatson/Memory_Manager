#import os
#from pathlib import Path, PurePath
#obj_copy_path = "../../Linker_Experiments/esp_bin/xtensa-esp32-elf-objcopy.exe"
# path to 
#ls ../
#ls ../../../.pio/build/lolin_d32_pro/src
#../../../Linker_Experiments/esp_bin/xtensa-esp32-elf-objcopy.exe -j .test.sort.text=sort  ../../../.pio/build/lolin_d32_pro/src/main.cpp.o
# For test sections
#../../../.pio/build/lolin_d32_pro/test/test_sections.cpp.o
# for main
# ../../../.pio/build/lolin_d32_pro/src/main.cpp.o 

#../../../Linker_Experiments/esp_bin/xtensa-esp32-elf-objdump.exe -h ../../../.pio/build/lolin_d32_pro/test/test_sections/test_sections.cpp.o
#../../../Linker_Experiments/esp_bin/xtensa-esp32-elf-objdump.exe -h  ../../../.pio/build/lolin_d32_pro/test/test_sections/test_sections.cpp.o

# copies section 4 into a new file named test4
clear
#../../../Linker_Experiments/esp_bin/xtensa-esp32-elf-objcopy.exe -j .test4.text  ../../../.pio/build/lolin_d32_pro/firmware.elf test4
../../../Linker_Experiments/esp_bin/xtensa-esp32-elf-objdump.exe -h  ../../../.pio/build/lolin_d32_pro/firmware.elf
# copies the section into the loadab
#mv test4 newtest4
# when the data folder is used for flash uploads this command will put things in the right folder
cp newtest4 ../../../data
# when SD uploads are used the sd folder will be used, so the file will go here and then to the sd
cp newtest4 SD_Uploads
