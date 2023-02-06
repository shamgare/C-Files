#include <stdio.h>

//2 jenis penulisan variable, 1 ya normal int kami = 85858; , satu lagi int kami() { return 354636;}
void kamu() //anggap kamu()= variable, tapi variable nya gaada isi karena (VOID)
{
	return 'r';
}

int main()
{
	int kami = 4+8;
	
	printf ("%d", kami);
	
	printf ("%c", kamu());
	
	return 0;
}

