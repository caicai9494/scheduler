#include <lz_dispatcher.h> 
#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <lz_error.h>
#include <lz_roundrobin.h>

using namespace std;

int main()
{
    // one process
    {
	using namespace LZ;
	RoundRobin rr;
	Process p1(1, 12, 2);
	Dispatcher disp(&rr, {p1}, 10);
	disp.start();
	cout << "end test 1\n";
    }

    // two process
    {
	using namespace LZ;
	RoundRobin rr;
	Process p1(1, 12, 2);
	Process p2(2, 110, 22);
	Dispatcher disp(&rr, {p1, p2}, 10);
	disp.start();

	cout << "end test 2\n";
    }

    // three process
    {
	using namespace LZ;
	RoundRobin rr;
	Process p1(1, 12, 2);
	Process p2(2, 110, 22);
	Process p3(3, 1110, 5);
	Dispatcher disp(&rr, {p1, p2, p3}, 10);
	disp.start();

	//rr.add(&p1);
	//rr.add(&p2);
	//rr.add(&p3);
	cout << "end test 3\n";
    }
    //ASSERT_EQ(1, 1);
    //ASSERT_TRUE("123" == "1231");

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
