#include <algorithm>
#include <bitset>
#include <cassert>
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
#include <lz_process.h> 

int main()
{
    using namespace LZ;

    const Process p1(1, 10, 2);
    ASSERT_EQ(1, p1.pid());
    ASSERT_EQ(10, p1.duration());
    ASSERT_EQ(2, p1.startTime());

    Process p2 = p1;
    unsigned rtm1 = 0;
    unsigned ret1 = p2.run(&rtm1, 5);
    ASSERT_EQ(5, rtm1);
    ASSERT_EQ(false, ret1);

    unsigned rtm2 = 0;
    bool ret2 = p2.run(&rtm2, 15);
    ASSERT_EQ(5, rtm2);
    ASSERT_EQ(true, ret2);
    ASSERT_EQ(0, p2.duration());
    //ASSERT_DEATH({ int a[]= {1,2}; a[3]; }, "nonon");
    //ASSERT_EQ(1, 1);
    //ASSERT_TRUE("123" == "1231");

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
