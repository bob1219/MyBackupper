#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* Process a command */
int
CommandProcess
(const char**);

/* Print a list of settings */
int
PrintList
(const char*);

/* Addition a setting */
int
AdditionSetting
(const char*,
const char*,
const char*);

/* Clear settings */
int
ClearSetting
(const char*);

/* Run backup */
int
backup
(const char*);

#endif
