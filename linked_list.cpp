/*
Author: Nick Turner
Version: 2019.3.30
*/
#ifndef LIST_CPP
#define LIST_CPP
#include "linked_list.h"
#include <iostream>
#include <string>
using namespace std;

template <class NODETYPE>
linked_list<NODETYPE>::linked_list() {
	first = NULL;
	current = NULL;
	last = NULL;
}

template <class NODETYPE>
linked_list<NODETYPE>::~linked_list() {
	current = first;
	while (current != NULL) {
		first = first->next;
		delete current;
		current = first;
	}
	current = last = first = NULL;
}

template <class NODETYPE>
linked_list<NODETYPE>::linked_list(linked_list<NODETYPE> &originalList) {
	//Fill in the copy constructor
	originalList.current = originalList.first;
	while(originalList.current != nullptr){
		insertRear(originalList.current->data);
		originalList.current=originalList.current->next;
	}
}


template <class NODETYPE>
bool linked_list<NODETYPE>::InsertInOrder(NODETYPE value)
{
	/*
	//Declare a new node
	//New the node
	//if the new node is not nullptr continue with the insert in order
	//else return false

	//if this is the first node you are inserting the linked list
	//call either insertFront or insertRear
	//else if the new node data is less than first data
	//call insertFront
	//else if the new node data is greater than last data
	//call insertRear
	//else
	//set current to first
	//use a while loop to set current to the node before where you want to insert the new node
	//connect the new node next to current next
	//connect current next to the new node
	*/

	ListNode<NODETYPE> *temp;
	temp = new(struct ListNode<NODETYPE>);
	temp->data = value;

	if(temp != NULL){
		if(first == NULL){
			//First node in list
			//Call insertFront or insertRear
			//cout<<"Added in first value\n";	//DEBUG
			return InsertFront(value);
		}else if(temp->data < first->data){
			//less than first data
			//call insertFront
			//cout<<"Added in the front\n";	//DEBUG
			return InsertFront(value);
		}else if(last->data < temp->data){
			//greater than last data
			//call insert rear
			//cout<<"Added in the back\n";
			return InsertRear(value);
		}else{
			current = first;
			while(temp->data < current->data){
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;
			//cout<<"Added in the middle\n";
		}
		return true;
	}else{
		return false;
	}
}

template <class NODETYPE>
bool linked_list<NODETYPE>::InsertFront(NODETYPE value) {
	/* //New a new node with current
	//if current equal nullptr return false
	//else
	//set current data to value
	//if this is the first node in the linked list
	//set first to current
	//set last to current
	//set current next to nullptr
	//else
	//set current next to first
	//set first to current
	//return true;
	*/

	ListNode<NODETYPE> *temp;
	temp = new(struct ListNode<NODETYPE>);

	//cout<<"made it to insertFront\n"; //DEBUG

	temp->data = value;
	//cout<<"checking if current is nullptr\n";	//DEBUG
	if(temp == nullptr){
		//cout<<"first value returned false\n";	//DEBUG
		return false;
	}else{
		//cout<<"first value returned true\n"; //DEBUG
		temp->data=value;
		//cout<<"set temp->data = value\n"; //DEBUG
		if(first != nullptr){
			//cout<<"first is NOT nullptr"; //DEBUG

			current = temp;
			current->next=first;
			first=temp;

			//cout<<"made value become only val in list\n"; //DEBUG
		} else {
			//	cout<<"first IS nullptr\n"; //DEBUG
			first = temp;
			last = temp;

			current = temp;
			current->next = nullptr;
		}
		return true;
	}
}

template <class NODETYPE>
bool linked_list<NODETYPE>::InsertRear(NODETYPE value) {
	/*New a new node with current
	//if current equal nullptr return false
	//else
	//set current data to value
	//if this is the first node in the linked list
	//set first to current
	//set last to current
	//set current next to nullptr
	//else
	//set last next to current
	//set current next to nullptr
	//set last to current
	//return true;*/

	ListNode<NODETYPE> *temp;
	temp = new(struct ListNode<NODETYPE>);

	temp->data = value;
	if(temp == nullptr){
		//cout<<"temp is nullptr"<<endl;	//DEBUG
		return false;
	} else {
		temp->data = value;
		if(first != nullptr){
			last->next = temp;
			current = temp;
			current->next = nullptr;
			last = current;
		}else{
			first = temp;
			last = temp;
			current = temp;
			current->next = nullptr;
		}
		//cout<<"worked"<<endl;	//DEBUG
		return true;
	}
	//cout<<"failed"<<endl;	//DEBUG
	return false;
}

template <class NODETYPE>
bool linked_list<NODETYPE>::IsEmpty() const {
	return (first == NULL);
}

template <class NODETYPE>
bool linked_list<NODETYPE>::Search(NODETYPE &value) {
	/*//if the list is empty return false
	//else
	//set current to first
	//use a while loop to check not for nullptr and not for current data not equal to the value
	//if current equals null not found
	//return false
	//else
	//return true*/

	//cout<<"making current = first"<<endl;	//DEBUG
	current = first;
	//cout<<"checking current != nullptr && current->data != value"<<endl;	//DEBUG
	while(current != nullptr){
		//cout<<"Searching"<<endl;	//DEBUG
		if(current->data.getName() == value.getName()){
			//cout<<"Found correct value"<<endl;	//DEBUG
			value = current->data;
			//cout<<"returning true"<<endl;
			return true;
		}else{
			current = current->next;
		}
	}
	//cout<<"not found"<<endl;	//DEBUG
	if(current == NULL || current == nullptr){
		return false;
	} else {
		return true;
	}
}


template <class NODETYPE>
void linked_list<NODETYPE>::PrintAll() {
	//if not empty
	//set current to first
	//use a while loop to check for not equal to nullptr
	//print out data
	//move current over

	//PROBLEM HERE
	//FIXME
	//DEBUG
	//TEMP

	//cout<<"Before checking if list is empty"<<endl;
	//cout<<"\n";
	if(!IsEmpty()){	//&& last != nullptr){
		//cout<<"\nBefore making current=first"<<endl;
		current = first;
		while(current != NULL){
			cout<<current->data;
			//cout<<"\ntesting that printall() works\n"<<endl;	//FIXME
			current=current->next;
			cout<<"\n";
		}
	}

}


template <class NODETYPE>
bool linked_list<NODETYPE>::RemoveFront(NODETYPE & value) {
	if(first->data==value){
		current = false;
		first=first->next;
		value=current->data;
		delete current;
		return true;
	}else{
		return false;
	}
}

template <class NODETYPE>
bool linked_list<NODETYPE>::RemoveRear(NODETYPE & value) {
	if(last->data == value){	//deleting last node
		current=first;
		while(current->next != last){
			current=current->next;
		}
		last = current;
		current = last->next;
		value=current->data;
		delete current;
		last->next=NULL;
		return true;
	}else{
		return false;
	}
}

template <class NODETYPE>
bool linked_list<NODETYPE>::Remove(NODETYPE & value) {
	//if the value equals the first data and it is the last node in the linked last
	//set value to first data
	//remove the node and set current last and first to nullptr
	//else if the value equals the first data
	//set value to first data
	//set current to first
	//move first to the next node
	//delete current
	//else if the value equals the last data
	//set value to last data
	//set current to first
	//use a while loop to set current to one before last
	//delete last
	//set last to current
	//set current next to nullptr
	//else
	//set current to first
	//use a while loop to check for current does not equal null and current next data does not equal value
	//if current equals null
	//return false
	//else
	//set temp pointer the node you will be deleting
	//set value to the temp data
	//set current next to temp next
	//delete temp
	//return true

	if(first->data==value && first==last){	//deleting 1 node
		value = first->data;
		delete first;
		first=last=nullptr;
	}else if(first->data==value){	//For deleteing first node
		current = first;
		first=first->next;
		value=current->data;
		delete current;
		return true;
	}else if(last->data == value){	//deleting last node
		current=first;
		while(current->next != last){
			current=current->next;
		}
		last = current;
		current = last->next;
		value=current->data;
		delete current;
		last->next=NULL;
		return true;
	}else{	//deleting in the middle
		current=first;
		while(current!=nullptr && current->next->data != value){
			current=current->next;
		}
		if(current!=nullptr){
			ListNode<NODETYPE> *temp; //CANNOT new
			temp=current->next;
			current->next=temp->next;
			value=temp->data;
			delete temp;
			return true;
		}
	}
	return false;
}

#endif
