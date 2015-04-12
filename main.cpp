/*********************************************************************************
*     File Name           :     main.cpp
*     Created By          :     QiangWei
*     Creation Date       :     [2015-04-12 07:33]
*     Last Modified       :     [2015-04-12 08:06]
*     Description         :      
**********************************************************************************/

#include "ObjectPool.hpp"
#include <string>
#include <iostream>
namespace obp
{
template <>
std::string* ObjectPool<std::string>::construct()
{
    std::cout << 123 << std::endl;
    return new std::string;
}

template <>
void ObjectPool<std::string>::destroy(std::string*)
{
    std::cout << 321 << std::endl;
}

}

int main()
{
    obp::ObjectPool<std::string> b(3);
}
