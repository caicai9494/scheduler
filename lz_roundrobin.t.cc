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
    using namespace LZ;
    RoundRobin rr;
    Process p1(1, 10, 2);
    Process p2(2, 110, 2);
    Process p3(3, 1110, 2);
    rr.add(&p1);
    rr.add(&p2);
    rr.add(&p3);

    ASSERT_EQ((*rr.getNext())->pid(), 1);
    ASSERT_EQ((*rr.getNext())->pid(), 2);
    ASSERT_EQ((*rr.getNext())->pid(), 3);
    ASSERT_EQ((*rr.getNext())->pid(), 1);
    //ASSERT_TRUE("123" == "1231");

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
