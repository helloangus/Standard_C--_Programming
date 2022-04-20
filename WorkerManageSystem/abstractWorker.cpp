#include "abstractWorker.h"

AbstractWorker :: AbstractWorker(int id, string name, int depId)
{
    m_Id = id;
    m_Name = name;
    m_DepId = depId;
}

int AbstractWorker :: getId()
{
    return m_Id;
}
string AbstractWorker :: getName()
{
    return m_Name;
}
int AbstractWorker :: getDepId()
{
    return m_DepId;
}
