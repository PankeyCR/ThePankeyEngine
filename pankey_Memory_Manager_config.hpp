
#ifndef pankey_Memory_Manager_config_hpp
    #define pankey_Memory_Manager_config_hpp

	#include "Data.hpp"
	#include "Variable.hpp"
	#include "Pointer.hpp"
	#include "Instance.hpp"
	#include "Value.hpp"
	#include "Object.hpp"
	#include "Self.hpp"

	#include "Command.hpp"
	#include "CommandReturn.hpp"
	
	#include "State.hpp"
	#include "AppState.hpp"
	
	#include "MemberArrayStorage.hpp"
	#include "MemberArrayList.hpp"
	#include "TypeList.hpp"
	#include "ObjectList.hpp"
	
	#include "DuoMember.hpp"
	#include "DuoTypeMember.hpp"
	#include "MemberArrayTableStorage.hpp"
	#include "MemberArrayMap.hpp"
	#include "TypeArrayMap.hpp"
	#include "ObjectArrayMap.hpp"

	#include "UniversalHolder.hpp"
	#include "UniversalManager.hpp"

	#include "ClassCount.hpp"
	
	// #include "Class.hpp"
	// #include "cppObjectClass.hpp"

	// #include "StorageManager.hpp"
	// #include "PointerArrayStorage.hpp"
	// #include "PointerArrayStorageAllocator.hpp"

	#define pankey_CREATE_ALLOCATOR(HOLDER) HOLDER,HOLDER,UniversalManager
	#define pankey_ENGINE_CREATE_ALLOCATOR() UniversalHolder,UniversalHolder,UniversalManager

	#define pankey_MEMORY_HOLDER UniversalHolder
	#define pankey_MEMORY_HOLDER_ALLOCATOR UniversalHolder,UniversalHolder
	#define pankey_POINTER_ALLOCATOR(TYPE,HOLDER) TYPE,HOLDER,HOLDER
	#define pankey_ENGINE_POINTER_ALLOCATOR(TYPE) TYPE,UniversalHolder,UniversalHolder

	
	namespace pankey{

		using data = Data<pankey_MEMORY_HOLDER>;

		using member = Member<pankey_MEMORY_HOLDER_ALLOCATOR>;

		using var = Variable<pankey_MEMORY_HOLDER_ALLOCATOR>;

		template<class P>
		using pointer = Pointer<pankey_ENGINE_POINTER_ALLOCATOR(P)>;

		template<class P>
		using instance = Instance<pankey_ENGINE_POINTER_ALLOCATOR(P)>;

		template<class P>
		using val = Value<pankey_ENGINE_POINTER_ALLOCATOR(P)>;

		template<class P>
		using self = Self<pankey_ENGINE_POINTER_ALLOCATOR(P)>;

		template<class P>
		using obj = Object<pankey_ENGINE_POINTER_ALLOCATOR(P)>;

		using object = Object<pankey_ENGINE_POINTER_ALLOCATOR(int)>;

		template<class... Args>
		using command = obj<Command<Args...>>;

		template<class... Args>
		using commandReturn = obj<CommandReturn<Args...>>;
		
		template<class... Args>
		using state = obj<State<Args...>>;
		
		template<class A, class... Args>
		using app_state = obj<AppState<A,Args...>>;

		// template<class P>
		// using PAStorage = PointerArrayStorage<pankey_ENGINE_POINTER_ALLOCATOR(P)>;

		using MAStorage = MemberArrayStorage<pankey_MEMORY_HOLDER_ALLOCATOR>;

		using List = MemberArrayList<pankey_MEMORY_HOLDER_ALLOCATOR>;

		template<class P>
		using TList = TypeList<pankey_ENGINE_POINTER_ALLOCATOR(P)>;

		template<class O>
		using OList = ObjectList<pankey_ENGINE_POINTER_ALLOCATOR(O)>;

		// using LinkedList = MemberLinkedList<pankey_MEMORY_HOLDER_ALLOCATOR>;

		// template<class P>
		// using TLinkedList = TypeLinkedList<pankey_ENGINE_POINTER_ALLOCATOR(P)>;

		// template<class O>
		// using OLinkedList = ObjectLinkedList<pankey_ENGINE_POINTER_ALLOCATOR(O)>;

		using duo = DuoMember<pankey_MEMORY_HOLDER_ALLOCATOR>;

		template<class K, class V>
		using duo_type = DuoTypeMember<K,V,pankey_MEMORY_HOLDER_ALLOCATOR>;

		// using TDuo = MemberMapEntry<pankey_MEMORY_HOLDER_ALLOCATOR>;

		using table = MemberArrayTableStorage<pankey_MEMORY_HOLDER_ALLOCATOR>;

		// template<class K, class V>
		// using MAMap = MemberArrayMap<K,V,pankey_MEMORY_HOLDER_ALLOCATOR>;

		// using HashMap = MemberHashMap<pankey_MEMORY_HOLDER_ALLOCATOR>;

		using Map = MemberArrayMap<pankey_MEMORY_HOLDER_ALLOCATOR>;

		template<class K, class V>
		using TMap = TypeArrayMap<K,V,pankey_MEMORY_HOLDER_ALLOCATOR>;

		template<class K, class V>
		using OMap = ObjectArrayMap<K,V,pankey_MEMORY_HOLDER_ALLOCATOR>;

		// template<class P>
		// using THashMap = TypeHashMap<pankey_ENGINE_POINTER_ALLOCATOR(P)>;

		// template<class O>
		// using OHashMap = ObjectHashMap<pankey_ENGINE_POINTER_ALLOCATOR(O)>;

		template<class T>
		using type = ClassCount<T>;

		void createEngineManager(){
			createManager<pankey_ENGINE_CREATE_ALLOCATOR()>();
		}

		template<class H>
        var VarHolder(const MemoryHolder<H>& a_holder){
            var i_var;
            i_var.copyMemoryHolder(a_holder);
            return i_var;
        }

		template<class O, class H = pankey_MEMORY_HOLDER>
        obj<O> ObjHolder(const MemoryHolder<H>& a_holder){
            obj<O> i_obj;
            i_obj.copyMemoryHolder(a_holder);
            return i_obj;
        }
		
    }


#endif