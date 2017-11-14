/* Standard Libraries */
#include <stdio.h>
#include <string.h>

/* Header */
#include "macros.h"

int
PrintList
(const char *SettingName)
{
	char	FromFilePath[FILENAME_MAX], ToFilePath[FILENAME_MAX], SettingFileName[FILENAME_MAX];
	FILE	*FromFilePointer, *ToFilePointer;
	
	if(((15 + strlen(SettingName) + 1) > FILENAME_MAX) || ((13 + strlen(SettingName) + 1 ) > FILENAME_MAX))return FAILURE;
	
	/* Input path of "from" file to "FromFilePath" */
	sprintf(FromFilePath, ".%csettings%c%s%cfrom", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER, SettingName, PATH_BREAK_CHARACTER);
	
	/* Input path of "to" file to "ToFilePath" */
	sprintf(ToFilePath, ".%csettings%c%s%cto", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER, SettingName, PATH_BREAK_CHARACTER);
	
	/* Open file */
	FromFilePointer = fopen(FromFilePath,	"r");
	ToFilePointer	= fopen(ToFilePath,		"r");
	if((FromFilePointer == NULL) || (ToFilePointer == NULL))return FAILURE;
	
	printf("From\t\tTo\n");
	
	while(1)
	{
		/* Input a line from "from" file to "SettingFileName" */
		if(fgets(SettingFileName, FILENAME_MAX, FromFilePointer) == NULL)break;
		
		printf("%s", SettingFileName);
		printf("\t\t");
		
		/* Input a line from "to" file to "SettingFileName" */
		if(fgets(SettingFileName, FILENAME_MAX, ToFilePointer) == NULL)break;
		
		printf("%s\n", SettingFileName);
	}
	
	/* Close file */
	fclose(FromFilePointer);
	fclose(ToFilePointer);
	
	return SUCCESS;
}

int
AdditionSetting
(const char *SettingName,
const char *From,
const char *To)
{
	char	FromFilePath[FILENAME_MAX], ToFilePath[FILENAME_MAX];
	FILE	*FromFilePointer, *ToFilePointer;
	
	if(((15 + strlen(SettingName) + 1) > FILENAME_MAX) || ((13 + strlen(SettingName) + 1 ) > FILENAME_MAX))return FAILURE;
	
	/* Input path of "from" file to "FromFilePath" */
	sprintf(FromFilePath, ".%csettings%c%s%cfrom", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER, SettingName, PATH_BREAK_CHARACTER);
	
	/* Input path of "to" file to "ToFilePath" */
	sprintf(ToFilePath, ".%csettings%c%s%cto", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER, SettingName, PATH_BREAK_CHARACTER);
	
	/* Open file */
	FromFilePointer = fopen(FromFilePath,	"a");
	ToFilePointer	= fopen(ToFilePath,		"a");
	if((FromFilePointer == NULL) || (ToFilePointer == NULL))return FAILURE;
	
	/* Write datas */
	fprintf(FromFilePointer,	"%s\n", From);
	fprintf(ToFilePointer,		"%s\n", To);
	
	/* Close file */
	fclose(FromFilePointer);
	fclose(ToFilePointer);
	
	return SUCCESS;
}
