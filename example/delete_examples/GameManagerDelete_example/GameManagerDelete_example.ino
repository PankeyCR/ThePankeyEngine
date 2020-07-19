

#include "GameManager.h"
#include "GameOn.h"
#include "MemoryFree.h"

int deletememory;
int startmemory;
int instancememory;

class Position : public GameOn{
  public:
    float x=0;
    float y=0;
    Position(){}
    ~Position(){}
    String getClassName(){
      return "Position";
    }
};
void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  GameManager* manager = new GameManager();
  
  int memoryEntity0 = freeMemory();
  int entity = manager->createEntity();
  int memoryEntity1 = freeMemory();
  
  int firstprePosition = freeMemory();
  manager->addComponent(entity, new Position());
  int firstprostPosition = freeMemory();
  
  int entity2 = manager->createEntity();
  int secondprePosition = freeMemory();
  manager->addComponent(entity2, new Position());
  int secondprostPosition = freeMemory();
  instancememory = freeMemory();
  delete manager;  
  deletememory = freeMemory();
  Serial.print("initial memory ");Serial.println(startmemory);
  Serial.print("memory used ");Serial.println(startmemory-instancememory);
  Serial.print("memory lefted ");Serial.println(instancememory);
  Serial.print("memory leaked ");Serial.println(startmemory-deletememory);
  Serial.print("entity instance ");Serial.println(memoryEntity0-memoryEntity1);
  Serial.print("Position instance + LikedList instance ");Serial.println(firstprePosition-firstprostPosition);
  Serial.print("LikedList instance ");Serial.println((firstprePosition-firstprostPosition)-(secondprePosition-secondprostPosition));
  Serial.print("Position instance ");Serial.println(secondprePosition-secondprostPosition);

}

void loop() {

}
