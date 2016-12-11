#include <stack.hpp>
#include "catch.hpp"

SCENARIO("if stack is empty (top-test)")
{
    GIVEN("empty stack")
    {
        stack<int> stack1;
        
        WHEN("try")
        {
            THEN("")
            {
                REQUIRE(stack1.top());
            }
            
        }
        
    }
    
}


SCENARIO("if stack isn't empty (top-test)")
{
    GIVEN(" stack")
    {
        stack<int> stack1;
        stack1.push(1);
        
        WHEN("try")
        {
            THEN("")
            {
                REQUIRE(stack1.top());
            }
            
        }
        
    }
    
}
