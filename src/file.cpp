#include "file.h"

void file_init() {
    Serial.println("initializing file system");
    if (!LittleFS.begin()) {
        Serial.println("LittleFS mount failed");
        return;
    }
}

void file_append(const char *message) {
    Serial.printf("writing to file: %s\n", FILE_MOISTURE);
    File file = LittleFS.open(FILE_MOISTURE, "a");
   
    if (!file) {
        Serial.println("open failed");
        return;
    }

    if (!file.print(message)) {
        Serial.println("write failed");
    }

    file.close();
}

String file_read() {
    Serial.printf("reading file: %s\n", FILE_MOISTURE);

    File file = LittleFS.open(FILE_MOISTURE, "r");
    if (!file) {
        Serial.println("open failed");
        return "";
    }

    String content = file.readString();

    // while (file.available()) {
    //     Serial.write(file.read());
    // }
    file.close();
    return content;
}

void file_delete() {
    Serial.printf("deleting file: %s\n", FILE_MOISTURE);
    if (!LittleFS.remove(FILE_MOISTURE)) {
        Serial.println("delete failed");
    }
}