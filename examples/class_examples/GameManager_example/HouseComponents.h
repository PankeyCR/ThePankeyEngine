

#ifndef HouseComponents_h
#define HouseComponents_h

#include "GameOn.h"

class FrontDoor : public GameOn{
public:
FrontDoor(){}
~FrontDoor(){}

String getClassName(){return "FrontDoor";}
bool instanceof(String name){return name == "FrontDoor" || GameOn::instanceof(name);}
};

class Entrance : public GameOn{
public:
Entrance(){}
~Entrance(){}

String getClassName(){return "Entrance";}
bool instanceof(String name){return name == "Entrance" || GameOn::instanceof(name);}
};

class Stairs : public GameOn{
public:
Stairs(){}
~Stairs(){}

String getClassName(){return "Stairs";}
bool instanceof(String name){return name == "Stairs" || GameOn::instanceof(name);}
};

class Roof : public GameOn{
public:
Roof(){}
~Roof(){}

String getClassName(){return "Roof";}
bool instanceof(String name){return name == "Roof" || GameOn::instanceof(name);}
};

class LivingRoom : public GameOn{
public:
LivingRoom(){}
~LivingRoom(){}

String getClassName(){return "LivingRoom";}
bool instanceof(String name){return name == "LivingRoom" || GameOn::instanceof(name);}
};

class Room1 : public GameOn{
public:
Room1(){}
~Room1(){}

String getClassName(){return "Room1";}
bool instanceof(String name){return name == "Room1" || GameOn::instanceof(name);}
};

class Room2 : public GameOn{
public:
Room2(){}
~Room2(){}

String getClassName(){return "Room2";}
bool instanceof(String name){return name == "Room2" || GameOn::instanceof(name);}
};

class BathRoom1 : public GameOn{
public:
BathRoom1(){}
~BathRoom1(){}

String getClassName(){return "BathRoom1";}
bool instanceof(String name){return name == "BathRoom1" || GameOn::instanceof(name);}
};

class BathRoom2 : public GameOn{
public:
BathRoom2(){}
~BathRoom2(){}

String getClassName(){return "BathRoom2";}
bool instanceof(String name){return name == "BathRoom2" || GameOn::instanceof(name);}
};

class Pool : public GameOn{
public:
Pool(){}
~Pool(){}

String getClassName(){return "Pool";}
bool instanceof(String name){return name == "Pool" || GameOn::instanceof(name);}
};


#endif 
