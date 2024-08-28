
#ifndef Parser_hpp
#define Parser_hpp
#define Parser_AVAILABLE

#include "PrimitiveList.hpp"
#include "Lexer.hpp"
#include "FullTree.hpp"

namespace pankey{

class TokenStructure{
	public:
		TokenStructure(){}
		TokenStructure(int a_parallel_priority, int a_serial_priority, Token a_sustitution){
			m_parallel_priority = a_parallel_priority;
			m_serial_priority = a_serial_priority;
			m_sustitution = a_sustitution;
		}
		TokenStructure(Token a_sustitution){
			m_sustitution = a_sustitution;
		}
		virtual ~TokenStructure(){}

		virtual PrimitiveList<Token>& getStructure(){
			return this->m_structure;
		}

		virtual void operator=(const TokenStructure& a_node){
			
		}

		virtual bool operator==(const TokenStructure& a_node){
			return false;
		}

		virtual bool operator!=(const TokenStructure& a_node){
			return false;
		}

	protected:
		int m_parallel_priority = 50;
		int m_serial_priority = 50;
		Token m_sustitution;
		PrimitiveList<Token> m_structure;
};

class Parser IMPLEMENTATION_cppObject {
    public:
		Parser(){}
		virtual ~Parser(){}
		
		template<class... Args>
		void addTokenStructure(int a_parallel_priority, int a_serial_priority, Token a_sustitution, Args... a_tokens){
			TokenStructure* i_structure = new TokenStructure(a_parallel_priority, a_serial_priority, a_sustitution);
			PrimitiveList<Token>& i_list = i_structure->getStructure();
			i_list.addPack(a_tokens...);
			this->m_token_structure_list.addPointer(i_structure);
		}
		
		template<class... Args>
		void addTokenStructure(int a_parallel_priority, Token a_sustitution, Args... a_tokens){
			this->addTokenStructure(a_parallel_priority, a_parallel_priority, a_sustitution, a_tokens...);
		}
		
		template<class... Args>
		void addTokenStructure(Token a_sustitution, Args... a_tokens){
			this->addTokenStructure(50, 50, a_sustitution, a_tokens...);
		}

	protected:

		virtual void FillTreeList(PrimitiveList<Token>& a_lexer_tokens, PrimitiveList<FullTree<Token>>& a_tree_list){
			for(int x = 0; x < a_lexer_tokens.getPosition(); x++){
				Token* f_token = a_lexer_tokens.getByPosition(x);
				if(f_token == nullptr){
					continue;
				}
				FullTree<Token>* i_node = new FullTree<Token>();
				//i_node->set(*f_token);
				a_tree_list.addPointer(i_node);
			}
		}

		virtual void ReduceTreeList(PrimitiveList<FullTree<Token>>& a_tree_list){
			for(int x = 0; x < a_tree_list.getPosition(); x++){
				FullTree<Token>* f_tree = a_tree_list.getByPosition(x);
				if(f_tree == nullptr){
					continue;
				}
				FullTree<Token>* i_node = new FullTree<Token>();
				//i_node->set(*f_token);
			}
		}

	public:

		virtual FullTree<Token>& generateTree(PrimitiveList<Token>& a_tokens){
			//this->m_tree.clear();

			if(a_tokens.isEmpty()){
				return this->m_tree;
			}

			PrimitiveList<FullTree<Token>> i_tree_list;

			this->FillTreeList(a_tokens, i_tree_list);

			this->ReduceTreeList(i_tree_list);

			if(i_tree_list.getPosition() != 1){
				return this->m_tree;
			}

			FullTree<Token>* i_tree = i_tree_list.getByPosition(0);
			if(i_tree == nullptr){
				return this->m_tree;
			}

			//this->m_tree.addPointer(i_tree);

			return this->m_tree;
		}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){
			return Class<Parser>::getClass();
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<Parser>::getClass();
		}
		#endif
		
	protected:
		PrimitiveList<TokenStructure> m_token_structure_list;
		FullTree<Token> m_tree;
};

}

#endif 
