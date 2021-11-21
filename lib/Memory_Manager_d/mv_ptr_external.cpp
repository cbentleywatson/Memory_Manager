//(int (*)()) external;
/*
int (*void_88_flash)(){&int_void_88};

void *external = heap_caps_malloc(1000, EXTERNAL || MALLOC_CAP_EXEC);
memcpy(external, void_88_flash, 300);
int (*void_21_flash)(){&int_void_21};
void_21_flash = (int (*)())external;
Serial.print("void_21_flash after ld from flash: ");
Serial.println(void_21_flash());

// direct run from external
  int (*f_external)() = (int (*)())external;
  Serial.print("Printing directly from external: ");
  Serial.println(f_external());


*/