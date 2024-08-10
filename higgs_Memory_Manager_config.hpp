
#ifndef higgs_Memory_Manager_config_hpp
    #define higgs_Memory_Manager_config_hpp

	#include "Data.hpp"
	#include "Variable.hpp"
	#include "Pointer.hpp"
	#include "Instance.hpp"
	#include "Value.hpp"
	#include "Object.hpp"
	#include "Self.hpp"
	
	#include "State.hpp"
	#include "AppState.hpp"
	
	#include "MemberArrayStorage.hpp"
	#include "MemberArrayList.hpp"
	#include "TypeList.hpp"
	#include "ObjectList.hpp"
	
	#include "DuoMember.hpp"
	#include "MemberArrayTableStorage.hpp"
	#include "MemberArrayMap.hpp"

	#include "UniversalHolder.hpp"
	#include "UniversalManager.hpp"
	
	// #include "Class.hpp"
	// #include "cppObjectClass.hpp"

	// #include "StorageManager.hpp"
	// #include "PointerArrayStorageAllocator.hpp"

	#define higgs_CREATE_ALLOCATOR(HOLDER) HOLDER,HOLDER,UniversalManager
	#define higgs_ENGINE_CREATE_ALLOCATOR() UniversalHolder,UniversalHolder,UniversalManager

	#define higgs_MEMORY_HOLDER UniversalHolder
	#define higgs_MEMORY_HOLDER_ALLOCATOR UniversalHolder,UniversalHolder
	#define higgs_POINTER_ALLOCATOR(TYPE,HOLDER) TYPE,HOLDER,HOLDER
	#define higgs_ENGINE_POINTER_ALLOCATOR(TYPE) TYPE,UniversalHolder,UniversalHolder

	
	namespace higgs{

		using data = Data<higgs_MEMORY_HOLDER>;

		using member = Member<higgs_MEMORY_HOLDER_ALLOCATOR>;

		using var = Variable<higgs_MEMORY_HOLDER_ALLOCATOR>;

		template<class P>
		using pointer = Pointer<higgs_ENGINE_POINTER_ALLOCATOR(P)>;

		template<class P>
		using instance = Instance<higgs_ENGINE_POINTER_ALLOCATOR(P)>;

		template<class P>
		using val = Value<higgs_ENGINE_POINTER_ALLOCATOR(P)>;

		template<class P>
		using self = Self<higgs_ENGINE_POINTER_ALLOCATOR(P)>;

		template<class P>
		using obj = Object<higgs_ENGINE_POINTER_ALLOCATOR(P)>;

		using object = Object<higgs_ENGINE_POINTER_ALLOCATOR(int)>;
		
		template<class... Args>
		using state = obj<State<Args...>>;
		
		template<class A, class... Args>
		using app_state = obj<AppState<A,Args...>>;

		using MAStorage = MemberArrayStorage<higgs_MEMORY_HOLDER_ALLOCATOR>;

		using List = MemberArrayList<higgs_MEMORY_HOLDER_ALLOCATOR>;

		template<class P>
		using TList = TypeList<higgs_ENGINE_POINTER_ALLOCATOR(P)>;

		template<class O>
		using OList = ObjectList<higgs_ENGINE_POINTER_ALLOCATOR(O)>;

		// using LinkedList = MemberLinkedList<higgs_MEMORY_HOLDER_ALLOCATOR>;

		// template<class P>
		// using TLinkedList = TypeLinkedList<higgs_ENGINE_POINTER_ALLOCATOR(P)>;

		// template<class O>
		// using OLinkedList = ObjectLinkedList<higgs_ENGINE_POINTER_ALLOCATOR(O)>;

		using duo = DuoMember<higgs_MEMORY_HOLDER_ALLOCATOR>;

		// using TDuo = MemberMapEntry<higgs_MEMORY_HOLDER_ALLOCATOR>;

		using table = MemberArrayTableStorage<higgs_MEMORY_HOLDER_ALLOCATOR>;

		// template<class K, class V>
		// using MAMap = MemberArrayMap<K,V,higgs_MEMORY_HOLDER_ALLOCATOR>;

		// using HashMap = MemberHashMap<higgs_MEMORY_HOLDER_ALLOCATOR>;

		using Map = MemberArrayMap<higgs_MEMORY_HOLDER_ALLOCATOR>;

		// template<class P>
		// using THashMap = TypeHashMap<higgs_ENGINE_POINTER_ALLOCATOR(P)>;

		// template<class O>
		// using OHashMap = ObjectHashMap<higgs_ENGINE_POINTER_ALLOCATOR(O)>;

		// using type = Class<cppObjectClass>;

		void createEngineManager(){
			createManager<higgs_ENGINE_CREATE_ALLOCATOR()>();
		}

		template<class H>
        var VarHolder(const MemoryHolder<H>& a_holder){
            var i_var;
            i_var.copyMemoryHolder(a_holder);
            return i_var;
        }

		template<class O, class H = higgs_MEMORY_HOLDER>
        obj<O> ObjHolder(const MemoryHolder<H>& a_holder){
            obj<O> i_obj;
            i_obj.copyMemoryHolder(a_holder);
            return i_obj;
        }
		
    }


#endif