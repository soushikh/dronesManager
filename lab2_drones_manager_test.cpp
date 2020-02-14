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
		return *last;
	}
	else if (index == 1)				
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
	if (size == 0)
		return size;
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

bool DronesManager::insert(DroneRecord value, unsigned int index) 
{
	if(index < 1 || index > size)
		return false;
	else if(index == 1)
		return insert_front(value);
	else if(index == size)
		return insert_back(value);
	else
	{
		DroneRecord* val = new DronesManager::DroneRecord(value);
		DroneRecord* cur = first;
		for(int i = 1; i < index; i++)
		{
			cur = cur->next;
		}
		val.prev = cur->prev;
		val.next = cur;
		val = NULL;
		size++;
		return true;		                     
	}
}

bool DronesManager::insert_front(DroneRecord value) 
{
	DroneRecord* val = new DronesManager::DroneRecord(value);
	val.prev = NULL;
	val.next = first;
	first = &val; 
	size++;
	val = NULL;
	return true;
}

bool DronesManager::insert_back(DroneRecord value) 
{
	DroneRecord* val = new DronesManager::DroneRecord(value);
	val.next = NULL;
	val.prev = last;
	last = &val; 
	val = NULL;
	size++;
	return true;
}

bool DronesManager::remove(unsigned int index) 
{
	if(index < 1 || index > size)
		return false;
	else if(index == 1)
		return remove_front(value);
	else if(index == size)
		return remove_back(value);
	else
	{
		DroneRecord* cur = first;
		for(int i = 1; i < index; i++)
		{
			cur = cur->next;
		}
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		cur->prev = NULL;
		cur->next = NULL;
		delete cur;
		size--;
		return true;                      
	}
}

bool DronesManager::remove_front() {
	first = first->next;
	first->prev->next = NULL;
	delete first->prev;
	first->prev = NULL;
	size--;
	return true;
}

bool DronesManager::remove_back() {
	last = last->prev;
	last->next->prev = NULL;
	delete last->next;
	last->next = NULL;
	size--;
	return true;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	if(index < 1 || index > size)
		return false;
	DroneRecord* cur = first;
	for(int i = 1; i < index; i++)
	{
		cur = cur->next;
	}
	DroneRecord* val = new DronesManager::DroneRecord(value);
	val.next = cur->next;
	val.prev = cur->prev;
	cur->next=NULL;
	cur->prev=NULL
	delete cur;
	if (index == 1)
		first = val;
	elseif(index == size)
		last = val;
	val = NULL;
	return true;
}

bool DronesManager::reverse_list() {
	DroneRecord*start = first;
	DroneRecord*end = last;
	DroneRecord*temp;
	
	if(start && end)
	
	temp->next = start->prev;
	temp->prev = start->next;	
}

// PURPOSE: select() and search() work properly
bool test3() {
	DronesManager manager1;
	ASSERT_TRUE(select(2) == DronesManager::DroneRecord(0))
	ASSERT_TRUE(search(DronesManager::DroneRecord(10)) == 0)
	manager1.insert_front(DronesManager::DroneRecord(100));
	manager1.insert_front(DronesManager::DroneRecord(90));
	manager1.insert_front(DronesManager::DroneRecord(80));
	ASSERT_TRUE(select(0) == DronesManager::DroneRecord(100))
	ASSERT_TRUE(select(4) == DronesManager::DroneRecord(100))
	ASSERT_TRUE(select(1) == DronesManager::DroneRecord(80))
	ASSERT_TRUE(select(2) == DronesManager::DroneRecord(90))
	ASSERT_TRUE(search(DronesManager::DroneRecord(90)) == 2)
	ASSERT_TRUE(search(DronesManager::DroneRecord(80)) == 1)
	ASSERT_TRUE(search(DronesManager::DroneRecord(0)) == 3)
	return true;
}

// PURPOSE: remove_front() and remove_back() on one-element list
bool test4() {
	DronesManager manager1, manager2;
	manager1.insert_front(DronesManager::DroneRecord(100));
	manager1.remove_front();
	manager2.insert_back(DronesManager::DroneRecord(100));
	manager2.remove_back();
	ASSERT_TRUE(manager1.empty() && manager2.empty())
	ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 0)
	ASSERT_TRUE(manager1.first == NULL && manager1.first == manager1.last)
	ASSERT_TRUE(manager2.first == NULL && manager2.first == manager2.last)
	ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(0))		
	return true;
}

// PURPOSE: replace() and reverse_list() work properly
bool test5()
{
	DronesManager manager1, manager2;
	manager2.replace(0,DronesManager::DroneRecord(0));
	manager2.replace(1,DronesManager::DroneRecord(0));
	manager1.reverse();
	ASSERT_TRUE( manager1 == manager2)
	DroneRecord drone1(100);
	manager1.insert_front(drone1);
	manager2.insert_back(drone1);
	manager2.replace(0,DronesManager::DroneRecord(0));
	manager2.replace(1,DronesManager::DroneRecord(0));
	manager1.replace(1,DronesManager::DroneRecord(0));
	manager1.reverse();
	ASSERT_TRUE( manager1 == manager2)
	DroneRecord drone2(90);
	manager1.insert_front(drone2);
	manager2.insert_back(drone2);
	DroneRecord drone3(80);
	manager1.insert_front(drone3);
	manager2.insert_back(drone3);
	manager1.reverse();
	manager2.replace(0,DronesManager::DroneRecord(0));
	manager2.replace(2,DronesManager::DroneRecord(0));
	manager2.replace(4,DronesManager::DroneRecord(0));
	ASSERT_TRUE( manager1 == manager2)
	ASSERT_TRUE(manager2.selesct(2) == DronesManager::DroneRecord(0))
	ASSERT_TRUE(manager.size ==  3)
    	return true;
}

// PURPOSE: insert_front() keeps moving elements forward
bool test6() 
{
	DronesManager manager1;
	manager1.insert_front(DronesManager::DroneRecord(100));
	manager1.insert_front(DronesManager::DroneRecord(10));
	ASSERT_TRUE(manager2.selesct(2) == DronesManager::DroneRecord(100))
	manager1.insert_front(DronesManager::DroneRecord(0));
	ASSERT_TRUE(manager2.selesct(2) == DronesManager::DroneRecord(10))
	ASSERT_TRUE(manager2.selesct(3) == DronesManager::DroneRecord(100))
    	return true;
}

// PURPOSE: inserting at different positions in the list
bool test7() {
    return false;
}

// PURPOSE: try to remove too many elements, then add a few elements
bool test8() {
    return false;
}

// PURPOSE: lots of inserts and deletes, some of them invalid
bool test9() {
	return false;
}    

// PURPOSE: lots of inserts, reverse the list, and then lots of removes until empty
bool test10() {
   return false;
} 
