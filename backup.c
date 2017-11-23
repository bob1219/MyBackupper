/* Standard Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

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
		
		if(from	[strlen(from) - 1] == '\n')from	[strlen(from) - 1] = '\0';
		if(to	[strlen(to	) - 1] == '\n')to	[strlen(to	) - 1] = '\0';
		
		if(from[strlen(from) - 1] == PATH_BREAK_CHARACTER)
		{
			DIR				*directory;
			struct dirent	*DirectoryPointer;
			char			from2[FILENAME_MAX], to2[FILENAME_MAX];
			size_t			FilenameLength;
			
			/* Open directory */
			directory = opendir(from);
			if(directory == NULL)
			{
				fprintf(stderr, "Error: Cannot open directory \"%s\".\n", from);
				continue;
			}
			
			for(DirectoryPointer = readdir(directory) ; DirectoryPointer != NULL ; DirectoryPointer = readdir(directory))
			{
				if((strcmp(DirectoryPointer -> d_name, ".") != 0) && (strcmp(DirectoryPointer -> d_name, "..") != 0))
				{
					FilenameLength = strlen(DirectoryPointer -> d_name);
					if(((strlen(from) + FilenameLength + 1) > FILENAME_MAX) || ((strlen(to) + FilenameLength + 1) > FILENAME_MAX))abort();
					
					/* Input path of "from" file to "from2" */
					sprintf(from2, "%s%s", from, DirectoryPointer -> d_name);
					
					/* Input path of "to" file to "to2" */
					sprintf(to2, "%s%s", to, DirectoryPointer -> d_name);
					
					/* Open file */
					BackupFromFilePointer	= fopen(from2,	"rb");
					BackupToFilePointer		= fopen(to2,	"wb");
					if((BackupFromFilePointer == NULL) || (BackupToFilePointer == NULL))
					{
						fprintf(stderr, "Error: Cannot open file \"%s\".\n", DirectoryPointer -> d_name);
						continue;
					}
		
					while(1)
						if((fread(&b, sizeof(BYTE), 1, BackupFromFilePointer) < 1) || (fwrite(&b, sizeof(BYTE), 1, BackupToFilePointer) < 1))break;
					
					/* Close file */
					fclose(BackupFromFilePointer);
					fclose(BackupToFilePointer);
				}
			}
		}
		else
		{
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
	}
	
	/* Close file */
	fclose(FromFilePointer);
	fclose(ToFilePointer);
	
	return SUCCESS;
}
