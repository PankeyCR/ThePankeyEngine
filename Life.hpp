//Life owns it lelf, life deletes it lelf, but it can be deleted by others


#ifndef Life_hpp
#define Life_hpp

#include "Logic.hpp"
#include "LearningLogic.hpp"
#include "GameObject.hpp"
#include "ByteArray.hpp"
#include "PrimitiveList.hpp"
#include "LinkedList.hpp"

namespace ame{
 
class Life : public GameObject{
	public:
		Life(){
			stepTimeLimit = 0.01f;
			m_logic = new LearningLogic();
			refresh();
		}
		Life(bool n_owner){
			owner = n_owner;
			stepTimeLimit = 0.01f;
			m_logic = new LearningLogic();
			refresh();
		}
		Life(int limit, ByteArray n_array, Logic* n_logic){
			stepTimeLimit = limit;
			cells = n_array;
			m_logic = n_logic;
		}
		Life(int limit, ByteArray n_array, Logic* n_logic, bool n_owner){
			owner = n_owner;
			stepTimeLimit = limit;
			cells = n_array;
			m_logic = n_logic;
		}
		Life(ByteArray n_array, Logic* n_logic){
			cells = n_array;
			m_logic = n_logic;
		}
		Life(ByteArray n_array, Logic* n_logic, bool n_owner){
			owner = n_owner;
			cells = n_array;
			m_logic = n_logic;
		}
		Life(const Life& life){
			owner = life.owner;
			stepTime = life.stepTime;
			stepTimeLimit = life.stepTimeLimit;
			cells = life.cells;
			if(life.m_logic != nullptr){
				m_logic = life.m_logic->clone();
			}
		}
		Life(Life&& life){
			owner = life.owner;
			stepTime = life.stepTime;
			stepTimeLimit = life.stepTimeLimit;
			cells = life.cells;
			m_logic = life.m_logic;
		}
		
		virtual ~Life(){
			if(owner && m_logic != nullptr){
				delete m_logic;
			}
		}

		virtual void update(float tpf){
			stepTime += tpf;
			if(stepTime < stepTimeLimit){
				return;
			}
			nextStepLocal();
		}

		virtual Life& operator=(const Life& life){
			owner = life.owner;
			stepTime = life.stepTime;
			stepTimeLimit = life.stepTimeLimit;
			cells = life.cells;
			if(life.m_logic != nullptr){
				m_logic = life.m_logic->clone();
			}
			return *this;
		}

		virtual Life& operator=(Life&& life){
			owner = life.owner;
			stepTime = life.stepTime;
			stepTimeLimit = life.stepTimeLimit;
			cells = life.cells;
			m_logic = life.m_logic;
			return *this;
		}
		
		void setGrid(LinkedList<int> grid){
			int total = 1;
			for(int x=0; x < grid.getPosition(); x++){
				total *= grid[x];
			}
			clearCells();
			addCells(total);
		}

		void setGrid(PrimitiveList<int> grid){
			int total = 1;
			for(int x=0; x < grid.getPosition(); x++){
				total *= grid[x];
			}
			clearCells();
			addCells(total);
		}

		void setCells(ByteArray n_array){
			cells = cells;
		}

		void setCell(LinkedList<int> position, bool state){
			
		}

		void setCell(PrimitiveList<int> position, bool state){
			
		}
		
		void setCell(int rawPosition, bool state){
			cells.setBit(rawPosition,0,state);
		}

		virtual void addCells(int spaceConsumed){
			float size = ((float)spaceConsumed)/8.0f;
			if(spaceConsumed % 8){
				size++;
			}
			for(int xx=0; xx < size; xx++){
				cells.add();
			}
		}

		virtual bool getCell(int cell){
			// float size = spaceConsumed/8.0f;
			// if(spaceConsumed % 8){
				// size++;
			// }
			// return size * cell;
			return false;
		}

