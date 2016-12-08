#include "catch.hpp"
#include <stack.hpp>

SCENARIO ("if stack is empty")
{
   GIVEN("")
   {      
     stack<int> stack1;
     stack1.push(1);
     stack1.push(2);
     stack1.push(3);
     auto count = stack1.count();
      
     WHEN("ok")
       {  
          stack1.pop();
       
           THEN("")
           {
                REQUIRE(stack1.count == count-1);
           }
       }
   }
}


