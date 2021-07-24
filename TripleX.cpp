// TripleX.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> // For std::rand() and std::srand()
#include <ctime> // for std::time()
#include <string> // For std::string()

int GetRandomNumber(int min, int max)
{
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
    return min + static_cast<int> ((max - min + 1) * (std::rand() * fraction));
}

bool Hacking(int a, int b, int c, int level)
{
    int multi{ a * b * c };
    int add{ a + b + c };
    int d{ 0 };
    int e{ 0 };
    int f{ 0 };
    int tempmulti{ 0 };
    int tempadd{ 0 };

    std::cout << "Enter Story here: Level " << level << std::endl;
    
    std::cout << "There are three numbers in the code" << std::endl;
    std::cout << "The codes multiply to give " << multi << std::endl;
    std::cout << "The codes add to give " << add << std::endl;
    while (true)
    {
        std::cout << "Enter the  three code numbers :";
        std::cin >> d;
        std::cin >> e;
        std::cin >> f;

        tempmulti = d * e * f;
        tempadd = d + e + f;
        

        if (std::cin.fail())
        {
            std::cout << "Please enter only 3 numbers" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
        {
            std::cin.ignore(32767, '\n');
          
        }
        
        if (tempadd == add)
        {
            if (tempmulti == multi)
            {
                return true;
            }
        }
        return false;
    }
  
    


     
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    bool win = true;
    int min = 2;
    int difficulty{ 3 };
    int difficultIncrease{ 3 };
    int levels{ 3 };
    bool test;


    for (int i = 1; i <= levels; ++i)
    {
        test = Hacking(GetRandomNumber(min, difficulty), GetRandomNumber(min, difficulty), GetRandomNumber(min, difficulty), i);
        if (test)
        {
            difficulty = difficulty + difficultIncrease;
        }
        if (!test)
        {
            std::cout << "You lose";
            break;
        }
    }
    if (test)
    {
        std::cout << "You Win!!!";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
