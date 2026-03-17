Extension for Debian 13 that learns usage pattern of applications, and automatically adjusts CPU scaling to optimize performance

Plan for Version 1.0:

    A background loop that checks /proc/stat for CPU load.

    A function that scans the process list for "Resource Heavy" apps (like vscodium, gcc, or python).

    A system call that writes to /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor to switch from powersave to performance
