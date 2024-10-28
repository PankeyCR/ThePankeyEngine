
#ifndef TR_PrimitiveRawPointerTree_Testing_hpp
	#define TR_PrimitiveRawPointerTree_Testing_hpp
	
	#include "pankey.hpp"

	#include "TestResult.hpp"
	#include "TestRunner.hpp"

	#include "PrimitiveRawPointerTree.hpp"
	#include "Array.hpp"
	#include "ArrayHelper.hpp"
	#include "InvokeMethod.hpp"

	namespace pankey{
		
		TestResult TR_PrimitiveRawPointerTree_Testing_1(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			result.assertTrue("tree has to be empty", i_tree.isEmpty());
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_2(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());

			result.assertTrue("tree shouldnt be empty", !i_tree.isEmpty());
			result.assertEqual("tree should have 1 element", i_tree.getPosition(), 1);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_3(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());

			result.assertTrue("tree shouldnt be empty", !i_tree.isEmpty());
			result.assertEqual("tree should have 1 element", i_tree.getPosition(), 1);
			result.assertTrue("tree should contain sub tree", i_tree.containBranchByPointer(i_sub_tree));
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_4(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			i_tree.putBranchPointer(i_sub_tree);

			result.assertTrue("tree shouldnt be empty", !i_tree.isEmpty());
			result.assertEqual("tree should have 1 element", i_tree.getPosition(), 1);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_5(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			i_tree.expandLocal(5);

			RawPointerTree<int>* i_sub_tree_1 = i_tree.setBranchPointer(0, new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.getBranchByPointer(i_sub_tree_1);

			result.assertEqual("tree should be the same", i_sub_tree_1, i_sub_tree_2);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_6(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());

			RawPointerTree<int>* i_sub_tree_4 = i_tree.insertBranchPointer(1, new PrimitiveRawPointerTree<int>());
			
			RawPointerTree<int>* i_sub_tree = i_tree.getBranchByPosition(1);

			result.assertEqual("tree should be the same", i_sub_tree, i_sub_tree_4);
			result.assertNotEqual("tree shouldnt be the same", i_sub_tree_2, i_sub_tree_4);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_7(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			
			int i_sub_tree_index = i_tree.getBranchIndexByPointer(i_sub_tree_2);

			result.assertEqual("tree index should be the same", i_sub_tree_index, 1);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_8(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			
			i_tree.clearBranches();

			delete i_sub_tree_1;
			delete i_sub_tree_2;
			delete i_sub_tree_3;

			result.assertTrue("tree should be empty", i_tree.isEmpty());
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_9(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			
			i_tree.clearDeleteBranches();

			result.assertTrue("tree should be empty", i_tree.isEmpty());
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_10(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			
			RawPointerTree<int>* i_sub_tree_r = i_tree.removeBranchByPointer(i_sub_tree_2);

			delete i_sub_tree_r;

			result.assertEqual("tree position should be 2", i_tree.getPosition(), 2);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_11(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			
			RawPointerTree<int>* i_sub_tree_r = i_tree.removeBranchByPosition(1);
			RawPointerTree<int>* i_sub_tree_4 = i_tree.getBranchByPosition(1);

			result.assertNotEqual("tree branch shouldnt be the same", i_sub_tree_r, i_sub_tree_4);
			result.assertEqual("tree branch should be the same", i_sub_tree_3, i_sub_tree_4);

			delete i_sub_tree_r;

			result.assertEqual("tree position should be 2", i_tree.getPosition(), 2);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_12(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			
			i_tree.removeDeleteBranchByPointer(i_sub_tree_2);

			i_sub_tree_2 = nullptr;

			result.assertEqual("tree position should be 2", i_tree.getPosition(), 2);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_13(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			
			i_tree.removeDeleteBranchByPosition(1);

			result.assertEqual("tree position should be 2", i_tree.getPosition(), 2);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_14(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			
			i_tree.removeBranchFirstIndex(2);

			result.assertEqual("tree position should be 1", i_tree.getPosition(), 1);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_15(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			
			i_tree.removeBranchLastIndex(2);

			result.assertEqual("tree position should be 1", i_tree.getPosition(), 1);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_16(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			
			i_tree.removeFirstBranch();

			RawPointerTree<int>* i_sub_tree_4 = i_tree.getBranchByPosition(0);

			result.assertEqual("tree position should be 2", i_tree.getPosition(), 2);
			result.assertEqual("tree branch should be the same", i_sub_tree_2, i_sub_tree_4);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_17(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			
			i_tree.removeLastBranch();

			RawPointerTree<int>* i_sub_tree_4 = i_tree.getBranchByPosition(i_tree.getPosition() - 1);

			result.assertEqual("tree position should be 2", i_tree.getPosition(), 2);
			result.assertEqual("tree branch should be the same", i_sub_tree_2, i_sub_tree_4);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_18(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			i_tree.expandLocal(5);

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());

			RawPointerTree<int>* i_tree_expanded = i_tree.expand(5);

			RawPointerTree<int>* i_sub_tree_2 = i_tree_expanded->addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree_expanded->addBranchPointer(new PrimitiveRawPointerTree<int>());

			result.assertNoteEqual("tree position should be 1", i_tree.getPosition(), 1);
			result.assertNoteEqual("tree position should be 3", i_tree_expanded->getPosition(), 3);
			result.assertNoteEqual("tree size should be 10", i_tree_expanded->getSize(), 10);
			
			delete i_sub_tree_2;
			delete i_sub_tree_3;
			delete i_tree_expanded;
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_19(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());

			PrimitiveRawPointerTree<int> i_tree_2 = i_tree;

			RawPointerTree<int>* i_sub_tree_11 = i_tree_2.getBranchByPosition(0);
			RawPointerTree<int>* i_sub_tree_22 = i_tree_2.getBranchByPosition(1);
			RawPointerTree<int>* i_sub_tree_33 = i_tree_2.getBranchByPosition(2);

			result.assertEqual("tree branch should be the same", i_sub_tree_1, i_sub_tree_11);
			result.assertEqual("tree branch should be the same", i_sub_tree_2, i_sub_tree_22);
			result.assertEqual("tree branch should be the same", i_sub_tree_3, i_sub_tree_33);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_20(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());

			PrimitiveRawPointerTree<int> i_tree_2;
			i_tree_2 = i_tree;

			RawPointerTree<int>* i_sub_tree_11 = i_tree_2.getBranchByPosition(0);
			RawPointerTree<int>* i_sub_tree_22 = i_tree_2.getBranchByPosition(1);
			RawPointerTree<int>* i_sub_tree_33 = i_tree_2.getBranchByPosition(2);

			result.assertEqual("tree branch should be the same", i_sub_tree_1, i_sub_tree_11);
			result.assertEqual("tree branch should be the same", i_sub_tree_2, i_sub_tree_22);
			result.assertEqual("tree branch should be the same", i_sub_tree_3, i_sub_tree_33);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_21(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree(5, true, false);

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			
			i_tree.removeDeleteBranchByPosition(1);

			RawPointerTree<int>* i_sub_tree_4 = i_tree.getBranchByPosition(1);

			result.assertNull("tree branch should be null", i_sub_tree_4);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_22(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree(5, true, false);

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());

			i_tree.removeDeleteBranchByPosition(1);

			result.assertEqual("tree position should be 3", i_tree.getPosition(), 3);

			i_tree.reorder();

			result.assertEqual("tree position should be 2", i_tree.getPosition(), 2);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_23(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree(5, true, false);

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());

			i_tree.replaceBranch(0, 2);

			RawPointerTree<int>* i_sub_tree_4 = i_tree.getBranchByPosition(0);
			RawPointerTree<int>* i_sub_tree_5 = i_tree.getBranchByPosition(2);

			result.assertEqual("tree branch should be the same", i_sub_tree_1, i_sub_tree_5);
			result.assertEqual("tree branch should be the same", i_sub_tree_3, i_sub_tree_4);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_24(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());

			PrimitiveRawPointerTree<int> i_tree_2;

			i_tree_2.addMoveBranch(&i_tree);

			result.assertEqual("trees position should be 0", i_tree.getPosition(), 0);
			result.assertEqual("trees position should be 3", i_tree_2.getPosition(), 3);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_25(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());

			PrimitiveRawPointerTree<int> i_tree_2;

			i_tree_2.addDuplicateBranch(&i_tree);

			result.assertEqual("trees should be the same", i_tree, i_tree_2);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_26(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			int* i_value = i_tree.set(new int(0));

			RawPointerTree<int>* i_sub_tree_1 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_2 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			RawPointerTree<int>* i_sub_tree_3 = i_tree.addBranchPointer(new PrimitiveRawPointerTree<int>());
			
			int* i_value_1 = i_sub_tree_1->set(new int(1));
			RawPointerTree<int>* i_sub_tree_1_1 = i_sub_tree_1->addBranchPointer(new PrimitiveRawPointerTree<int>());
			int* i_value_1_1 = i_sub_tree_1_1->set(new int(2));
			
			int* i_value_2 = i_sub_tree_2->set(new int(3));
			RawPointerTree<int>* i_sub_tree_2_1 = i_sub_tree_2->addBranchPointer(new PrimitiveRawPointerTree<int>());
			int* i_value_2_1 = i_sub_tree_2_1->set(new int(4));
			
			int* i_value_3 = i_sub_tree_3->set(new int(5));
			RawPointerTree<int>* i_sub_tree_3_1 = i_sub_tree_3->addBranchPointer(new PrimitiveRawPointerTree<int>());
			int* i_value_3_1 = i_sub_tree_3_1->set(new int(6));

			RawPointerTree<int>* i_sub_tree_iterator = &i_tree;

			for(int x = 0; i_sub_tree_iterator != nullptr; x++){
				int* f_value = i_sub_tree_iterator->get();
				if(f_value != nullptr){
					result.assertEqual("trees value and iterator index should be the same", *f_value, x);
				}
				RawPointerTree<int>* i_sub_tree_iterator_sub = i_sub_tree_iterator->getBranchByPosition(0);
				if(i_sub_tree_iterator_sub != nullptr){
					i_sub_tree_iterator = i_sub_tree_iterator_sub;
					continue;
				}
				RawPointerTree<int>* i_sub_tree_iterator_1 = i_sub_tree_iterator->getNextBranchFromParent();
				if(i_sub_tree_iterator_1 != nullptr){
					i_sub_tree_iterator = i_sub_tree_iterator_1;
					continue;
				}
				RawPointerTree<int>* i_sub_tree_iterator_parent = i_sub_tree_iterator->getParent();
				if(i_sub_tree_iterator_parent == &i_tree){
					i_sub_tree_iterator = nullptr;
					continue;
				}
				i_sub_tree_iterator = i_sub_tree_iterator_parent->getNextBranchFromParent();
			}
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_27(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;
			
			RawPointerTree<int>* i_sub_tree = &i_tree;
			RawPointerTree<int>* i_sub_tree_1 = i_tree.createBranch({ });

			result.assertEqual("trees should be the same", i_sub_tree, i_sub_tree_1);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_28(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;
			
			RawPointerTree<int>* i_sub_tree_1 = i_tree.createBranch({ 1, 1, 5 });

			RawPointerTree<int>* i_sub_tree = i_tree.getBranchByPosition(1);
			if(i_sub_tree == nullptr){
				result.catchError("i_sub_tree is null in position 1");
				return result;
			}

			i_sub_tree = i_sub_tree->getBranchByPosition(1);
			if(i_sub_tree == nullptr){
				result.catchError("i_sub_tree is null in position 1,1");
				return result;
			}

			i_sub_tree = i_sub_tree->getBranchByPosition(5);
			if(i_sub_tree == nullptr){
				result.catchError("i_sub_tree is null in position 1,1,5");
				return result;
			}

			result.assertEqual("trees should be the same", i_sub_tree, i_sub_tree_1);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_29(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;
			
			i_tree.createBranches({ }, 4);

			result.assertEqual("trees position should be 4", i_tree.getPosition(), 4);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_30(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;
			
			i_tree.createBranches({ 5, 10, 7}, 4);

			RawPointerTree<int>* i_sub_tree = i_tree.getBranchByPosition(5);
			if(i_sub_tree == nullptr){
				result.catchError("i_sub_tree is null in position 5");
				return result;
			}

			i_sub_tree = i_sub_tree->getBranchByPosition(10);
			if(i_sub_tree == nullptr){
				result.catchError("i_sub_tree is null in position 5,10");
				return result;
			}

			i_sub_tree = i_sub_tree->getBranchByPosition(7);
			if(i_sub_tree == nullptr){
				result.catchError("i_sub_tree is null in position 5,10,7");
				return result;
			}

			result.assertEqual("trees position should be 4", i_sub_tree->getPosition(), 4);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_31(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;
			
			RawPointerTree<int>* i_sub_tree_0 = i_tree.createBranch({ 7, 8, 9});

			RawPointerTree<int>* i_sub_tree_1 = i_tree.getBranch({ 7, 8, 9});

			result.assertEqual("sub trees should be the same", i_sub_tree_0, i_sub_tree_1);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_32(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			int* i_value_0 = i_tree.setBranchValuePointer({ 0, 1 }, new int(3));

			int* i_value_1  = i_tree.getBranchValuePointer({ 0, 1 });

			result.assertEqual("sub trees values should be the same", i_value_0, i_value_1);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_33(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			i_tree.setBranchValuePointer({ }, new int(0));
			i_tree.setBranchValuePointer({ 1 }, new int(1));
			i_tree.setBranchValuePointer({ 1, 2 }, new int(2));
			i_tree.setBranchValuePointer({ 1, 2, 0 }, new int(3));
			i_tree.setBranchValuePointer({ 1, 2, 2 }, new int(4));
			i_tree.setBranchValuePointer({ 3 }, new int(5));
			i_tree.setBranchValuePointer({ 3, 1 }, new int(6));

			i_tree.forEachTopDownPointer<InvokeMethod<int,const Array<int>&,RawPointerTree<int>*,int*,TestResult&>,TestResult&>([](int a_x, const Array<int>& a_location, RawPointerTree<int>* a_tree, int* a_value, TestResult& a_result) {
				if(a_location == Array<int>()){
					a_result.assertNoteEqual("index should be ", a_x, 0);
					a_result.assertNotNull("value shouldnt be null", a_value);
					if(a_value != nullptr){
						a_result.assertEqual("values should be the same", *a_value, 0);
					}
				}
				if(a_location == Array<int>( 1 )){
					a_result.assertNoteEqual("index should be ", a_x, 1);
					a_result.assertNotNull("value shouldnt be null", a_value);
					if(a_value != nullptr){
						a_result.assertEqual("values should be the same", *a_value, 1);
					}
				}
				if(a_location == Array<int>( 1, 2 )){
					a_result.assertNoteEqual("index should be ", a_x, 2);
					a_result.assertNotNull("value shouldnt be null", a_value);
					if(a_value != nullptr){
						a_result.assertEqual("values should be the same", *a_value, 2);
					}
				}
				if(a_location == Array<int>( 1, 2, 0 )){
					a_result.assertNoteEqual("index should be ", a_x, 3);
					a_result.assertNotNull("value shouldnt be null", a_value);
					if(a_value != nullptr){
						a_result.assertEqual("values should be the same", *a_value, 3);
					}
				}
				if(a_location == Array<int>( 1, 2, 2 )){
					a_result.assertNoteEqual("index should be ", a_x, 4);
					a_result.assertNotNull("value shouldnt be null", a_value);
					if(a_value != nullptr){
						a_result.assertEqual("values should be the same", *a_value, 4);
					}
				}
				if(a_location == Array<int>( 3 )){
					a_result.assertNoteEqual("index should be ", a_x, 5);
					a_result.assertNotNull("value shouldnt be null", a_value);
					if(a_value != nullptr){
						a_result.assertEqual("values should be the same", *a_value, 5);
					}
				}
				if(a_location == Array<int>( 3, 1 )){
					a_result.assertNoteEqual("index should be ", a_x, 6);
					a_result.assertNotNull("value shouldnt be null", a_value);
					if(a_value != nullptr){
						a_result.assertEqual("values should be the same", *a_value, 6);
					}
				}
			}, result);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_34(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			i_tree.setBranchValuePointer({ }, new int(0));
			i_tree.setBranchValuePointer({ 1 }, new int(1));
			i_tree.setBranchValuePointer({ 1, 2 }, new int(2));
			i_tree.setBranchValuePointer({ 1, 2, 0 }, new int(3));
			i_tree.setBranchValuePointer({ 1, 2, 2 }, new int(4));
			i_tree.setBranchValuePointer({ 1, 2, 3, 5, 7, 8 }, new int(55));
			i_tree.setBranchValuePointer({ 1, 2, 4, 6, 7, 8 }, new int(55));
			i_tree.setBranchValuePointer({ 1, 2, 5, 6, 8, 8 }, new int(55));
			i_tree.setBranchValuePointer({ 1, 2, 6, 7, 7, 8 }, new int(55));
			i_tree.setBranchValuePointer({ 0, 2, 7, 5, 7, 8 }, new int(66));
			i_tree.setBranchValuePointer({ 3 }, new int(5));
			i_tree.setBranchValuePointer({ 3, 1 }, new int(6));

			i_tree.forEachTopDownPointer<InvokeMethod<int,const Array<int>&,RawPointerTree<int>*,int*,TestResult&>,TestResult&>([](int a_x, const Array<int>& a_location, RawPointerTree<int>* a_tree, int* a_value, TestResult& a_result) {
				if(a_location == Array<int>(0, 2, 7, 5, 7, 8)){
					a_result.assertNoteEqual("index should be ", a_x, 6);
					a_result.assertNotNull("value shouldnt be null", a_value);
					if(a_value != nullptr){
						a_result.assertEqual("values should be the same", *a_value, 66);
					}
				}
			}, result);
			
			return result;
		}
		
		TestResult TR_PrimitiveRawPointerTree_Testing_35(){
			TestResult result;

			PrimitiveRawPointerTree<int> i_tree;

			i_tree.setBranchValuePointer({ }, new int(0));
			i_tree.setBranchValuePointer({ 1 }, new int(1));
			i_tree.setBranchValuePointer({ 1, 2 }, new int(2));
			i_tree.setBranchValuePointer({ 1, 2, 0 }, new int(3));
			i_tree.setBranchValuePointer({ 1, 2, 2 }, new int(4));
			i_tree.createBranch({ 1, 3 });
			i_tree.setBranchValuePointer({ 3 }, new int(5));
			i_tree.setBranchValuePointer({ 3, 1 }, new int(6));

			i_tree.forEachDownTopPointer<InvokeMethod<int,const Array<int>&,RawPointerTree<int>*,int*,TestResult&>,TestResult&>([](int a_x, const Array<int>& a_location, RawPointerTree<int>* a_tree, int* a_value, TestResult& a_result) {
				// System::console.print("location: ");
				// println(a_location);
				// if(a_value != nullptr){
				// 	System::console.print("value: ");
				// 	System::console.println(*a_value);
				// }
				if(a_location == Array<int>(1, 2, 2)){
					a_result.assertNoteEqual("index should be ", a_x, 1);
					a_result.assertNotNull("value shouldnt be null", a_value);
					if(a_value != nullptr){
						a_result.assertNoteEqual("values should be the same", *a_value, 4);
					}
				}
				if(a_location == Array<int>(1, 3)){
					a_result.assertNoteEqual("index should be ", a_x, 3);
					a_result.assertNull("value should be null", a_value);
				}
			}, result);
			
			return result;
		}

		void TR_PrimitiveRawPointerTree_Testing(TestRunner& a_test_runner){
			a_test_runner.map.add("Tree Constructor", TR_PrimitiveRawPointerTree_Testing_1);
			a_test_runner.map.add("Tree add branch", TR_PrimitiveRawPointerTree_Testing_2);
			a_test_runner.map.add("Tree contain", TR_PrimitiveRawPointerTree_Testing_3);
			a_test_runner.map.add("Tree put", TR_PrimitiveRawPointerTree_Testing_4);
			a_test_runner.map.add("Tree setBranchPointer getBranchByPointer", TR_PrimitiveRawPointerTree_Testing_5);
			a_test_runner.map.add("Tree insertBranchPointer getBranchByPosition", TR_PrimitiveRawPointerTree_Testing_6);
			a_test_runner.map.add("Tree getBranchIndexByPointer", TR_PrimitiveRawPointerTree_Testing_7);
			a_test_runner.map.add("Tree clear", TR_PrimitiveRawPointerTree_Testing_8);
			a_test_runner.map.add("Tree clearDelete", TR_PrimitiveRawPointerTree_Testing_9);
			a_test_runner.map.add("Tree removeBranchByPointer", TR_PrimitiveRawPointerTree_Testing_10);
			a_test_runner.map.add("Tree removeBranchByPosition", TR_PrimitiveRawPointerTree_Testing_11);
			a_test_runner.map.add("Tree removeDeleteBranchByPointer", TR_PrimitiveRawPointerTree_Testing_12);
			a_test_runner.map.add("Tree removeBranchByPosition", TR_PrimitiveRawPointerTree_Testing_13);
			a_test_runner.map.add("Tree removeBranchFirstIndex", TR_PrimitiveRawPointerTree_Testing_14);
			a_test_runner.map.add("Tree removeBranchLastIndex", TR_PrimitiveRawPointerTree_Testing_15);
			a_test_runner.map.add("Tree removeFirstBranch", TR_PrimitiveRawPointerTree_Testing_16);
			a_test_runner.map.add("Tree removeLastBranch", TR_PrimitiveRawPointerTree_Testing_17);
			a_test_runner.map.add("Tree expand", TR_PrimitiveRawPointerTree_Testing_18);
			a_test_runner.map.add("Tree copy contructor", TR_PrimitiveRawPointerTree_Testing_19);
			a_test_runner.map.add("Tree copy operator", TR_PrimitiveRawPointerTree_Testing_20);
			a_test_runner.map.add("Tree no reorder constructor", TR_PrimitiveRawPointerTree_Testing_21);
			a_test_runner.map.add("Tree reorder", TR_PrimitiveRawPointerTree_Testing_22);
			a_test_runner.map.add("Tree replacebranch", TR_PrimitiveRawPointerTree_Testing_23);
			a_test_runner.map.add("Tree addMoveBranch", TR_PrimitiveRawPointerTree_Testing_24);
			a_test_runner.map.add("Tree addDuplicateBranch operator==", TR_PrimitiveRawPointerTree_Testing_25);
			a_test_runner.map.add("Tree iterating throught branches", TR_PrimitiveRawPointerTree_Testing_26);
			a_test_runner.map.add("Tree createBranch", TR_PrimitiveRawPointerTree_Testing_27);
			a_test_runner.map.add("Tree createBranch 1,1,5", TR_PrimitiveRawPointerTree_Testing_28);
			a_test_runner.map.add("Tree createBranches", TR_PrimitiveRawPointerTree_Testing_29);
			a_test_runner.map.add("Tree createBranches 5,10,7", TR_PrimitiveRawPointerTree_Testing_30);
			a_test_runner.map.add("Tree getBranches", TR_PrimitiveRawPointerTree_Testing_31);
			a_test_runner.map.add("Tree setBranchValuePointer getBranchValuePointer", TR_PrimitiveRawPointerTree_Testing_32);
			a_test_runner.map.add("Tree forEachTopDownPointer", TR_PrimitiveRawPointerTree_Testing_33);
			a_test_runner.map.add("Tree forEachTopDownPointer deep", TR_PrimitiveRawPointerTree_Testing_34);
			a_test_runner.map.add("Tree forEachDownTopPointer", TR_PrimitiveRawPointerTree_Testing_35);
		}		

	}

#endif
