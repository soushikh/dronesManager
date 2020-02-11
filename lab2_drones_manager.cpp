#include "lab2_drones_manager.hpp"

// TODO: Implement all of the listed functions below

DronesManager::DronesManager() 																			//Complete
{
	first = Null;
  	last = Null;
  	size = 0;
}

DronesManager::~DronesManager() 																	//Complete
{
	DroneRecord* cur = first;
	for (int i=0; i<size; i++)
	{
		DroneRecord* next = cur.next;
		delete cur;
		cur = next;
	}
  	first = Null;
  	last = Null;
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) 														//Complete
{
	if (lhs.size != rhs.size)
		return false;
	DroneRecord curLeft = lhs.first, curRight =rhs.first;
	for (int i=0; i<lhs.size; i++)
	{
		if(!(curLeft == curRight))
			return false;
		curLeft = curLeft.next;
		curRight = curRight.next;
	}
}

unsigned int DronesManager::get_size() const 													//Complete
{
	return size;																																									
}

bool DronesManager::empty() const 																	 //Complete
{
	if (size == 0)
  		return true;
  	return false;
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const 		//Complete
{
	if (size == 0)
  		return DroneRecord(0);
	else if (index < 1 || index > size)
  	{
	  	for(int i = 0; i < size; i++)
	    {
	    	DroneRecord* next = cur.next;
	    }
    	return DroneRecord();
  	}
	if (index == 1)				//Assume index 0 is the first element
		return DroneRecord();
	else 
	{
		for (int i = 1; i < index; i++)
		{
			DroneRecord* next = cur.next;
		}
		return DroneRecord();
	}
}

unsigned int DronesManager::search(DroneRecord value) const 
{
	int index = 0;
	DroneRecord* cur = first;
	for (int i=0; i<size; i++)
	{
		if(*cur == value)
    	return index;
		cur = cur.next;
    index++
	}
	return size;
}

void DronesManager::print() const {
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	return false;
}

bool DronesManager::insert_front(DroneRecord value) {
	return false;
}

bool DronesManager::insert_back(DroneRecord value) {
	return false;
}

bool DronesManager::remove(unsigned int index) {
	return false;
}

bool DronesManager::remove_front() {
	return false;
}

bool DronesManager::remove_back() {
	return false;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	return false;
}

bool DronesManager::reverse_list() {
	return false;
}

