#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
   int option;

   while((option = getopt(argc, argv, "qf:b:r:")) != -1){ //get option from the getopt() method
      switch(option){
         case 'q':
		printf("Aha no debugging information printed\n");
	 break;
         case 'f':
		printf("Aha flight information file is %s\n", optarg);
         break;
         case 'b':
		printf("Aha booking information file is %s\n", optarg);
         break;
         case 'r':
		printf("Aha report file should be  %s\n", optarg);
         break;
         default :
            printf("Usage \n\t%s -f {flight information filename} -b {booking information filename} -r {report filename}\n\n",argv[0]);
         break;
      }
   }
   return 0;
}
