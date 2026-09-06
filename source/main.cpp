#include <switch.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    consoleInit(NULL);
    
    printf("\x1b[2J");
    printf("\x1b[16;20H");
    printf("Hello, Nintendo Switch!");
    printf("\x1b[18;15H");
    printf("Press PLUS to exit.");
    
    while (appletMainLoop()) {
        hidScanInput();
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
        
        if (kDown & KEY_PLUS) {
            break;
        }
        
        consoleUpdate(NULL);
    }
    
    consoleExit(NULL);
    return 0;
}
