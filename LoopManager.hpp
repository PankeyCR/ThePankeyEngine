
#ifndef LoopManager_hpp
	#define LoopManager_hpp

	#include "UpdateManager.hpp"

	#include "Note.hpp"

	#include "UpdateFunctionListManager.hpp"
	#include "UpdateClassFunctionListManager.hpp"
	#include "StateListManager.hpp"
	#include "AppStateListManager.hpp"

	#include "UpdateFunctionMapManager.hpp"
	#include "UpdateClassFunctionMapManager.hpp"
	// #include "AppStateMapManager.hpp"

	#ifdef LoopManager_LogApp
		#include "pankey_Logger.hpp"
		#define LoopManagerLog(location,method,type,mns) pankey_Log(this,location,"LoopManager",method,type,mns)
	#else
		#define LoopManagerLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class A>
		class LoopManager : public UpdateManager<A&,long>{
			public:
				LoopManager(){
					LoopManagerLog(pankey_Log_StartMethod, "Constructor", "println", "");
					LoopManagerLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				virtual ~LoopManager(){
					LoopManagerLog(pankey_Log_StartMethod, "Destructor", "println", "");
					LoopManagerLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual void removeAll(){
					init_functions_list.removeAll();
					init_app_functions_list.removeAll();
					
					init_class_functions_list.removeAll();

					functions_list.removeAll();
					app_functions_list.removeAll();
					timed_functions_list.removeAll();
					app_timed_functions_list.removeAll();
					
					class_functions_list.removeAll();
					class_timed_functions_list.removeAll();
					
					state_functions_list.removeAll();
					state_timed_functions_list.removeAll();
					
					app_state_functions_list.removeAll();
					app_state_timed_functions_list.removeAll();
					
					functions_map.removeAll();
					app_functions_map.removeAll();
					timed_functions_map.removeAll();
					app_timed_functions_map.removeAll();
					
					class_functions_map.removeAll();
					class_timed_functions_map.removeAll();
					
					// app_state_functions_map.removeAll();
				}

				virtual void initialize(A& a_app){
					init_functions_list.update();
					init_app_functions_list.update(a_app);
					
					init_class_functions_list.update(a_app);

					state_functions_list.initialize();
					state_timed_functions_list.initialize();

					app_state_functions_list.initialize(a_app);
					app_state_timed_functions_list.initialize(a_app);
				}

				virtual void update(A& a_app, long a_tpc){
					LoopManagerLog(pankey_Log_StartMethod, "update",  "println", "");
					functions_list.update();
					app_functions_list.update(a_app);
					timed_functions_list.update(a_tpc);
					app_timed_functions_list.update(a_app, a_tpc);

					class_functions_list.update(a_app);
					class_timed_functions_list.update(a_app, a_tpc);
					
					state_functions_list.update();
					state_timed_functions_list.update(a_tpc);
					
					app_state_functions_list.update(a_app);
					app_state_timed_functions_list.update(a_app, a_tpc);
					
					functions_map.update();
					app_functions_map.update(a_app);
					timed_functions_map.update(a_tpc);
					app_timed_functions_map.update(a_app, a_tpc);

					class_functions_map.update(a_app);
					class_timed_functions_map.update(a_app, a_tpc);
					
					// app_state_functions_map.update(a_app, a_tpc);
					LoopManagerLog(pankey_Log_EndMethod, "update",  "println", "");
				}

			public:
				//initialize
				UpdateFunctionListManager<> init_functions_list;
				UpdateFunctionListManager<A&> init_app_functions_list;

				UpdateClassFunctionListManager<A> init_class_functions_list;

				//update
				UpdateFunctionListManager<> functions_list;
				UpdateFunctionListManager<A&> app_functions_list;
				UpdateFunctionListManager<long> timed_functions_list;
				UpdateFunctionListManager<A&,long> app_timed_functions_list;

				UpdateClassFunctionListManager<A> class_functions_list;
				UpdateClassFunctionListManager<A,long> class_timed_functions_list;
				
				StateListManager<> state_functions_list;
				StateListManager<long> state_timed_functions_list;
				
				AppStateListManager<A> app_state_functions_list;
				AppStateListManager<A,long> app_state_timed_functions_list;

				UpdateFunctionMapManager<Note> functions_map;
				UpdateFunctionMapManager<Note,A&> app_functions_map;
				UpdateFunctionMapManager<Note,long> timed_functions_map;
				UpdateFunctionMapManager<Note,A&,long> app_timed_functions_map;

				UpdateClassFunctionMapManager<A,Note> class_functions_map;
				UpdateClassFunctionMapManager<A,Note,long> class_timed_functions_map;
				
				// AppStateMapManager<A,long> app_state_functions_map;
		};

	}

#endif