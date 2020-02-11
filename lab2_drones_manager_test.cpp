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
		DroneRecord* temp = cur->next;												
		delete cur;
		cur = temp;
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
	DroneRecord* cur = first;
	if (size == 0)
  return DroneRecord(0);
	else if (index < 1 || index > size)
  {
  	for(int i = 0; i < size-1; i++)
    {
    cur = cur->next;
    }
    return *cur;
  }
  else if
  {
	if (index == 1)				//Assume index 0 is the first element
  return *cur;
  else 
  {
  	for (int i = 1; i < index; i++)
  	{
   	cur = cur->next;
    }
  return *cur;
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
		cur = cur->next;
    index++
	}
	return size;
}

void DronesManager::print() const {
  cout << "droneID" <<" range" <<" yearBought" <<" droneType" <<" manufacturer" <<" description" <<" batteryType"<<endl;
	DroneRecord* cur = first;
	for (int i=0; i<size; i++)
	{
  	cout << cur->droneID <<cur->range <<cur->yearBought <<cur->droneType <<cur->manufacturer <<cur->description <<cur->batteryType <<endl;
    cur = cur.next;
  }
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	if(index < 1 || index > size)
    return false;
  else if(index == 1)
    return insert_front(value);
  	
  else if(index == size)
    return insert_back(value);
  
  else
  {
    DroneRecord* cur = first;
    for(int i = 1; i < index; i++)
    {
      cur = cur->next;
    }
    delete value.prev;
    delete value.next;
    value.prev = cur->prev;
    value.next = cur;
    size++;
    return true;                      
  }
}

bool DronesManager::insert_front(DroneRecord value) {
	delete value.prev;
  delete value.next;
  value.prev = NULL;
  value.next = first;
  first = &value; 
  size++;
	return true;
}

bool DronesManager::insert_back(DroneRecord value) {
	delete value.next;
  value.next = NULL;
  value.prev = last;
  last = &value; 
  size++;
	return true;
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
