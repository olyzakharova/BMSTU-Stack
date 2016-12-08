#include "catch.hpp"
#include <stack.hpp>

SCENARIO ("")
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
          stack1.push(12);
       
           THEN("")
           {
                REQUIRE(stack1.count() == count+1);
           }
       }
   }
}
