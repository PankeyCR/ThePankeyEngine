
#ifndef ListEvent_hpp
#define ListEvent_hpp

#include "Event.hpp"
#include "ArrayList.hpp"
#include "List.hpp"

namespace ame{

template<class T>
class ListEvent : public Event<T>{
	protected:
		using EventMethod = void (*)(T);
		List<EventMethod>* list;
    public:
		ListEvent(){
			this->list = new ArrayList<EventMethod,10>();
		}
		virtual ~ListEvent(){
			delete this->list;
		}
		virtual void event(){
			for(int x = 0; x < this->list->getPosition(); x++){
				(**this->list->getByPosition(x))(this->var);
			}
		}
		virtual void event(T c){
			if(this->var != c){
				this->var = c;
				for(int x = 0; x < this->list->getPosition(); x++){
					(**this->list->getByPosition(x))(this->var);
				}
			}
		}
		virtual void add(EventMethod c){
			this->list->addLValue(c);
		}
		virtual void add(T name, EventMethod c){
		
		}
};

}

#endif 
