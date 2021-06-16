
#ifndef BaseInvoke_h
#define BaseInvoke_h

class BaseInvoke{
public:
BaseInvoke(){}
virtual ~BaseInvoke(){}
virtual bool invokeGlobal(String method){return true;}
virtual bool invokeGlobal(String method, String parameter1){return true;}
virtual bool invokeGlobal(String method, String parameter1, String parameter2){return true;}
virtual bool invokeGlobal(String method, String parameter1, String parameter2, String parameter3){return true;}
virtual bool invokeGlobal(String method, String parameter1, String parameter2, String parameter3, String parameter4){return true;}
virtual bool invoke(String method){return true;}
virtual bool invoke(String method, String parameter1){return true;}
virtual bool invoke(String method, String parameter1, String parameter2){return true;}
virtual bool invoke(String method, String parameter1, String parameter2, String parameter3){return true;}
virtual bool invoke(String method, String parameter1, String parameter2, String parameter3, String parameter4){return true;}
virtual void operator=(BaseInvoke b){}
virtual bool operator==(BaseInvoke b){return true;}
virtual bool operator!=(BaseInvoke b){return true;}
void type(String t){m_type = t;}
void messageId(int i){m_id = i;}
String type(){return m_type;}
int messageId(){return m_id;}
protected:
String m_type;
int m_id;
};

#endif 
