#pragma once

/*
 * Values to support:
 * d - default, no action
 * l - linux
 * w - windows
 * s - stop, wait in the menu
*/

#define CONFIG_DEFAULT 'd'
#define CONFIG_LINUX 'l'
#define CONFIG_WINDOWS 'w'
#define CONFIG_STOP 's'

void setSwitchValue(char newValue);
char getSwitchValue();