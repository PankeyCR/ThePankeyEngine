
#include "ame_Enviroment.hpp"

#if defined(DISABLE_PortMail)
	#define PortMail_hpp
#endif

#ifndef PortMail_hpp
#define PortMail_hpp
#define PortMail_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "LinkedList.hpp"
#include "Note.hpp"
#include "PrimitiveMap.hpp"

namespace ame{

template<class T>
struct PortMail{
	static PrimitiveMap<Note,LinkedList<T>>* mail;
	
	static void add(Note a_name, T m_value){
		if(mail == nullptr){
			mail = new PrimitiveMap<Note,LinkedList<T>>();
			LinkedList<T>* list = new LinkedList<T>();
			mail->addPointer(a_name, list);
			list->add(m_value);
			return;
		}
		LinkedList<T>* list = mail->getByLValue(a_name);
		if(list == nullptr){
			list = new LinkedList<T>();
			mail->addPointer(a_name, list);
		}
		list->add(m_value);
	}
	
	static void put(Note a_name, T m_value){
		if(mail == nullptr){
			mail = new PrimitiveMap<Note,LinkedList<T>>();
			LinkedList<T>* list = new LinkedList<T>();
			mail->addPointer(a_name, list);
			list->add(m_value);
			return;
		}
		LinkedList<T>* list = mail->get(a_name);
		if(list == nullptr){
			list = new LinkedList<T>();
			mail->addPointer(a_name, list);
		}
		list->put(m_value);
	}
	
	static T retrieveMessage(Note a_name){
		if(mail == nullptr){
			return T();
		}
		for(int x = 0; x < mail->getPosition(); x++){
			Note i_name = *mail->getKeyByPosition(x);
			LinkedList<T>* i_list = mail->getByPosition(x);
			if(i_list == nullptr){
				continue;
			}
			if(i_name == a_name && !i_list->isEmpty()){
				T* i_value = i_list->getByPosition(0);
				if(i_value == nullptr){
					continue;
				}
				T t = *i_value;
				i_list->removeDeleteByPosition(0);
				return t;
			}
		}
		return T();
	}
	
	static LinkedList<T> retrieveMail(Note a_name){
		if(mail == nullptr){
			return LinkedList<T>();
		}
		LinkedList<T> list;
		list.addCopy(mail.get(a_name));
		mail->removeDeleteByLValue(a_name);
		return list;
	}
};

template<class T> PrimitiveMap<Note,LinkedList<T>>* PortMail<T>::mail = nullptr;

}

#endif