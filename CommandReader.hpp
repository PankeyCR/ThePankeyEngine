
#ifndef CommandReader_hpp
#define CommandReader_hpp

#include "Arduino.h"

#ifdef CommandReaderLogApp
	#include "Logger.hpp"
	#define CommandReaderLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define CommandReaderLog(name,method,type,mns)
#endif

namespace ame{

class CommandReader{
    public:
		CommandReader(){
			CommandReaderLog("CommandReader", "Constructor",  "println", "");
		}
		CommandReader(String t){
			CommandReaderLog("CommandReader", "Constructor",  "println", "");
			setText(t);
		}
		virtual ~CommandReader(){
			CommandReaderLog("CommandReader", "Constructor",  "println", "");
		}
		
		void setText(String t){
			CommandReaderLog("CommandReader", "setText",  "println", t);
			text = t;
		}
		
		String getText(){
			CommandReaderLog("CommandReader", "getText",  "println", text);
			return text;
		}
		
		int getCommandOrder(String t, char split, char end){
			CommandReaderLog("CommandReader", "getCommandOrder",  "println", String("command ") +  t);
			String c = "";
			bool init = true;
			int gcmd = 0;
			for(int x = 0; x < text.length(); x++){
				char cr = text.charAt(x);
				CommandReaderLog("CommandReader", "getCommandOrder",  "println", String("char = ") + String(cr));
				if(cr == end){
					CommandReaderLog("CommandReader", "getCommandOrder",  "println", "char == endLine");
					init = true;
					if(t == c){
						CommandReaderLog("CommandReader", "getCommandOrder",  "println", String("returning line of command") + String(gcmd));
						return gcmd;
					}
					gcmd++;
					c = "";
					CommandReaderLog("CommandReader", "getCommandOrder",  "println", "continue to other line");
					continue;
				}
				if(init){
					CommandReaderLog("CommandReader", "getCommandOrder",  "println", "capturing char");
					if(cr == split){
						CommandReaderLog("CommandReader", "getCommandOrder",  "println", "char == splitChar");
						if(t == c){
							CommandReaderLog("CommandReader", "getCommandOrder",  "println", String("returning line of command") + String(gcmd));
							return gcmd;
						}
						CommandReaderLog("CommandReader", "getCommandOrder",  "println", "stop capturing char command");
						init = false;
						continue;
					}
					c.concat(cr);
				}
			}
			return -1;
		}
		
		int getCommandOrder(String t){
			int cmdO = getCommandOrder(t, '#', '$');
			if(cmdO == -1){
				return getCommandOrder(t, ' ', '\n');
			}
			return cmdO;
		}
		
		String getLine(int l, char end){
			String c = "";
			int gcmd = 0;
			for(int x = 0; x < text.length(); x++){
				char cr = text.charAt(x);
				if(cr == end){
					if(gcmd == l){
						return c;
					}
					c = "";
					gcmd++;
					continue;
				}
				c.concat(cr);
			}
			return "";
		}
		
		String getLine(int l){
			String cmdO = getLine(l, '$');
			if(cmdO == ""){
				return getLine(l, '\n');
			}
			return cmdO;
		}
		
		void removeLine(int line, char end){
			if(line == -1){
				return;
			}
			String newTxt = "";
			int xLine = 0;
			for(int x = 0; x < text.length(); x++){
				char ctext = text.charAt(x);
				if(ctext == end){
					xLine++;
					if(newTxt == ""){
						continue;
					}
					char cnewTxt = newTxt.charAt(newTxt.length()-1);
					if(newTxt != "" && cnewTxt != end){
						newTxt.concat(end);
					}
					continue;
				}
				if(xLine != line){
					newTxt.concat(ctext);
				}
			}
			text = newTxt;
		}
		
		void removeLine(String txt){
			int cmdO = getCommandOrder(txt, '#', '$');
			char c = '$';
			if(cmdO == -1){
				cmdO = getCommandOrder(txt, ' ', '\n');
				c = '\n';
			}
			if(cmdO == -1){
				return;
			}
			removeLine(cmdO, c);
		}
		
		void overwriteLine(int line, String txt, char end){
			
		}
		
