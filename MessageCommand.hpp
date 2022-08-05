
#include "ame_Enviroment.hpp"

#ifndef MessageCommand_hpp
#define MessageCommand_hpp

#include "PrimitiveList.hpp"

#include "Note.hpp"

#ifdef Note_AVAILABLE

#else
	#include "ame_String.hpp"
#endif

namespace ame{

class MessageCommand{
	public:
		MessageCommand(){
			// Serial.println("MessageCommand Constructor");
		}
		virtual ~MessageCommand(){
			// mns.resetDelete();
			// Serial.println("MessageCommand Destructor");
		}
		
		#ifdef Note_AVAILABLE
		void addMessage(Note message){
			mns.add(message);
		}
		#else
		void addMessage(ame_String message){
			mns.add(message);
		}
		#endif
		#ifdef Note_AVAILABLE
		Note getMessage(int x){
			if(x >= mns.getPosition()){
				return "";
			}
			return *mns.getByPosition(x);
		}
		#else
		ame_String getMessage(int x){
			if(x >= mns.getPosition()){
				return "";
			}
			return *mns.getByPosition(x);
		}
		#endif
		int getSize(){return mns.getPosition();}
		
		void setId(int i_id){
			m_id = i_id;
		}
		
		int getId(){
			return m_id;
		}
		
		virtual void operator=(MessageCommand b){}
		virtual bool operator==(MessageCommand b){
				return false;
		}
		virtual bool operator!=(MessageCommand b){
				return false;
		}
	protected:
		#ifdef Note_AVAILABLE
		PrimitiveList<Note> mns;
		#else
		PrimitiveList<ame_String> mns;
		#endif
		
		int m_id = -1;
};

}

#endif 
