#include "Buffer/StaticBuffer.h"
#include "Cache/OpenRelTable.h"
#include "Disk_Class/Disk.h"
#include "FrontendInterface/FrontendInterface.h"
#include <bits/stdc++.h> 

int main(int argc, char *argv[]) {
  /* Initialize the Run Copy of Disk */
  Disk disk_run;

  unsigned char buffer[BLOCK_SIZE]; //BLOCK_SIZE is a constant that has value 2048
  Disk::readBlock(buffer, 7000);    // 7000 is a random block number that's unused.
  char message[] = "hello";
  memcpy(buffer + 20, message, 6);  //Now, buffer[20] = 'h', buffer[21] = 'e' ...
  Disk::writeBlock(buffer, 7000);

  unsigned char buffer2[BLOCK_SIZE];
  char message2[6];
  Disk::readBlock(buffer2, 7000);
  memcpy(message2, buffer2 + 20, 6);
  std::cout << message2 << "\n";

  for(int i=0;i<4;i++)
  {
    unsigned char buffer3[BLOCK_SIZE];
    char message3[BLOCK_SIZE];
    Disk::readBlock(buffer3, i);
    memcpy(message3, buffer3, BLOCK_SIZE);
    std::cout << message3 << "\n";
  }

  return 0;
  // StaticBuffer buffer;
  // OpenRelTable cache;

  //return FrontendInterface::handleFrontend(argc, argv);
}