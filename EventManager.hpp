
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
					g_events.add(a_name, a_method);
				}

				void add(Note a_name, InvokeMethod<A&> a_method){
					g_app_events.add(a_name, a_method);
				}

				void put(Note a_name, InvokeMethod<> a_method){
					if(g_app_events.contain(a_name)){
						return;
					}
					g_events.put(a_name, a_method);
				}

				void put(Note a_name, InvokeMethod<A&> a_method){
					if(g_events.contain(a_name)){
						return;
					}
					g_app_events.put(a_name, a_method);
				}

				void putMethod(Note a_name, InvokeMethod<> a_method){
					g_events.put(a_name, a_method);
				}

				void putAppMethod(Note a_name, InvokeMethod<A&> a_method){
					g_app_events.put(a_name, a_method);
				}

				void change(Note a_name, InvokeMethod<> a_method){
					g_events.remove(a_name);
					g_app_events.remove(a_name);
					g_events.add(a_name, a_method);
				}

				void change(Note a_name, InvokeMethod<A&> a_method){
					g_events.remove(a_name);
					g_app_events.remove(a_name);
					g_app_events.add(a_name, a_method);
				}

				void changeMethod(Note a_name, InvokeMethod<> a_method){
					g_events.remove(a_name);
					g_events.add(a_name, a_method);
				}

				void changeAppMethod(Note a_name, InvokeMethod<A&> a_method){
					g_app_events.remove(a_name);
					g_app_events.add(a_name, a_method);
				}

				void remove(Note a_name){
					g_events.removeDeleteByKeyLValue(a_name);
					g_app_events.removeDeleteByKeyLValue(a_name);
				}

				void removeMethod(Note a_name){
					g_events.removeDeleteByKeyLValue(a_name);
				}

				void removeAppMethod(Note a_name){
					g_app_events.removeDeleteByKeyLValue(a_name);
				}

				void removeAll(){
					g_events.resetDelete();
					g_app_events.resetDelete();
				}

				void removeAllMethod(){
					g_events.resetDelete();
				}

				void removeAllAppMethod(){
					g_app_events.resetDelete();
				}

				void run(Note a_name, A& a_app){
					invoke<Note>(g_events, a_name);
					invoke<Note,A&>(g_app_events, a_name, a_app);
				}

				void runMethod(Note a_name){
					invoke<Note>(g_events, a_name);
				}

				void runAppMethod(Note a_name, A& a_app){
					invoke<Note,A&>(g_app_events, a_name, a_app);
				}

				void runAll(A& a_app){
					invokeAll<Note>(g_events);
					invokeAll<Note,A&>(g_app_events, a_app);
				}

				void runAllMethods(){
					invokeAll<Note>(g_events);
				}

				void runAllAppMethods(A& a_app){
					invokeAll<Note,A&>(g_app_events, a_app);
				}

			protected:
				MethodMap<Note> g_events;
				MethodMap<Note,A&> g_app_events;
		};

	}

#endif
