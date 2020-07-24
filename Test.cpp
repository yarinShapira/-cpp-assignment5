#include "doctest.h"
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"
#include <vector>


using namespace std;
using namespace itertools;

TEST_CASE("Test range") {
    int k = 0;
    for (int i: range(0,60)){ // 0 to 24
		CHECK(i==k);   
        k++;   
    }
}

TEST_CASE("Test accumulate") {
    int k = 0;
    int sum = 0;
	for (int i: accumulate(range(0,10))) {
        CHECK(i==sum);
        k++;
        sum=sum+k;
    }
    int l = 1;
    int mul = 1;
	for (int i: accumulate(range(1,15), [](int x, int y){return x*y;})) {
        CHECK(i==mul);
        l++;
        mul=mul*l;
    }
}

TEST_CASE("Test filterfalse") {
    vector<int> vecInt = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    for (auto i: filterfalse([](int x){return x%2==1;}, vecInt))
        CHECK(i%2==0);
}

TEST_CASE("Test compress") {
    vector<int> vecInt = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    vector<bool> bool_v = {true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true,false,true};
    for (auto i: compress(vecInt, bool_v)) {
        CHECK(i%2 == 1);
    }
}
