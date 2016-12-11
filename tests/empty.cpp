#include "catch.hpp"
#include <stack.hpp>

SCENARIO("if stack is empty (must return true) ")
{
    GIVEN("stack")
    {
       stack<int> stack1;
        
        WHEN("try")
        {
            THEN("true")
            {
            
              REQUIRE(stack1.empty());
              
            }
            
        }
        
    }
    
}



SCENARIO("if stack isn't empty (must return false)")
{
    GIVEN("non-empty stack")
    {
        stack<int> stack1;
        stack1.push(2);
       
       WHEN("try")
         {
            THEN("return false")
            {
            
                REQUIRE_FALSE(stack1.empty());
                
            }
            
        }
        
    }
    
}
