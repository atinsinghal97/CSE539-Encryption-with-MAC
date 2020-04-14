#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

#include "md5.h" 

int key; // symmetric key
int buf, n, infile, outfile;
int hash=0, flag=0;

MD5_CTX mdContext;  // needed to compute MD5

check_pw(char * pass)
{
  int i = 0;
  for (i=0;i<4;i++) { 
       if (!(((pass[i] >= 'a') && (pass [i] <= 'z'))
             || ((pass[i] >= 'A') && (pass [i] <= 'Z'))
             || ((pass[i] >= '0') && (pass [i] <= '9')))) {
                   break;
       };
  };
};

encrypt(char *name)
{ 
  struct stat st;
  int size,i,j;
  int *temp, result;   
  int rollingkey;    
  // priliminaries, get files ready and sized
  infile = open (name, O_RDONLY);
  if (infile<0) { printf("input file %s open error\n", name); exit(0); }
  
  outfile = open ("output", O_RDWR|O_CREAT|O_TRUNC, 0700);
  if (outfile<0) { printf("Cannot access file: output\n"); exit(0); }
  
  stat(name, &st); size = st.st_size;
  if (size <4) {printf("input file too small\n"); exit(0);}; 
  
  // do the encryption, buf contains plaintext, and rollingkey contains key
  buf = 0;
  rollingkey = key;  
  while ((n = read(infile, &buf, 4)) > 0 ) {
         buf = buf ^ rollingkey; //XOR with key, and put ciphertext in buf
   MD5Init(&mdContext);  // compute MD5 of rollingkey
   MD5Update(&mdContext, &rollingkey, 4);
   MD5Final(&mdContext);
   temp = (int *) &mdContext.digest[12]; 
   result = *temp; // result is 32 bits of MD5 of buf
   
   rollingkey = rollingkey ^ result; // new key
   write(outfile, &buf, 4);  // write ciphertext

   buf = 0; // rinse and repeat
  };
  close(infile); close(outfile);
  return(size);
};

void getHash()
{ 
  int size,i,j;
  int *temp, result; 
  // priliminaries, get files ready and sized
  infile = open ("output", O_RDONLY);
  if (infile<0) { printf("encrypted file output open error\n"); exit(0); }

  buf = 0;
  while ((n = read(infile, &buf, 4)) > 0 ) {
   MD5Init(&mdContext);
   MD5Update(&mdContext, &buf, 4);
   MD5Final(&mdContext);
   temp = (int *) &mdContext.digest[12]; 
   result = *temp;

   if (flag!=0)
    hash=hash^result;
   
   else if (flag==0){
    flag++;
    hash=result;
   }

   buf = 0; // rinse and repeat
  };
  close(infile);
};

main(int argc, char *argv[])
{
 if (argc!= 3) {printf("Usage: %s <filename> <key>\n", argv[0]); exit(0);}; 
 
 sscanf(argv[2], "%x", &key); 
 
 encrypt(argv[1]); // encrypt input file and place in "output"
 
 getHash();
 printf("%x\n", hash); // print a human readable version of hash (using hex conversion)
};
