#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define pathToGovernor "/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"

int isProcessRunning(const char *nameOfProcess) {
    // Use 'pgrep' via a pipe
    char command[128];
    sprintf(command, "pgrep %s > /dev/null", nameOfProcess);

    return (system(command)== 0); // Return 1 if found
}

int main() {
    printf("Starting Selective Resource Governor");
    return 0;
}