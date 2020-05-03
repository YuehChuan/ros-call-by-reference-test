#include <iostream>
#include <memory>

//compile: g++ -std=c++11 main.c -o main
//void foo( const std::shared_ptr<int>& p) 10 times faster

void foo( const std::shared_ptr<int> p, int &b)
{

        int* referenceb_address = &b;
        printf("reference_b's  pointer in foo() %p\n",referenceb_address);
        
        int d=4;
        int* address_d=&d;
        printf("address_d %p\n",address_d);
        referenceb_address = address_d;
       
        printf("assign d address to reference_b's new address in new foo() %p\n",referenceb_address);//expect ==d's address
        printf("assign d address to reference_b's new value in foo() %d\n",*referenceb_address);//expect ==d'value 4
      
        printf("b reference address(&b) in foo %p\n",&b);
        printf("b reference address's value in foo() %d\n",b);
    
}

int main(void)
{
        auto p =std::make_shared<int>();
        auto start = clock();
        *p = 3;

        int c=5;    
        int* address_c=&c;
        
        printf("address_c %p\n",address_c);

        for(int i = 0; i < 1; i++)
        {       
                foo(p,c);
        }


        std::cout << " Took " << (clock() -start)/CLOCKS_PER_SEC << " s " << std::endl;
        printf("final c %d\n",c);// address_d , b ref 7
        printf("final c address %p\n",&c);// address_d , b ref 7
        return 0;
}