		virtual bool getCell(LinkedList<int> cell){
			// float size = spaceConsumed/8.0f;
			// if(spaceConsumed % 8){
				// size++;
			// }
			// return size * cell;
			return false;
		}

		virtual bool getCell(PrimitiveList<int> cell){
			// float size = spaceConsumed/8.0f;
			// if(spaceConsumed % 8){
				// size++;
			// }
			// return size * cell;
			return false;
		}

		virtual void clearCells(){
			
		}

		int getPosition(LinkedList<int> i_size){
			
		}

		int getPosition(PrimitiveList<int> i_size){
			
		}

		virtual int getByteSize(){
			return cells.getPosition();
		}

		virtual int getCellSize(){
			return cells.getPosition() * 8;
		}
		
		virtual Life nextStep(){
			if(m_logic == nullptr){
				return *this;
			}
			Life newLife = Life(stepTimeLimit, cells, m_logic->clone());
			return newLife.nextStepLocal();
		}
		
		virtual Life nextStepLocal(){
			if(m_logic == nullptr){
				return *this;
			}
			step++;
			cells = m_logic->logic(cells);
			return *this;
		}
		
		virtual void refresh(){
			
		}
		
		virtual long getStep(){
			return step;
		}
		
		virtual bool operator=(const int& i){
			cells = i;
			return false;
		}
		
		virtual bool operator=(const float& i){
			
			return false;
		}
		
		virtual bool operator=(const double& i){
			
			return false;
		}
		
		virtual bool operator=(const long& i){
			
			return false;
		}
		
		virtual bool operator=(const char* i){
			
			return false;
		}
		
		virtual bool operator=(const char& i){
			
			return false;
		}
		
		virtual bool operator=(const String& i){
			
			return false;
		}
		
		virtual bool operator=(const ByteArray& i){
			
			return false;
		}
		
		//////////////////////////////////////////////////
		
		virtual bool operator==(const int& i){
			
			return false;
		}
		
		virtual bool operator==(const float& i){
			
			return false;
		}
		
		virtual bool operator==(const double& i){
			
			return false;
		}
		
		virtual bool operator==(const long& i){
			
			return false;
		}
		
		virtual bool operator==(const char* i){
			
			return false;
		}
		
		virtual bool operator==(const char& i){
			
			return false;
		}
		
		virtual bool operator==(const String& i){
			
			return false;
		}
		
		virtual bool operator==(const ByteArray& i){
			
			return false;
		}
		
		////////////////////////////////////////////////
		
		virtual bool operator!=(const int& i){
			
			return false;
		}
		
		virtual bool operator!=(const float& i){
			
			return false;
		}
		
		virtual bool operator!=(const double& i){
			
			return false;
		}
		
		virtual bool operator!=(const long& i){
			
			return false;
		}
		
		virtual bool operator!=(const char* i){
			
			return false;
		}
		
		virtual bool operator!=(const char& i){
			
			return false;
		}
		
		virtual bool operator!=(const String& i){
			
			return false;
		}
		
		virtual bool operator!=(const ByteArray& i){
			
			return false;
		}
		
		////////////////////////////////////////////////
		
		virtual bool similar(const int& i){
			
			return false;
		}
		
		virtual bool similar(const float& i){
			
			return false;
		}
		
		virtual bool similar(const double& i){
			
			return false;
		}
		
		virtual bool similar(const long& i){
			
			return false;
		}
		
		virtual bool similar(const char* i){
			
			return false;
		}
		
		virtual bool similar(const char& i){
			
			return false;
		}
		
		virtual bool similar(const String& i){
			
			return false;
		}
		
		virtual bool similar(const ByteArray& i){
			
			return false;
		}

	protected:
		Logic* m_logic = nullptr;
		ByteArray cells;

		float stepTime = 0.0f;
		float stepTimeLimit = 1.0f;
		
		long step = 0;
		
		bool owner = true;
};

}

#endif