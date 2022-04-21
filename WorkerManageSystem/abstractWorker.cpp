#include "abstractWorker.h"

AbstractWorker :: AbstractWorker(int id, string name, int depId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DepId = depId;
}

int AbstractWorker :: getId()
{
    return this->m_Id;
}
string AbstractWorker :: getName()
{
    return this->m_Name;
}
int AbstractWorker :: getDepId()
{
    return this->m_DepId;
}
