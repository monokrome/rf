#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX_PATHS 255


char **paths;


char* get_directory_name(int argc, char *argv[]) {
	if (argc == 1) return ".";
	return argv[1];
}



int main(int argc, char *argv[]) {
	short index = 0;

	paths = (char**) malloc(sizeof(char) * MAX_PATHS);

	DIR *directory = opendir(get_directory_name(argc, argv));

	struct dirent *entity;

	if (directory == NULL) {
		perror("The provided directory does not exist.");
		return 1;
	}

	while ((entity = readdir(directory)) != NULL) {
		if ((*entity).d_name[0] == '.') continue;
		paths[index] = (*entity).d_name;
		++index;
	}

	index = arc4random_uniform(index);

	printf("%s\n", paths[index]);

	return 0;
}
