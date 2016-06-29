#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <lz_error.h>
#include <lz_roundrobin.h> 

int main()
{
    // add and then call next;
    {
	using namespace LZ;
	RoundRobin rr;
	Process p1(1, 10, 2);
	Process p2(2, 110, 2);
	Process p3(3, 1110, 2);
	rr.add(&p1);
	rr.add(&p2);
	rr.add(&p3);

	ASSERT_EQ(rr.next()->pid(), 1);
	ASSERT_EQ(rr.next()->pid(), 2);
	ASSERT_EQ(rr.next()->pid(), 3);
	ASSERT_EQ(rr.next()->pid(), 1);
	ASSERT_EQ(rr.next()->pid(), 2);
    }

    // add, call next and remove;
    {
	using namespace LZ;
	RoundRobin rr;
	Process p1(1, 10, 2);
	Process p2(2, 110, 2);
	Process p3(3, 1110, 2);
	rr.add(&p1);
	rr.add(&p2);
	rr.add(&p3);

	ASSERT_EQ(rr.next()->pid(), 1);
	ASSERT_EQ(rr.next()->pid(), 2);
	rr.removeCurrent();
	ASSERT_EQ(rr.next()->pid(), 1);
	ASSERT_EQ(rr.next()->pid(), 2);
	ASSERT_EQ(rr.next()->pid(), 1);
    }

    // add, call next and remove 2;
    {
	using namespace LZ;
	RoundRobin rr;
	Process p1(1, 10, 2);
	Process p2(2, 110, 2);
	Process p3(3, 1110, 2);
	rr.add(&p1);
	rr.add(&p2);
	rr.add(&p3);

	ASSERT_EQ(rr.next()->pid(), 1);
	ASSERT_EQ(rr.next()->pid(), 2);
	rr.removeCurrent();
	ASSERT_EQ(rr.next()->pid(), 1);
	rr.removeCurrent();
	ASSERT_EQ(rr.next()->pid(), 1);
	ASSERT_EQ(rr.next()->pid(), 1);
    }

    // add, call next and remove 3 (empty);
    {
	using namespace LZ;
	RoundRobin rr;
	Process p1(1, 10, 2);
	Process p2(2, 110, 2);
	Process p3(3, 1110, 2);
	rr.add(&p1);
	rr.add(&p2);
	rr.add(&p3);

	ASSERT_EQ(rr.next()->pid(), 1);
	ASSERT_EQ(rr.next()->pid(), 2);
	rr.removeCurrent();
	ASSERT_EQ(rr.next()->pid(), 1);
	rr.removeCurrent();
	ASSERT_EQ(rr.next()->pid(), 1);
	ASSERT_EQ(rr.next()->pid(), 1);
	rr.removeCurrent();
	ASSERT_EQ(rr.next(), NULL);
    }

    // add, next, remove interleave 1;
    {
	using namespace LZ;
	RoundRobin rr;
	Process p1(1, 10, 2);
	Process p2(2, 110, 2);
	Process p3(3, 1110, 2);
	rr.add(&p1);
	rr.add(&p2);

	ASSERT_EQ(rr.next()->pid(), 1);
	ASSERT_EQ(rr.next()->pid(), 2);

	rr.add(&p3);
	ASSERT_EQ(rr.next()->pid(), 1);
	ASSERT_EQ(rr.next()->pid(), 2);
	ASSERT_EQ(rr.next()->pid(), 3);
    }

    // add, next, remove interleave 2;
    {
	using namespace LZ;
	RoundRobin rr;
	Process p1(1, 10, 2);
	Process p2(2, 110, 2);
	Process p3(3, 1110, 2);
	rr.add(&p1);
	rr.add(&p2);

	ASSERT_EQ(rr.next()->pid(), 1);
	rr.add(&p3);

	ASSERT_EQ(rr.next()->pid(), 2);
	ASSERT_EQ(rr.next()->pid(), 3);
    }

    // add, next, remove interleave 3;
    {
	using namespace LZ;
	RoundRobin rr;
	Process p1(1, 10, 2);
	Process p2(2, 110, 2);
	Process p3(3, 1110, 2);
	rr.add(&p1);
	rr.add(&p2);

	ASSERT_EQ(rr.next()->pid(), 1);
	rr.add(&p3);
	rr.removeCurrent();
	ASSERT_EQ(rr.next()->pid(), 3);
    }

    // add, next, remove interleave 4;
    {
	using namespace LZ;
	RoundRobin rr;
	Process p1(1, 10, 2);
	Process p2(2, 110, 2);
	Process p3(3, 1110, 2);
	rr.add(&p1);
	rr.add(&p2);

	ASSERT_EQ(rr.next()->pid(), 1);
	ASSERT_EQ(rr.next()->pid(), 2);
	ASSERT_EQ(rr.next()->pid(), 1);
	rr.removeCurrent();
	DBG(rr.next()->pid());
	ASSERT_EQ(rr.next()->pid(), 2);
	ASSERT_EQ(rr.next()->pid(), 2);
	ASSERT_EQ(rr.next()->pid(), 2);

	//ASSERT_EQ(rr.next()->pid(), 1);
	//ASSERT_EQ(rr.next()->pid(), 2);
	//rr.add(&p3);
	//ASSERT_EQ(rr.next()->pid(), 3);
    }

    return 0;
}
