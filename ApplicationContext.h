//
// Created by kir on 23.05.19.
//

#ifndef CASS_LION_APPLICATIONCONTEXT_H
#define CASS_LION_APPLICATIONCONTEXT_H

#include <string_view>

class ApplicationContext
{
public:
    static ApplicationContext &getInstance();

    void load(std::string_view filename);

    void unload(std::string_view filename) const;

private:
    ApplicationContext();
    ~ApplicationContext();
    ApplicationContext(const ApplicationContext &) = delete;
    ApplicationContext(const ApplicationContext &&) = delete;
    ApplicationContext& operator=(const ApplicationContext &) = delete;
    ApplicationContext& operator=(const ApplicationContext &&) = delete;


};


#endif //CASS_LION_APPLICATIONCONTEXT_H
