#include <stdio.h>

int main(){
	char *ptr;
	char string[20] = "abcdefghijkl";
	ptr = string;
	++ptr;
	printf("%c\n\n", *ptr);
	ptr = ptr += 5;
	printf("%c\n\n", *ptr);
	
}
