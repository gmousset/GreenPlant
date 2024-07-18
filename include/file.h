#include <LittleFS.h>

#define FILE_MOISTURE "/data/moisture.dat"

void file_init();
void file_append(const char *message);
String file_read();
void file_delete();
