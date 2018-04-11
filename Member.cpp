#include <algorithm>
#include <iostream>
#include <vector>
#include <stdbool.h>
#include "Member.hpp"
using namespace std;

int Member::counter;
Member::Member(){
	id = counter++;
	Followers = new std::vector<int>;
	Following = new std::vector<int>;
}


void Member::follow(Member m){
	std::vector<int>::iterator it;

	it = std::find(Member::Following->begin(), Member::Following->end(), Member(m).getId());
	if(it == Member::Following->end()){
		Member::Following->push_back(m.getId());
		m.Followers->push_back(this->getId());
	}
}

void Member::unfollow(Member m){
	m.Followers->erase(std::remove(m.Followers->begin(), m.Followers->end(), this->getId()), m.Followers->end());
	this->Following->erase(std::remove(this->Following->begin(), this->Following->end(), m.getId()), this->Following->end());

	}


bool Member::operator==(const Member & obj2) const{
	if(this->id == (obj2.id))
		return true;
	else
		return false;
}

void Member::count(){
	cout<<"Num of members: " <<counter<<endl;
}

int Member::getId(){
	return this->id;
}

int Member::numFollowers(){
	return Member::Followers->size();
}

int Member::numFollowing(){
	return Member::Following->size();}