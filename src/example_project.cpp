// Copyright 2024 timetravelCat
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stdio.h>
#include <ExampleProject/Version.h>
#include <memory>
#include <vector>
#include <iostream>

void check_editor_warning() {
    int* p = new int;
    delete p;
    *p = 0;

    char buf[10];
    buf[0] = 0;

    int a = 10;
    int b = 0;
    int c = a / b;
};

using namespace std;
void superComplexFunction(int a, int b, int c, int d, int e, int f, vector<int> nums) {
    std::cout << e << std::endl;
    if(a > 0) {
        for(int i = 0; i < b; ++i) {
            if(i % 2 == 0) {
                for(int j = 0; j < c; ++j) {
                    switch(j % 3) {
                    case 0:
                        cout << "Case 0: i = " << i << ", j = " << j << endl;
                        for(int k = 0; k < nums.size(); ++k) {
                            if(nums[k] > 0) {
                                cout << "Positive number: " << nums[k] << endl;
                                if(nums[k] % 2 == 0) {
                                    while(nums[k] > 0) {
                                        nums[k] -= 1;
                                        cout << "Decrementing even number: " << nums[k] << endl;
                                        if(nums[k] == 5)
                                            break;
                                    }
                                } else {
                                    nums[k] *= 2;
                                    cout << "Doubling odd number: " << nums[k] << endl;
                                }
                            } else if(nums[k] == 0) {
                                cout << "Zero encountered, skipping." << endl;
                                continue;
                            } else {
                                cout << "Negative number: " << nums[k] << endl;
                                for(int m = 0; m < f; ++m) {
                                    if(m % 5 == 0) {
                                        cout << "m divisible by 5: " << m << endl;
                                    } else if(m % 3 == 0) {
                                        cout << "m divisible by 3: " << m << endl;
                                    } else {
                                        cout << "m is neither divisible by 3 nor 5: " << m << endl;
                                    }
                                }
                            }
                        }
                        break;
                    case 1:
                        cout << "Case 1: Skipping odd j = " << j << endl;
                        break;
                    case 2:
                        cout << "Case 2: j = " << j << endl;
                        break;
                    default:
                        cout << "Unexpected default case for j = " << j << endl;
                        break;
                    }
                }
            } else {
                cout << "Odd iteration i = " << i << endl;
                if(d > 0) {
                    for(int n = 0; n < d; ++n) {
                        if(n % 2 == 0) {
                            cout << "n is even: " << n << endl;
                        } else {
                            cout << "n is odd: " << n << endl;
                        }
                    }
                } else {
                    cout << "No iterations for d as it is <= 0." << endl;
                }
            }
        }
    } else if(a == 0) {
        cout << "a is zero, initializing a new vector." << endl;
        vector<int> newNums = {1, 2, 3, 4, 5};
        for(auto num: newNums) {
            cout << "Number in new vector: " << num << endl;
        }
    } else {
        cout << "a is negative, skipping outer loops." << endl;
    }
}
