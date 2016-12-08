#include "catch.hpp"
#include <stack.hpp>

SCENARIO("if stack is empty (for push-test")
{
    GIVEN("empty stack")
    {
        stack<int> stack1;
       
        WHEN("try to push ")
        {
            stack1.push(1);
           
            THEN(" count == 1")
            {
                REQUIRE(stack1.count() == 1);
            }
        }
    }
}

SCENARIO("if stack isn't empty (but isn't full)")
{
    GIVEN("stack")
    {
        stack<int> stack1;
        stack1.push(2);
        WHEN("try to push new element")
        {
            stack1.push(4);
            THEN("")
            {
                REQUIRE(stack1.count() == 2);
            }
        }
    }
}
SCENARIO("if full stack")
{
    GIVEN("full stack")
    {
        stack<int> stack1;
        stack1.push(1);
        stack1.push(2);
        stack1.push(3);
        stack1.push(4);
       
        WHEN("try to push")
        {
            stack1.push(5);
           
            THEN("count == 5")
            {
                REQUIRE(stack1.count() == 5);
            }
        }
    }
}
