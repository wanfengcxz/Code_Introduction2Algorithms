//
// Created by 晚风吹行舟 on 2022/4/23.
//
#include "maximum_subarray.cpp"
#include "gtest/gtest.h"

class MaximumSubarrayTest:public ::testing::Test{
protected:
    vector<int> arr1 = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    vector<int> arr_negative = {-20,-341,-2,-1,-35,-6,-4,-24,-7};

protected:
    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(MaximumSubarrayTest, brute_force){
    vector<int> ans = maximumSubarray_bruteforce(arr1);
    ASSERT_EQ(ans[0], 7);
    ASSERT_EQ(ans[1],10);
    ASSERT_EQ(ans[2], 43);
}



int main(){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}