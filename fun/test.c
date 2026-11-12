#include <stdio.h>
int main() { 
	unsigned int a = 0x12345678u; 
	unsigned char* p = (unsigned char*)&a; 
	for (size_t i = 0; i < sizeof(int); i++)  
		printf("%x\n", p[i]); 
}