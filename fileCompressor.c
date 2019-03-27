#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void fileListing(char *initialPath)
{
    char path[1000];
    struct dirent *dirEntry;
    DIR *directory = opendir(initialPath);
    if (directory == NULL)
        return;
    while ((dirEntry = readdir(directory)) != NULL)
    {
        if (strcmp(dirEntry->d_name, ".") != 0 && strcmp(dirEntry->d_name, "..") != 0)
        {
            printf("-%s\n", dirEntry->d_name);

            strcpy(path, initialPath);
            strcat(path,"/");
            strcat(path,dirEntry->d_name);
            fileListing(path);
        }
    }
    closedir(directory);
}

int main(int argc, char const *argv[])
{
	/*
	if (argc!=4){
		printf("%s\n","Invalid number of arguments.");
		return EXIT_FAILURE;
	}*/
	//FILE *fp;
	/*
	DIR *directory;
    struct dirent *dirEntry;
    directory = opendir(".");
    dirEntry = readdir(directory);
    while (dirEntry != NULL)
    {
        printf("%s\n", dirEntry->d_name);
        dirEntry = readdir(directory);
    }
    closedir(directory);*/
  fileListing(".");
	return EXIT_SUCCESS;
}
