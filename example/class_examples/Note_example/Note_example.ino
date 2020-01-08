
#include "Note.h"
#include "ArrayList.h"
#include <MemoryFree.h>

 
void setup() {
  Serial.begin(9600);
 //   Serial.print("freeMemory()=");
 //   Serial.println(freeMemory());
  Note note1;
  Note note;
  Note n;
  Serial.print("size note ");Serial.println(note.getPos());
  Serial.print("size note1 ");Serial.println(note1.getPos());
  Serial.print("size n ");Serial.println(n.getPos());
  
  n = "hello";
  Serial.print("size n ");Serial.println(n.getPos());
  n+=' ';
  Serial.print("size n ");Serial.println(n.getPos());
  n+="world";
  n+=' ';
  n+='\n';
  Serial.print("size n ");Serial.println(n.getPos());
  note1.add('c');
  note1.add('a');
  note1.add('t');
  note.add('c');
  note.add('a');
  note.add('t');
  //note = note + " bad";//not available at the moment
  Serial.print("size note ");Serial.println(note.getPos()); 
  Serial.print("size note1 ");Serial.println(note1.getPos());
  Serial.print("size n ");Serial.println(n.getPos());
  
  
  Serial.print("size note ");Serial.println(note.getNote());
  Serial.print("size n ");Serial.println(n.getNote());
  Serial.print("size note1 ");Serial.println(note1.getNote());

//    Serial.print("freeMemory()=");
//    Serial.println(freeMemory());
  Serial.print("char position n ");Serial.println(*n.getCharPositions('o').getByPos(0));
  Serial.print("char size n ");Serial.println(n.getCharSize('o'));
  Serial.print("char spacePositions 0 n ");Serial.println(*n.getSpacePositions().getByPos(0));
  Serial.print("char space n ");Serial.println(n.getSpaceSize());
  Serial.print("char total words n ");Serial.println(n.getSpacingSize());
  
  ArrayList<int,20> listOfAllCharPositionsInNote = n.getCharPositions<20>('o');
  Serial.print("char 'o' positions n ");
  for(int x = 0; x < listOfAllCharPositionsInNote.getPos(); x++){
    Serial.println(*listOfAllCharPositionsInNote.getByPos(x));
  }

  Note extraS(1);
  extraS = "adding";
  extraS += space;
  extraS += 'a';
  extraS += space;
  extraS += "extra";
  extraS += space;
  extraS += "spaces";
  extraS += space;
  extraS += space;
  extraS += space;
  extraS += space;
  extraS += space;
  Serial.print("string  ");Serial.println(extraS.getNote());
  Serial.print("string length  ");Serial.println(extraS.getNote().length());
  extraS.fixExtraSpace();
  Serial.print("fix extra space ");Serial.println(extraS.getNote());
  Serial.print("fix extra space size ");Serial.println(extraS.getPos());
  Serial.print("fix extra space total size ");Serial.println(extraS.getSize());
  
  Note extraSEmpty(1);
 // extraSEmpty = "adding a empty space";
  extraSEmpty = "adding";
  extraSEmpty += empty;
  extraSEmpty += space;
  extraSEmpty += 'a';
  extraSEmpty += empty;
  extraSEmpty += space;
  extraSEmpty += empty;
  extraSEmpty += "empty";
  extraSEmpty += space;
  extraSEmpty += empty;
  extraSEmpty += "space.";
  Serial.print("string  ");Serial.println(extraSEmpty.getNote());
  Serial.print("string length  ");Serial.println(extraSEmpty.getNote().length());
  Serial.print("fix empty space size ");Serial.println(extraSEmpty.getPos());
  extraSEmpty.fixEmptySpaces();
  Serial.print("fix empty space ");Serial.println(extraSEmpty.getNote());
  Serial.print("fix empty space size ");Serial.println(extraSEmpty.getPos());
  Serial.print("fix empty space total size ");Serial.println(extraSEmpty.getSize());
  Serial.print("string  ");Serial.println(extraSEmpty.getNote());
  extraSEmpty.fixEndLinePoint();
  Serial.print("fix empty space ");Serial.println(extraSEmpty.getNote());
  Serial.print("fix empty space size ");Serial.println(extraSEmpty.getPos());

}

void loop(){}
