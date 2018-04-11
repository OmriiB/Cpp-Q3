#ifndef MEMBER_HPP_
#define MEMBER_HPP_
#include <vector>
using namespace std;

class Member {

	static int counter;
	static std::vector<Member> *Members;
	int id;
	std::vector<int> *Followers;
	std::vector<int> *Following;


public:

	Member();
	void follow(Member k);
	void unfollow(Member k);
	int numFollowers();
	int numFollowing();
	bool operator==(const Member & obj2) const;
	int getId();
	static void count();
};

#endif