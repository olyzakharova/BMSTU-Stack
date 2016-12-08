#include <stack.hpp>
#include "catch.hpp"

SCENARIO("if stack is empty")
{
    GIVEN("empty stack")
    {
        stack<int> stack1;
       
        WHEN("")
        {
            stack1.pop();
           
            THEN("count must be 0")
            {
                REQUIRE(stack1.count() == 0);
            }
        }
    }
}

SCENARIO("if stack isn't empty v1")
{
    GIVEN("stack")
    {
        stack<int> stack1;
        st.push_back(1);
        st.push_back(2);
        st.push_back(3);
        st.push_back(4);
        st.push_back(5);

        stack<int> stack2;
        stack2.push_back(1);
        stack2.push_back(2);
        stack2.push_back(3);
        stack2.push_back(4);
        
       WHEN("try to pop")
        {
            stack1.pop();
            
           THEN("stack 1 == stack 2")
            {
                REQUIRE(stack1 == stack2);
            }
        }
    }
}

SCENARIO("if stack isn't empty v2")
{
    GIVEN("stack")
    {
        stack<int> stack1;
        stack1.push(1);
        stack1.push(2);
        stack1.push(3);
        stack1.push(4);
        stack1.push(5);
       
        WHEN("try to pop")
        {
            stack1.pop();
            THEN("count == 4")
            {
                REQUIRE(stack1.count() == 4);
            }
        }
    }
}
