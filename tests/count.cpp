#include "catch.hpp"
#include <stack.hpp>

SCENARIO ("if stack is empty")
{
   GIVEN("")
   {      
     stack<int> stackf;
           WHEN("ok")
       {  
           THEN("")
           {
                REQUIRE(stackf.count() == 0);
           }
       }
   }
}

SCENARIO ("if stack isn'tempty")
{
   GIVEN("")
   {      
          stack<int> stacks;
          stacks.push(1);  
          stacks.push(2);
          stacks.push(3);
           WHEN("ok")
       {  
           THEN("")
           {
                REQUIRE(stacks.count() != 0);
           }
       }
   }
}
