
#ifndef CONFIGURATION_PostMessageRedirection_hpp
#define CONFIGURATION_PostMessageRedirection_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_PostMessageRedirection)
		#define PostMessageRedirection_hpp
	#endif
#endif

#ifndef PostMessageRedirection_hpp
#define PostMessageRedirection_hpp
#define PostMessageRedirection_AVAILABLE

#include "Command.hpp"
#include "SerialPost.hpp"
#include "NoteHelper.hpp"
#include "Class.hpp"

namespace ame{

class PostMessageRedirection : public Command<Note>{
    public:
		PostMessageRedirection(){}
		PostMessageRedirection(SerialPost* c_serialPost){
			m_serialPost = c_serialPost;
		}
		virtual ~PostMessageRedirection(){}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<PostMessageRedirection<Note>>::getClass();}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<PostMessageRedirection<Note>>::getClass();
		}
		#endif
		
		virtual void execute(Note* a_execute){
			if (a_execute == nullptr || m_serialPost == nullptr) {
				System::console.println("a_execute == nullptr || m_serialPost == nullptr");
				return;
			}
			System::console.println("PostMessageRedirection");
			
			PrimitiveList<Note> commands = splitFirstNote(4, *a_execute, ' ');

			if(commands.getPosition() != 4){
				return;
			}
			Note command_0 = commands[0];
			Note command_1 = commands[1];
			Note command_2 = commands[2];
			Note command_3 = commands[3];
			if (command_0 == "ram") {
				System::console.print("ram: ");
				System::console.println(getRamSize());
			}
		}
		
	protected:
		SerialPost* m_serialPost = nullptr;
};

}

#endif