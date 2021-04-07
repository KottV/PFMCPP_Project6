/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>

struct T
{
    int value = 0;
    char name; FIXME: 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()

    T(int v, const char* pname)//1
    {
        value = v;//2
        name = *pname;//3
    }
};

struct structName1                                //4
{
    T* compare(T* a, T* b) //5
    {
        if (a != nullptr && b != nullptr)
        {
            if (a->value < b->value) return a;
            if (a->value > b->value) return b;
        }
        return nullptr;
    }
};

struct U
{
    float value1 { 0 }, value2 { 0 };

    float multiple(float* updatedValue1)      //12
    {
        if (updatedValue1 != nullptr)
        {
            std::cout << "U's value1 value: " << this->value1 << std::endl;
            this->value1 = *updatedValue1;
            std::cout << "U's value1 updated value: " << this->value1 << std::endl;
            while (std::abs(this->value2 - this->value1) > 0.001f)
            {
                /*
                 write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                 */
                this->value2 += 0.05f;
            }
            std::cout << "U's value2 updated value: " << this->value2 << std::endl;
            return this->value2 * this->value1;
        }
        return 1;
    }
};

struct structName2
{
    static float multiple(U* that, float* updatedValue1)        //10
    {
        if (that != nullptr && updatedValue1 != nullptr)
        {
            std::cout << "U's value1 value: " << that->value1 << std::endl;
            that->value1 = *updatedValue1;
            std::cout << "U's value1 updated value: " << that->value1 << std::endl;
            while (std::abs(that->value2 - that->value1) > 0.001f)
            {
                /*
                 write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                 */
                that->value2 += 0.05f;
            }
            std::cout << "U's value2 updated value: " << that->value2 << std::endl;
            return that->value2 * that->value1;
        }
        return 1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    
    char alphaName = 'a';
    T alpha(3 , &alphaName);                                             //6
    char betaName = 'b';
    T beta(2 , &betaName);  
    
    structName1 f;                                            //7
    auto* smaller = f.compare(&alpha , &beta);                              //8
    if (smaller != nullptr)
        std::cout << "the smaller one is: " << smaller->name << std::endl; //9
    
    U x;
    float updatedValue = 5.f;
    std::cout << "[static func] x's multiplied values: " << structName2::multiple(&x , &updatedValue) << std::endl;                  //11
    
    U y;
    std::cout << "[member func] y's multiplied values: " << y.multiple( &updatedValue ) << std::endl;
}
