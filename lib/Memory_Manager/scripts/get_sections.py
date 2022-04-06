import os
from pathlib import Path, PurePath
os.system("../../../Linker_Experiments/esp_bin/xtensa-esp32-elf-objcopy.exe -j .test.sort.text=sort  ../../../.pio/build/lolin_d32_pro_src/main.cpp.o")