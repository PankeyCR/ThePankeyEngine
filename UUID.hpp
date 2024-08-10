
#ifndef UUID_hpp
#define UUID_hpp

#include "Random.hpp"
#include "NoRepiteRandom.hpp"
#include "Note.hpp"

namespace higgs{

#ifdef higgs_Windows
class UUID{
#endif

#ifdef higgs_ArduinoIDE
class UUID : public Printable{
#endif
    public:
		UUID(){
			uuid = rand.getRandom();
		}
		UUID(const float& u){
			uuid = u;
		}
		UUID(const UUID& u){
			uuid = u.uuid;
		}
		virtual ~UUID(){}
		
#ifdef higgs_ArduinoIDE
		size_t printTo(Print& p) const{
			p.print(uuid);
			return sizeof(uuid);
		}
#endif
		
		UUID& operator=(const UUID& u){
			uuid = u.uuid;
		}
		
		bool operator==(const UUID& u){
			return uuid == u.uuid;
		}
		
		bool operator!=(const UUID& u){
			return uuid != u.uuid;
		}
		
		UUID& operator=(const float& u){
			uuid = u;
		}
		
		bool operator==(const float& u){
			return uuid == u;
		}
		
		bool operator!=(const float& u){
			return uuid != u;
		}
		
		virtual float getId(){
			return uuid;
		}
		
		virtual Note toNote(){
			return Note(uuid);
		}
	protected:
		float uuid = 0;
		static NoRepiteRandom rand;
};

NoRepiteRandom UUID::rand = NoRepiteRandom(100000l, 0, 78545l);

}

#endif