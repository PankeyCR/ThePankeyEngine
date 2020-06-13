
#include "MonkeyFile.h"

void setup() {
  Serial.begin(9600);
  MonkeyFile* file = new MonkeyFile(53);
  file->setRootPathFile("monkey");

  bool start = true;
  bool gstart;

  file->create("started.txt");
  
  if(file->write("started.txt", String(start))){
    if(file->read("started.txt") == "0"){
      gstart = false;
    }
    if(file->read("started.txt") == "1"){
      gstart = true;
    }
    file->deleteFile("started.txt");
  }
  
  Serial.println("gstart "+String(gstart));
}

void loop() {

}
