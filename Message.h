

#ifndef Message_h
#define Message_h

class Message{
    public:
		Message(){}
		Message(String txt){
			m_text = txt;
		}
		Message(int i,String txt){
			m_id = i;
			m_text = txt;
		}
		Message(String mType,String txt){
			m_type = mType;
			m_text = txt;
		}
		Message(String mType,int i,String txt){
			m_type = mType;
			m_id = i;
			m_text = txt;
		}
		~Message(){}
		
		int id(){
			return m_id;
		}
		String text(){
			return m_text;
		}
		String type(){
			return m_type;
		}
		
		void id(int i){
			m_id = i;
		}
		void text(String t){
			m_text = t;
		}
		void type(String t){
			m_type = t;
		}
		virtual void operator=(String b){
			m_text = b;
		}
		virtual void operator=(Message b){
			m_id = b.m_id;
			m_text = b.m_text;
			m_type = b.m_type;
		}
		virtual bool operator==(Message b){
			return m_id == b.m_id && m_text == b.m_text && m_type == b.m_type;
		}
		virtual bool operator!=(Message b){
			return m_id != b.m_id && m_text != b.m_text && m_type != b.m_type;
		}
	protected:
		int m_id = -1;
		String m_text = "";
		String m_type = "normal";
};

#endif 
