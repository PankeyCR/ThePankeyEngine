
#ifndef PrimitiveRawPointerTree_hpp
	#define PrimitiveRawPointerTree_hpp

	#include "RawPointerTree.hpp"
	#include "PrimitiveRawPointerTree.hpp"

	#ifdef PrimitiveRawPointerTree_LogApp
		#include "higgs_Logger.hpp"
		#define PrimitiveRawPointerTreeLog(location,method,type,mns) higgs_Log((void*)this,location,"PrimitiveRawPointerTree",method,type,mns)
	#else
		#define PrimitiveRawPointerTreeLog(location,method,type,mns)
	#endif

	namespace higgs{

		template<class T>
		class PrimitiveRawPointerTree : virtual public RawPointerTree<T>{
			public:
				PrimitiveRawPointerTree(){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "Constructor", "println", "");
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}
				
				//all copys have no ownership over the branches
				PrimitiveRawPointerTree(const PrimitiveRawPointerTree<T>& a_list){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "Constructor", "println", "");
					this->expandLocal(a_list.getSize());
					this->setBranchOwner(false);
					for(int x = 0; x < a_list.getPosition(); x++){
						this->addBranchPointer(a_list.getBranchByPosition(x));
					}
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}
				
				PrimitiveRawPointerTree(int c_size, bool c_own, bool c_reordering){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "Constructor", "println", "");
					this->m_branch_owner = c_own;
					this->m_reorder = c_reordering;
					this->expandLocal(c_size);
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}
				
				virtual ~PrimitiveRawPointerTree(){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "Destructor", "println", "");
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "Destructor", "println", "position: ");
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "Destructor", "println", this->getPosition());
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "Destructor", "println", "size: ");
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "Destructor", "println", this->getSize());
					if(this->m_tree_values != nullptr){
						PrimitiveRawPointerTreeLog(higgs_Log_Statement, "Destructor", "println", "this->m_tree_values != nullptr");
						if(this->m_branch_owner){
							PrimitiveRawPointerTreeLog(higgs_Log_Statement, "Destructor", "println", "this->m_branch_owner");
							for(int x=0; x < this->getPosition() ; x++){
								PrimitiveRawPointerTreeLog(higgs_Log_Statement, "Destructor", "println", "delete iteration: ");
								PrimitiveRawPointerTreeLog(higgs_Log_Statement, "Destructor", "println", x);
								if(this->m_tree_values[x] != nullptr){
									PrimitiveRawPointerTreeLog(higgs_Log_Statement, "Destructor", "println", "this->m_tree_values[x] != nullptr");
									delete this->m_tree_values[x];
								}
							}
						}
						this->setPosition(0);
						this->setSize(0);
						delete[] this->m_tree_values;
						this->m_tree_values = nullptr;
					}
					if(this->m_var != nullptr){
						if(this->m_value_owner){
							delete this->m_var;
						}
						this->m_var = nullptr;
					}
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "Destructor", "println", "");
				}
                
                virtual T* set(T* a_value){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "Destructor", "println", "");
					this->m_var = a_value;
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "Destructor", "println", "");
					return this->m_var;
				}
                
                virtual T* get(){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "Destructor", "println", "");
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "Destructor", "println", "");
					return this->m_var;
				}
                
                virtual T* remove(){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "Destructor", "println", "");
					T* i_var = this->m_var;
					this->m_var = nullptr;
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "Destructor", "println", "");
					return i_var;
				}
                
                virtual bool isEmpty()const{
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "isEmpty", "println", "");
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "isEmpty", "println", this->m_tree_values == nullptr || this->m_position <= 0);
					return this->m_tree_values == nullptr || this->m_position <= 0;
				}
			
				virtual bool replaceBranch(int i, int j){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "replaceBranch", "println", "");
					if(i >= this->getPosition() || j >= this->getPosition()){
						return false;
					}
					RawPointerTree<T>* it = this->m_tree_values[i];
					RawPointerTree<T>* jt = this->m_tree_values[j];
					this->m_tree_values[i] = jt;
					this->m_tree_values[j] = it;
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "replaceBranch", "println", "");
					return true;
				}

                virtual RawPointerTree<T>* addBranchPointer(RawPointerTree<T>* a_value){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "addBranchPointer", "println", "");
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "addBranchPointer", "println", "List Position Before adding:");
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "addBranchPointer", "println", this->getPosition());
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "addBranchPointer", "println", "List Size Before adding:");
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "addBranchPointer", "println", this->getSize());
					if(this->getPosition() >= this->getSize()){
						PrimitiveRawPointerTreeLog(higgs_Log_Statement, "addBranchPointer", "println", "this->getPosition() >= this->getSize()");
						this->expandLocal(this->m_expandSize);
					}
					if(this->getPosition() >= this->getSize()){
						PrimitiveRawPointerTreeLog(higgs_Log_Statement, "addBranchPointer", "println", "this->getPosition() >= this->getSize()");
						if(a_value != nullptr && this->isBranchOwner()){
							PrimitiveRawPointerTreeLog(higgs_Log_Statement, "addBranchPointer", "println", "deleting pointer");
							delete a_value;
						}
						return nullptr;
					}
					this->m_tree_values[this->getPosition()] = a_value;
					if(a_value != nullptr){
						a_value->setParent(this);
						a_value->setBranchPosition(this->getPosition());
					}
					this->incrementPosition();
					
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "addBranchPointer", "println", "List Position After adding:");
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "addBranchPointer", "println", this->getPosition());
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "addBranchPointer", "println", "List Size After adding:");
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "addBranchPointer", "println", this->getSize());	
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "addBranchPointer", "println", "");
					return a_value;
				}

                virtual RawPointerTree<T>* setBranchPointer(int a_position, RawPointerTree<T>* a_value){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "setBranchPointer", "println", "");
					if(a_position >= this->getSize()){
						PrimitiveRawPointerTreeLog(higgs_Log_Statement, "setBranchPointer", "println", "exanding");
						this->expandLocal(a_position - this->getSize() + this->m_expandSize);
					}
					if(a_position >= this->getSize()){
						PrimitiveRawPointerTreeLog(higgs_Log_Statement, "setBranchPointer", "println", "a_position >= this->getSize()");
						if(a_value != nullptr && this->isBranchOwner()){
							delete a_value;
						}
						PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "setBranchPointer", "println", "");
						return nullptr;			
					}
					RawPointerTree<T>* i_value = this->getBranchByPosition(a_position);
					if(a_value == i_value){
						PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "setBranchPointer", "println", "a_value == i_value");
						return a_value;
					}
					if(this->isBranchOwner() && i_value != nullptr){
						PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "setBranchPointer", "println", "delete i_value");
						delete i_value;
					}
					this->m_tree_values[a_position] = a_value;
					if(a_position >= this->getPosition()){
						PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "setBranchPointer", "println", "a_position >= this->getPosition()");
						this->setPosition(a_position + 1);
					}
					if(a_value != nullptr){
						PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "setBranchPointer", "println", "set parent to a_value");
						a_value->setParent(this);
						a_value->setBranchPosition(a_position);
					}
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "setBranchPointer", "println", "");
					return a_value;
				}
				
				virtual RawPointerTree<T>* insertBranchPointer(int a_position, RawPointerTree<T>* a_value){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "insertPointer", "println", "");
					if(a_position >= this->getPosition()){
						PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "insertPointer", "println", "a_position >= this->getPosition()");
						return this->addBranchPointer(a_value);
					}
					if(this->getPosition() >= this->getSize()){
						this->expandLocal(this->m_expandSize);
					}
					if(this->getPosition() >= this->getSize()){
						if(a_value != nullptr && this->isBranchOwner()){
							delete a_value;
						}
						return nullptr;
					}
					RawPointerTree<T>* nVaule;
					RawPointerTree<T>* rVaule = a_value;
					if(a_value != nullptr){
						a_value->setParent(this);
						a_value->setBranchPosition(a_position);
					}
					for(int x = a_position; x <= this->getPosition(); x++){
						nVaule = this->m_tree_values[x];
						this->m_tree_values[x] = rVaule;
						if(a_value != nullptr){
							this->m_tree_values[x]->setBranchPosition(x);
						}
						rVaule = nVaule;
					}
					this->incrementPosition();
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "insertPointer", "println", "");
					return a_value;
				}
				
				virtual RawPointerTree<T>* getBranchByPointer(RawPointerTree<T>* a_value){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "getBranchByPointer", "println", "");
					if(this->isEmpty()){
						return nullptr;
					}
					for(int x = 0; x < this->getPosition(); x++){
						if(a_value == this->m_tree_values[x]){
							return a_value;
						}
					}
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "getBranchByPointer", "println", "");
					return nullptr;
				}
				
				virtual RawPointerTree<T>* getBranchByPosition(int x)const{
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "getBranchByPosition", "println", "");
					if(this->isEmpty() || x >= this->getPosition()){
						return nullptr;
					}
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "getBranchByPosition", "println", "");
					return this->m_tree_values[x];
				}

                virtual bool containBranchByPointer(RawPointerTree<T>* a_value){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "containBranchByPointer", "println", "");
					if(this->isEmpty()){
						PrimitiveRawPointerTreeLog(higgs_Log_Statement, "containBranchByPointer", "println", "this->isEmpty()");
						PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "containBranchByPointer", "println", "return false");
						return false;
					}
					for(int x = 0; x < this->getPosition(); x++){
						if(a_value == this->m_tree_values[x]){
							PrimitiveRawPointerTreeLog(higgs_Log_Statement, "containBranchByPointer", "println", "a_value == this->m_tree_values[x]");
							PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "containBranchByPointer", "println", "return true");
							return true;
						}
					}
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "containBranchByPointer", "println", "");
					return false;
				}
				
				virtual int getBranchIndexByPointer(RawPointerTree<T>* a_value){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "getIndexByPointer", "println", "");
					if(this->isEmpty()){
						return -1;
					}
					for(int x = 0; x < this->getPosition(); x++){
						if(a_value == this->m_tree_values[x]){
							return x;
						}
					}
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "getIndexByPointer", "println", "");
					return -1;
				}
				
				virtual void clearBranches(){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "clearBranches", "println", "");
					for(int x = 0; x < this->getPosition(); x++){
						RawPointerTree<T>* f_value = this->m_tree_values[x];
						if(f_value == nullptr){
							PrimitiveRawPointerTreeLog(higgs_Log_Statement, "clearBranches", "println", "this->m_tree_values[x] == nullptr");
							continue;
						}
						f_value->setParent(nullptr);
						f_value->setBranchPosition(-1);
						this->m_tree_values[x] = nullptr;
					}
					this->setPosition(0);
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "clearBranches", "println", "");
				}
				
				virtual void clearDeleteBranches(){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "clearDeleteBranches", "println", "");
					for(int x = 0; x < this->getPosition(); x++){
						RawPointerTree<T>* f_value = this->m_tree_values[x];
						if(f_value == nullptr){
							PrimitiveRawPointerTreeLog(higgs_Log_Statement, "clearDeleteBranches", "println", "this->m_tree_values[x] == nullptr");
							continue;
						}
						f_value->setParent(nullptr);
						f_value->setBranchPosition(-1);
						if(this->isBranchOwner()){
							PrimitiveRawPointerTreeLog(higgs_Log_Statement, "clearDeleteBranches", "println", "this->isBranchOwner()");
							delete f_value;
						}
						this->m_tree_values[x] = nullptr;
					}
					this->setPosition(0);
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "clearDeleteBranches", "println", "");
				}
				
				virtual RawPointerTree<T>* removeBranchByPointer(RawPointerTree<T>* a_value){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "removeBranchByPointer", "println", "");
					int i_position = this->getBranchIndexByPointer(a_value);
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "removeBranchByPointer", "println", "removed position: ");
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "removeBranchByPointer", "println", i_position);
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "removeBranchByPointer", "println", "");
					return this->removeBranchByPosition(i_position);
				}
				
				virtual RawPointerTree<T>* removeBranchByPosition(int a_position){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "removeBranchByPosition", "println", "");
					if(this->isEmpty() || a_position >= this->getPosition()){
						return nullptr;
					}
					RawPointerTree<T>* i_value = this->m_tree_values[a_position];
					if(i_value != nullptr){
						i_value->setParent(nullptr);
						i_value->setBranchPosition(-1);
					}
					this->m_tree_values[a_position] = nullptr;
					if(!this->isInOrder()){
						PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "removeBranchByPosition", "println", "!this->isInOrder()");
						return i_value;
					}
					int i_iteration = this->getPosition();
					this->decrementPosition();
					for(int x = a_position + 1; x < i_iteration; x++){
						this->m_tree_values[x - 1] = this->m_tree_values[x];
						if(this->m_tree_values[x - 1] != nullptr){
							this->m_tree_values[x - 1]->setBranchPosition(x - 1);
						}
					}
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "removeBranchByPosition", "println", "");
					return i_value;
				}
				
				virtual bool removeBranchFirstIndex(int a_amount){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "removeBranchFirstIndex", "println", "");
					if(this->isEmpty()){
						return false;
					}
					int i_iteration = 0;
					for(int x = 0; x < a_amount && x < this->getPosition(); x++){
						if(this->isBranchOwner() && this->m_tree_values[x] != nullptr){
							delete this->m_tree_values[x];
						}
						this->m_tree_values[x] = nullptr;
						i_iteration++;
					}
					if(!this->isInOrder()){
						PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "removeBranchFirstIndex", "println", "!this->isInOrder()");
						return true;
					}
					for(int x = i_iteration; x < this->getPosition(); x++){
						this->m_tree_values[x - i_iteration] = this->m_tree_values[x];
						if(this->m_tree_values[x - i_iteration] != nullptr){
							this->m_tree_values[x - i_iteration]->setBranchPosition(x - i_iteration);
						}
					}
					this->decrementPosition(i_iteration);
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "removeBranchFirstIndex", "println", "");
					return true;
				}
			
				virtual bool removeBranchLastIndex(int a_amount){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "removeBranchLastIndex", "println", "");
					if(this->isEmpty()){
						return false;
					}
					int i_iteration = 0;
					for(int x = this->getPosition() - 1; x >= this->getPosition() - a_amount && x >= 0; x--){
						if(this->isBranchOwner() && this->m_tree_values[x] != nullptr){
							delete this->m_tree_values[x];
						}
						this->m_tree_values[x] = nullptr;
						i_iteration++;
					}
					if(!this->isInOrder()){
						PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "removeBranchLastIndex", "println", "!this->isInOrder()");
						return true;
					}
					this->decrementPosition(i_iteration);
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "removeBranchLastIndex", "println", "");
					return true;
				}

                virtual RawPointerTree<T>* createBranch(const Array<int>& a_location){
					RawPointerTreeLog(higgs_Log_StartMethod, "createBranch", "println", "");
                    if(a_location.isEmpty()){
					    PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "createBranch", "println", "a_location.isEmpty()");
                        return this;
                    }

                    RawPointerTree<T>* i_actual_tree = this;

                    for(int x = 0; x < a_location.getPosition(); x++){
                        int f_location = a_location.get(x);
					    PrimitiveRawPointerTreeLog(higgs_Log_Statement, "createBranch", "println", "iteration: ");
					    PrimitiveRawPointerTreeLog(higgs_Log_Statement, "createBranch", "println", x);
					    PrimitiveRawPointerTreeLog(higgs_Log_Statement, "createBranch", "println", "location: ");
					    PrimitiveRawPointerTreeLog(higgs_Log_Statement, "createBranch", "println", f_location);
                        if(f_location == -1){
					        PrimitiveRawPointerTreeLog(higgs_Log_Statement, "createBranch", "println", "");
                            break;
                        }
                        RawPointerTree<T>* f_tree = i_actual_tree->getBranchByPosition(f_location);
                        if(f_tree == nullptr){
                            f_tree = i_actual_tree->setBranchPointer(f_location, new PrimitiveRawPointerTree<T>());
                        }
						i_actual_tree = f_tree;
                    }
					RawPointerTreeLog(higgs_Log_EndMethod, "createBranch", "println", "");
					return i_actual_tree;
                }

                virtual void createBranches(const Array<int>& a_location, int a_branches_size){
					RawPointerTreeLog(higgs_Log_StartMethod, "createBranches", "println", "");

                    RawPointerTree<T>* i_actual_tree = this->createBranch(a_location);

					if(i_actual_tree == nullptr){
						RawPointerTreeLog(higgs_Log_EndMethod, "createBranches", "println", "i_actual_tree == nullptr");
						return;
					}

					for(int s = 0; s < a_branches_size; s++){
						i_actual_tree->addBranchPointer(new PrimitiveRawPointerTree<T>());
					}
					RawPointerTreeLog(higgs_Log_EndMethod, "createBranches", "println", "");
                }

                virtual RawPointerTree<T>* getBranch(const Array<int>& a_location){
					RawPointerTreeLog(higgs_Log_StartMethod, "getBranch", "println", "");

                    RawPointerTree<T>* i_actual_tree = this;

                    for(int x = 0; x < a_location.getPosition(); x++){
                        int f_location = a_location.get(x);
					    PrimitiveRawPointerTreeLog(higgs_Log_Statement, "getBranch", "println", "iteration: ");
					    PrimitiveRawPointerTreeLog(higgs_Log_Statement, "getBranch", "println", x);
					    PrimitiveRawPointerTreeLog(higgs_Log_Statement, "getBranch", "println", "location: ");
					    PrimitiveRawPointerTreeLog(higgs_Log_Statement, "getBranch", "println", f_location);
                        if(f_location == -1){
					        PrimitiveRawPointerTreeLog(higgs_Log_Statement, "getBranch", "println", "");
                            break;
                        }
                        RawPointerTree<T>* f_tree = i_actual_tree->getBranchByPosition(f_location);
                        if(f_tree == nullptr){
							RawPointerTreeLog(higgs_Log_EndMethod, "getBranch", "println", "");
                            return nullptr;
						}
						i_actual_tree = f_tree;
                    }
					RawPointerTreeLog(higgs_Log_EndMethod, "getBranch", "println", "");
					return i_actual_tree;
                }
				
				//resize length by adding more space
				//bug unkown for template = char on feather m0
				virtual void expandLocal(int a_size){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "expandLocal", "println", "");
					
					int i_size = this->getSize() + a_size;
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", "List Position:");
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", this->getPosition());
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", "List Size:");
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", this->getSize());	
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", "List extra size added:");
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", a_size);
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", "List new size:");
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", i_size);
					if(i_size <= 1){
						PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "expandLocal", "println", "new size is too small");
						return;
					}
					RawPointerTree<T> **nT;
					nT = new RawPointerTree<T>*[i_size];
					for(int x = 0; x < this->getPosition(); x++){
						PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", "iteration:");
						PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", x);
						nT[x] = this->m_tree_values[x];
					}
					if(this->m_tree_values != nullptr){
						PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", "this->m_tree_values != nullptr");
						delete[] this->m_tree_values;
					}

					this->m_tree_values = nT;
					this->setSize(i_size);

					for(int x = this->getPosition(); x < this->getSize(); x++){
						PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", "nulling iteration:");
						PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", x);
						this->m_tree_values[x] = nullptr;
					}
					
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", "List Position:");
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", this->getPosition());
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", "List Size:");
					PrimitiveRawPointerTreeLog(higgs_Log_Statement, "expandLocal", "println", this->getSize());	
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "expandLocal", "println", "");
				}
				
				virtual RawPointerTree<T>* expand(int a_size){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "expand", "println", "");
					int i_size = this->getSize() + a_size;
					PrimitiveRawPointerTree<T> *i_list = new PrimitiveRawPointerTree<T>(i_size, false, true);	
					for(int x = 0; x < this->getPosition(); x++){
						RawPointerTree<T>* f_value = this->getBranchByPosition(x);
						i_list->addBranchPointer(f_value);
					}
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "expand", "println", "");
					return i_list;
				}
			
				////////////////////////////////////////////operator part///////////////////////////////////////////////
				
				
				virtual PrimitiveRawPointerTree<T>& operator=(const PrimitiveRawPointerTree<T>& a_list){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "operator=", "println", "");
					this->clearDeleteBranches();
					this->setBranchOwner(false);
					for(int x = 0; x < a_list.getPosition(); x++){
						RawPointerTree<T>* f_value = a_list.getBranchByPosition(x);
						this->addBranchPointer(f_value);
					}
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "operator=", "println", "");
					return *this;
				}
				
				virtual bool operator==(const PrimitiveRawPointerTree<T>& a_list){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "operator=", "println", "");
					if(a_list.getPosition() != this->getPosition()){
						return false;
					}
					for(int x = 0; x < a_list.getPosition(); x++){
						RawPointerTree<T>* f_value = this->getBranchByPosition(x);
						RawPointerTree<T>* f_value_2 = a_list.getBranchByPosition(x);
						if(f_value != f_value_2){
							return false;
						}
					}
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "operator=", "println", "");
					return true;
				}
				
				virtual bool operator!=(const PrimitiveRawPointerTree<T>& a_list){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "operator=", "println", "");
					if(a_list.getPosition() != this->getPosition()){
						return true;
					}
					for(int x = 0; x < a_list.getPosition(); x++){
						RawPointerTree<T>* f_value = this->getBranchByPosition(x);
						RawPointerTree<T>* f_value_2 = a_list.getBranchByPosition(x);
						if(f_value != f_value_2){
							return true;
						}
					}
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "operator=", "println", "");
					return false;
				}

				virtual void reorder(){
					PrimitiveRawPointerTreeLog(higgs_Log_StartMethod, "reoder", "println", "");
					int i_offset = 0;
					for(int x = 0; x < this->getPosition(); x++){
						RawPointerTree<T>* f_value = this->getBranchByPosition(x);
						if(f_value == nullptr){
							continue;
						}
						this->m_tree_values[i_offset] = f_value;
						i_offset++;
					}
					this->setPosition(i_offset);
					PrimitiveRawPointerTreeLog(higgs_Log_EndMethod, "reoder", "println", "");
				}

			protected:
                T* m_var = nullptr;

				RawPointerTree<T>** m_tree_values = nullptr;
				int m_expandSize = 5;
		};

	}

#endif