/*****************************************************************//**
 * \file   factory.cpp
 * \brief  Factory design pattern with std::shared_ptr<typename T>.
 * 
 * \author Xuhua Huang
 * \date   December 03, 2022
 *********************************************************************/

#include <iostream>
#include <iomanip>
#include <memory>
#include <stdio.h>

class IAbstract {
protected:
    IAbstract() = default;
    virtual ~IAbstract() = default;
public:
    virtual void execute() = 0;
};

class Impl : public IAbstract {
public:
    Impl() = default;
    virtual ~Impl() override = default;
    virtual void execute() override {
        std::cout << std::quoted("Impl::execute()") << "\n";
    }
};

std::shared_ptr<IAbstract> create_impl() {
    return std::make_shared<Impl>();
}

auto main(void) -> int {
    std::shared_ptr<IAbstract> pImpl = create_impl();
    pImpl->execute();

    system("pause");
    return EXIT_SUCCESS;
}
