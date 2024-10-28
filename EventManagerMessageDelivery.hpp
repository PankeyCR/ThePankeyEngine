
#ifndef EventManagerMessageDelivery_hpp
	#define EventManagerMessageDelivery_hpp

	#include "Application.hpp"
	#include "Command.hpp"
	#include "Note.hpp"

	namespace pankey{

		class EventManagerMessageDelivery : public Command<Application&,const Note&>{
			public:
				EventManagerMessageDelivery(){}
				EventManagerMessageDelivery(const Note& a_sender){
					sender = a_sender;
				}
				EventManagerMessageDelivery(const EventManagerMessageDelivery& a_event){
					sender = a_event.sender;
				}
				virtual ~EventManagerMessageDelivery(){}

				Note sender = "send_message";

				virtual void execute(Application& a_app, const Note& a_message){
					int i_message_size = a_message.getPartSize(' ');
					if(i_message_size == 3){
						Note i_command_1 = a_message.split(0, ' ');
						Note i_command_2 = a_message.split(1, ' ');
						Note i_command_3 = a_message.split(2, ' ');
						if(i_command_1 == "EventManager" && i_command_2 == "run" && !i_command_3.isEmpty()){
							a_app.run(i_command_3);
						}
						if(i_command_1 == "EventManager" && i_command_2 == "runMethod" && !i_command_3.isEmpty()){
							a_app.runMethod(i_command_3);
						}
						if(i_command_1 == "EventManager" && i_command_2 == "runAppMethod" && !i_command_3.isEmpty()){
							a_app.runAppMethod(i_command_3);
						}
					}
					if(i_message_size == 4){
						Note i_command_1 = a_message.split(0, ' ');
						Note i_command_2 = a_message.split(1, ' ');
						Note i_command_3 = a_message.split(2, ' ');
						Note i_command_4 = a_message.split(3, ' ');
						if(i_command_1 == "EventManager" && i_command_2 == "run" && !i_command_3.isEmpty()){
							a_app.run(i_command_3, i_command_4);
						}
						if(i_command_1 == "EventManager" && i_command_2 == "runMessageMethod" && !i_command_3.isEmpty()){
							a_app.runMessageMethod(i_command_3, i_command_4);
						}
						if(i_command_1 == "EventManager" && i_command_2 == "runAppMessageMethod" && !i_command_3.isEmpty()){
							a_app.runAppMessageMethod(i_command_3, i_command_4);
						}
					}
				}
		};
	}

#endif
