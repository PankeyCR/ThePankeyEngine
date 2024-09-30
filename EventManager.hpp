
#ifndef EventManager_hpp
	#define EventManager_hpp

	#include "InvokeRawMap.hpp"
	#include "Note.hpp"

	#ifdef EventManager_LogApp
		#include "pankey_Logger.hpp"
		#define EventManagerLog(location,method,type,mns) pankey_Log((void*)this,location,"EventManager",method,type,mns)
	#else
		#define EventManagerLog(location,method,type,mns) 
	#endif

	namespace pankey{

		template<class A>
		class EventManager{
			public:
				EventManager(){}
				virtual ~EventManager(){}

				void add(Note a_name, InvokeMethod<> a_method){
					m_events.add(a_name, a_method);
				}

				void add(Note a_name, InvokeMethod<A&> a_method){
					m_app_events.add(a_name, a_method);
				}

				void put(Note a_name, InvokeMethod<> a_method){
					if(m_app_events.contain(a_name)){
						return;
					}
					m_events.put(a_name, a_method);
				}

				void put(Note a_name, InvokeMethod<A&> a_method){
					if(m_events.contain(a_name)){
						return;
					}
					m_app_events.put(a_name, a_method);
				}

				void putMethod(Note a_name, InvokeMethod<> a_method){
					m_events.put(a_name, a_method);
				}

				void putAppMethod(Note a_name, InvokeMethod<A&> a_method){
					m_app_events.put(a_name, a_method);
				}

				void change(Note a_name, InvokeMethod<> a_method){
					m_events.remove(a_name);
					m_app_events.remove(a_name);
					m_events.add(a_name, a_method);
				}

				void change(Note a_name, InvokeMethod<A&> a_method){
					m_events.remove(a_name);
					m_app_events.remove(a_name);
					m_app_events.add(a_name, a_method);
				}

				void changeMethod(Note a_name, InvokeMethod<> a_method){
					m_events.remove(a_name);
					m_events.add(a_name, a_method);
				}

				void changeAppMethod(Note a_name, InvokeMethod<A&> a_method){
					m_app_events.remove(a_name);
					m_app_events.add(a_name, a_method);
				}

				void remove(Note a_name){
					m_events.removeDeleteByKeyLValue(a_name);
					m_app_events.removeDeleteByKeyLValue(a_name);
				}

				void removeMethod(Note a_name){
					m_events.removeDeleteByKeyLValue(a_name);
				}

				void removeAppMethod(Note a_name){
					m_app_events.removeDeleteByKeyLValue(a_name);
				}

				void removeAll(){
					m_events.resetDelete();
					m_app_events.resetDelete();
				}

				void removeAllMethod(){
					m_events.resetDelete();
				}

				void removeAllAppMethod(){
					m_app_events.resetDelete();
				}

				void run(Note a_name, A& a_app){
					invoke<Note>(m_events, a_name);
					invoke<Note,A&>(m_app_events, a_name, a_app);
				}

				void runMethod(Note a_name){
					invoke<Note>(m_events, a_name);
				}

				void runAppMethod(Note a_name, A& a_app){
					invoke<Note,A&>(m_app_events, a_name, a_app);
				}

				void runAll(A& a_app){
					invokeAll<Note>(m_events);
					invokeAll<Note,A&>(m_app_events, a_app);
				}

				void runAllMethods(){
					invokeAll<Note>(m_events);
				}

				void runAllAppMethods(A& a_app){
					invokeAll<Note,A&>(m_app_events, a_app);
				}

			protected:
				MethodMap<Note> m_events;
				MethodMap<Note,A&> m_app_events;
				
				// CommandMap<Note> m_commands;
				// CommandMap<Note,A&> m_app_commands;
		};

	}

#endif
