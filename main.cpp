#include <iostream>
#include <vector>

long int max = 150;
int N = 5;

std::vector<long long int> powerVec;
std::vector<long long int> permVec;

int init()
{
    permVec.clear();
    for (int i = 0; i < max; ++i)
    {
        long int k = 1;
        for (int j = 0; j < N; ++j)
        {
           k *= i; 
        }
        powerVec.push_back(k);
    }

    permVec.resize(N - 1);
    
}

void printVec(const std::vector<long long int>& vec, int size = -1)
{
    int s = vec.size();
    if (size > 0)
        s = size;

    for (int i = 0; i < s; ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

bool findPower()
{
    long long int sum = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        sum += permVec[i];
    }

    std::vector<long long int>::iterator it = std::lower_bound(powerVec.begin(), powerVec.end(), sum);
    if (it != powerVec.end() && *it == sum)
    {
        std::cout << "Found! " << std::endl;
        for (int i = 0; i < N - 1; ++i)
        {
            if (i == 0)
                std:: cout << find(powerVec.begin(), powerVec.end(), permVec[i]) - powerVec.begin() << " ^ 5 " ;
            else
                std:: cout << " + " << find(powerVec.begin(), powerVec.end(), permVec[i]) - powerVec.begin() << " ^ 5 " ;
        }
        std::cout << " = " << it - powerVec.begin()  << " ^ 5 " << std::endl; 
    }
}




// n (N) elements out of m (max)
// result is stored in permVec
void f(int n, int l)
{
    if (n > 0)
    {
        n--;
        for (int j = l; j < max; ++j)
        {
            //if (n >= N - 2) printVec(permVec);

            permVec[N - n - 2] = powerVec[j];
            f(n, j + 1);
        }
    }
    else
    {
        findPower();
    }
}

int main()
{
    init();

    f(N - 1, 0);

    return 0;
}
