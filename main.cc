//
// Created by holzel on 5/19/22.
//

#include "./include/cpu.h"

int main(int argc, char **argv)
{
    //
    std::cout << "Argc: " << argc << std::endl;
    std::cout << "Argv: " << argv << std::endl;
    cpu gb = cpu();

   for(int i=0;i<10;i++)
   {
       gb.emulate();
   }

    return 0;
}

