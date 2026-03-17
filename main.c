#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define pathToGovernor "/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"

// Pass a pointer of type const char of the mode desired
void changeGovernor(const char *mode) {
    // Create file pointer with the path to the governor file and the ability to write
    FILE *file = fopen(pathToGovernor, "W")
    if (file == NULL) {
        perror("Error opening governor path. Make sure you are root.");
        return;
    }
    fprintf(file, "%s", mode);
    fclose(file);
    printf("System mode has been set to: %s\n", mode);
}

int isProcessRunning(const char *nameOfProcess) {
    // Use 'pgrep' via a pipe
    char command[128];
    sprintf(command, "pgrep %s > /dev/null", nameOfProcess);

    return (system(command)== 0); // Return 1 if found
}

int main() {
    printf("Starting Selective Resource Manager");

    return 0;
}