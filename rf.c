#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_PATHS 255


char **paths;


char* get_directory_name(int argc, char *argv[]) {
	if (argc == 1) return ".";
	return argv[1];
}


int main(int argc, char *argv[]) {
	short index = 0;
	paths = (char**) malloc(sizeof(char) * MAX_PATHS);
	char *directoryName = get_directory_name(argc, argv);
	DIR *directory = opendir(directoryName);
	struct dirent *entity;

	if (directory == NULL) {
		perror("");
		return 1;
	}

	while ((entity = readdir(directory)) != NULL) {
		if ((*entity).d_name[0] == '.') continue;
		paths[index] = (*entity).d_name;
		++index;
	}

	srand(time(0));
	index = rand() % index;

	printf("%s/%s\n", directoryName, paths[index]);

	free(directoryName);
	return 0;
}
