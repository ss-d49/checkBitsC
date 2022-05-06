#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define BYTES 1024
int main (int argc, char **argv)
{
  FILE *EXE;
  size_t bytes_in;
  unsigned char buf[BYTES];
  unsigned char sub[2];
  const unsigned char header64[] = { 0x64, 0x86 };
  const unsigned char header86[] = { 0x4c, 0x01 };

  if (argc < 2)
  {
    fprintf (stderr, "Usage: checkBits exe file\n");
    fprintf (stderr, "This utility determines whether an executable in 32 or 64 bit.\n");
    exit(1);
  }

  if (EXE = fopen (argv[1], "rb"))
  {
    fseek(EXE, 0, SEEK_SET);
    bytes_in = fread (buf, 1, BYTES, EXE);
    fclose (EXE);
  }
  else
  {
    fprintf (stderr, "Error Opening exe file '%s': %s\n", argv[1], strerror (errno));
    exit(1);
  }
  
	for (int i=0;i<BYTES;i+=2) 
	{
		memcpy(sub, &buf[i], 2);	
	
	if (memcmp(sub, header64, 2) == 0)
	  {
		printf("%s\n","File is 64 Bit.");
		  exit(0);
	  }
	else if (memcmp(sub, header86, 2) == 0)
	  {
		printf("%s\n","File is 32 Bit.");
		  exit(0);
	  }
	}
	
	printf("%s\n","File bitness is unknown.");
  exit(0);
}