		void writeLine(int line, String txt, char end){
			String newTxt = "";
			int xLine = 0;
			int xTxt = 0;
			int xText = 0;
			for(int x = 0; x < text.length() + txt.length(); x++){
				char ctext = text.charAt(xText);
				char ctxt = txt.charAt(xTxt);
				if(ctext == end){
					xLine++;
					xText++;
					newTxt.concat(end);
					continue;
				}
				if((xLine == line || xText >= text.length())){
					newTxt.concat(ctxt);
					xTxt++;
					if(xTxt == txt.length()){
						newTxt.concat('\n');
						xLine++;
					}
				}else{
					newTxt.concat(ctext);
					xText++;
				}
			}
			text = newTxt;
		}
		
		void writeLine(int line, String txt){
			writeLine(line, txt, '\n');
		}
		
		void writeLine(String cmdt, String txt){
			int line = getCommandOrder(cmdt, '#', '$');
			char c = '$';
			if(line == -1){
				line = getCommandOrder(cmdt, ' ', '\n');
				c = '\n';
			}
			if(line == -1){
				return;
			}
			writeLine(line,txt,c);
			removeLine(line + 1,c);
		}
		
		String getCommand(int l, char split, char end){
			String c = "";
			bool init = true;
			int gcmd = 0;
			for(int x = 0; x < text.length(); x++){
				char cr = text.charAt(x);
				if(cr == end){
					if(gcmd == l){
						return c;
					}
					init = true;
					gcmd++;
					c = "";
					continue;
				}
				if(init){
					if(cr == split){
						if(gcmd == l){
							return c;
						}
						init = false;
						c = "";
						continue;
					}
					c.concat(cr);
				}
			}
			return "";
		}
		
		String getCommand(int l){
			String cmdO = getCommand(l, '#', '$');
			if(cmdO == ""){
				return getCommand(l, ' ', '\n');
			}
			return cmdO;
		}
		
		String getArgument(int l, char split, char end){
			String c = "";
			bool init = false;
			int gcmd = 0;
			for(int x = 0; x < text.length(); x++){
				char cr = text.charAt(x);
				if(cr == end){
					if(gcmd == l){
						return c;
					}
					gcmd++;
					c = "";
					init = false;
					continue;
				}
				if(cr == split && !init){
					init = true;
					continue;
				}
				if(init && gcmd == l){
					c.concat(cr);
				}
			}
			if(gcmd == l){
				return c;
			}
			return "";
		}
		
		String getArgument(int l){
			String cmdO = getArgument(l, '#', '$');
			if(cmdO == ""){
				return getArgument(l, ' ', '\n');
			}
			return cmdO;
		}
		
		int getSize(char split){
			int gcmd = -1;
			for(int x = 0; x < text.length(); x++){
				char cr = text.charAt(x);
				if(cr == split){
					if(gcmd == -1){
						gcmd = 0;
					}
					gcmd++;
					continue;
				}
			}
			return gcmd;
		}
		
		int getEnterSize(){
			int cmdO = getSize('$');
			if(cmdO == -1){
				return getSize('\n');
			}
			return cmdO;
		}
		
		int getSizeNoStartNoEnd(String txt, char split){
			int gcmd = 0;
			for(int x = 0; x < txt.length(); x++){
				char cr = txt.charAt(x);
				if(cr == split){
					gcmd++;
					continue;
				}
			}
			return gcmd + 1;
		}
		
		int getEnterSizeNoStartNoEnd(String txt){
			return getSizeNoStartNoEnd(txt,'\n');
		}
		
		String split(String txt, int arg, char splitChar){
			String c = "";
			bool init = true;
			int gcmd = 0;
			for(int x = 0; x < txt.length(); x++){
				char cr = txt.charAt(x);
				if(cr == splitChar){
					if(gcmd == arg){
						return c;
					}
					c = "";
					gcmd++;
					continue;
				}
				c.concat(cr);
			}
			if(gcmd == arg){
				return c;
			}
			return "";
		}
		
		String split(String txt, int arg, String splitString){
			String c = "";
			bool init = true;
			int gcmd = 0;
			int splitPos = 0;
			for(int x = 0; x < txt.length(); x++){
				char cr = txt.charAt(x);
				char sChar = splitString.charAt(splitPos);
				if(cr == sChar){
					if(splitPos >= splitString.length()){
						if(gcmd == arg){
							return c.substring(0,splitPos);
						}
					}else{
						c = "";
						splitPos++;
					}
				}else{
					splitPos = 0;
				}
				if(x == txt.length() - 1){
					return c.substring(0,splitPos);
				}
				c.concat(cr);
			}
			return "";
		}
		
	protected:
		String text = "";
};

}

#endif
