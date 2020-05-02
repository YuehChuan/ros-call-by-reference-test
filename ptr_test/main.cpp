#include <iostream>
#include <memory>

//compile: g++ -std=c++11 main.c -o main
void foo( const std::shared_ptr<int> p)
{
        static int x =0;
        *p =++x;
}

int main(void)
{
        auto p =std::make_shared<int>();
        auto start = clock();
        for(int i = 0; i < 500000000; i++)
        {
                foo(p);
        }
        std::cout << " Took " << (clock() -start)/CLOCKS_PER_SEC << " s " << std::endl;

        return 0;
}
