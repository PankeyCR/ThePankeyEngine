
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

				void add(Note a_name, InvokeMethod<Note> a_method){
					m_message_events.add(a_name, a_method);
				}

				void add(Note a_name, InvokeMethod<A&,Note> a_method){
					m_message_app_events.add(a_name, a_method);
				}

				void put(Note a_name, InvokeMethod<> a_method){
					m_events.put(a_name, a_method);
				}

				void put(Note a_name, InvokeMethod<A&> a_method){
					m_app_events.put(a_name, a_method);
				}

				void put(Note a_name, InvokeMethod<Note> a_method){
					m_message_events.put(a_name, a_method);
				}

				void put(Note a_name, InvokeMethod<A&,Note> a_method){
					m_message_app_events.put(a_name, a_method);
				}

				void change(Note a_name, InvokeMethod<> a_method){
					m_events.remove(a_name);
					m_events.add(a_name, a_method);
				}

				void change(Note a_name, InvokeMethod<A&> a_method){
					m_app_events.remove(a_name);
					m_app_events.add(a_name, a_method);
				}

				void change(Note a_name, InvokeMethod<Note> a_method){
					m_message_events.remove(a_name);
					m_message_events.add(a_name, a_method);
				}

				void change(Note a_name, InvokeMethod<A&,Note> a_method){
					m_message_app_events.remove(a_name);
					m_message_app_events.add(a_name, a_method);
				}

				void remove(Note a_name){
					m_events.removeDeleteByKeyLValue(a_name);
					m_app_events.removeDeleteByKeyLValue(a_name);
					m_message_events.removeDeleteByKeyLValue(a_name);
					m_message_app_events.removeDeleteByKeyLValue(a_name);
				}

				void removeMethod(Note a_name){
					m_events.removeDeleteByKeyLValue(a_name);
				}

				void removeAppMethod(Note a_name){
					m_app_events.removeDeleteByKeyLValue(a_name);
				}

				void removeMessageMethod(Note a_name){
					m_message_events.removeDeleteByKeyLValue(a_name);
				}

				void removeAppMessageMethod(Note a_name){
					m_message_app_events.removeDeleteByKeyLValue(a_name);
				}

				void removeAll(){
					m_events.resetDelete();
					m_app_events.resetDelete();
					m_message_events.resetDelete();
					m_message_app_events.resetDelete();
				}

				void removeAllMethod(){
					m_events.resetDelete();
				}

				void removeAllAppMethod(){
					m_app_events.resetDelete();
				}

				void removeAllMessageMethod(){
					m_message_events.resetDelete();
				}

				void removeAllAppMessageMethod(){
					m_message_app_events.resetDelete();
				}

				void run(Note a_name, A& a_app){
					invoke<Note>(m_events, a_name);
					invoke<Note,A&>(m_app_events, a_name, a_app);
				}

				void run(Note a_name, A& a_app, Note a_message){
					invoke<Note>(m_events, a_name);
					invoke<Note,A&>(m_app_events, a_name, a_app);
					invoke<Note,Note>(m_message_events, a_name, a_message);
					invoke<Note,A&,Note>(m_message_app_events, a_name, a_app, a_message);
				}

				void runMethod(Note a_name){
					invoke<Note>(m_events, a_name);
				}

				void runAppMethod(Note a_name, A& a_app){
					invoke<Note,A&>(m_app_events, a_name, a_app);
				}

				void runMessageMethod(Note a_name, Note a_message){
					invoke<Note,Note>(m_message_events, a_name, a_message);
				}

				void runAppMessageMethod(Note a_name, A& a_app, Note a_message){
					invoke<Note,A&,Note>(m_message_app_events, a_name, a_app, a_message);
				}

				void runAll(A& a_app){
					invokeAll<Note>(m_events);
					invokeAll<Note,A&>(m_app_events, a_app);
				}

				void runAll(A& a_app, Note a_message){
					invokeAll<Note>(m_events);
					invokeAll<Note,A&>(m_app_events, a_app);
					invokeAll<Note,Note>(m_message_events, a_message);
					invokeAll<Note,A&,Note>(m_message_app_events, a_app, a_message);
				}

				void runAllMethods(){
					invokeAll<Note>(m_events);
				}

				void runAllAppMethods(A& a_app){
					invokeAll<Note,A&>(m_app_events, a_app);
				}

				void runAllMessageMethods(Note a_message){
					invokeAll<Note,Note>(m_message_events, a_message);
				}

				void runAllAppMessageMethods(A& a_app, Note a_message){
					invokeAll<Note,A&,Note>(m_message_app_events, a_app, a_message);
				}

			protected:
				MethodMap<Note> m_events;
				MethodMap<Note,A&> m_app_events;

				MethodMap<Note,Note> m_message_events;
				MethodMap<Note,A&,Note> m_message_app_events;
				
				// CommandMap<Note> m_commands;
				// CommandMap<Note,A&> m_app_commands;
		};

	}

#endif
