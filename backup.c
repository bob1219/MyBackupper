/* Standard Libraries */
#include <stdio.h>
#include <string.h>

/* Headers */
#include "macros.h"
#include "typedef.h"

int
backup
(const char *SettingName)
{
	char	FromFilePath[FILENAME_MAX], ToFilePath[FILENAME_MAX],
			from[FILENAME_MAX], to[FILENAME_MAX];
	FILE	*FromFilePointer, *ToFilePointer,
			*BackupFromFilePointer, *BackupToFilePointer;
	BYTE	b;
	
	if(((15 + strlen(SettingName) + 1) > FILENAME_MAX) || ((13 + strlen(SettingName) + 1 ) > FILENAME_MAX))return FAILURE;
	
	/* Input path of "from" file to "FromFilePath" */
	sprintf(FromFilePath, ".%csettings%c%s%cfrom", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER, SettingName, PATH_BREAK_CHARACTER);
	
	/* Input path of "to" file to "ToFilePath" */
	sprintf(ToFilePath, ".%csettings%c%s%cto", PATH_BREAK_CHARACTER, PATH_BREAK_CHARACTER, SettingName, PATH_BREAK_CHARACTER);
	
	/* Open file */
	FromFilePointer = fopen(FromFilePath,	"r");
	ToFilePointer	= fopen(ToFilePath,		"r");
	if((FromFilePointer == NULL) || (ToFilePointer == NULL))return FAILURE;
	
	while(1)
	{
		/* Input from "from" file */
		if((fgets(from, FILENAME_MAX, FromFilePointer) == NULL) || (fgets(to, FILENAME_MAX, ToFilePointer) == NULL))break;
		
		/* Open file */
		BackupFromFilePointer	= fopen(from,	"rb");
		BackupToFilePointer		= fopen(to,		"wb");
		if((BackupFromFilePointer == NULL) || (BackupToFilePointer == NULL))
		{
			fprintf(stderr, "Error: Cannot open file.\n");
			continue;
		}
		
		while(1)
			if((fread(&b, sizeof(BYTE), 1, BackupFromFilePointer) < 1) || (fwrite(&b, sizeof(BYTE), 1, BackupToFilePointer) < 1))break;
			
		/* Close file */
		fclose(BackupFromFilePointer);
		fclose(BackupToFilePointer);
	}
	
	/* Close file */
	fclose(FromFilePointer);
	fclose(ToFilePointer);
	
	return SUCCESS;
}
