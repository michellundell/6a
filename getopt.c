
#include <stdio.h>
#include <string.h>
#include <unistd.h>


/* getopt -f flights.txt -b books.txt -r rapp.txt -q */

/*
getopt -f flights.txt -b books.txt -r rapp.txt

Aha flight information file is flights.txt
Aha booking information file is books.txt
Aha report file should be  rapp.txt
*/

/*
getopt -f flights.txt -b books.txt -r rapp.txt -v 

Aha flight information file is flights.txt
Aha booking information file is books.txt
Aha report file should be  rapp.txt
Aha more debugging information printed (level 1)
flights=flights.txt
booking=books.txt
report=rapp.txt
*/

/*
getopt -f flights.txt -b books.txt -r rapp.txt -v -v

Aha flight information file is flights.txt
Aha booking information file is books.txt
Aha report file should be  rapp.txt
Aha more debugging information printed (level 1)
Aha more debugging information printed (level 2)
flights=flights.txt
more debug information
booking=books.txt
report=rapp.txt
*/

/*
./getopt: illegal option -- z
Usage 
	./getopt -f {flight information filename} -b {booking information filename} -r {report filename}
*/

int main(int argc, char *argv[]) {
   int option;
   int debug = 0;
   char flight_filename[255];
   char booking_filename[255];
   char report_filename[255];

   while( ( option = getopt(argc, argv, "vqf:b:r:")) != -1) { //get option from the getopt() method
      switch(option){
         case 'v':
		debug++;
		printf("Aha more debugging information printed (level %d)\n",debug);
	 break;
         case 'q':
		printf("Aha no debugging information printed\n");
	 break;
         case 'f':
		printf("Aha flight information file is %s\n", optarg);
		strcpy(flight_filename, optarg);
         break;
         case 'b':
		printf("Aha booking information file is %s\n", optarg);
		strcpy(booking_filename, optarg);
         break;
         case 'r':
		printf("Aha report file should be  %s\n", optarg);
		strcpy(report_filename, optarg);
         break;
         default :
            printf("Usage \n\t%s -f {flight information filename} -b {booking information filename} -r {report filename}\n\n",argv[0]);
         break;
      }
   }
   if( debug ) {
	   fprintf(stdout,"flights=%s\n",flight_filename);
	   if( debug == 2 ) { fprintf(stdout,"more debug information\n"); }
	   fprintf(stdout,"booking=%s\n",booking_filename);
	   if( debug == 3 ) { fprintf(stdout,"even more debug information\n"); }
	   fprintf(stdout,"report=%s\n",report_filename);
   }
   return 0;
}

/*
Aha flight information file is flights.txt
Aha booking information file is books.txt
Aha report file should be  rapp.txt
Aha no debugging information printed


Aha booking information file is bookings.txt
Aha flight information file is flights.csv
Aha report file should be  report.txt

flights=flights.csv
booking=bookings.txt
report=report.txt
*/
