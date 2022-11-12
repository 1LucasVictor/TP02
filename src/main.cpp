#include <iostream>
#include <fstream>
#include <sys/resource.h>
#include "Sorts.hpp"
#include <iomanip>

using namespace std;

void printKeys(Register r[], int n) {
  for (int i = 0; i < n; i++) {
    cout << r[i].key << " | ";
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  string input, output;
  int wichQS, seed;

  for (int i = 1; i < argc; i += 2) {
    if ((string)argv[i] == "-i") {
      input = argv[i + 1];
    } else if ((string)argv[i] == "-o") {
      output = argv[i + 1];
    } else if ((string)argv[i] == "-v") {
      wichQS = stoi(argv[i+1]);
    } else if((string)argv[i]=="-s") {
      seed = stoi(argv[i+1]);
    }
  }
  //Setting the new seed
  srand(seed);

  fstream inputFile(input, fstream::in);
  fstream outputFile(output, fstream::out);
  int N, nReg;
  inputFile >> N;

  while(N > 0) {
    inputFile >> nReg;
    // List of itens
    Register *registers = new Register[nReg];
    // Variables that contains infos about the number of comparations and attributions
    int comp = 0, atrib = 0;
    // Generating keys
    for(int i = 0; i < nReg; i++) {
      registers[i].key = rand();
    }

    //Preparing to get execution time
    struct rusage resources;
    int rc;
    double utime, stime, total_time;

    //Sorting
    switch (wichQS)
    {
    case 1:
      quickSort(registers, 0, nReg-1, comp, atrib);
      break;
    case 2:
      quickSortM(registers, 0, nReg-1, comp, atrib);
      break;
    case 3:
      quickSortS(registers, 0, nReg-1, comp, atrib);
      break;
    case 4:
      quickSortNR(registers, 0, nReg-1, comp, atrib);
      break;
    case 5:
      quickSortEI(registers, nReg, comp, atrib);
      break;
    } 

    //Getting time spent infos
    if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
      perror("getrusage failed");
    utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
    stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
    total_time = utime+stime;
    
    outputFile << N << ": \n";
    outputFile << "User time " << utime <<" System time " << stime << " Total Time " << total_time << "\n";
    outputFile << "Comparações: " << comp << " Atrib: " <<  atrib << endl;
    
    // printKeys(registers, nReg);

    delete registers;
    N--;
  }

  return 0;
}